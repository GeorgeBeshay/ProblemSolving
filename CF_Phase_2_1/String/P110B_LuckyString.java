/*
 * Problem Link:			https://codeforces.com/problemset/problem/110/B
 * Problem Status:		Accepted.
 */

package String;

import java.util.*;

public class P110B_LuckyString {
	
	public static String SolverA(int N) {
		// --------------------------- SEPARATOR ---------------------------
		String Answer = "";
		String Palette = "abcd";
		Answer += Palette.repeat( (int)Math.floor(N / 4) );
		Answer += Palette.substring(0, N%4);
		return Answer;
		// --------------------------- SEPARATOR ---------------------------
	}

	public static void main(String[] args) {
		// --------------------------- SEPARATOR ---------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		Reader.close();
		System.out.println(SolverA(N));
		// --------------------------- SEPARATOR ---------------------------
	}

}
