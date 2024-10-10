package SpecialityDocPatientScheduler;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.util.stream.Collectors;

public class SpecialityDocPatientScheduler {

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter the name of the text file: ");
            String fileName = scanner.nextLine();

            HashMap<String, Doctor> doctors = new HashMap<>();
            HashMap<String, Patient> patients = new HashMap<>();
            HashMap<String, HashSet<String>> schedule = new HashMap<>();

            if (readDataFromFile(fileName, doctors, patients)) {
                boolean isSchedulingPossible = schedulePatientsWithSpecialties(doctors, patients, schedule, "desiredPatientSpecialty", "desiredDoctorSpecialty");

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

    private static boolean readDataFromFile(String fileName, HashMap<String, Doctor> doctors, HashMap<String, Patient> patients) {
        try {
            Scanner fileScanner = new Scanner(new File(fileName));
            while (fileScanner.hasNextLine()) {
                String line = fileScanner.nextLine();
                String[] parts = line.split(":");
                String name = parts[0].trim();
                int hours = Integer.parseInt(parts[1].trim());
    
                if (name.startsWith("Doctor")) {
                    String specialty = parts[2].trim(); // Assuming specialty is present in the data
                    doctors.put(name, new Doctor(name, hours, specialty));
                } else if (name.startsWith("Patient")) {
                    String patientSpecialty = parts[2].trim(); // Assuming patient specialty is present in the data
                    patients.put(name, new Patient(name, hours, patientSpecialty));
                }
            }
    
            // Print Doctors and Patients here
            // Print Doctors
            System.out.println("Doctors:");
            doctors.values().forEach(doctor -> System.out.println(doctor.getName() + ": " + doctor.getHours() + " hours, Specialty: " + doctor.getSpecialty()));
    
            // Print Patients
            System.out.println("\nPatients:");
            patients.values().forEach(patient -> System.out.println(patient.getName() + ": " + patient.getHours() + " hours, Specialty: " + patient.getSpecialty()));
    
            fileScanner.close();
            return true;
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return false;
        }
    }
    


    private static void displaySchedule(HashMap<String, HashSet<String>> schedule) {
        for (Map.Entry<String, HashSet<String>> entry : schedule.entrySet()) {
            String doctor = entry.getKey();
            HashSet<String> patients = entry.getValue();
            System.out.println(doctor + " scheduled to see: " + patients);
        }
    }



    private static boolean schedulePatientsWithSpecialties(
        HashMap<String, Doctor> doctors,
        HashMap<String, Patient> patients,
        HashMap<String, HashSet<String>> schedule,
        String patientSpecialty,
        String doctorSpecialty) {

    // Filter patients by specialty
    List<Patient> eligiblePatients = patients.values().stream()
            .filter(patient -> patient.getSpecialty().equalsIgnoreCase(patientSpecialty))
            .collect(Collectors.toList());

    // Sort eligible patients by required hours (descending)
    eligiblePatients.sort(Comparator.comparingInt(Patient::getHours).reversed());

    // Iterate through eligible patients
    for (Patient patient : eligiblePatients) {
        int requiredHours = patient.getHours();

        // Iterate through doctors
        for (Map.Entry<String, Doctor> entry : doctors.entrySet()) {
            String doctorName = entry.getKey();
            Doctor doctor = entry.getValue();
            int availableHours = doctor.getHours();

            // Check if the doctor has the correct specialty and can accommodate the patient
            if (doctor.getSpecialty().equalsIgnoreCase(doctorSpecialty) && availableHours >= requiredHours) {
                // Schedule the patient with the doctor
                doctor.setHours(availableHours - requiredHours);
                patients.remove(patient.getName());

                // Update the schedule map
                schedule.computeIfAbsent(doctorName, k -> new HashSet<>()).add(patient.getName());

                // Recursively try scheduling the remaining patients
                if (schedulePatientsWithSpecialties(doctors, patients, schedule, patientSpecialty, doctorSpecialty)) {
                    return true;
                }

                // Backtrack: undo the scheduling attempt
                doctor.setHours(availableHours + requiredHours);  // Corrected line
                patients.put(patient.getName(), patient);
                schedule.get(doctorName).remove(patient.getName());
            }
        }
    }

    // No valid schedule found for the given patient and doctor specialties
    return false;
}

    // private static boolean schedulePatientsWithSpecialties(
    //         HashMap<String, Doctor> doctors,
    //         HashMap<String, Patient> patients,
    //         HashMap<String, HashSet<String>> schedule,
    //         String patientSpecialty,
    //         String doctorSpecialty) {

    //     // Filter patients by specialty
    //     List<Patient> eligiblePatients = patients.values().stream()
    //             .filter(patient -> patient.getSpecialty().equalsIgnoreCase(patientSpecialty))
    //             .collect(Collectors.toList());

    //     // Sort eligible patients by required hours (descending)
    //     eligiblePatients.sort(Comparator.comparingInt(Patient::getHours).reversed());

    //     // Iterate through eligible patients
    //     for (Patient patient : eligiblePatients) {
    //         int requiredHours = patient.getHours();

    //         // Iterate through doctors
    //         for (Map.Entry<String, Doctor> entry : doctors.entrySet()) {
    //             String doctorName = entry.getKey();
    //             Doctor doctor = entry.getValue();
    //             int availableHours = doctor.getHours();

    //             // Check if the doctor has the correct specialty and can accommodate the patient
    //             if (doctor.getSpecialty().equalsIgnoreCase(doctorSpecialty) && availableHours >= requiredHours) {
    //                 // Schedule the patient with the doctor
    //                 doctor.setHours(availableHours - requiredHours);
    //                 patients.remove(patient.getName());

    //                 // Update the schedule map
    //                 schedule.computeIfAbsent(doctorName, k -> new HashSet<>()).add(patient.getName());

    //                 // Recursively try scheduling the remaining patients
    //                 if (schedulePatientsWithSpecialties(doctors, patients, schedule, patientSpecialty, doctorSpecialty)) {
    //                     return true;
    //                 }

    //                 // Backtrack: undo the scheduling attempt
    //                 doctor.setHours(availableHours);
    //                 patients.put(patient.getName(), patient);
    //                 schedule.get(doctorName).remove(patient.getName());
    //             }
    //         }
    //     }

    //     // No valid schedule found for the given patient and doctor specialties
    //     return false;
    // }

    // Additional class definitions for Doctor and Patient
    static class Doctor {
        private String name;
        private int hours;
        private String specialty;

        public Doctor(String name, int hours, String specialty) {
            this.name = name;
            this.hours = hours;
            this.specialty = specialty;
        }

        public String getName() {
            return name;
        }

        public int getHours() {
            return hours;
        }

        public String getSpecialty() {
            return specialty;
        }

        public void setHours(int hours) {
            this.hours = hours;
        }
    }

    static class Patient {
        private String name;
        private int hours;
        private String specialty;

        public Patient(String name, int hours, String specialty) {
            this.name = name;
            this.hours = hours;
            this.specialty = specialty;
        }

        public String getName() {
            return name;
        }

        public int getHours() {
            return hours;
        }

        public String getSpecialty() {
            return specialty;
        }

        
    }
}

