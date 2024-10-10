#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

// Function to copy a file from source to destination
int copy_file(const char *src, const char *dest) {
    FILE *sptr, *dptr;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    size_t bytes_written;

    // Open the source file in read mode
    sptr = fopen(src, "rb");
    if (sptr == NULL) {
        printf("Error: Unable to open source file: %s\n", src);
        return 1;  // Return non-zero value to indicate failure
    }

    // Open the destination file in write mode (binary)
    dptr = fopen(dest, "wb");
    if (dptr == NULL) {
        printf("Error: Unable to open destination file: %s\n", dest);
        fclose(sptr);  // Close source file before returning
        return 1;  // Return non-zero value to indicate failure
    }

    // Read from the source file and write to the destination file in chunks
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, sptr)) > 0) {
        bytes_written = fwrite(buffer, 1, bytes_read, dptr);
        if (bytes_written != bytes_read) {
            printf("Error: Writing to destination file failed.\n");
            fclose(sptr);
            fclose(dptr);
            return 1;  // Return non-zero value to indicate failure
        }
    }

    // Check if reading from the source file ended with an error
    if (ferror(sptr)) {
        printf("Error: Reading from source file failed.\n");
        fclose(sptr);
        fclose(dptr);
        return 1;  // Return non-zero value to indicate failure
    }

    // Close both files
    fclose(sptr);
    fclose(dptr);

    printf("File copied successfully!\n");
    return 0;  // Return 0 to indicate success
}