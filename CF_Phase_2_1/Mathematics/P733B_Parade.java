/*
 * Problem Link:				https://codeforces.com/problemset/problem/733/B
 * Problem Status:			Accepted.
 */

package Mathematics;

import java.util.*;

public class P733B_Parade {
	
	public static int SolverA(int[] L, int[] R) {
		// ------------------------------------ SEPARATOR ------------------------------------
		int ansL = 0;
		int ansR = 0;
		int L_Total = 0;
		int R_Total = 0;
		int MaxDiffL = 0;
		int MaxDiffR = 0;
		int CurrentBeauty = 0;
		int TempBeautyL = 0;
		int TempBeautyR = 0;
		// ------------------------------------ SEPARATOR ------------------------------------
		for(int i = 0 ; i < L.length ; i++) {
			L_Total += L[i];
			R_Total += R[i];
			if(L[i] > R[i]) {
				if(Math.abs(L[i] - R[i]) > MaxDiffL) {
					MaxDiffL = Math.abs(L[i] - R[i]);
					ansL = i+1;
				}
			} else if (R[i] > L[i]) {
				if(Math.abs(L[i] - R[i]) > MaxDiffR) {
					MaxDiffR = Math.abs(L[i] - R[i]);
					ansR = i+1;
				}
			}
		}
		// ------------------------------------ SEPARATOR ------------------------------------
		CurrentBeauty = Math.abs( L_Total - R_Total );
		if(ansL != 0)
			TempBeautyR = Math.abs(  (L_Total - L[ansL-1] + R[ansL-1]) - (R_Total - R[ansL-1] + L[ansL-1]) );
		if(ansR != 0)
			TempBeautyL = Math.abs(  (L_Total - L[ansR-1] + R[ansR-1]) - (R_Total - R[ansR-1] + L[ansR-1]) );
		// ------------------------------------ SEPARATOR ------------------------------------
		if(TempBeautyR > CurrentBeauty && TempBeautyR >= TempBeautyL)
			return ansL;
		else if (TempBeautyL > CurrentBeauty && TempBeautyL >= TempBeautyR)
			return ansR;
		else
			return 0;
		// ------------------------------------ SEPARATOR ------------------------------------
	}

	public static void main(String[] args) {
		// ------------------------------------ SEPARATOR ------------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int[] L = new int[N];
		int[] R = new int[N];
		for(int i = 0 ; i < N ; i++) {
			L[i] = Reader.nextInt();
			R[i] = Reader.nextInt();
		}
		Reader.close();
		// ------------------------------------ SEPARATOR ------------------------------------
		System.out.println(SolverA(L, R));
		// ------------------------------------ SEPARATOR ------------------------------------
	}

}
