/*
 * Problem Link:				https://codeforces.com/problemset/problem/984/B
 * Problem Status:			Accepted.
 */

package String;

import java.util.*;

public class P984B_Minesweeper {

	public static String SolverA(char[][] Field) {
		// ---------------------------------- SEPARATOR ----------------------------------
		String Answer = "YES";
		for(int i = 0 ; i < Field.length ; i++) {
			for(int j = 0 ; j < Field[0].length ; j++) {
				if(SolverAJunior(Field, i, j))
					continue;
				else
					return "NO";
			}
		}
		return Answer;
		// ---------------------------------- SEPARATOR ----------------------------------
	}
	
	public static boolean SolverAJunior(char[][] Field, int i, int j) {
		// ---------------------------------- SEPARATOR ----------------------------------
		if(Field[i][j] == '.') {
			// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			try {
				if (Field[i+1][j+1] == '*')
					return false;
			} catch (Exception E) { }
			try {
				if (Field[i-1][j-1] == '*')
					return false;
			} catch (Exception E) { }
			try {
				if (Field[i+1][j] == '*')
					return false;
			} catch (Exception E) { }
			try {
				if (Field[i][j+1] == '*')
					return false;
			} catch (Exception E) { }
			try {
				if (Field[i-1][j] == '*')
					return false;
			} catch (Exception E) { }
			try {
				if (Field[i][j-1] == '*')
					return false;
			} catch (Exception E) { }
			try {
				if (Field[i+1][j-1] == '*')
					return false;
			} catch (Exception E) { }
			try {
				if (Field[i-1][j+1] == '*')
					return false;
			} catch (Exception E) { }
			// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		}
		// ---------------------------------- SEPARATOR ----------------------------------
		else if ( ( (int)Field[i][j] - 48 ) > 0 && ( (int)Field[i][j] - 48 ) < 9 ) {
			// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			int count = ( (int)Field[i][j] - 48 );
			try {
				if (Field[i+1][j+1] == '*')
					count--;;
			} catch (Exception E) { }
			try {
				if (Field[i-1][j-1] == '*')
					count--;
			} catch (Exception E) { }
			try {
				if (Field[i+1][j] == '*')
					count--;
			} catch (Exception E) { }
			try {
				if (Field[i][j+1] == '*')
					count--;
			} catch (Exception E) { }
			try {
				if (Field[i-1][j] == '*')
					count--;
			} catch (Exception E) { }
			try {
				if (Field[i][j-1] == '*')
					count--;
			} catch (Exception E) { }
			try {
				if (Field[i+1][j-1] == '*')
					count--;
			} catch (Exception E) { }
			try {
				if (Field[i-1][j+1] == '*')
					count--;
			} catch (Exception E) { }
			if(count == 0)
				return true;
			else
				return false;
			// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		}
		// ---------------------------------- SEPARATOR ----------------------------------
		return true;
	}
	
	public static void main(String[] args) {
		// ---------------------------------- SEPARATOR ----------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int M = Reader.nextInt();
		char[][] Field = new char[N][M];
		for(int i = 0 ; i < N ; i++) 
			Field[i] = Reader.next().toCharArray();
		Reader.close();
		System.out.println(SolverA(Field));
		// ---------------------------------- SEPARATOR ----------------------------------
	}

}
