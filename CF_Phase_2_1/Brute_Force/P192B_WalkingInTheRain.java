/*
 * Problem Link:			https://codeforces.com/problemset/problem/192/B
 * Problem Status:		Accepted.
 */

package Brute_Force;

import java.util.*;

public class P192B_WalkingInTheRain {
	
	public static int SolverA(int[] A) {
		int Answer = 0;
		// ----------------------------------- SEPARATOR -----------------------------------
		while(SupportMethod2(A)) {
			Answer++;
			SupportMethod1(A);
		}
		// ----------------------------------- SEPARATOR -----------------------------------
		return Answer;
	}
	
	public static void SupportMethod1(int[] A) {
		for(int i = 0 ; i < A.length ; i ++)
			A[i]--;
	}
	
	public static boolean SupportMethod2(int[] A) {
		boolean Answer = true;
		// ----------------------------------- SEPARATOR -----------------------------------
		if(A[0] <= 0 || A[A.length-1] <= 0)
			return false;
		for(int i = 0 ; i < A.length-1 ; i++) 
			if(A[i] <= 0 && A[i+1] <= 0)
				return false;
		// ----------------------------------- SEPARATOR -----------------------------------
		return Answer;
	}

	public static void main(String[] args) {
		// ----------------------------------- SEPARATOR -----------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int[] A = new int[N];
		for(int i = 0 ; i < N ; i++)
			A[i] = Reader.nextInt();
		Reader.close();
		// ----------------------------------- SEPARATOR -----------------------------------
		System.out.println(SolverA(A));
		// ----------------------------------- SEPARATOR -----------------------------------
	}

}
