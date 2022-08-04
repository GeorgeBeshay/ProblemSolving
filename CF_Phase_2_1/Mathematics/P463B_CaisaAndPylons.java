/*
 * Problem Link:			https://codeforces.com/problemset/problem/463/B
 * Problem Status:		Accepted.
 */

package Mathematics;

import java.util.*;

public class P463B_CaisaAndPylons {
	
	public static int SolverA(int[] A) {
		int ans = 0;
		int CurrentHeight = 0;
		int Energy = 0;
		// ------------------------------------- SEPARATOR -------------------------------------
		for(int i = 0 ; i < A.length ; i++) {
			Energy += CurrentHeight - A[i];
			if(Energy < 0) {
				ans += Math.abs(Energy);
				Energy = 0;
			}
			CurrentHeight = A[i];
		}
		// ------------------------------------- SEPARATOR -------------------------------------
		return ans;
	}

	public static void main(String[] args) {
		Scanner Reader = new Scanner(System.in);
		// ------------------------------------- SEPARATOR -------------------------------------
		int N = Reader.nextInt();
		int[] A = new int[N];
		for(int i = 0 ; i < N ; i++)
			A[i] = Reader.nextInt();
		// ------------------------------------- SEPARATOR -------------------------------------
		Reader.close();
		// ------------------------------------- SEPARATOR -------------------------------------
		System.out.println(SolverA(A));
		// ------------------------------------- SEPARATOR -------------------------------------
	}

}
