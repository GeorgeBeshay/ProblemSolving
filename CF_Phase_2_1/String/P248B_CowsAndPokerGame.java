/*
 * Problem Link:			https://codeforces.com/problemset/problem/284/B
 * Problem Status:	Accepted.
 */
package String;

import java.util.*;

public class P248B_CowsAndPokerGame {

	/*
	 * Primary Method Used To Solve The Problem.
	 * Input: The Array's Length, The Array.
	 * Output: Integer Answer.
	 * IDEA:
	 * 	1) Count The A's, I's
	 * 	2) If I's >= 2		Answer = 0
	 * 	3) If I's == 1		Answer = 1
	 * 	4) if I's == 0		Answer = Number of A's.
	 */
	public static int SolverA(int N, char[] A) {
		// ------------------------------------------------------------------------------
		int ans = 0;
		int A_s = 0;
		int I_s = 0;
		// ------------------------------------------------------------------------------
		for(int i = 0 ; i < A.length ; i++) {
			if(A[i] == 'A')
				A_s++;
			else if (A[i] == 'I')
				I_s++;
		}
		if(I_s >= 2)
			ans = 0;
		else if (I_s == 1)
			ans = 1;
		else
			ans = A_s;
		// ------------------------------------------------------------------------------
		return ans;
		// ------------------------------------------------------------------------------
	}
	
	/*
	 * Main Method
	 */
	public static void main(String[] args) {
		// ------------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// ------------------------------------------------------------------------------
		int N = Reader.nextInt();														// Number of Characters
		char[] A = Reader.next().toCharArray();							// Character Array
		// ------------------------------------------------------------------------------
		Reader.close();
		// ------------------------------------------------------------------------------
		System.out.println(SolverA(N, A));
		// ------------------------------------------------------------------------------
	}

}
