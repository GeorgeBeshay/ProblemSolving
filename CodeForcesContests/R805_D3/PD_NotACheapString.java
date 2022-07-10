/*
 * Problem Link:			https://codeforces.com/contest/1702/problem/D
 * Problem Status:	Accepted.
 */
package Competitions.CodeForcesContests.R805_D3;

import java.util.*;

public class PD_NotACheapString {
	
	public static void SolverB(Scanner Reader) {
		String W = Reader.next();
		int P = Reader.nextInt();
		int GivenValue = 0;
		int[] Arr = new int[26];
		for(int i = 0 ; i < W.length() ; i++) {
			int value = (int)W.charAt(i) - 97;
			Arr[value]++;
			GivenValue += value +1;
		}
		if(GivenValue <= P) {
			System.out.println(W);
			return;
		}
		String ans = "";
		int AnswerValue = 0;
		for(int i = 0 ; i < 26 ; i++) {
			if(i+1 <= P) {
				if(Arr[i] > 0) {
					if(Arr[i] >= Math.floor( P/(i+1) )) {
						ans += ( ((char)(i+97))+"").repeat((int)Math.floor(P / (i+1) ));
						AnswerValue += (i+1)*Math.floor(P / (i+1));
						Arr[i] -= Math.floor(P / (i+1) );
						P -= (i+1) * Math.floor(P / (i+1));
					} else {
						ans +=( ((char)(i+97))+"").repeat( Arr[i] );
						AnswerValue += (i+1) * Arr[i];
						P -= (i+1) * Arr[i];
						Arr[i] = 0;
					}
				} else
					continue;
			} else 
				break;
		}
		int[] TheAmazingArray = new int[26];
		for(int i = 0 ; i < ans.length() ; i++) {
			TheAmazingArray[(int)ans.charAt(i) - 97]++;
		}
		String FinalAnswer = "";
		for(int i = 0 ; i < W.length() ; i++) {
			if( TheAmazingArray[ (int)W.charAt(i)-97]  > 0   ) {
				FinalAnswer += "" + W.charAt(i);
				TheAmazingArray[ (int)W.charAt(i)-97] --;
			}
		}
		System.out.println(FinalAnswer);
		return;
	}
	
	public static void main(String[] args) {
		// ------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// ------------------------------------------------------------
		int T = Reader.nextInt();
		while(T > 0) {
//			SolverA(Reader);
			SolverB(Reader);
			T--;
		}
		// ------------------------------------------------------------
		Reader.close();
		// ------------------------------------------------------------
	}
	
}
