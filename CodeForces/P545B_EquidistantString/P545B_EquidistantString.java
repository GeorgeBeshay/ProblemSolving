/*
 * Problem Link:			https://codeforces.com/problemset/problem/545/B
 * Problem Status:		Accepted.
 */

package CodeForces.P545B_EquidistantString;

import java.util.*;

public class P545B_EquidistantString {
	
	public static String SolverA(String A, String B) {
		StringBuilder C = new StringBuilder("");
		int Counter = 0;
		for(int i = 0 ; i < A.length() ; i++) {
			if(A.charAt(i) == B.charAt(i))
				C.append(A.charAt(i));
//				C += A.charAt(i);
			else {
				Counter++;
				if(Counter % 2 == 1) 
					C.append(A.charAt(i));
				else 
					C.append(B.charAt(i));
			}
		}
		if(Counter % 2 == 0)
			return C.toString();
		return "impossible";
	}

	public static void main(String[] args) {
		Scanner Reader = new Scanner(System.in);
		String S = Reader.next();
		String T = Reader.next();
		System.out.println(SolverA(S, T));
		Reader.close();
	}

}
