/*
 * Problem Link:			https://codeforces.com/problemset/problem/672/B
 * Problem Status:		Accepted
 */
package CodeForces.P672B_DifferentIsGood;

import java.util.*;

public class P672B_DifferentIsGood {

	/*
	 * Major Method Used To Solve The Problem
	 * Input: String's Length, String
	 * Output: Minimum number of characters needed to be replaced.
	 * IDEA:
	 * 		Hash table will be used.
	 * 		Iterate over each character in the string, if the character was already seen before, (Value = 1)
	 * 		this character should be replaced. (ans++)
	 * 		else, make its value in the hash table = 1;
	 * 		if the string's length is greater than 26, then it is impossible to make all the substrings
	 * 		unique, as there are only 26 small English letter.
	 */
	public static int Solver(int N, String S) {
		if(N > 26)
			return -1;
		// --------------------------------------------------------------------------------------------------
		int ans = -1;
		Hashtable<Character, Integer> Table = new Hashtable<Character, Integer>(N);
		// --------------------------------------------------------------------------------------------------
		for(int i = 0 ; i < N ; i++) {
			if( Table.get(S.charAt(i)) == null )
				Table.put(S.charAt(i), 1);
			else 
				ans++;
		}
		// --------------------------------------------------------------------------------------------------
		return ++ans;
		// --------------------------------------------------------------------------------------------------
	}
	
	/*
	 * Main Method
	 */
	public static void main(String[] args) {
		// --------------------------------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// --------------------------------------------------------------------------------------------------
		int N = Reader.nextInt();			// String's Length
		String Input = Reader.next();
		// --------------------------------------------------------------------------------------------------
		Reader.close();
		// --------------------------------------------------------------------------------------------------
		System.out.println(Solver(N, Input));
		// --------------------------------------------------------------------------------------------------
	}

}
