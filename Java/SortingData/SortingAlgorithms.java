
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class SortingAlgorithms {

    // Sort1: Insertion Sort
    public static Map<String, Integer> sort1(int[] arr) {
        int comparisons = 0;
        int exchanges = 0;

        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
                comparisons++;
                exchanges++;
            }
            arr[j + 1] = key;
            exchanges++;
        }

        Map<String, Integer> result = new HashMap<>();
        result.put("comparisons", comparisons);
        result.put("exchanges", exchanges);
        return result;
    }

    // Sort2: Quicksort
    public static Map<String, Integer> sort2(int[] arr) {
        int comparisons = 0;
        int exchanges = 0;

        quickSort(arr, 0, arr.length - 1, comparisons, exchanges);

        Map<String, Integer> result = new HashMap<>();
        result.put("comparisons", comparisons);
        result.put("exchanges", exchanges);
        return result;
    }

    private static void quickSort(int[] arr, int low, int high, int comparisons, int exchanges) {
        if (low < high) {
            int pi = partition(arr, low, high, comparisons, exchanges);
            quickSort(arr, low, pi - 1, comparisons, exchanges);
            quickSort(arr, pi + 1, high, comparisons, exchanges);
        }
    }

    private static int partition(int[] arr, int low, int high, int comparisons, int exchanges) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            comparisons++;
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                exchanges++;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        exchanges++;

        return i + 1;
    }

    // Sort3: Shellsort
    public static Map<String, Integer> sort3(int[] arr) {
        int comparisons = 0;
        int exchanges = 0;

        int n = arr.length;
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                    comparisons++;
                    exchanges++;
                }
                arr[j] = temp;
                exchanges++;
            }
        }

        Map<String, Integer> result = new HashMap<>();
        result.put("comparisons", comparisons);
        result.put("exchanges", exchanges);
        return result;
    }

    public static void main(String[] args) {
        // Test your sorting algorithms here if needed
    }
}
