/*
 * Problem Link:	https://codeforces.com/problemset/problem/32/B
 * Problem Status: Accepted.
 */
package CodeForces.P32B_Borze;

import java.util.*;

public class P32B_Borze {

	public static String Solver(char[] A) {
		// -----------------------------------------------------------------------------
		String Answer = "";
		String Stored = "";
		// -----------------------------------------------------------------------------
		for(int i = 0 ; i < A.length + 1 ; i++) {
			switch (Stored) {
				case "." :
					Answer += "0";
					Stored = "";
					break;
				case "-." :
					Answer += "1";
					Stored = "";
					break;
				case "--" :
					Answer += "2";
					Stored = "";
					break;
				default :
					break;
			}
			if(i < A.length)
				Stored += A[i];
		}
		// -----------------------------------------------------------------------------
		return Answer;
		// -----------------------------------------------------------------------------
	}
	
	public static void main(String[] args) {
		// -----------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// -----------------------------------------------------------------------------
		String Input = Reader.next();
		// -----------------------------------------------------------------------------
		Reader.close();
		// -----------------------------------------------------------------------------
		System.out.println( Solver( Input.toCharArray() ) );
		// -----------------------------------------------------------------------------
	}

}
