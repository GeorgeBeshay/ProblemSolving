/*
 * Problem Link:			https://codeforces.com/contest/1703/problem/A
 * Problem Status:		Accepted.
 */

package Competitions.CodeForcesContests.R806_D4;

import java.util.*;

public class PA_YESorYES {

	public static String EssentialSolver(String S) {
		if(S.toLowerCase().equals("yes"))
			return "YES";
		else 
			return "NO";
	}
	
	public static void main(String[] args) {
		// ------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// ------------------------------------------------------------------------
		int N = Reader.nextInt();
		while(N > 0) {
			String temp = Reader.next();
			System.out.println(EssentialSolver(temp));
			N--;
		}
		// ------------------------------------------------------------------------		
		Reader.close();
		// ------------------------------------------------------------------------
	}

}
