import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class RecommendApplicants {
    public static void main(String[] args) {
        String csvFile = "path/to/csv/file.csv";
        String line = "";
        String cvsSplitBy = ",";
        ArrayList<String[]> applicants = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(csvFile))) {
            while ((line = br.readLine()) != null) {
                String[] data = line.split(cvsSplitBy);
                if (data[7].contains("Java") && Double.parseDouble(data[8]) > 3.25) {
                    applicants.add(data);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        //applicants.sort((a, b) -> Double.compare(Double.parseDouble(b[8]), Double.parseDouble(a[8])));

        Collections.sort(applicants, new Comparator<String[]>() {
            @Override
            public int compare(String[] o1, String[] o2) {
                return Double.compare(Double.parseDouble(o2[8]), Double.parseDouble(o1[8]));
            }
        });

        for (int i = 0; i < Math.min(10, applicants.size()); i++) {
            System.out.println("First Name: " + applicants.get(i)[1] + ", Last Name: " + applicants.get(i)[0] + ", GPA: " + applicants.get(i)[8] + ", Major: " + applicants.get(i)[9] + ", Email: " + applicants.get(i)[3] + ", Languages: " + applicants.get(i)[7]);
        }
    }
}
