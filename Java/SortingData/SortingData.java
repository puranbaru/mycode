
    import java.io.FileWriter;
    import java.io.IOException;
    import java.util.Arrays;
    import java.util.HashMap;
    import java.util.Map;
    import java.util.Random;

    public class SortingData {


        public static void main(String[] args) throws IOException {
            runTests();
        }

        // Method to run tests on sorting algorithms and output results to a CSV file
        public static void runTests() {
            Random rand = new Random();
            int runCount = 1000;

            try (FileWriter csvWriter = new FileWriter("KritiTest.csv")) {
                // Write CSV file header
                csvWriter.append("Algorithm,Size,Comparisons,Exchanges,Time(ms)\n");

                // Loop for running tests
                for (int i = 0; i < runCount; i++) {
                    int[] randomArray = listGenerator(rand.nextInt(10000));

                    // Sort1: Insertion Sort
                    long timeStart = System.nanoTime();
                    Map<String, Integer> sort1Result = insertionSort(Arrays.copyOf(randomArray, randomArray.length));
                    long timePassed = (System.nanoTime() - timeStart) / 1000000;
                    writeResultToCSV(csvWriter, "Insertion Sort", randomArray.length, sort1Result, timePassed);
                }

            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        // Method to generate a random list of given size
        public static int[] listGenerator(int listSize) {
            Random rand = new Random();
            int[] randomList = new int[listSize];
            for (int i = 0; i < listSize; i++) {
                randomList[i] = rand.nextInt(1000000);
            }
            return randomList;
        }

        // Method to write results to CSV file
        public static void writeResultToCSV(FileWriter csvWriter, String algorithm, int size, Map<String, Integer> result, long time) throws IOException {
            csvWriter.append(algorithm + ",");
            csvWriter.append(Integer.toString(size) + ",");
            csvWriter.append(result.get("comparisons") + ",");
            csvWriter.append(result.get("exchanges") + ",");
            csvWriter.append(Long.toString(time) + "\n");
        }

        // Sort1: Insertion Sort implementation with tracking comparisons and exchanges
        public static Map<String, Integer> insertionSort(int[] toSortList) {
            int comparisons = 0;
            int exchanges = 0;

            int n = toSortList.length;
            for (int i = 1; i < n; ++i) {
                int key = toSortList[i];
                int j = i - 1;

                while (j >= 0 && toSortList[j] > key) {
                    toSortList[j + 1] = toSortList[j];
                    j = j - 1;
                    comparisons++;
                    exchanges++;
                }
                toSortList[j + 1] = key;
                exchanges++;
            }

            // Store results in a map
            Map<String, Integer> result = new HashMap<>();
            result.put("comparisons", comparisons);
            result.put("exchanges", exchanges);
            return result;
        }
    }

