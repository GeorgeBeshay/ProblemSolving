/*
 * Problem Link:				https://codeforces.com/problemset/problem/268/B
 * Problem Status:			Accepted.
 */

package Mathematics;

import java.util.*;

public class P268B_Buttons {

	public static int SolverA(int N) {
		int ans = N;
		for(int i = 1 ; i < N ; i++) {
			ans += i * (N-i);
		}
		return ans;
	}
	
	public static void main(String[] args) {
		// ---------------------------- SEPARATOR ----------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		System.out.println(SolverA(N));
		Reader.close();
		// ---------------------------- SEPARATOR ----------------------------
	}

}
