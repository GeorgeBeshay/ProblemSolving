/*
 * Problem Link:			https://codeforces.com/contest/1722/problem/A
 * Problem Status:		Accepted.
 */

package R817_D4;

import java.util.*;

public class PA_SpellCheck {

	 static Hashtable<Integer, Integer> Table = new Hashtable<Integer, Integer>(5);
	
	public static void TheAmazingFunction(String Name, int X) {
		if(X != 5) {
			System.out.println("NO");
			return;
		} else {
			for(int i = 0 ; i < Name.length() ; i++) {
				if(Table.get((int)Name.charAt(i)) == null) {
					System.out.println("NO");
					return;
				} else 
					Table.remove((int)Name.charAt(i));
			}
			System.out.println("YES");
			return;
		}
	}

	public static void main(String[] args) {
		// ------------------------------------- SEPARATOR -------------------------------------
		Scanner Reader = new Scanner(System.in);
		// ------------------------------------- SEPARATOR -------------------------------------
		String Name = "Timur";
		// ------------------------------------- SEPARATOR -------------------------------------
		int N = Reader.nextInt();
		while(N > 0) {
			int X = Reader.nextInt();
			String Temp = Reader.next();
			for(int i = 0 ; i < 5 ; i++) {
				Table.put((int)Name.charAt(i), 1);
			}
			TheAmazingFunction(Temp, X);
			N--;
		}
		Reader.close();
		// ------------------------------------- SEPARATOR -------------------------------------
	}

}
