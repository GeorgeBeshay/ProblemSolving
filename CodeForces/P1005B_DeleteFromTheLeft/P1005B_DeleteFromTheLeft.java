/*
 * Problem Link:			https://codeforces.com/problemset/problem/1005/B
 * Problem Status:		Accepted.
 */	

package CodeForces.P1005B_DeleteFromTheLeft;

import java.util.*;

public class P1005B_DeleteFromTheLeft {
	/*
	 * Main Method Used To Solve The Problem
	 * Input: The 2 Strings.
	 * Output: Number Of Minimum Moves.
	 * IDEA:
	 *		1) Search For The Longer String.
	 *		2) Keep Decreasing the length Until both Strings are Equal in length.
	 *		3) Compare Both Strings When They Are Equal In Length.
	 *		4) If They Are Equivalent => End, If Not, Decrease The Length of Any One of Them, and Return to
	 *			The First Step. 
	 */
	public static int SolverA(String A, String B) {
		// -----------------------------------------------------------------------------------------------
		int ans = 0;
		int tempAns = 0;
		int minLength = SupportA(A, B);
		// -----------------------------------------------------------------------------------------------
		if(A.length() > minLength) {
			ans+= (A.length() - minLength) ;
			A = SupportB(A, (A.length()-minLength) );
		}
		if(B.length() > minLength) {
			ans+= (B.length() - minLength) ;
			B = SupportB(B, (B.length()-minLength));
		}
		for(int j = A.length()-1 ; j >= 0 ; j--) {
			if(A.charAt(j) == B.charAt(j)) {
				tempAns += 2;
			} else
				break;
		}
		// -----------------------------------------------------------------------------------------------
		return ans + 2*minLength - tempAns;
		// -----------------------------------------------------------------------------------------------
	}
	
	/*
	 * Support Method A
	 * Method Used To Calculate the length of the shortest string among the 2 strings.
	 * Input: The 2 Strings
	 * Output is one of the following:
	 * 		= A's Length
	 * 		= B's Length
	 * 		= -1
	 */
	public static int SupportA(String A, String B) {
		if( A.length() < B.length() )
			return A.length();
		else if( B.length() < A.length() )
			return B.length();
		else
			return A.length();
	}
	
	/*
	 * Support Method B
	 * Method Used To Remove The Left Most Character From A String, Taking In Consideration 
	 * if the String's Length = 0 or 1
	 * Input: String To Remove Character From.
	 * Output: String After Removing The Character.
	 */
	public static String SupportB(String A, int LengthToBeCropped) {
		if(LengthToBeCropped > A.length())
			return "ERROR";
		if(A.length() == 0)
			return A;
		else if(A.length() == 1)
			return "";
		else
			return A.substring(LengthToBeCropped);
		
	}

	/*
	 * Driver Code - Main Method -
	 */
	public static void main(String[] args) {
		// -----------------------------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// -----------------------------------------------------------------------------------------------
		String TextA = Reader.next();
		String TextB = Reader.next();
		// -----------------------------------------------------------------------------------------------
		Reader.close();
		// -----------------------------------------------------------------------------------------------
		System.out.println(SolverA(TextA, TextB));
		// -----------------------------------------------------------------------------------------------
	}
}
