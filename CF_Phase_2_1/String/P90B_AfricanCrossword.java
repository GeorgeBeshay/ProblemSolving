/*
 * Problem Link:					https://codeforces.com/problemset/problem/90/B
 * Problem Status:				Accepted.
 */

package String;

import java.util.*;

public class P90B_AfricanCrossword {
	
	public static String SolverA(char[][] Grid) {
		// ------------------------------- SEPARATOR -------------------------------
		StringBuilder Answer = new StringBuilder("");
		// ------------------------------- SEPARATOR -------------------------------
		for(int i = 0 ; i < Grid.length ; i++) 
			for(int j = 0 ; j < Grid[0].length ; j++) 
				if(CheckAndRemove(Grid, Grid[i][j], i, j))
					Answer.append(Grid[i][j]);
		// ------------------------------- SEPARATOR -------------------------------
		return Answer.toString();
		// ------------------------------- SEPARATOR -------------------------------
	}
	
	public static boolean CheckAndRemove(char[][] Grid, char L, int R, int C) {
		int R_Count = 0;
		int C_Count = 0;
		// ------------------------------- SEPARATOR -------------------------------
		for(int i = 0 ; i < Grid.length ; i++)
			if(Grid[i][C] == L)
				R_Count++;
		for(int j = 0 ; j < Grid[0].length ; j++) 
			if(Grid[R][j] == L)
				C_Count++;
		// ------------------------------- SEPARATOR -------------------------------
		if(R_Count > 1 || C_Count > 1)
			return false;
		return true;
		// ------------------------------- SEPARATOR -------------------------------
	}

	public static void main(String[] args) {
		// ------------------------------- SEPARATOR -------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int M = Reader.nextInt();
		char[][] Grid = new char[N][M];
		for(int i = 0 ; i < N ; i++)
			Grid[i] = Reader.next().toCharArray();
		Reader.close();
		System.out.println(SolverA(Grid));
		// ------------------------------- SEPARATOR -------------------------------
	}

}
