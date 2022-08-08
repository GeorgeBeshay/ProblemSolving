/*
 * Problem Link:			https://codeforces.com/problemset/problem/898/B
 * Problem Status:		Accepted.
 */

package Mathematics;

import java.util.*;

public class P898B_ProperNutrition {
	
	public static void SolverA(int N, int A, int B) {
		if(N % A == 0 || N % B == 0) {
			if(N % A == 0) {
				System.out.println("YES");
				System.out.print(N / A + " 0");
				return;
			}
			else {
				System.out.println("YES");
				System.out.print("0 " + N / B);
				return;
			}
		} else {
			int count = 0;
			while(count * A < N) {
				if( (N - (count * A) ) / (float)B  % 1 == 0) {
					System.out.println("YES");
					System.out.print(count + " "  + (N - (count * A) ) / B);
					return;
				}
				count++;
			}
			System.out.println("NO");
		}
	}

	public static void main(String[] args) {
		// ------------------------------------------- SEPARATOR -------------------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int A = Reader.nextInt();
		int B = Reader.nextInt();
		Reader.close();
		// ------------------------------------------- SEPARATOR -------------------------------------------
		SolverA(N, A, B);
		// ------------------------------------------- SEPARATOR -------------------------------------------
	}

}
