/*
 * Problem Link:				https://codeforces.com/problemset/problem/151/A
 * Problem Status:			Accepted.			
 */

package BasicOperator;

import java.util.*;

public class P151A_SoftDrinking {
	
	public static int SolverA(int n, int k, int l, int c, int d, int p, int nl, int np) {
		// -------------------------- SEPARATOR --------------------------
		int A = k * l / nl;
		int B = c*d;
		int C = p / np;
		// -------------------------- SEPARATOR --------------------------
		return getMin(A, B, C) / n;
	}
	
	public static int getMin(int A, int B, int C) {
		if(A <= B && A<= C)
			return A;
		else if(B <= A && B <= C)
			return B;
		else if(C <= A && C <= B)
			return C;
		else
			return 0;
	}

	public static void main(String[] args) {
		// -------------------------- SEPARATOR --------------------------
		Scanner Reader = new Scanner(System.in);
		int n = Reader.nextInt(); 
		int k = Reader.nextInt(); 
		int l = Reader.nextInt(); 
		int c = Reader.nextInt(); 
		int d = Reader.nextInt(); 
		int p = Reader.nextInt(); 
		int nl = Reader.nextInt(); 
		int np = Reader.nextInt(); 
		Reader.close();
		// -------------------------- SEPARATOR --------------------------
		System.out.println(SolverA(n, k, l, c, d, p, nl, np));
		// -------------------------- SEPARATOR --------------------------
	}

}
