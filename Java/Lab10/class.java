package Lab10;


public abstract class Question {
    private int points;
    private int difficulty;
    private int answerSpace;
    private String questionText;

    public Question(int points, int difficulty, int answerSpace, String questionText) {
        this.points = points;
        this.difficulty = difficulty;
        this.answerSpace = answerSpace;
        this.questionText = questionText;
    }

    public abstract String toString();
}

public class ObjectiveQuestion extends Question {
    private String correctAnswer;

    public ObjectiveQuestion(int points, int difficulty, int answerSpace, String questionText, String correctAnswer) {
        super(points, difficulty, answerSpace, questionText);
        this.correctAnswer = correctAnswer;
    }

    @Override
    public String toString() {
        return super.toString() + "\nCorrect Answer: " + correctAnswer;
    }
}

public class FillInTheBlankQuestion extends Question {
    private String[] answers;

    public FillInTheBlankQuestion(int points, int difficulty, int answerSpace, String questionText, String[] answers) {
        super(points, difficulty, answerSpace, questionText);
        this.answers = answers;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(super.toString());
        sb.append("\nAnswers:");
        for (String answer : answers) {
            sb.append("\n\t").append(answer);
        }
        return sb.toString();
    }
}
