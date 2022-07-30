/*
 * Problem Link:			https://codeforces.com/problemset/problem/765/B
 * Problem Status:		Accepted.
 */

package String;

import java.util.*;

public class P765B_CodeObfuscation {
	
	public static String SolverA(String Input) {
		// --------------------------------------- SEPARATOR ---------------------------------------
		boolean Flag = false;
		int[] Arr = new int[26];
		int LastVisited = 96;
		// --------------------------------------- SEPARATOR ---------------------------------------
		for(int i = 0 ; i < Input.length() ; i++) {
			// --------------------------------------- SEPARATOR ---------------------------------------
			char tempChar = Input.charAt(i);
			// --------------------------------------- SEPARATOR ---------------------------------------
			if((int)tempChar <= LastVisited) {
				if(Arr[(int)tempChar - 97] == 1)
					continue;
				else {
					Flag = true;
					break;
				}
			}
			// --------------------------------------- SEPARATOR ---------------------------------------
			else {
				if((int)tempChar - LastVisited == 1) {
					LastVisited = (int)tempChar;
					Arr[(int)tempChar - 97] = 1;
				}
				else {
					Flag = true;
					break;
				}
			}
		}
		// --------------------------------------- SEPARATOR ---------------------------------------
		if(!Flag)
			return "YES";
		else
			return "NO";
		// --------------------------------------- SEPARATOR ---------------------------------------
	}

	public static void main(String[] args) {
		// --------------------------------------- SEPARATOR --------------------------------------- 
		Scanner Reader = new Scanner(System.in);
		// --------------------------------------- SEPARATOR ---------------------------------------
		String Input = Reader.next();
		// --------------------------------------- SEPARATOR ---------------------------------------
		Reader.close();
		// --------------------------------------- SEPARATOR ---------------------------------------
		System.out.println(SolverA(Input));
		// --------------------------------------- SEPARATOR ---------------------------------------
	}

}
