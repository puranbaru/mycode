package NQueens;

public class NQueens {
    public static void main(String[] args) {
        int N = 8; // Change N to the desired board size
        solveNQueens(N);
    }

    public static void solveNQueens(int N) {
        int[][] board = new int[N][N];
        if (solveNQueensUtil(board, 0, N)) {
            printSolution(board);
        } else {
            System.out.println("No solution exists.");
        }
    }

    public static boolean isSafe(int[][] board, int row, int col, int N) {
        // Check the row on the left side
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 1) {
                return false;
            }
        }

        // Check upper diagonal on the left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        // Check lower diagonal on the left side
        for (int i = row, j = col; i < N && j >= 0; i++, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    public static boolean solveNQueensUtil(int[][] board, int col, int N) {
        if (col == N) {
            return true;
        }

        for (int i = 0; i < N; i++) {
            if (isSafe(board, i, col, N)) {
                board[i][col] = 1;

                if (solveNQueensUtil(board, col + 1, N)) {
                    return true;
                }

                board[i][col] = 0;
            }
        }

        return false;
    }

    public static void printSolution(int[][] board) {
        int N = board.length;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }
}
