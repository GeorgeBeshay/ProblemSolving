/*
 * Problem Link:			https://codeforces.com/problemset/problem/688/B
 * Problem Status:	Accepted.
 */

package String;

import java.util.*;

public class P688B_LovelyPalindromes {

	/*
	 * Main Method
	 * IDEA:
	 * 	Iterate over a char array consisting of the double of the given number length (to be even)
	 * 	if the pointer is before the half of the string, then copy the char from the main string.
	 * 	if greater, copy the char at (char[] Length - 1 - i)  
	 */
	public static void main(String[] args) {
		// ---------------------------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// ---------------------------------------------------------------------------------------------
		String N = Reader.nextLine();
		// ---------------------------------------------------------------------------------------------
		Reader.close();
		// ---------------------------------------------------------------------------------------------
		char[] Ans = new char[N.length()*2];
		for(int i = 0 ; i < Ans.length ; i++) {
			if(i < Ans.length / 2 )
				Ans[i] = N.charAt(i);
			else
				Ans[i] = N.charAt(Ans.length-1-i);
		}
		// ---------------------------------------------------------------------------------------------
		System.out.println(Ans);
		// ---------------------------------------------------------------------------------------------
	}

}
