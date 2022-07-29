/*
 * Problem Link:				https://codeforces.com/problemset/problem/764/A
 * Problem Status:			Accepted.
 */
package BasicOperator;

import java.util.*;

public class P764A_TaymyrIsCallingYou {
	
	public static int SolverA(int N, int M, int Z) {
		int Answer = 0;
		int CopyN = N;
		// ------------------------------- SEPARATOR -------------------------------
		while(CopyN <= Z) {
			if(CopyN % M == 0)
				Answer++;
			CopyN += N;
		}
		// ------------------------------- SEPARATOR -------------------------------
		return Answer;
	}

	public static void main(String[] args) {
		// ------------------------------- SEPARATOR -------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int M = Reader.nextInt();
		int Z = Reader.nextInt();
		Reader.close();
		// ------------------------------- SEPARATOR -------------------------------
		System.out.println(SolverA(N, M, Z));
		// ------------------------------- SEPARATOR -------------------------------
	}

}
