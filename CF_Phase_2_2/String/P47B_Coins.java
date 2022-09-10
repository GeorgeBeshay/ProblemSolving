/*
 * Problem Link:				https://codeforces.com/problemset/problem/47/B
 * Problem Status:			Accepted.
 */

package String;

import java.util.*;

public class P47B_Coins {

	public static void main(String[] args) {
		// -------------------- Variables --------------------
		char[][] A = new char[3][3];
		// -------------------- Separator --------------------
		Scanner Reader = new Scanner(System.in);
		for(int i = 0 ; i < 3 ; i++) 
			A[i] = Reader.next().toCharArray();
		Reader.close();
		// -------------------- Separator --------------------
		System.out.println(TheAmazingFunction(A));
		// -------------------- Separator --------------------
	}
	
	public static String TheAmazingFunction(char[][] A) {
		String Answer = "";
		Hashtable<Character, Integer> Table = new Hashtable<Character, Integer>();
		// -------------------- Separator --------------------
		for(int i = 0 ; i < 3 ; i++) {
			if(A[i][1] == '>') {
				if(Table.get(A[i][0]) == null)
					Table.put(A[i][0], 1);
				else
					Table.put(A[i][0], Table.get(A[i][0])+1);
			} else {
				if(Table.get(A[i][2]) == null)
					Table.put(A[i][2], 1);
				else
					Table.put(A[i][2], Table.get(A[i][2])+1);
			}
		}
		// -------------------- Separator --------------------
		if(Table.size() == 3)
			return "Impossible";
		// -------------------- Separator --------------------
		else {
			Enumeration<Character> E = Table.keys();
			while(E.hasMoreElements()) {
				char temp = E.nextElement();
				if(Table.get(temp) == 1) 
					Answer = temp + Answer;
				else
					Answer = Answer + temp;
			}
			// -------------------- Separator --------------------
			if(!Answer.contains("A"))
				Answer = "A" + Answer;
			else if (!Answer.contains("B"))
				Answer = "B" + Answer;
			else
				Answer = "C" + Answer;
		}
		return Answer;
	}

}
