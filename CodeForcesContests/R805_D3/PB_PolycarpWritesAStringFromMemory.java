/*
 * Problem Link: https://codeforces.com/contest/1702/problem/B
 * Problem Status:		Accepted.
 */
package Competitions.CodeForcesContests.R805_D3;

import java.util.*;

public class PB_PolycarpWritesAStringFromMemory {

	public static int Solver(String S) {
		int ans = 0;
		String[] Arr = new String[ S.length() ];
		if(S.length() <= 3)
			return 1;
		for(int i = 0 ; i < S.length() ; i++) {
			if(Arr[ans] != null) {
				if( Arr[ans].contains( S.charAt(i) + "" ) )
					continue;
				else
					if(Arr[ans].length() != 3)
						Arr[ans] += "" + S.charAt(i);
					else {
						ans++;
						Arr[ans] = "" + S.charAt(i);
					}
			}
			else
				Arr[ans] = "" + S.charAt(i);
		}
		return ++ans;
	}
	
	public static void main(String[] args) {
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		for(int i = 0 ; i < N ; i++) {
			String temp = Reader.next();
			System.out.println(Solver(temp));
		}
		Reader.close();
	}

}
