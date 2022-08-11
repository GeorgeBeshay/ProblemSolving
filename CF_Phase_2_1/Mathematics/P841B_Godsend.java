/*
 * Problem Link:				https://codeforces.com/problemset/problem/841/B
 * Problem Status:			Accepted.
 */

package Mathematics;

import java.util.*;

public class P841B_Godsend {
	
	public static String SolverA(int[] A) {
		int NumberOfOdd = 0;
		// ------------------------------------- SEPARATOR -------------------------------------
		for(int i = 0 ; i< A.length ; i++) 
			if(A[i] % 2 == 1)
				NumberOfOdd++;
		// ------------------------------------- SEPARATOR -------------------------------------
		if(NumberOfOdd == 0)
			return "Second";
		else
			return "First";
		// ------------------------------------- SEPARATOR -------------------------------------	
	}

	public static void main(String[] args) {
		// ------------------------------------- SEPARATOR -------------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int[] A = new int[N];
		for(int i = 0 ; i < N ; i++)
			A[i] = Reader.nextInt();
		Reader.close();
		// ------------------------------------- SEPARATOR -------------------------------------
		System.out.println(SolverA(A));
		// ------------------------------------- SEPARATOR -------------------------------------
	}

}