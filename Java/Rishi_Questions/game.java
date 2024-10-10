import java.util.Arrays;

public class game {
    public static void main(String[] args) {
        String [] choices = 
        {"Kloven", "Oxberg", "Vittsjo", "Tvaro", "Revskar"};
        
        // Correct way to print the array elements
        System.out.println(Arrays.toString(choices));
        
        System.out.println("The rules are:\n Revskar beats Vittsjo, Kloven\n Vittsjo beats Oxberg, Tvaro\n Oxberg beats Revskar, Kloven\n Kloven Beats Tvaro, Vittsjo\n Tvaro beats Revskar, Oxberg");
    }
}