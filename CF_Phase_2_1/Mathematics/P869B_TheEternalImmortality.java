/*
 * Problem Link:				https://codeforces.com/problemset/problem/869/B
 * Problem Status:			Accepted. 
 */

package Mathematics;

import java.util.*;

public class P869B_TheEternalImmortality {
	
	public static long SolverA(long A, long B) {
		long Ans = 1;
		// ------------------------------------------ SEPARATOR ------------------------------------------
		for(long i = 0 ; i < B - A ; i++) {
			if(Ans == 0)
				break;
			Ans = ( Ans * ((B-i)%10) ) % 10;
		}
		// ------------------------------------------ SEPARATOR ------------------------------------------
		return Ans;
	}

	public static void main(String[] args) {
		// ------------------------------------------ SEPARATOR ------------------------------------------
		Scanner Reader = new Scanner(System.in);
		long A = Reader.nextLong();
		long B  = Reader.nextLong();
		Reader.close();
		// ------------------------------------------ SEPARATOR ------------------------------------------
		System.out.println(SolverA(A, B));
		// ------------------------------------------ SEPARATOR ------------------------------------------
	}

}
