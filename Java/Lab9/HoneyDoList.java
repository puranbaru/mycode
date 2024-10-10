//Package Lab9;

import java.util.Arrays;

public class HoneyDoList {
    private Task[] tasks;
    private int numTasks;
    private final int INITIAL_CAPACITY = 10;

    public HoneyDoList() {
        tasks = new Task[INITIAL_CAPACITY];
        numTasks = 0;
    }

    public String toString() {
        String result = "";
        for (int i = 0; i < numTasks; i++) {
            result += tasks[i].toString() + "\n";
        }
        return result;
    }

    public int find(String name) {
        for (int i = 0; i < numTasks; i++) {
            if (tasks[i].getName().equalsIgnoreCase(name)) {
                return i;
            }
        }
        return -1;
    }

    public void addTask(Task task) {
        if (numTasks == tasks.length) {
            tasks = Arrays.copyOf(tasks, tasks.length * 2);
        }
        tasks[numTasks] = task;
        numTasks++;
    }

    public int totalTime() {
        int total = 0;
        for (int i = 0; i < numTasks; i++) {
            total += tasks[i].getEstMinsToComplete();
        }
        return total;
    }

    public int shortestTime() {
        if (numTasks == 0) {
            return -1;
        }
        int shortestIndex = 0;
        for (int i = 1; i < numTasks; i++) {
            if (tasks[i].getEstMinsToComplete() < tasks[shortestIndex].getEstMinsToComplete()) {
                shortestIndex = i;
            }
        }
        return shortestIndex;
    }

    public Task completeTask(int index) {
        if (index < 0 || index >= numTasks) {
            return null;
        }
        Task completedTask = tasks[index];
        for (int i = index + 1; i < numTasks; i++) {
            tasks[i - 1] = tasks[i];
        }
        numTasks--;
        return completedTask;
    }
    public Task getTask(int index) {
        if (index < 0 || index >= numTasks) {
            return null;
        }
        return tasks[index];
    }

    public Task[] overdueTasks() {
      // Extra credit
      // Implement this method to return an array of Task consisting of only the items in tasks[] that are overdue.
      // You can use the overdue() method from the Task class to check if a task is overdue.
      // If there are no overdue tasks, the method should return an empty array.
      // If you need further assistance, let me know.
      return new Task[0];
    }
}