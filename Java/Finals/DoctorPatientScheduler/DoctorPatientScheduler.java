package DoctorPatientScheduler;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class DoctorPatientScheduler {

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter the name of the text file: ");
            String fileName = scanner.nextLine();

            HashMap<String, Integer> doctors = new HashMap<>();
            HashMap<String, Integer> patients = new HashMap<>();
            HashMap<String, HashSet<String>> schedule = new HashMap<>();

            if (readDataFromFile(fileName, doctors, patients)) {
                boolean isSchedulingPossible = schedulePatients(doctors, patients, schedule);

                if (isSchedulingPossible) {
                    System.out.println("Scheduling successful!");
                    displaySchedule(schedule);
                } else {
                    System.out.println("Scheduling not possible.");
                }
            } else {
                System.out.println("Error reading data from the file.");
            }
        }
    }

    private static boolean readDataFromFile(String fileName, HashMap<String, Integer> doctors, HashMap<String, Integer> patients) {
        try {
            Scanner fileScanner = new Scanner(new File(fileName));
            while (fileScanner.hasNextLine()) {
                String line = fileScanner.nextLine();
                String[] parts = line.split(":");
                String name = parts[0].trim();
                int hours = Integer.parseInt(parts[1].trim());

                if (name.startsWith("Doctor")) {
                    doctors.put(name, hours);
                } else if (name.startsWith("Patient")) {
                    patients.put(name, hours);
                }
            }
            // Print Doctors and Patients here
            // Print Doctors
            System.out.println("Doctors:");
            doctors.forEach((name, hours) -> System.out.println(name + ": " + hours + " hours"));

            // Print Patients
            System.out.println("\nPatients:");
            patients.forEach((name, hours) -> System.out.println(name + ": " + hours + " hours"));

            System.out.println("\n");

            fileScanner.close();
            return true;
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return false;
        }
    }

 
    private static boolean schedulePatients(HashMap<String, Integer> doctors, HashMap<String, Integer> patients, HashMap<String, HashSet<String>> schedule) {
        // Base case: All patients have been scheduled
        if (patients.isEmpty()) {
            return true;
        }
    
        // Iterate through each doctor
        for (String doctor : new ArrayList<>(doctors.keySet())) {
            int availableHours = doctors.get(doctor);
    
            // Iterate through each patient
            for (String patient : new ArrayList<>(patients.keySet())) {
                int requiredHours = patients.get(patient);
    
                // Check if the doctor can accommodate the patient
                if (availableHours >= requiredHours) {
                    // Try scheduling the patient with the doctor
                    doctors.put(doctor, availableHours - requiredHours);
                    patients.remove(patient);
    
                    // Recursively try scheduling the remaining patients
                    if (schedulePatients(doctors, patients, schedule)) {
                        // If a valid schedule is found, update the schedule map
                        schedule.computeIfAbsent(doctor, k -> new HashSet<>()).add(patient);
                        return true;
                    }
    
                    // Backtrack: undo the scheduling attempt
                    doctors.put(doctor, availableHours);
                    patients.put(patient, requiredHours);
                }
            }
        }
    
        // No valid schedule found
        return false;
    }
    
    private static void displaySchedule(HashMap<String, HashSet<String>> schedule) {
        for (Map.Entry<String, HashSet<String>> entry : schedule.entrySet()) {
            String doctor = entry.getKey();
            HashSet<String> patients = entry.getValue();
            System.out.println(doctor + " scheduled to see: " + patients);
        }
    }
}
