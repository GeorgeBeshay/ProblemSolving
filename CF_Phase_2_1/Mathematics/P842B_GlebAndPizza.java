/*
 * Problem Link:			https://codeforces.com/problemset/problem/842/B
 * Problem Status:		Accepted.
 */

package Mathematics;

import java.util.*;

public class P842B_GlebAndPizza {
	
	public static void SolverA(Scanner Reader) {
		int Answer = 0;
		int R = Reader.nextInt();
		int D = Reader.nextInt();
		int N = Reader.nextInt();
		// ----------------------------- SEPARATOR -----------------------------
		for(int i = 0 ; i < N ; i++) {
			int X = Reader.nextInt();
			int Y = Reader.nextInt();
			int R_ = Reader.nextInt();
			// ----------------------------- SEPARATOR -----------------------------
			double Temp = Math.sqrt(Math.pow((double)X, 2) + Math.pow((double)Y, 2));
			if(Temp > R || Temp < R - D) {
				continue;
			} else {
				if( Temp >= R - D + R_ && Temp <= R - R_ )
					Answer++;
			}
			// ----------------------------- SEPARATOR -----------------------------
		}
		// ----------------------------- SEPARATOR -----------------------------
		System.out.println(Answer);
	}

	public static void main(String[] args) {
		// ----------------------------- SEPARATOR ----------------------------- 
		Scanner Reader = new Scanner(System.in);
		// ----------------------------- SEPARATOR -----------------------------
		SolverA(Reader);
		// ----------------------------- SEPARATOR -----------------------------
		Reader.close();
		// ----------------------------- SEPARATOR -----------------------------
	}

}
