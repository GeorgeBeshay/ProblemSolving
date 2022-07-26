/*
 * Problem Link:				https://codeforces.com/problemset/problem/447/B
 * Problem Status:			Accepted.
 */

package CodeForces.P447B_DZYLovesStrings;

import java.util.*;

public class P447B_DZYLovesStrings {
	
	public static int SolverA(int[] Values, int N, String Input, int Max) {
		int ans = 0;
		// ---------------------------------------- SEPARATOR ----------------------------------------
		for(int i = 0 ; i < Input.length() ; i++) {
			ans += (i+1) *  Values[(int)(Input.charAt(i))-97];
		}
		for(int i = 0 ; i < N ; i++) {
			ans += (Input.length() + i + 1) * Max;
		}
		// ---------------------------------------- SEPARATOR ----------------------------------------
		return ans;
	}

	public static void main(String[] args) {
		// ---------------------------------------- SEPARATOR ----------------------------------------
		Scanner Reader = new Scanner(System.in);
		String Input = Reader.next();
		int N = Reader.nextInt();
		int[] Values = new int[26];
		int Max = -1;
		for(int i = 0 ; i < 26 ; i++) {
			Values[i] = Reader.nextInt();
			if(Values[i] > Max)
				Max = Values[i];
		}
		System.out.println(SolverA(Values, N, Input, Max));
		Reader.close();
		// ---------------------------------------- SEPARATOR ----------------------------------------
	}

}
