/*
 * Problem Link:				https://codeforces.com/problemset/problem/535/B
 * Problem Status:			Accepted.
 */

package Mathematics;

import java.util.*;

public class P535B_TavasAndSaDDas {
	
	public static int SolverA(String A) {
		// ---------------------------- SEPARATOR ----------------------------
		int MaxRange = (int)(Math.pow(2, A.length()+1));
		MaxRange-=2;
		int MinRange = MaxRange + 1 - (int)(Math.pow(2,  A.length()));
		int Answer = MinRange;
		char[] TempA = A.toCharArray();
		for(int i = 0 ; i < A.length() ; i++) {
			if(TempA[i] == '7') {
				Answer += Math.pow(2,  A.length()-1-i);
			}
		}
		// ---------------------------- SEPARATOR ----------------------------
		return Answer;
	}

	public static void main(String[] args) {
		// ---------------------------- SEPARATOR ----------------------------
		Scanner Reader = new Scanner(System.in);
		String A = Reader.next();
		Reader.close();
		// ---------------------------- SEPARATOR ----------------------------
		System.out.println(SolverA(A));
		// ---------------------------- SEPARATOR ----------------------------
	}

}
