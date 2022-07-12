/*
 * Problem Link:			https://codeforces.com/contest/1703/problem/C
 * Problem Status:		Accepted.
 */

package Competitions.CodeForcesContests.R806_D4;

import java.util.*;

public class PC {
	
	public static void EssentialSolver(int[] A, String[] Operations) {
		int[] Answer = new int[A.length];
		for(int i = 0 ; i < A.length ; i++) {
			int Us = 0;
			int Ds = 0;
			String Operation = Operations[i];
			for(int j = 0 ; j < Operation.length() ; j++) {
				if(Operation.charAt(j) == 'U')
					Us++;
				else
					Ds++;
			}
			Answer[i] = A[i] - (Us % 10);
			Answer[i] = ( (Answer[i]) % (10) );
			Answer[i] = Answer[i] + (Ds % 10);
			Answer[i] = Answer[i] % 10;
			if(Answer[i] < 0) 
				Answer[i] = 10 - (Math.abs(Answer[i]) % 10);			
		}
		ShowArray(Answer);
	}

	public static void ShowArray(int[] Arr) {
		for(int i = 0 ; i < Arr.length ; i++)
			System.out.print(Arr[i] + " ");
		System.out.println();
	}
	
	public static void main(String[] args) {
		// ------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// ------------------------------------------------------------------------
		int T = Reader.nextInt();
		while (T > 0) {
			int N = Reader.nextInt();
			int[] FinalSequence = new int[N];
			String[] Operations = new String[N];
			for(int i = 0 ; i < N ; i++)
				FinalSequence[i] = Reader.nextInt();
			for(int i = 0 ; i < N ; i++) {
				int Temp = Reader.nextInt();
				Operations[i] = Reader.next();
			}
			EssentialSolver(FinalSequence, Operations);
			T--;
		}
		// ------------------------------------------------------------------------
		Reader.close();
		// ------------------------------------------------------------------------
	}

}
