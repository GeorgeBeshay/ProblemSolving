/*
 * Problem Link:				https://codeforces.com/contest/1702/problem/C
 * Problem Status:		Accepted.
 */

package Competitions.CodeForcesContests.R805_D3;

import java.util.*;
import java.awt.*;

public class PC_TrainAndQueries {
	
	public static void SolverB(Scanner Reader) {
		// ---------------------------------------------------------------------------------------
		String NewLineString = Reader.nextLine();
		int N = Reader.nextInt();
		int Q = Reader.nextInt();
		long[] A = new long[N];
		Hashtable<Long , Point> Table = new Hashtable<Long , Point>(N);
		// ---------------------------------------------------------------------------------------
		for(int i = 0 ; i < N ; i++) {
			A[i] = Reader.nextLong();
			if(Table.get(A[i]) == null)
				Table.put(A[i], new Point(i, i));
			else 
				Table.get(A[i]).setLocation(Table.get(A[i]).x, i);
		}
		// ---------------------------------------------------------------------------------------
		while(Q > 0) {
			long i = Reader.nextLong();
			long j = Reader.nextLong();
			if(Table.get(i) == null || Table.get(j) == null)
				System.out.println("NO");
			else if( Table.get(i).x < Table.get(j).y )
				System.out.println("YES");
			else
				System.out.println("NO");
			Q--;
		}
		// ---------------------------------------------------------------------------------------
	}
	
	public static void main(String[] args) {	
		// ---------------------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		int T = Reader.nextInt();
		// ---------------------------------------------------------------------------------------
		while(T > 0) {
			SolverB(Reader);
			T--;
		}
		// ---------------------------------------------------------------------------------------
		Reader.close();
		// ---------------------------------------------------------------------------------------
	}

}
