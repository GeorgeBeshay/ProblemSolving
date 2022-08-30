/*
 * Problem Link:			https://codeforces.com/contest/1722/problem/B
 * Problem Status: 	Accepted.
 */

package R817_D4;

import java.util.*;

public class PB_Colourblindness {

	public static void main(String[] args) {
		// ---------------------------- SEPARATOR ----------------------------
		Scanner Reader = new Scanner(System.in);
		int T = Reader.nextInt();
		while(T > 0) {
			int N = Reader.nextInt();
			char[][] Temp = new char[2][N];
			Temp[0] = Reader.next().toCharArray();
			Temp[1] = Reader.next().toCharArray();
			checkBlindness(Temp);
			T--;
		}
		Reader.close();
		// ---------------------------- SEPARATOR ----------------------------
	}
	
	public static void checkBlindness(char[][] A) {
		for(int i = 0 ; i < A[0].length ; i++) {
			// ---------------------------- SEPARATOR ----------------------------
			if(A[0][i] == 'R' || A[1][i] == 'R') {
				if(A[0][i] == 'R' && A[1][i] == 'R')
					continue;
				// ---------------------------- SEPARATOR ----------------------------
				else {
					System.out.println("NO");
					return;
				}
				// ---------------------------- SEPARATOR ----------------------------
			}
			// ---------------------------- SEPARATOR ----------------------------
		}
		System.out.println("YES");
		return;
	}

}
