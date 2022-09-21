/*
 * Problem Link:			https://codeforces.com/contest/989/problem/B
 * Problem Status:		Accepted.
 */

package String;

import java.util.*;

public class P989B_ATideOfRiverscape {

	public static void main(String[] args) {
		// -------------- Separator --------------
		int N, P;
		char[] A;
		// -------------- Separator --------------
		Scanner Reader = new Scanner(System.in);
		N = Reader.nextInt();
		P = Reader.nextInt();
		A = new char[N];
		A = Reader.next().toCharArray();
		Reader.close();
		// -------------- Separator --------------
		showArr(TheAmazingFunction(P, A));
		// -------------- Separator --------------
	}
	
	public static void showArr(char[] X) {
		for(int i = 0 ; i < X.length ; i++)
			System.out.print(X[i]);
	}
	
	public static char[] TheAmazingFunction(int P, char[] A) {
		boolean Flag = false;
		// -------------- Separator --------------
		for(int i = 0 ; i < A.length - P ; i++) {
			if(A[i] == A[i+P] && A[i] == '.') {
				A[i] = '0';
				A[i+P] = '1';
				Flag = true;
				break;
			}
			if(A[i] != A[i+P]) {
				if(A[i] == '.' || A[i+P] == '.') {
					if(A[i] == '.') {
						if(A[i+P] == '1')
							A[i] = '0';
						else
							A[i] = '1';
					} else {
						if(A[i] == '1')
							A[i+P] = '0';
						else
							A[i+P] = '1';
					}
				}
				Flag = true;
				break;
			}
		}
		if(Flag) {
			for(int i = 0 ; i < A.length ; i++) {
				if(A[i] == '.') {
					A[i] = '0';
				}
			}
			return A;
		} else 
			return "NO".toCharArray();
		// -------------- Separator --------------
	}

}
