/*
 * Problem Link:			https://codeforces.com/problemset/problem/779/B
 * Problem Status:		Accepted.
 */

package Brute_Force;

import java.util.*;

public class P779B_WeirdRounding {
	
	public static int solvingMethodA(int N, int K) {
		int Answer = 0;
		String Num = Integer.toString(N);
		// ------------------------------------ SEPARATOR ------------------------------------
		if(countZeros(Num) < K) {
			for(int i = Num.length()-1 ; i >= 0 ; i--)
				// ------------------------------------ SEPARATOR ------------------------------------
				if(Num.charAt(i) != '0') {
					Answer++;
					String X = Num.substring(0, i);
					String Y = Num.substring(i+1);
					Num = X.concat(Y);
				}
				// ------------------------------------ SEPARATOR ------------------------------------
				else
					continue;
			// ------------------------------------ SEPARATOR ------------------------------------
			for(int i = 0 ; i < Num.length()-1 ; i++)
				if(Num.charAt(i) == '0')
					Answer++;
			// ------------------------------------ SEPARATOR ------------------------------------
		} 
		// ------------------------------------ SEPARATOR ------------------------------------
		else {
			while(!check(Num, K)) {
				int i = Num.length()-1;
				// ------------------------------------ SEPARATOR ------------------------------------
				while(Num.charAt(i) == '0' && i > 0)
					i--;
				// ------------------------------------ SEPARATOR ------------------------------------
				Answer++;
				String Temp1 = Num.substring(0, i);
				String Temp2 = Num.substring(i+1);
				Num = Temp1.concat(Temp2);
				// ------------------------------------ SEPARATOR ------------------------------------
			}
		}
		// ------------------------------------ SEPARATOR ------------------------------------
		return Answer;
	}
	
	public static boolean check(String S, int N) {
		// ------------------------------------ SEPARATOR ------------------------------------
		if(S.substring(S.length() - N).compareTo("0".repeat(N)) == 0)
			return true;
		else
			return false;
		// ------------------------------------ SEPARATOR ------------------------------------
	}
	
	public static int countZeros(String S) {
		int Answer = 0;
		// ------------------------------------ SEPARATOR ------------------------------------
		for(int i = 0 ; i < S.length() ; i++)
			if(S.charAt(i) == '0')
				Answer++;
		// ------------------------------------ SEPARATOR ------------------------------------
		return Answer;
	}

	public static void main(String[] args) {
		// ------------------------------------ SEPARATOR ------------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int K = Reader.nextInt();
		Reader.close();
		// ------------------------------------ SEPARATOR ------------------------------------
		System.out.println(solvingMethodA(N, K));
		// ------------------------------------ SEPARATOR ------------------------------------
	}

}
