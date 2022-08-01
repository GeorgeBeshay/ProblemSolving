/*
 * Problem Link:				https://codeforces.com/problemset/problem/667/B
 * Problem Status:			Accepted.
 */

package Mathematics;

import java.util.*;

public class P667B_CoatOfAnticubism {
	
	public static int SolverA(int[] A) {
		int ans = 0;
		ArrayList<Integer> B = new ArrayList<Integer>(A.length);
		// ------------------------------ SEPARATOR ------------------------------
		for(int i = 0 ; i < A.length ; i++)
			B.add(A[i]);
		// ------------------------------ SEPARATOR ------------------------------
		Collections.sort(B);
		// ------------------------------ SEPARATOR ------------------------------
		int X = B.get(0);
		int Z = B.get(A.length-1);
		int Y = 0;
		for(int i = 1 ; i < A.length-1 ; i++)
			Y += B.get(i);
		// ------------------------------ SEPARATOR ------------------------------
		if( !( X + Y > Z) )
			ans = Z - Y - X + 1;
		else if (! ( X + Z > Y))
			ans = Y - Z - X + 1;
		// ------------------------------ SEPARATOR ------------------------------		
		return ans;
	}

	public static void main(String[] args) {
		// ------------------------------ SEPARATOR ------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int[] A = new int[N];
		// ------------------------------ SEPARATOR ------------------------------
		for(int i = 0 ; i < N ; i++)
			A[i] = Reader.nextInt();
		// ------------------------------ SEPARATOR ------------------------------
		Reader.close();
		// ------------------------------ SEPARATOR ------------------------------
		System.out.println(SolverA(A));
		// ------------------------------ SEPARATOR ------------------------------
	}

}
