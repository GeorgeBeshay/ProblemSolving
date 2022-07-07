/*
 * Problem Link:		https://codeforces.com/problemset/problem/746/B
 * Problem Status:	Accepted.
 */

package CodeForces.P746B_Decoding;

import java.util.*;

public class P746B_Decoding {
	
	public static String Solver(char[] A, int N) {
		// -----------------------------------------------------------------------------
		String Answer = "";
		// -----------------------------------------------------------------------------
		for(int i = N-1 ; i >= 0 ; i--) {
				Answer = Insert(Answer, (Answer.length() / 2) - 1, A[i]);
		}
		// -----------------------------------------------------------------------------
		return Answer;
		// -----------------------------------------------------------------------------
	}
	
	public static String Insert( String S, int index, char C ) {
		String toBeReturned = "";
		toBeReturned += S.substring(0, index+1);
		toBeReturned += C;
		toBeReturned += S.substring(index + 1, S.length());
		return toBeReturned;
	}

	public static void main(String[] args) {
		// -----------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// -----------------------------------------------------------------------------
		int N = Reader.nextInt();
		String Input = Reader.next();
		// -----------------------------------------------------------------------------
		Reader.close();
		// -----------------------------------------------------------------------------
		System.out.println( Solver( Input.toCharArray() , N ) );
		// -----------------------------------------------------------------------------
	}

}
