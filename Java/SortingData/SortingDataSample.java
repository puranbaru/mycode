import java.io.*;
import java.util.*;

//note: make sure to cite your source if using this file
public class SortingDataSample {
    //example way of showing how to display results = comparison of runtime
    public static void main(String[] args) throws IOException {
        Random rand = new Random();
        int runCount = 1000;
        
        //generates runCount number of lists of random sizes and checks their runtime 
        for (int i = 0; i < runCount; i++) { 
            int[] randomArray = listGenerator(rand.nextInt(10000)); //array is of size 0-9999
            long timeStart = System.nanoTime();
            insertionSort(randomArray);
            long timePassed = (System.nanoTime() - timeStart) / 1000000;
/*
  System.nanotime() returns the time that has passed in nanoseconds (1 second =10^9 nanoseconds)
  by dividing by 1000000 (10^6) we can convert nanoseconds into milliseconds
 */
            
            //randomArray.length and timePassed are converted to strings for appendToCSV helper method below
            String[] data = {String.valueOf(randomArray.length), String.valueOf(timePassed)};
            
            appendToCSV("insertionData.csv", data);
        }
    }
    
    /*
     PARAMETERS: int listSize
     OUTPUT: int[] randomList
     PURPOSE: outputs a list of size (listSize) populated with random values
     */
    public static int[] listGenerator(int listSize) {
        Random rand = new Random();
        int[] randomList = new int[listSize];
        for (int i = 0; i < listSize; i++) {
            randomList[i] = rand.nextInt(1000000);
        }
        return randomList;
    }
    
    //appends to a CSV file of your choice ("insertionData.csv" in my case). You can find it by using the search function in your file explorer.
    /*
        note: if you want to generate new results, delete the file before running your program with this method. 
              Otherwise it will append to the same file
     */
    
    public static void appendToCSV(String fileName, String[] data) throws IOException { //source: addison migash
        try (FileWriter csvWriter = new FileWriter(fileName, true)) {
            csvWriter.append(String.join(",", data));
            csvWriter.append("\n");
        }
    }
   
    
    public static Map<String, Integer> insertionSort(int[] toSortList) {
        return null;
    }
    
}
