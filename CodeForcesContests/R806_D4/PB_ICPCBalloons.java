/*
 * Problem Link:			https://codeforces.com/contest/1703/problem/B
 * Problem Status:		Accepted.
 */

package Competitions.CodeForcesContests.R806_D4;

import java.util.*;

public class PB_ICPCBalloons {

	public static int EssentialSolver(String S) {
		int ans = 0;
		int[] Table = new int[26];
		int charValue;
		for(int i = 0 ; i < S.length() ; i++) {
			charValue = (int)S.charAt(i) - 65;
			if(Table[charValue] == 0) {
				ans += 2;
				Table[charValue]++;
			} else {
				ans ++;
			}
		}
		return ans;
	}
	
	public static void main(String[] args) {
		// ------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// ------------------------------------------------------------------------
		int T = Reader.nextInt();
		while(T > 0) {
			int N = Reader.nextInt();
			String Input = Reader.next();
			System.out.println(EssentialSolver(Input));
			T--;
		}
		// ------------------------------------------------------------------------
		Reader.close();
		// ------------------------------------------------------------------------
	}

}
