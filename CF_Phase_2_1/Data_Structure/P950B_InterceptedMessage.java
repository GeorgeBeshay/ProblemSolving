package Data_Structure;

/*
 * Problem Link: 	https://codeforces.com/problemset/problem/950/B
 * Problem Status: 	Accepted.
 */

import java.util.*;

public class P950B_InterceptedMessage {
	
	public static boolean Continue(int index1, int maxL1, int index2, int maxL2) {
		return ( (index1 < maxL1-1) && (index2 < maxL2-1) );
	}

	public static int SolverA(int[] A, int[] B) {
		int ans = 0;
		int P1;
		int P2;
		int S1;
		int S2;
		if(A[0] <= B[0]) {
			P1 = -1;
			P2 = 0;
			S1 = 0;
			S2 = B[0];
		} else {
			P1 = 0;
			P2 = -1;
			S1 = A[0];
			S2 = 0;
		}
		// -------------------------------------------------------------------
		while(Continue(P1, A.length, P2, B.length)) {
			
			while(Continue(P1, A.length, P2, B.length) && ( (S1 < S2) || (S1 == S2 && S1 == 0 && A[0] <= B[0]) ) ) {
				P1++;
				S1+=A[P1];
			}
			while(Continue(P1, A.length, P2, B.length) && (S2 < S1) || (S1 == S2 && S1 == 0 && A[0] > B[0]) ) {
				P2++;
				S2+=B[P2];
			}
			if(S1 == S2) {
//				System.out.println("P1 = " + P1 +"\nP2 = " + P2 + "\nS1 = " + S1 + "\nS2 = " + S2);
				ans++;
				P1++;
				P2++;
				S1 = A[P1];
				S2 = B[P2];
			}
				
		}
		// -------------------------------------------------------------------
		return ans+1;
	}
	
	public static void main(String[] args) {
		// -------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// -------------------------------------------------------------------
		int n = Reader.nextInt();
		int m = Reader.nextInt();
		int[] A = new int[n];
		int[] B = new int[m];
		for(int i = 0 ; i < n ; i++)
			A[i] = Reader.nextInt();
		for(int i = 0 ; i < m ; i++)
			B[i] = Reader.nextInt();
		// -------------------------------------------------------------------
		Reader.close();
		// -------------------------------------------------------------------
		System.out.println(SolverA(A, B));
	}

}
