/*
 * Problem Link:				https://codeforces.com/problemset/problem/265/B
 * Problem Status:			Accepted.
 */

package Mathematics;

import java.util.*;

public class P265B_RoadsideTreesSimplifiedEdition {
	
	public static int SolverA(int[] A) {
		int ans = 0;
		int currentHeight = 0;
		// --------------------------- SEPARATOR ---------------------------
		for(int i = 0 ; i < A.length ; i++) {
			ans += ((A[i] - currentHeight)*1) ;				// Walking Up
			ans++;															// Eating
			currentHeight = A[i];
			// --------------------------- SEPARATOR ---------------------------
			if(i != A.length-1) {
				if(A[i+1] >= A[i])
					ans++;													// Jumping to the next tree.
				else {
					ans += A[i] - A[i+1];								// Walking Down
					ans++;													// Jump to the next tree
					currentHeight = A[i+1];
				}
			}
			// --------------------------- SEPARATOR ---------------------------
		}
		// --------------------------- SEPARATOR ---------------------------
		return ans;
	}

	public static void main(String[] args) {
		// --------------------------- SEPARATOR ---------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int[] A = new int[N];
		for(int i = 0 ; i < N ; i++)
			A[i] = Reader.nextInt();
		Reader.close();
		System.out.println(SolverA(A));
		// --------------------------- SEPARATOR ---------------------------
	}

}
