/*
 * Problem Link:					https://codeforces.com/problemset/problem/670/B
 * Problem Status:				Accepted.
 */

package Mathematics;

import java.util.*;

public class P670B_GameOfRobots {
	
	public static int SolverA(int[] A, long M) {
		Long[] B = new Long[A.length];
		long temp = 0;
		// --------------------------------- SEPARATOR ---------------------------------
		for(int i = 0 ; i < A.length ; i++) {
			B[i] = (long)(i+1)*(long)(i+2)/ (long)2;
			if(B[i] <= M ) {
				temp = B[i];
				if(temp == M)
					return A[i];
			}
		}
		// --------------------------------- SEPARATOR ---------------------------------
		return A[(int)(M-temp)-1];
	}
 
	public static void main(String[] args) {
		// --------------------------------- SEPARATOR ---------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		long M = Reader.nextLong();
		int[] A = new int[N];
		for(int i = 0 ; i < N ; i++)
			A[i] = Reader.nextInt();
		System.out.println(SolverA(A, M));
		Reader.close();
		// --------------------------------- SEPARATOR ---------------------------------
	}

}
