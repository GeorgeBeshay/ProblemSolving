/*	
 * Problem Link:			https://codeforces.com/problemset/problem/200/B
 * Problem Status:		Accepted.
 */

package Mathematics;

import java.util.*;

public class P200B_Drinks {
	
	public static double SolverA(int[] A) {
		double ans = 0;
		// ---------------------------------- SEPARATOR ----------------------------------
		for(int i = 0 ; i < A.length ; i++)
			ans+= A[i];
		ans /= (A.length);
		// ---------------------------------- SEPARATOR ----------------------------------
		return ans;
	}

	public static void main(String[] args) {
		// ---------------------------------- SEPARATOR ----------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int[] A = new int[N];
		for(int i = 0 ; i < N ; i++)
			A[i] = Reader.nextInt();
		Reader.close();
		System.out.println(SolverA(A));
		// ---------------------------------- SEPARATOR ----------------------------------
	}

}
