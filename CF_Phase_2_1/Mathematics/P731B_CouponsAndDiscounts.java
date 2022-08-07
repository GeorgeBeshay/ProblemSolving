/*
 * Problem Link:				https://codeforces.com/problemset/problem/731/B
 * Problem Status:			Accepted.
 */

package Mathematics;

import java.util.*;

public class P731B_CouponsAndDiscounts {
	
	public static String SolverA(int[] A) {
		String Answer = "YES";
		// --------------------------------- SEPARATOR ---------------------------------
		boolean CouponActivated = false;
		for(int i = 0 ; i < A.length ; i++) {
			if(A[i] % 2 == 0 && A[i] != 0) {
				if(!CouponActivated)
					continue;
				else {
					CouponActivated = true;
					continue;
				}
			}
			else if(A[i] % 2 != 0) {
				if(CouponActivated) {
					CouponActivated = false;
					continue;
				} else {
					CouponActivated = true;
				}
			} 
			else {
				if(CouponActivated)
					return "NO";
			}
		}
		if(CouponActivated)
			return "NO";
		// --------------------------------- SEPARATOR ---------------------------------
		return Answer;
	}

	public static void main(String[] args) {
		// --------------------------------- SEPARATOR ---------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int[] A = new int[N];
		for(int i = 0 ; i < N ; i++)
			A[i] = Reader.nextInt();
		Reader.close();
//		 --------------------------------- SEPARATOR ---------------------------------
		System.out.println(SolverA(A));
		// --------------------------------- SEPARATOR ---------------------------------
	}

}
