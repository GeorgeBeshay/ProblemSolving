/*
 * Problem LinkL:			https://codeforces.com/problemset/problem/546/A
 * Problem Status: 		Accepted.
 */

package BasicOperator;

import java.util.*;

public class P546A_SoldierAndBananas {
	
	public static int SolverA(int K, int N, int W) {
		int ans = 0;
		// --------------------------------- SEPARATOR ---------------------------------
		for(int i = 1 ; i <= W ; i++)
			N -= (i * K);
		if(N < 0)
			ans = Math.abs(N);
		// --------------------------------- SEPARATOR ---------------------------------
		return ans;
	}

	public static void main(String[] args) {
		// --------------------------------- SEPARATOR ---------------------------------
		Scanner Reader = new Scanner(System.in);
		int K = Reader.nextInt();
		int N = Reader.nextInt();
		int W = Reader.nextInt();
		Reader.close();
		System.out.println(SolverA(K, N, W));
		// --------------------------------- SEPARATOR ---------------------------------
	}

}
