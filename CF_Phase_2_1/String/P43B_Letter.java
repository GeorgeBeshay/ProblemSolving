/*
 * Problem Link:				https://codeforces.com/problemset/problem/43/B
 * Problem Status:			Accepted.
 */

package String;

import java.util.*;

public class P43B_Letter {

	public static String SolverA(String Heading, String Text) {
		Hashtable<Character, Integer> Available = new Hashtable<Character, Integer>();
		// ------------------------------ SEPARATOR ------------------------------
		for(int i = 0 ; i < Heading.length() ; i++) {
			char C = Heading.charAt(i);
			if( Available.get(C) == null )
				Available.put(C, 1);
			else
				Available.replace(C, Available.get(C)+1);
		}
		// ------------------------------ SEPARATOR ------------------------------
		for(int i = 0 ; i < Text.length() ; i++) {
			char X = Text.charAt(i);
			if(X == ' ')
				continue;
			if(Available.get(X) == null || Available.get(X) == 0)
				return "NO";
			else
				Available.replace(X, Available.get(X)-1);
		}
		// ------------------------------ SEPARATOR ------------------------------
		return "YES";
	}
	
	public static void main(String[] args) {
		// ------------------------------ SEPARATOR ------------------------------
		Scanner Reader = new Scanner(System.in);
		String Heading = Reader.nextLine();
		String Text = Reader.nextLine();
		Reader.close();
		// ------------------------------ SEPARATOR ------------------------------
		System.out.println(SolverA(Heading, Text));
		// ------------------------------ SEPARATOR ------------------------------
	}

}
