/*
 * Problem Link: https://codeforces.com/contest/1702/problem/A
 * Problem Status: Accepted.
 */
package Competitions.CodeForcesContests.R805_D3;

import java.util.*;

public class PA_RoundDownThePrice {

	public static void main(String[] args) {
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		for(int i = 0 ; i < N ; i++) {
			int temp = Reader.nextInt();
			System.out.println( (int)(temp - Math.pow(10, Math.floor(Math.log10(temp)))));
		}
		Reader.close();
	}

}
