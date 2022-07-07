/*
 * Problem Link:		https://codeforces.com/problemset/problem/977/B
 * Problem Status:	Accepted.
 */
package CodeForces.P977B_TwoGram;

import java.util.*;

public class P977B_TwoGram {
	
	public static String Solver(char[] A, int N) {
		// ----------------------------------------------------------------------------------
		String temp = "";
		String Answer = "";
		// ----------------------------------------------------------------------------------
		Hashtable<String, Integer> Data = new Hashtable<String, Integer>();
		int CurrentMax = 0;
		for(int i = 1 ; i < N ; i++) {
			temp = "" + A[i-1] +  A[i];
			if(Data.get(temp) != null)
				Data.put(temp, Data.get(temp)+1);
			else
				Data.put(temp,1);
			if(CurrentMax < Data.get(temp)) {
				CurrentMax = Data.get(temp);
				Answer = temp;
			}
		}
		// ----------------------------------------------------------------------------------
		return Answer;
		// ----------------------------------------------------------------------------------
	}

	public static void main(String[] args) {
		// ----------------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// ----------------------------------------------------------------------------------
		int N = Reader.nextInt();
		String Input = Reader.next(); 
		// ----------------------------------------------------------------------------------
		Reader.close();
		// ----------------------------------------------------------------------------------
		System.out.println( Solver( Input.toCharArray(), N ) );
		// ----------------------------------------------------------------------------------
	}

}
