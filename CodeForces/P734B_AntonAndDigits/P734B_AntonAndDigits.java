/*
 * Problem Link:				https://codeforces.com/problemset/problem/734/B
 * Problem Status:			Accepted.
 */

package CodeForces.P734B_AntonAndDigits;

import java.util.*;

public class P734B_AntonAndDigits {

	public static int SolverA(int K2, int K3, int K5, int K6) {
		int ans = 0;
		int NumberOf256 = getMin(K2, getMin(K5, K6));
		K2 -= NumberOf256;
		K5 -= NumberOf256;
		K6 -= NumberOf256;
		int NumberOf32 = getMin(K2, K3);
		K2 -= NumberOf256;
		K3 -= NumberOf256;
		ans = (256*NumberOf256) + (32*NumberOf32);
		return ans;
	}
	
	public static int getMin(int A, int B) {
		if(A > B)
			return B;
		else
			return A;
	}
	
	public static void main(String[] args) {
		// ---------------------------- SEPARATOR ----------------------------
		Scanner Reader = new Scanner(System.in);
		int K2; int K3; int K5; int K6;
		K2 = Reader.nextInt(); K3 = Reader.nextInt(); K5 = Reader.nextInt(); K6 = Reader.nextInt();
		System.out.println(SolverA(K2, K3, K5, K6));
		Reader.close();
		// ---------------------------- SEPARATOR ----------------------------
	}

}
