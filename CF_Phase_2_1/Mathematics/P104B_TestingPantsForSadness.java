/*
 * Problem Link:				https://codeforces.com/problemset/problem/104/B
 * Problem Status:			Accepted.
 */

package Mathematics;

import java.util.*;
import java.math.*;

public class P104B_TestingPantsForSadness {
	
	public static BigInteger SolverA(long[] A) {
		BigInteger Ans = new BigInteger("0");
		int Count = 0;
		// ----------------------------------- SEPARATOR -----------------------------------
		for(int i = 0 ; i < A.length ; i++) {
			if(Ans.equals(new BigInteger("0"))) {
				Ans = Ans.add(new BigInteger(Long.toString(A[i])));
				Count++;
			}
			else {
				Ans = Ans.add(new BigInteger(Long.toString((A[i]-1) * (Count+1) + 1)));
				Count++;
			}
		}
		// ----------------------------------- SEPARATOR -----------------------------------
		return Ans;
	}

	public static void main(String[] args) {
		// ----------------------------------- SEPARATOR -----------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		long[] A = new long[N];
		for(int i = 0 ; i < N ; i++)
			A[i] = Reader.nextInt();
		Reader.close();
		// ----------------------------------- SEPARATOR -----------------------------------
		System.out.println(SolverA(A));
		// ----------------------------------- SEPARATOR -----------------------------------
	}

}
