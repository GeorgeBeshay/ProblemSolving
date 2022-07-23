/*
 * Problem Link:				https://codeforces.com/problemset/problem/834/B
 * Problem Status:			Accepted.
 */

package CodeForces.P834B_TheFestiveEvening;

import java.util.*;

public class P834B_TheFestiveEvening {
	
	public static String SolverA(char[] Sequence, int G) {
		int[] NumberOfVisitors = new int[26];
		boolean[] Guarded = new boolean[26];
		// ---------------------------------- SEPARATOR ----------------------------------
		for(int i = 0 ; i < Sequence.length ; i++)
			NumberOfVisitors[(int)Sequence[i] - 65]++;
		for(int i = 0 ; i < Sequence.length ; i++)
			if(NumberOfVisitors[(int)Sequence[i] - 65] == 0)
				NumberOfVisitors[(int)Sequence[i] - 65] = -1;
		// ---------------------------------- SEPARATOR ----------------------------------
		for(int i = 0 ; i < Sequence.length ; i++) {
			int Value = (int)Sequence[i] - 65;
			if(!Guarded[Value]) {
				Guarded[Value] = true;
				NumberOfVisitors[Value]--;
				G--;
			} else
				NumberOfVisitors[Value]--;
			if(G == -1)
				return "YES";
			if(NumberOfVisitors[Value] == 0) {
				G++;
				Guarded[Value] = false;
			}
		}
		// ---------------------------------- SEPARATOR ----------------------------------
		return "NO";
	}

	public static void main(String[] args) {
		// ---------------------------------- SEPARATOR ----------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();							// Number Of Guests.
		int G = Reader.nextInt(); 							// Number Of Guards
		char[] Sequence = new char[N];				// Sequence by which the guests entered the gates.
		Sequence = Reader.next().toCharArray();
		Reader.close();
		System.out.println(SolverA(Sequence, G));
		// ---------------------------------- SEPARATOR ----------------------------------
	}

}
