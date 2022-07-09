/*
 * Problem Link:			https://codeforces.com/problemset/problem/801/B
 * Problem Status:		Accepted.
 */

package CodeForces.P801B_ValuedKeys;

import java.util.*;

public class P801B_ValuedKeys {
	
	/*
	 * Major Method Used To Solve The Problem
	 * Input: The 2 Strings S1, Ans.
	 * Output: S2 String.
	 * IDEA:
	 * 		- Iterate Over Each Character
	 * 		- if char(y) < char(x)
	 * 				char(z) => char(y)
	 * 		- if char(y) == char(x)
	 * 				char(z) => Any char > char(y) [Note if the char is 'z', no greater character]
	 * 		- else
	 * 				return "-1"
	 */
	public static String Solver(String S1, String Ans) {
		String S2 = "";
		for(int i = 0 ; i < S1.length() ; i++) {
			if( (int)Ans.charAt(i) < (int)S1.charAt(i) )
				S2 += Ans.charAt(i);
			else if ( (int)Ans.charAt(i) == (int)S1.charAt(i)  )
				if( (int)Ans.charAt(i) < 122 )
					S2 += (char) ((int)Ans.charAt(i) + 1);
				else
					S2 += (char) ((int)Ans.charAt(i));
			else
				return "-1";
		}
		return S2;
	}

	/*
	 * Main Method
	 */
	public static void main(String[] args) {
		// -----------------------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// -----------------------------------------------------------------------------------------
		String S1 = Reader.next();
		String Ans = Reader.next();
		// -----------------------------------------------------------------------------------------
		Reader.close();
		// -----------------------------------------------------------------------------------------
		System.out.println(Solver(S1, Ans));
		// -----------------------------------------------------------------------------------------
	}

}
