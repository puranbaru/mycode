package DisasterPlanner;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class DisasterPlanner {

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter the name of the text file: ");
            String fileName = scanner.nextLine();

            HashMap<String, HashSet<String>> roadNetwork = new HashMap<>();

            if (readRoadNetworkFromFile(fileName, roadNetwork)) {
                // int numCities = roadNetwork.size();
                
                HashSet<String> supplyLocations = new HashSet<>();
                int numCities = supplyLocations.size();

                boolean isPossible = allocateResources(roadNetwork, numCities, supplyLocations);

                if (isPossible) {
                    System.out.println("Resource allocation successful!");
                    System.out.println("Supply locations: " + supplyLocations);
                } else {
                    System.out.println("Resource allocation not possible.");
                }
            } else {
                System.out.println("Error reading road network from the file.");
            }
        }
    }

    private static boolean readRoadNetworkFromFile(String fileName, HashMap<String, HashSet<String>> roadNetwork) {
        try {
            Scanner fileScanner = new Scanner(new File(fileName));
            while (fileScanner.hasNextLine()) {
                String line = fileScanner.nextLine();
                String[] parts = line.split(":");
                String city = parts[0].trim();
                String[] neighbors = parts[1].split(",");
                HashSet<String> neighborSet = new HashSet<>();
                for (String neighbor : neighbors) {
                    neighborSet.add(neighbor.trim());
                }
                roadNetwork.put(city, neighborSet);
            }
            fileScanner.close();
            return true;
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return false;
        }
    }
    
    
    // Helper method to check if all cities have access to supplies or are adjacent to a city with supplies
    private static boolean allCitiesCovered(HashMap<String, HashSet<String>> roadNetwork, HashSet<String> supplyLocations) {
        for (String city : roadNetwork.keySet()) {
            if (!supplyLocations.contains(city) && !hasNeighborWithSupplies(city, roadNetwork, supplyLocations)) {
                return false;
            }
        }
        return true;
    }
    
    // Helper method to check if a city has a neighbor with supplies
    private static boolean hasNeighborWithSupplies(String city, HashMap<String, HashSet<String>> roadNetwork, HashSet<String> supplyLocations) {
        for (String neighbor : roadNetwork.get(city)) {
            if (supplyLocations.contains(neighbor)) {
                return true;
            }
        }
        return false;
    }

    private static boolean allocateResources(HashMap<String, HashSet<String>> roadNetwork, int numCities, HashSet<String> supplyLocations) {
        // Check if all cities are covered
        if (allCitiesCovered(roadNetwork, supplyLocations)) {
            return true;
        }
    
        // Find the best city to stockpile
        String bestCity = findBestCity(roadNetwork, supplyLocations);
    
        if (bestCity == null) {
            return false;  // No city found to stockpile
        }
    
        // Add the city to the supply locations
        supplyLocations.add(bestCity);
    
        // Remove the city and its neighbors from the road network
        roadNetwork.remove(bestCity);
        for (HashSet<String> neighbors : roadNetwork.values()) {
            neighbors.remove(bestCity);
        }
    
        // Recursive call to continue allocation
        return allocateResources(roadNetwork, numCities - 1, supplyLocations);
    }
    
    
    // Helper method to find the best city to stockpile based on the number of uncovered neighbors
    private static String findBestCity(HashMap<String, HashSet<String>> roadNetwork, HashSet<String> supplyLocations) {
        String bestCity = null;
        int maxUncoveredNeighbors = -1;
    
        for (String city : roadNetwork.keySet()) {
            // Check if the city is not covered
            if (!supplyLocations.contains(city)) {
                int uncoveredNeighbors = countUncoveredNeighbors(city, roadNetwork, supplyLocations);
                
                // Update the best city if it has more uncovered neighbors
                if (uncoveredNeighbors > maxUncoveredNeighbors) {
                    bestCity = city;
                    maxUncoveredNeighbors = uncoveredNeighbors;
                }
            }
        }
    
        return bestCity;
    }
    
    // Helper method to count the number of uncovered neighbors for a city
    private static int countUncoveredNeighbors(String city, HashMap<String, HashSet<String>> roadNetwork, HashSet<String> supplyLocations) {
        int count = 0;
    
        for (String neighbor : roadNetwork.get(city)) {
            if (!supplyLocations.contains(neighbor)) {
                count++;
            }
        }
    
        return count;
    }
    
    
}

