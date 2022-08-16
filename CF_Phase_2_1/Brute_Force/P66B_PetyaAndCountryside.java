/*
 * Problem Link:			https://codeforces.com/problemset/problem/66/B
 * Problem Status:		Accepted.
 */

package Brute_Force;

import java.util.Scanner;

public class P66B_PetyaAndCountryside {
	
	public static int SolvingFunctionA(int[] A) {
		int Answer = 0;
		// ------------------------------------- SEPARATOR -------------------------------------
		for(int i = 0 ; i < A.length ; i++) {
			int TempAnswer = 1;
			// ------------------------------------- SEPARATOR -------------------------------------
			for(int j = i+1 ; j < A.length ; j++) 
				if(A[j] <= A[j-1])
					TempAnswer++;
				else
					break;
			// ------------------------------------- SEPARATOR -------------------------------------
			for(int u = i-1 ; u >= 0 ; u--)
				if(A[u] <= A[u+1])
					TempAnswer++;
				else
					break;
			// ------------------------------------- SEPARATOR -------------------------------------
			if(TempAnswer > Answer)
				Answer = TempAnswer;
		}
		// ------------------------------------- SEPARATOR -------------------------------------
		return Answer;
	}

	public static void main(String[] args) {
		// ------------------------------------- SEPARATOR -------------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int[] Arr = new int[N];
		for(int i = 0 ; i < N ; i++)
			Arr[i] = Reader.nextInt();
		Reader.close();
		// ------------------------------------- SEPARATOR -------------------------------------
		System.out.println(SolvingFunctionA(Arr));
		// ------------------------------------- SEPARATOR -------------------------------------
	}

}
