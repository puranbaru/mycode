import javax.swing.*;
import java.awt.*;
import java.util.Stack;

public class MazeGridPanel extends JPanel {
	private int rows;
	private int cols;
	private Cell[][] maze;

	// Extra credit
	public void generateMazeByDFS() {
		boolean[][] visited;
		Stack<Cell> stack = new Stack<Cell>();
		Cell start = maze[0][0];
		stack.push(start);
	}

	public void solveMaze() {
		Stack<Cell> stack = new Stack<Cell>();
		Cell start = maze[0][0];
		start.setBackground(Color.GREEN);
		Cell finish = maze[rows - 1][cols - 1];
		finish.setBackground(Color.RED);
		stack.push(start);

		//int row = maze[][].row;

		// Implement your algorithm here
		// setting current position as the start

		Cell currentPos = start;

		while (!currentPos.equals(finish) && !stack.empty()){
			currentPos = stack.peek();
			if (currentPos == finish){
				System.out.println("You have escaped the maze!");
				break;
			}

//			boolean done = false;

			int row = currentPos.row;
			int col = currentPos.col;


			if (traverse(stack, row, col)){
				maze[row][col].setBackground(Color.GRAY);
			}
//			else{
//				stack.pop();
//			}

//			traverse
			/*
			boolean done = false;
//			Cell finish = maze[rows - 1][cols - 1];
//			Cell start = maze[0][0];

			if (maze[row][col] == finish ){
				done = true;
			} else if (!done) {
				if (moveIsValid(row + 1, col) && !maze[row+1][col].northWall ) {
					// validate movement up
					row++;
					maze[row][col].setBackground(Color.GRAY);
					stack.push(maze[row][col]);
				} else if (moveIsValid(row, col + 1) && !maze[row][col+1].eastWall) {
					// validate movement right
					col++;
					maze[row][col].setBackground(Color.GRAY);
					stack.push(maze[row][col]);
				} else if (moveIsValid(row - 1, col) && !maze[row-1][col].southWall) {
					// validate movement down
					row--;
					maze[row][col].setBackground(Color.GRAY);
					stack.push(maze[row][col]);
				} else if (moveIsValid(row, col - 1) && !maze[row][col-1].westWall) {
					// validate movement left
					col--;
					maze[row][col].setBackground(Color.GRAY);
					stack.push(maze[row][col]);
//				}
//				else {
//					//			maze[row][col].setBackground(Color.BLACK);
//					maze[row][col].setBackground(Color.BLUE);
//					stack.pop();
//
				}
			}

			if (done)
				maze[row][col].setBackground(Color.GREEN);
			//return done;
*/



//			for (int i = 0; i < 4; i++){
//				for (int j = 0; j < 4; j++){
////					int newRow = currentPos.row + maze[i][0].row;
////					int newCol = currentPos.col + maze[0][i].col;
//
//					// iterating through maze
//					Cell newPos = maze[i][j];
//
//
//// relationship between newPos and currentPos?
//
////				if the move is valid, then make this a new Cell and push it onto the stack + color it gray
//					if (moveIsValid(newPos.))
//					if (moveIsValid(newPos.row,newPos.col)){
//						stack.push(new Cell(newPos.row,newPos.col));
//						maze[newPos.row][newPos.col].setBackground(Color.DARK_GRAY);
//						visited(newPos.row,newPos.col);
//						break;
//					}
//					System.out.println("final row: "+ newPos.row + " final col: "+ newPos.col);
//				}
//
//			}



		}
//		if (traverse(stack,0,0)){
//			System.out.println("Maze was traversed");
//		}
	}
	public boolean moveIsValid(int row, int col){
		boolean result = false;
		if(row >= 0 && row < maze.length
				&& col >= 0 && col < maze[row].length){
			// if color is white, then cell has not been explored or is not a wall
			if (!visited(row,col)){
				result = true;
			}

		};
		return result;
	}
/*********************************************** */
	// public boolean traverse(Stack<Cell> stack, int row, int col){
	// 	boolean done = false;
	// 	Cell finish = maze[rows - 1][cols - 1];
	// 	Cell start = maze[0][0];

	// 	if (maze[row][col] == finish ){
	// 		done = true;
	// 	} else if (!done) {
	// 		if (moveIsValid(row + 1, col) && !maze[row+1][col].northWall ) {
	// 			// validate movement up
	// 			row++;
	// 			maze[row][col].setBackground(Color.GREEN);
	// 			stack.push(maze[row][col]);
	// 		} else if (moveIsValid(row, col + 1) && !maze[row][col+1].eastWall) {
	// 			// validate movement right
	// 			col++;
	// 			maze[row][col].setBackground(Color.GREEN);
	// 			stack.push(maze[row][col]);
	// 		} else if (moveIsValid(row - 1, col) && !maze[row-1][col].southWall) {
	// 			// validate movement down
	// 			row--;
	// 			maze[row][col].setBackground(Color.GREEN);
	// 			stack.push(maze[row][col]);
	// 		} else if (moveIsValid(row, col - 1) && !maze[row][col-1].westWall) {
	// 			// validate movement left
	// 			col--;
	// 			maze[row][col].setBackground(Color.GREEN);
	// 			stack.push(maze[row][col]);
	// 		} else {
	// 			//			maze[row][col].setBackground(Color.BLACK);
	// 			maze[row][col].setBackground(Color.GRAY);
	// 			stack.pop();


	// 		}
	// 	}

	// 	if (done)
	// 		maze[row][col].setBackground(Color.GREEN);
	// 	return done;
	// }

	// public boolean visited(int row, int col) {
	// 	Cell c = maze[row][col];
	// 	Color status = c.getBackground();
	// 	if (status.equals(Color.WHITE) || status.equals(Color.RED) ) {
	// 		return false;
	// 	}

	// 	return true;
	// }

//	public boolean canMove(Cell currentCell, Direction direction){
//		int row = currentCell.row;;
//		int col = currentCell.col;
//
//		switch (direction){
//			case NORTH:
//				// check for north wall in current cell
//				if (row > 0){
//					return !currentCell.northWall;
//				} break;
//
//			case SOUTH:
//				if (row < maze.length -1){
//					return !currentCell.southWall;
//				}
//		}
//
//
//		return false;
//	}

/************************************************************* */

	public boolean traverse(Stack<Cell> stack, int row, int col) {
		Cell finish = maze[rows - 1][cols - 1];
		Cell start = maze[0][0];

		if (row == finish.getRow() && col == finish.getCol()) {
			// Check if the current cell is the finish
			maze[row][col].setBackground(Color.GREEN);
			return true;
		}

		// Try to move in different directions
		if (moveIsValid(row + 1, col) && !visited(row + 1, col)) {
			// Move down
			if (traverse(stack, row + 1, col)) {
				maze[row][col].setBackground(Color.GREEN);
				stack.push(maze[row][col]);
				return true;
			}
		}
		if (moveIsValid(row, col + 1) && !visited(row, col + 1)) {
			// Move right
			if (traverse(stack, row, col + 1)) {
				maze[row][col].setBackground(Color.GREEN);
				stack.push(maze[row][col]);
				return true;
			}
		}
		if (moveIsValid(row - 1, col) && !visited(row - 1, col)) {
			// Move up
			if (traverse(stack, row - 1, col)) {
				maze[row][col].setBackground(Color.GREEN);
				stack.push(maze[row][col]);
				return true;
			}
		}
		if (moveIsValid(row, col - 1) && !visited(row, col - 1)) {
			// Move left
			if (traverse(stack, row, col - 1)) {
				maze[row][col].setBackground(Color.GREEN);
				stack.push(maze[row][col]);
				return true;
			}
		}

		// If no valid move is possible, mark the cell as visited
		maze[row][col].setBackground(Color.GRAY);
		return false;
	}

	public void generateMaze() {
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {

				if (row == 0 && col == 0) {
					continue;
				} else if (row == 0) {
					maze[row][col].westWall = false;
					maze[row][col - 1].eastWall = false;
				} else if (col == 0) {
					maze[row][col].northWall = false;
					maze[row - 1][col].southWall = false;
				} else {
					boolean north = Math.random() < 0.5;
					if (north) {
						maze[row][col].northWall = false;
						maze[row - 1][col].southWall = false;
					} else {
						maze[row][col].westWall = false;
						maze[row][col - 1].eastWall = false;
					}
					maze[row][col].repaint();
				}
			}
		}

		this.repaint();
	}

	public MazeGridPanel(int rows, int cols) {
		this.setPreferredSize(new Dimension(800, 800));
		this.rows = rows;
		this.cols = cols;
		this.setLayout(new GridLayout(rows, cols));
		this.maze = new Cell[rows][cols];
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				maze[row][col] = new Cell(row, col);
				this.add(maze[row][col]);
			}
		}

		this.generateMaze();
		this.solveMaze();
	}
}
