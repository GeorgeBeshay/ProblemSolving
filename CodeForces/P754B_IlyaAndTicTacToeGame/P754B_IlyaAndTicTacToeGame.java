/*
 * Problem Link:				https://codeforces.com/problemset/problem/754/B
 * Problem Status:			Accepted.
 */

package CodeForces.P754B_IlyaAndTicTacToeGame;

import java.util.*;

public class P754B_IlyaAndTicTacToeGame {
	
	public static String SolverA(char[][]Grid) {
		for(int i = 0 ; i < 4 ; i++) {
			for(int j = 0 ; j < 4 ; j++) {
				if(SolverBJunior(Grid, i, j))
					return "YES";
			}
		}
		return "NO";
	}
	
	public static boolean SolverBJunior(char[][] Grid, int i, int j) {
		if(Grid[i][j] != 'x')
			return false;
		else {
			// ---------------------------------------------------------------------
			int temp = 0;
			try {
				if(Grid[i+1][j] == 'x' || Grid[i+1][j] == '.') {
					if(Grid[i+1][j] == 'x')
						temp++;
					else
						temp +=2;
					if(Grid[i+2][j] == 'x' || Grid[i+2][j] == '.') {
						if(Grid[i+2][j] == 'x')
							temp++;
						else
							temp +=2;
					}
				}
				if(temp == 3) {
//					System.out.println("Case 0");
//					System.out.println(i + " " + j);
					return true;
				}
			} catch (Exception E) {}
			// ---------------------------------------------------------------------
			temp = 0;
			try {
				if(Grid[i-1][j] == 'x' || Grid[i-1][j] == '.') {
					if(Grid[i-1][j] == 'x')
						temp++;
					else
						temp +=2;
					if(Grid[i-2][j] == 'x' || Grid[i-2][j] == '.') {
						if(Grid[i-2][j] == 'x')
							temp++;
						else
							temp +=2;
					}
				}
				if(temp == 3) {
//					System.out.println("Case 1");
//					System.out.println(i + " " + j);
					return true;
				}
			} catch (Exception E) {}
			// ---------------------------------------------------------------------
			temp = 0;
			try {
				if(Grid[i][j+1] == 'x' || Grid[i][j+1] == '.') {
					if(Grid[i][j+1] == 'x')
						temp++;
					else
						temp +=2;
					if(Grid[i][j+2] == 'x' || Grid[i][j+2] == '.') {
						if(Grid[i][j+2] == 'x')
							temp++;
						else
							temp +=2;
					}
				}
				if(temp == 3) {
//					System.out.println("Case 2");
//					System.out.println(i + " " + j);
					return true;
				}
			} catch (Exception E) {}
			// ---------------------------------------------------------------------
			temp = 0;
			try {
				if(Grid[i][j-1] == 'x' || Grid[i][j-1] == '.') {
					if(Grid[i][j-1] == 'x')
						temp++;
					else
						temp +=2;
					if(Grid[i][j-2] == 'x' || Grid[i][j-2] == '.') {
						if(Grid[i][j-2] == 'x')
							temp++;
						else
							temp +=2;
					}
				}
				if(temp == 3) {
//					System.out.println("Case 3");
//					System.out.println(i + " " + j);
					return true;
				}
			} catch (Exception E) {}
			// ---------------------------------------------------------------------
			temp = 0;
			try {
				if(Grid[i+1][j+1] == 'x' || Grid[i+1][j+1] == '.') {
					if(Grid[i+1][j+1] == 'x')
						temp++;
					else
						temp +=2;
					if(Grid[i+2][j+2] == 'x' || Grid[i+2][j+2] == '.') {
						if(Grid[i+2][j+2] == 'x')
							temp++;
						else
							temp +=2;
					}
				}
				if(temp == 3) {
//					System.out.println("Case 4");
//					System.out.println(i + " " + j);
					return true;
				}
			} catch (Exception E) {}
			// ---------------------------------------------------------------------
			temp = 0;
			try {
				if(Grid[i-1][j-1] == 'x' || Grid[i-1][j-1] == '.') {
					if(Grid[i-1][j-1] == 'x')
						temp++;
					else
						temp +=2;
					if(Grid[i-2][j-2] == 'x' || Grid[i-2][j-2] == '.') {
						if(Grid[i-2][j-2] == 'x')
							temp++;
						else
							temp +=2;
					}
				}
				if(temp == 3) {
//					System.out.println("Case 5");
//					System.out.println(i + " " + j);
					return true;
				}
			} catch (Exception E) {}
			// ---------------------------------------------------------------------
			temp = 0;
			try {
				if(Grid[i+1][j-1] == 'x' || Grid[i+1][j-1] == '.') {
					if(Grid[i+1][j-1] == 'x')
						temp++;
					else
						temp +=2;
					if(Grid[i+2][j-2] == 'x' || Grid[i+2][j-2] == '.') {
						if(Grid[i+2][j-2] == 'x')
							temp++;
						else
							temp +=2;
					}
				}
				if(temp == 3) {
//					System.out.println("Case 6");
//					System.out.println(i + " " + j);
					return true;
				}
			} catch (Exception E) {}
			// ---------------------------------------------------------------------
			temp = 0;
			try {
				if(Grid[i-1][j+1] == 'x' || Grid[i-1][j+1] == '.') {
					if(Grid[i-1][j+1] == 'x')
						temp++;
					else
						temp +=2;
					if(Grid[i-2][j+2] == 'x' || Grid[i-2][j+2] == '.') {
						if(Grid[i-2][j+2] == 'x')
							temp++;
						else
							temp +=2;
					}
				}
				if(temp == 3) {
//					System.out.println("Case 7");
//					System.out.println(i + " " + j);
					return true;
				}
			} catch (Exception E) {}
			// ---------------------------------------------------------------------
		}
		return false;
	}

	public static void main(String[] args) {
		// --------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		char[][] Grid = new char[4][4];
		for(int i = 0 ; i < 4 ; i++) {
			Grid[i] = Reader.next().toCharArray();
		}
		Reader.close();
		System.out.println(SolverA(Grid));
		// --------------------------------------------------------------
	}

}
