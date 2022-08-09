/*
 * Problem Link:					https://codeforces.com/problemset/problem/987/B
 * Problem Status:				Accepted.
 */

package Mathematics;

import java.util.*;

public class P987B_HighSchoolBecomeHuman {
	
	public static char SolverA(long X, long Y) {
		char Answer;
		// -------------------------------- SEPARATOR --------------------------------
		if(X == Y) {
			Answer = '=';
		} else if (X == 1 || Y == 1) {
			if (X == 1)
				Answer = '<';
			else
				Answer = '>';
		} else {
			if(X == 2 || Y == 2 && X == 3 || Y == 3 || X == 4 || Y == 4) {
				if(Math.pow(X, Y) > Math.pow(Y,X)) {
					Answer = '>';
				} else if (Math.pow(X, Y) < Math.pow(Y,X)) {
					Answer = '<';
				} else {
					Answer = '=';
				}			
			} else {
				if (X > Y)
					Answer = '<';
				else if (Y > X)
					Answer = '>';
				else
					Answer = '=';
			}
		}
		// -------------------------------- SEPARATOR --------------------------------
		return Answer;
	}

	public static void main(String[] args) {
		// -------------------------------- SEPARATOR -----------------------)---------
		Scanner Reader = new Scanner(System.in);
		long X = Reader.nextInt();
		long Y = Reader.nextInt();
		Reader.close();
		// -------------------------------- SEPARATOR --------------------------------
		System.out.println(SolverA(X, Y));
		// -------------------------------- SEPARATOR --------------------------------
	}

}
