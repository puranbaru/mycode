// Import any necessary packages

public class Main {
    public static void main(String[] args) {
        // Create an instance of HoneyDoList
        HoneyDoList honeyDoList = new HoneyDoList();

        // Create and add some tasks
        // Task task1 = new Task("Task 1", 30);
        // Task task2 = new Task("Task 2", 45);

        honeyDoList.addTask(task1);
        honeyDoList.addTask(task2);

        // Display the current state of the HoneyDoList
        System.out.println("Current tasks:");
        System.out.println(honeyDoList);

        // Display total time
        System.out.println("Total time to complete tasks: " + honeyDoList.totalTime() + " minutes");

        // Display the index of the shortest task
        int shortestIndex = honeyDoList.shortestTime();
        if (shortestIndex != -1) {
            System.out.println("Shortest task: " + honeyDoList.getTask(shortestIndex));
        } else {
            System.out.println("No tasks available.");
        }

        // Complete a task and display the completed task
        Task completedTask = honeyDoList.completeTask(0);
        if (completedTask != null) {
            System.out.println("Completed task: " + completedTask);
        } else {
            System.out.println("Invalid task index.");
        }

        // Display the updated state of the HoneyDoList
        System.out.println("Updated tasks:");
        System.out.println(honeyDoList);
    }
}

