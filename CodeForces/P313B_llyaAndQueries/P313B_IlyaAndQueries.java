/*
 * Problem Link:					https://codeforces.com/problemset/problem/313/B
 * Problem Status:				Accepted.
 */

package CodeForces.P313B_llyaAndQueries;

import java.util.*;

public class P313B_IlyaAndQueries {
	
	public static int[] MethodA(String Input) {;
		int[] ans = new int[Input.length()];
		// --------------------------------------- SEPARATOR ---------------------------------------
		for(int i = Input.length()-2 ; i >= 0 ; i--) {
			if( Input.charAt(i) == Input.charAt(i+1) ) {
				ans[i] = ans[i+1] + 1;
			}
			else {
				ans[i] = ans[i+1];
			}
		}
		// --------------------------------------- SEPARATOR ---------------------------------------
		return ans;
	}
	
	public static void main(String[] args) {
		Scanner Reader = new Scanner(System.in);
		String Input = Reader.next();
		int[] Answers = MethodA(Input);
		int Q = Reader.nextInt();
		StringBuilder Result = new StringBuilder("");
		// --------------------------------------- SEPARATOR ---------------------------------------
		while(Q > 0) {
			int L = Reader.nextInt();
			int R = Reader.nextInt();
			Result.append(Answers[L-1] - Answers[R-1] + "\n");
			Q--;
		}
		System.out.print(Result);
		// --------------------------------------- SEPARATOR ---------------------------------------
		Reader.close();
	}

}
