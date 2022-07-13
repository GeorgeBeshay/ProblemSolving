/*
 * Problem Link:			https://codeforces.com/problemset/problem/805/B
 * Problem Status:		Accepted Using Method SolverB.
 */

package CodeForces.P805B_3Palindrome;

import java.util.*;

public class P805B_3Palindrome {

	/*
	 * IDEA:
	 * 		= For 1 <= N <= 2 
	 * 			- Answer = "a" 
	 * 			- Answer = "aa"
	 * 		=	For N >= 3	
	 * 			- Place Two Pointers for charAt(LastIndex-1) & charAt(LastIndex)
	 * 			- The Third Character To Be Concatenated Should Not Be Equal To charAt(LastIndex-1)
	 * 			- Keep in Consideration That the characters to be placed priorities are as follow:
	 * 																									[ a, b, c ]
	 */
	public static String SolverA(int N) {
		// -------------------------------- SEPARATOR --------------------------------
		if(N <= 2)
			return "a".repeat(N);
		// -------------------------------- SEPARATOR --------------------------------
		String Answer = "";
		// -------------------------------- SEPARATOR --------------------------------
		while(N > 0) {
			// -------------------------------- SEPARATOR --------------------------------
			if(Answer.length() < 2)
				Answer += "a";
			// -------------------------------- SEPARATOR --------------------------------
			else {
				char BeforeLast = Answer.charAt(Answer.length()-2);
				if(BeforeLast == 'a')
					Answer += "b";
				else if (BeforeLast == 'b')
					Answer += "a";
				else
					Answer += "c";
			}
			// -------------------------------- SEPARATOR --------------------------------
			N--;
			// -------------------------------- SEPARATOR --------------------------------
		}
		// -------------------------------- SEPARATOR --------------------------------
		return Answer;
		// -------------------------------- SEPARATOR --------------------------------
	}	
	
	
	public static String SolverB(int N) {
		// -------------------------------- SEPARATOR --------------------------------
		if(N <= 2)
			return "a".repeat(N);
		// -------------------------------- SEPARATOR --------------------------------
		String Palette = "aabbaabbaabb";
		// -------------------------------- SEPARATOR --------------------------------
		String Answer = "";
		// -------------------------------- SEPARATOR --------------------------------
		Answer = Palette.repeat((int)Math.floor(N / 12));
		Answer += Palette.substring(0, (int)(N % 12) );
		// -------------------------------- SEPARATOR --------------------------------
		return Answer;
		// -------------------------------- SEPARATOR --------------------------------
	}
	
	
	public static void main(String[] args) {
		// -------------------------------- SEPARATOR --------------------------------
		Scanner Reader = new Scanner(System.in);
		// -------------------------------- SEPARATOR --------------------------------
		int N = Reader.nextInt();
		// -------------------------------- SEPARATOR --------------------------------
		Reader.close();
		// -------------------------------- SEPARATOR --------------------------------
		System.out.println(SolverB(N));
		// -------------------------------- SEPARATOR --------------------------------
	}

}
