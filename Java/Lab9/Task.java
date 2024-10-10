import java.time.LocalDateTime;

public class Task {
    private String name;
    private int priority;
    private int estMinsToComplete;
    private LocalDateTime whenDue;

    public Task(String name, int priority, int estMinsToComplete, LocalDateTime whenDue) {
        this.name = name;
        this.priority = priority;
        this.estMinsToComplete = estMinsToComplete;
        this.whenDue = whenDue;
    }

    public String getName() {
        return name;
    }

    public int getPriority() {
        return priority;
    }

    public int getEstMinsToComplete() {
        return estMinsToComplete;
    }

    public LocalDateTime getWhenDue() {
        return whenDue;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setEstMinsToComplete(int estMinsToComplete) {
        this.estMinsToComplete = estMinsToComplete;
    }

    public void setWhenDue(LocalDateTime whenDue) {
        this.whenDue = whenDue;
    }

    public String toString() {
        return "Task: " + name + ", Priority: " + priority + ", Estimated Minutes to Complete: " + estMinsToComplete
                + ", When Due: " + whenDue.toString();
    }

    public void increasePriority(int amount) {
        if (amount >= 0) {
            priority += amount;
        }
    }

    public void decreasePriority(int amount) {
        if (amount >= priority) {
            priority = 0;
        } else if (amount >= 0) {
            priority -= amount;
        }
    }

    public boolean overdue() {
        return LocalDateTime.now().isAfter(whenDue);
    }
}