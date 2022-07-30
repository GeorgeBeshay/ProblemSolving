/*
 * Problem Link:			https://codeforces.com/problemset/problem/116/B
 * Problem Status:		Accepted.
 */

package String;

import java.util.*;

public class P116B_LittlePigsAndWolves {
	
	public static int SolverA(char[][] Grid) {
		int Answer = 0;
		for(int i = 0 ; i < Grid.length ; i++) {
			for(int j = 0 ; j < Grid[0].length ; j++) {
				if(SolverAJunior(Grid, i, j))
					Answer++;
			}
		}
		return Answer;
	}
	
	public static boolean SolverAJunior(char[][] Grid, int i, int j) {
		if(Grid[i][j] == 'W') {
			try {
				if(Grid[i+1][j] == 'P') {
					Grid[i+1][j] = '.';
					return true;
				}
			} catch (Exception E) { }
			try {
				if(Grid[i-1][j] == 'P') {
					Grid[i-1][j] = '.';
					return true;
				}
			} catch (Exception E) { }
			try {
				if(Grid[i][j+1] == 'P') {
					Grid[i][j+1] = '.';
					return true;
				}
			} catch (Exception E) { }
			try {
				if(Grid[i][j-1] == 'P') {
					Grid[i][j-1] = '.';
					return true;
				}
			} catch (Exception E) { }
		}
		return false;
	}

	public static void main(String[] args) {
		// ---------------------------------- SEPARATOR ----------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int M = Reader.nextInt();
		char[][] Grid = new char[N][M]; 
		for(int i = 0 ; i < N ; i++) {
			Grid[i] = Reader.next().toCharArray();
		}
		Reader.close();
		System.out.println(SolverA(Grid));
		// ---------------------------------- SEPARATOR ----------------------------------
	}

}
