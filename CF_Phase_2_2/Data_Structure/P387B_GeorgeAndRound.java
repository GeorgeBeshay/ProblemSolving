/*
 * Problem Link:			https://codeforces.com/problemset/problem/387/B
 * Problem Status:		Accepted.
 */

package Data_Structure;

import java.util.Scanner;

public class P387B_GeorgeAndRound {
	
	public static int solvingFunctionA(int[] Arr1, int[] Arr2) {
		int Answer = 0;
		// --------------------------------- SEPARATOR  ---------------------------------
		for(int i = 0 ; i < Arr1.length ; i++) {
			int X = Arr1[i];
			boolean Flag = false;
			// --------------------------------- SEPARATOR  ---------------------------------
			for(int j = 0 ; j < Arr2.length ; j++) {
				int Y = Arr2[j];
				if(Y >= X) {
					Flag = true;
					Arr2[j] = 0;
					break;
				} else
					continue;
			}
			// --------------------------------- SEPARATOR  ---------------------------------
			if(!Flag)
				Answer++;
		}
		// --------------------------------- SEPARATOR  ---------------------------------
		return Answer;
	}

	public static void main(String[] args) {
		Scanner Reader = new Scanner(System.in);
		// --------------------------------- SEPARATOR  ---------------------------------
		int N = Reader.nextInt();
		int M = Reader.nextInt();
		int[] A = new int[N];
		int[] B = new int[M];
		for(int i = 0 ; i < N ; i++)
			A[i] = Reader.nextInt();
		for(int j = 0 ; j < M ; j++)
			B[j] = Reader.nextInt();
		// --------------------------------- SEPARATOR  ---------------------------------
		System.out.println(solvingFunctionA(A, B));
		// --------------------------------- SEPARATOR  ---------------------------------
		Reader.close();
	}

}
