/*
 * Problem Link:		https://codeforces.com/problemset/problem/747/B
 * Problem Status:	Accepted.
 */
package CodeForces.P747B_MammothsGenomeDecoding;

import java.util.*;

public class P747B_MammothsGenomeDecoding {
	
	public static String Solver(char[] A, int N) {
		String Answer = "";
		int A_Counter = 0;
		int C_Counter = 0;
		int G_Counter = 0;
		int T_Counter = 0;
		int Q_Counter = 0;
		int Max;
		for(int i = 0 ; i < N ; i++) {
			switch (A[i]) {
			case 'A':
				A_Counter++;
				break;
			case 'C':
				C_Counter++;
				break;
			case 'G':
				G_Counter++;
				break;
			case 'T':
				T_Counter++;
				break;
			case '?':
				Q_Counter++;
				break;
			default:
				break;
			}
		}
		Max = getMaxOfFour(A_Counter, C_Counter, G_Counter, T_Counter);
		if(
				( Q_Counter - ( Math.abs(A_Counter - Max) + Math.abs(C_Counter - Max) 
				+ Math.abs(G_Counter - Max) + Math.abs(T_Counter - Max) ) ) % 4 
				== 0
			) {
			for(int i = 0 ; i < N ; i++) {
				if (A[i] != '?')
					Answer += A[i];
				else {
					if( Math.abs(A_Counter - Max) > 0) {
						Answer += 'A';
						A_Counter++;
					} else if (Math.abs(C_Counter - Max) > 0) {
						Answer += 'C';
						C_Counter++;
					} else if (Math.abs(G_Counter - Max) > 0) {
						Answer += 'G';
						G_Counter++;
					} else {
						Answer += 'T';
						T_Counter++;
					}
					Max = getMaxOfFour(A_Counter, C_Counter, G_Counter, T_Counter);
				}
			}
		} else
			Answer = "===";
		if(A_Counter != C_Counter || A_Counter != G_Counter || A_Counter != T_Counter)
			Answer = "===";
		return Answer;
	}
	
	public static int getMaxOfFour(int X, int Y, int Z, int W) {
		if(X >= Y) {
			if(X >= Z)
				if(X >= W)
					return X;
				else
					return W;
			else
				if(Z >= W)
					return Z;
				else
					return W;
		} else {
			if(Y >= Z)
				if(Y >= W)
					return Y;
				else
					return W;
			else
				if(Z >= W)
					return Z;
				else
					return W;
		}
	}

	public static void main(String[] args) {
		// ---------------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// ---------------------------------------------------------------------------------
		int N = Reader.nextInt();
		String Input = Reader.next();
		// ---------------------------------------------------------------------------------
		Reader.close();
		// ---------------------------------------------------------------------------------
		System.out.println( Solver(Input.toCharArray(), N) ) ;
		// ---------------------------------------------------------------------------------
	}

}
