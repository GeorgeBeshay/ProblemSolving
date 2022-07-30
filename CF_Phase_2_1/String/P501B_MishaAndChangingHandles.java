/*
 * Problem Link:				https://codeforces.com/problemset/problem/501/B
 * Problem Status:			Accepted.
 */

package String;

import java.util.*;

public class P501B_MishaAndChangingHandles {
	
	public static void SolverA(Scanner Reader, int N) {
		// -------------------------------------- SEPARATOR --------------------------------------
		Hashtable<String, String> Table = new Hashtable<String, String>();
		// 							Note:		Map From New To Old
		// -------------------------------------- SEPARATOR --------------------------------------
		while(N > 0) {
			String Old = Reader.next();
			String New = Reader.next();
			if(!Table.containsKey(Old))
				Table.put(New, Old);
			else {
				String FirstName = Table.get(Old);
				Table.remove(Old);
				Table.put(New, FirstName);
			}
			N--;
		}
		// -------------------------------------- SEPARATOR --------------------------------------
		 Enumeration<String> Keys = Table.keys();
		// -------------------------------------- SEPARATOR --------------------------------------
		System.out.println(Table.size());
		while(Keys.hasMoreElements()) {
			String TempKey = Keys.nextElement();
			System.out.println(Table.get(TempKey) + " " + TempKey);
		}
		// -------------------------------------- SEPARATOR --------------------------------------
	}

	public static void main(String[] args) {
		// -------------------------------------- SEPARATOR --------------------------------------
		Scanner Reader = new Scanner(System.in);
		// -------------------------------------- SEPARATOR --------------------------------------
		int N = Reader.nextInt();
		SolverA(Reader, N);
		// -------------------------------------- SEPARATOR --------------------------------------
		Reader.close();
		// -------------------------------------- SEPARATOR --------------------------------------
	}

}
