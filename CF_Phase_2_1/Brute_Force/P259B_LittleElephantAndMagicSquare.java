/*
 * Problem Link:			https://codeforces.com/problemset/problem/259/B
 * Problem Status:		Accepted.
 */

package Brute_Force;

import java.util.*;

public class P259B_LittleElephantAndMagicSquare {
	
	public static void SolverA(int[][] A) {
		// ----------------------------- SEPARATOR -----------------------------
		int X = 0;
		int Y = 0; 
		int Z = 0;
		int D = 0;
		int Temp;
		// ----------------------------- SEPARATOR -----------------------------
		for(int i = 0 ; i < 3 ; i++) {
			X += A[i][0];
			Y += A[i][1];
			Z += A[i][2];
		}
		// ----------------------------- SEPARATOR -----------------------------
		Temp = GetMin(X, Y, Z);
		X -= Temp;
		Y -= Temp;
		Z -= Temp;
		D -= Temp;
		if(X == 0)
			Temp =  (Math.abs((int)D) + Y + Z) / 2;
		else if(Y == 0)
			Temp = (Math.abs((int)D) + X + Z) / 2;
		else
			Temp = (Math.abs((int)D) + Y + X) / 2;
		X = Temp - X;
		Y = Temp - Y;
		Z = Temp - Z;
		A[0][0] = X;
		A[1][1] = Y;
		A[2][2] = Z;
		// ----------------------------- SEPARATOR -----------------------------
		ShowArray(A);
		// ----------------------------- SEPARATOR -----------------------------
	}
	
	public static int GetMax(int A, int B, int C) {
		if (A >= B)
			if (A >= C)
				return A;
			else
				return C;
		else if (B >= C)
			return B;
		else
			return C;
	}
	
	public static int GetMin(int A, int B, int C) {
		if (A <= B)
			if (A <= C)
				return A;
			else
				return C;
		else if (B <= C)
			return B;
		else
			return C;
	}
	
	public static void ShowArray(int[][] A) {
		for(int i = 0 ; i < A.length ; i++) {
			for(int j = 0 ; j < A.length ; j++)
				System.out.print(A[i][j] + " ");
			System.out.println();
		}
	}

	public static void main(String[] args) {
		// ----------------------------- SEPARATOR -----------------------------
		Scanner Reader = new Scanner(System.in);
		int[][] A = new int[3][3];
		for(int i = 0 ; i < 3 ; i++)
			for(int j = 0 ; j < 3 ; j++)
				A[i][j] = Reader.nextInt();
		Reader.close();
		// ----------------------------- SEPARATOR -----------------------------
		SolverA(A);
		// ----------------------------- SEPARATOR -----------------------------
	}

}
