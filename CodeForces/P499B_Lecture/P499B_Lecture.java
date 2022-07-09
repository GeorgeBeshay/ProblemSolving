/*
 * Problem Link:		https://codeforces.com/problemset/problem/499/B
 * Problem Status:	Accepted.
 */

package CodeForces.P499B_Lecture;

import java.util.*;

public class P499B_Lecture {

	
	
	/*
	 * Main Method
	 * IDEA:
	 * 		1) Scan Both of the corresponding words in the 2 languages.
	 * 		2) Store the shorter in a Hash table.
	 * 		3) Use the Key as the String of the 1st language, because the professor's lecture is in it.
	 */
	public static void main(String[] args) {
		// -------------------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();				// Number Of Words in The Professor's Lecture.
		int M = Reader.nextInt();			// Number Of Words in Each Language.
		Hashtable<String, String> Table = new Hashtable<String, String>(M);
		// -------------------------------------------------------------------------------------
		for(int i = 0 ; i < M ; i++) {
			String temp1 = Reader.next();
			String temp2 = Reader.next();
			if(temp1.length() <= temp2.length())
				Table.put(temp1, temp1);
			else
				Table.put(temp1, temp2);
		}
		// -------------------------------------------------------------------------------------
		for(int j = 0 ; j < N ; j++) {
			String temp = Reader.next();
			System.out.print(Table.get(temp) + " ");
		}
		// -------------------------------------------------------------------------------------
		Reader.close();
		// -------------------------------------------------------------------------------------
	}

}
