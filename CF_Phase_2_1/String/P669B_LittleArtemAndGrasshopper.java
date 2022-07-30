/*
 * Problem Link:			https://codeforces.com/problemset/problem/669/B
 * Problem Status:	Accepted.
 */
package String;

import java.util.*;

public class P669B_LittleArtemAndGrasshopper {
	
	/*
	 * Primary Method Used To Solve The Problem
	 * IDEA:
	 * 	1) loop for the strip's length
	 * 	2) Keep track of the position x
	 * 	3) X indicates if the position at any time will be out of the strip or no
	 * 	4) After looping for the strip's length, check the value of X.
	 * 	5) if 0 <= X < N	Then "IFINITE" 	else "FINITE".
	 */
	public static String SolverA(char[] D, int[] V) {
		int x = 0;
		for(int i = 0 ; i < D.length ; i++) {
			if(D[x] == '>')
				x += V[x];
			else
				x -= V[x];
//			if(D[i] == '>') 
//				x += V[i];
//			else
//				x -= V[i];
			if(x < 0 || x > D.length)
				break;
		}
		if(x >= 0 && x < D.length)
			return "INFINITE";
		else
			return "FINITE";
	}

	/*
	 * Main Method
	 */
	public static void main(String[] args) {
		// ------------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// ------------------------------------------------------------------------------
		int N = Reader.nextInt();
		char[] Directions = Reader.next().toCharArray();
		int[] Values = new int[N];
		for(int i = 0 ; i < N ; i++)
			Values[i] = Reader.nextInt();
		// ------------------------------------------------------------------------------
		Reader.close();
		// ------------------------------------------------------------------------------
		System.out.println(SolverA(Directions, Values));
		// ------------------------------------------------------------------------------
	}

}
