/*
 * Problem Link:			https://codeforces.com/problemset/problem/581/B
 * Problem Status:		Accepted.
 */

package Mathematics;

import java.util.*;

public class P581B_LuxuriousHouses {
	
	public static void SolverA(int[] A) {
		// ---------------------------------- SEPARATOR ----------------------------------
		int[] Answers = new int[A.length];
		int GHOTR = 0; // GreatestHeightOnTheRight
		// ---------------------------------- SEPARATOR ----------------------------------
		for(int i = A.length-1 ; i>= 0 ; i--) {
			if(A[i] > GHOTR)
				Answers[i] = 0;
			else {
				Answers[i] = 1 + GHOTR - A[i];
			}
			if(A[i] > GHOTR)
				GHOTR = A[i];
		}
		// ---------------------------------- SEPARATOR ----------------------------------
		for(int i = 0 ; i < Answers.length ; i++)
			System.out.print(Answers[i] + " ");
		// ---------------------------------- SEPARATOR ----------------------------------
	}

	public static void main(String[] args) {
		// ---------------------------------- SEPARATOR ----------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int[] A = new int[N];
		for(int i = 0 ; i < N ; i++)
			A[i] = Reader.nextInt();
		Reader.close();
		// ---------------------------------- SEPARATOR ----------------------------------
		SolverA(A);
		// ---------------------------------- SEPARATOR ----------------------------------
	}

}
