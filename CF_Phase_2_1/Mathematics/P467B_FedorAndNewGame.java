/*
 * Problem Link:				https://codeforces.com/problemset/problem/467/B
 * Problem Status:			Accepted.
 */

package Mathematics;

import java.util.*;

public class P467B_FedorAndNewGame {
	
	public static int SolverA(String[] A, int K, int N) {
		int ans = 0;
		String Fedor = A[A.length-1];
		// --------------------------------------- SEPARATOR ---------------------------------------
		for(int i = 0 ; i < A.length-1 ; i++) {
			int Differences = 0;
			int j = 0;
			while(Differences <=  K && j < N) {
				if(A[i].charAt(j) != Fedor.charAt(j))
					Differences++;
				j++;
			}
			if(Differences <= K)
				ans++;
		}
		// --------------------------------------- SEPARATOR ---------------------------------------
		return ans;
	}
	
	public static String Fill(String S, int N) {
		if(S.length()== N)
			return S;
		else {
			return ("0".repeat(N-S.length()).concat(S));
		}
	}

	public static void main(String[] args) {
		// --------------------------------------- SEPARATOR ---------------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int M = Reader.nextInt();
		int K = Reader.nextInt();
		String[] A = new String[M+1];
		for(int i = 0 ; i < M+1 ; i++)
			A[i] = Fill(Integer.toBinaryString(Reader.nextInt()), N);
		Reader.close();
		// --------------------------------------- SEPARATOR ---------------------------------------
		System.out.println(SolverA(A, K, N));
		// --------------------------------------- SEPARATOR ---------------------------------------
	}

}
