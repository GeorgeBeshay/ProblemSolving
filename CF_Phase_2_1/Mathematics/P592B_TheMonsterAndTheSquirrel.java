/*
 * Problem Link: 				https://codeforces.com/problemset/problem/592/B
 * Problem Status:				Accepted.
 */

package Mathematics;

import java.util.*;

public class P592B_TheMonsterAndTheSquirrel {
	
	public static long SolverA(int N) {
		long Answer;
		// -------------------------------- SEPARATOR --------------------------------
		Answer = (long)Math.pow((N-2), 2);
		// -------------------------------- SEPARATOR --------------------------------
		return Answer;
	}

	public static void main(String[] args) {
		// -------------------------------- SEPARATOR --------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		Reader.close();
		// -------------------------------- SEPARATOR --------------------------------
		System.out.println(SolverA(N));
		// -------------------------------- SEPARATOR --------------------------------
	}

}
