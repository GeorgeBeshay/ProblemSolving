/*
 * Problem Link:		https://codeforces.com/problemset/problem/978/B
 * Problem Status:	Accepted.
 */

package String;

import java.util.*;

public class P978B_FileName {
	
	public static int Solver(char[] A, int N) {
		// -------------------------------------------------------------------------
		int ans = 0;
		String temp = "";
		// -------------------------------------------------------------------------
		for(int i = 0 ; i < N ; i++) {
			if(A[i] != 'x') {
				temp = "";
			} else {
				temp += 'x';
				if( temp.compareTo("xxx") == 0  ) {
					ans++;
					temp = "xx";
				}
			}
		}
		// -------------------------------------------------------------------------
		return ans;
		// -------------------------------------------------------------------------
	}

	public static void main(String[] args) {
		// -------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// -------------------------------------------------------------------------
		int N = Reader.nextInt();
		String Input = Reader.next();
		// -------------------------------------------------------------------------
		Reader.close();
		// -------------------------------------------------------------------------
		System.out.println( Solver( Input.toCharArray(), N ) );
		// -------------------------------------------------------------------------
	}

}
