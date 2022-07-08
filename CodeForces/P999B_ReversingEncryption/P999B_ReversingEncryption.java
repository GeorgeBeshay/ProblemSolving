/*
 * Problem Link:		https://codeforces.com/problemset/problem/999/B
 * Problem Status:	Accepted.
 */
package CodeForces.P999B_ReversingEncryption;

import java.util.*;

public class P999B_ReversingEncryption {
	
	/*
	 * The Essential Function Used To Solve The Problem.
	 * Input: String To Be Reverse Encrypted, String Length N.
	 * Output: Char Array After Being Reverse Encrypted.
	 * ------------------------------------ Idea ------------------------------------
	 * 1) Get All Divisors Of N [d1, d2, ...]
	 * 2) Iterate Over The Divisors Starting From The Smallest One Which is Actually (1)
	 * 3) For Each Iteration Reverse The Characters In CURRENT STRING Starting from index 0, Ending At index D-1 (Inclusively). 
	 */
	public static char[] Solver(String A, int N) {
		// --------------------------------------------------------------------------------------
		char[] Answer = A.toCharArray();
		// --------------------------------------------------------------------------------------
		for(int i = 1 ; i <= N ; i++) {
			if( (N / i) == ( (double)N / i) ) {
				Answer = SupportMethod1(Answer, 0, i-1);
			} else 
				continue;
		}
		// --------------------------------------------------------------------------------------
		return Answer;
		// --------------------------------------------------------------------------------------
	}

	/*
	 * Method Used As A Support Method For The Main Solver Method.
	 * Method Reverses Characters in a string from index i to index j.
	 * Input: Character Array, Index Starting From, Ending At, At Which The Letter Between Inclusively Will Be Reversed.
	 * Output: Character Array After Reversing Characters Required.
	 */
	public static char[] SupportMethod1(char[] A, int i, int j) {
		// --------------------------------------------------------------------------------------
		char[] Answer = String.copyValueOf(A).toCharArray();
		int Max;
		if(j % 2 == 0)
			Max = (j / 2) - 1;
		else
			Max = j / 2;
		// --------------------------------------------------------------------------------------
		for(int u = i ; u <= Max ; u++) {
			char temp = Answer[u];
			Answer[u] = Answer[j-u];
			Answer[j-u] = temp;
		}
		// --------------------------------------------------------------------------------------
		return Answer;
		// --------------------------------------------------------------------------------------
	}
	
	/*
	 * Driver Code - Main Method -
	 * Scanning Input
	 * Calling The Solver Method
	 * Returning The Output
	 */
	public static void main(String[] args) {
		// --------------------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// --------------------------------------------------------------------------------------
		int N = Reader.nextInt();
		String Input = Reader.next();
		// --------------------------------------------------------------------------------------
		Reader.close();
		// --------------------------------------------------------------------------------------
		System.out.println(Solver(Input, N));
		// --------------------------------------------------------------------------------------
	}

}
