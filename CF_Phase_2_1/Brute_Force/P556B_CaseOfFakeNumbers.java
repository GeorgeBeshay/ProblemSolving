/*
 * Problem Link:			https://codeforces.com/problemset/problem/556/B
 * Problem Status:
 */

package Brute_Force;

import java.util.*;

public class P556B_CaseOfFakeNumbers {
	
	public static String SolverA(int[] A) {
		String Answer = "YES";
		// --------------------------------------- SEPARATOR ---------------------------------------
		while(A[0] != 0)
			SupportMethod1(A);
		for(int i = 1 ; i < A.length ; i++)
			if(A[i] != A[i-1]+1) {
				Answer = "NO";
				break;
			}
		// --------------------------------------- SEPARATOR ---------------------------------------
		return Answer;
	}
	
	public static void SupportMethod1(int[] A) {
		// --------------------------------------- SEPARATOR ---------------------------------------
		for(int i = 0 ; i < A.length ; i++) 
			// --------------------------------------- SEPARATOR ---------------------------------------
			if(i % 2 == 0)
				A[i] = (A[i]+1) % A.length;
			// --------------------------------------- SEPARATOR ---------------------------------------
			else {
				if(A[i] != 0)
					A[i] = (A[i] - 1) % A.length;
				else
					A[i] = A.length - 1;
			}
			// --------------------------------------- SEPARATOR ---------------------------------------
	}

	public static void main(String[] args) {
		// --------------------------------------- SEPARATOR ---------------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int[] A = new int[N];
		for(int i = 0 ; i < N ; i++)
			A[i] = Reader.nextInt();
		Reader.close();
		// --------------------------------------- SEPARATOR ---------------------------------------
		System.out.println(SolverA(A));
		// --------------------------------------- SEPARATOR ---------------------------------------
	}

}
