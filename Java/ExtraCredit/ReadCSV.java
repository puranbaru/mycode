
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ReadCSV {
    public static void main(String[] args) {
        String csvFile = "applicant_data.csv";
        String line = "";
        String cvsSplitBy = ",";

        try (BufferedReader br = new BufferedReader(new FileReader(csvFile))) {
            while ((line = br.readLine()) != null) {
                String[] data = line.split(cvsSplitBy);
                System.out.println("First Name: " + data[0] + ", Last Name: " + data[1] + ", GPA: " + data[8] + ", Major: " + data[9] + ", Email: " + data[3] + ", Languages: " + data[7]);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}