/*
 * Problem Link:		https://codeforces.com/problemset/problem/864/B
 * Problem Status:	Accepted.
 */

package String;

import java.util.*;

public class P864B_PolycarpAndLetters {

	public static int SolverA(int N, String Input) {
		int CurrentMax = 0;
		Hashtable<Character, Integer> Table = new Hashtable<Character, Integer>();
		// ----------------------------- SEPARATOR -----------------------------
		for(int i = 0 ; i < N ; i++) {
			// ----------------------------- SEPARATOR -----------------------------
			if( Character.isUpperCase(Input.charAt(i)) ) {
				if(Table.size() > CurrentMax)
					CurrentMax = Table.size();
				Table.clear();
				continue;
			}
			// ----------------------------- SEPARATOR -----------------------------
			if(Table.get(Input.charAt(i)) == null)
				Table.put(Input.charAt(i), 1);
			// ----------------------------- SEPARATOR -----------------------------
		}
		// ----------------------------- SEPARATOR -----------------------------
		if(Table.size() > CurrentMax)
			CurrentMax = Table.size();
		// ----------------------------- SEPARATOR -----------------------------
		return CurrentMax;
		// ----------------------------- SEPARATOR -----------------------------
	}
	
	public static void main(String[] args) {
		// ----------------------------- SEPARATOR -----------------------------
		Scanner Reader = new Scanner(System.in);
		// ----------------------------- SEPARATOR -----------------------------
		int N = Reader.nextInt();
		String Input = Reader.next();
		// ----------------------------- SEPARATOR -----------------------------
		Reader.close();
		// ----------------------------- SEPARATOR -----------------------------
		System.out.println(SolverA(N, Input));
		// ----------------------------- SEPARATOR -----------------------------
	}

}
