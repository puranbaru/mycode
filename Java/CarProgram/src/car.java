
class Car {
    String make;
    String model;
    int year;
    double MPG;
    double milesDriven;
    double fuelCapacity;
    double fuelRemaining;

    public Car(String make, String model, int year, double MPG, double milesDriven, double fuelCapacity, double fuelRemaining) {
        this.make = make;
        this.model = model;
        this.year = year;
        this.MPG = MPG;
        this.milesDriven = milesDriven;
        this.fuelCapacity = fuelCapacity;
        this.fuelRemaining = fuelRemaining;
    }

    public void fillTank(double g) {
        if (g > 0 && g <= (fuelCapacity - fuelRemaining)) {
            fuelRemaining += g;
            System.out.println("Added " + g + " gallons of gas to tank.");
        } else if (g > 0 && g > (fuelCapacity - fuelRemaining)) {
            System.out.println("Cannot add more than " + (fuelCapacity - fuelRemaining) + " gallons of gas.");
            fuelRemaining = fuelCapacity;
        } else {
            System.out.println("Invalid input.");
        }
    }

    public void drive(double m) {
        if (m > 0 && m <= ((fuelRemaining * MPG))) {
            milesDriven += m;
            fuelRemaining -= m / MPG;
            System.out.println("Drove " + m + " miles.");
        } else if (m > 0 && m > ((fuelRemaining * MPG))) {
            System.out.println("Cannot drive more than " + ((fuelRemaining * MPG)) + " miles.");
            milesDriven += ((fuelRemaining * MPG));
            fuelRemaining = 0;
        } else {
            System.out.println("Invalid input.");
        }
    }

    public String toString() {
        return "Make: " + make + "\nModel: " + model + "\nYear: " + year + "\nMPG: " + MPG + "\nMiles Driven: " + milesDriven + "\nFuel Capacity: " + fuelCapacity + "\nFuel Remaining: " + fuelRemaining;
    }

    public double getFuelRemaining() {
        return fuelRemaining;
    }
}
