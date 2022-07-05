/*
 * Problem Link:		https://codeforces.com/problemset/problem/266/B
 * Problem Status:	Accepted.
 */

package CodeForces.P266B_QueueAtTheSchool;

import java.util.*;

public class P266B_QueueAtTheSchool {
	
	public static void Solver(char[] A, int t) {
		while(t > 0) {
			// ----------------------------------------------------------------------------
			for(int i = 0 ; i < A.length-1 ; i++) {
				if(A[i] == 'B' && A[i+1] == 'G') {
					Swap(A, i, i+1);
					i++;
				} else 
					continue;
			}
			t--;
			// ----------------------------------------------------------------------------
		}
		System.out.println(A);
	}
	
	public static void Swap(char[] A, int index1, int index2) {
		char temp = A[index1];
		A[index1] = A[index2];
		A[index2] = temp;
	}

	public static void main(String[] args) {
		
		// ----------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// ----------------------------------------------------------------------------
		int n, t;
		String S;
		// ----------------------------------------------------------------------------
		n = Reader.nextInt();
		t = Reader.nextInt();
		S = Reader.next();
		// ----------------------------------------------------------------------------
		Reader.close();
		// ----------------------------------------------------------------------------
		Solver(S.toCharArray(), t);
		
	}
	
}
