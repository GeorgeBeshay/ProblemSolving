/*
 * Problem Link:			https://codeforces.com/problemset/problem/712/B
 * Problem Status:		Accepted.
 */

package CodeForces.P712B_MemoryAndTrident;

import java.util.*;

public class P712B_MemoryAndTrident {

	public static int SolverA(String Input) {
		int ans = 0;
		Hashtable <Character, Integer> Table = new Hashtable<Character, Integer>(4);
		Table.put('L', 0);
		Table.put('R', 0);
		Table.put('U', 0);
		Table.put('D', 0);
		for(int i = 0; i < Input.length() ; i++) {
			Table.replace(Input.charAt(i), Table.get(Input.charAt(i)) + 1);
		}
		int X = Table.get('L') + Table.get('R');
		int Y = Table.get('U') + Table.get('D');
		int temp1 = Math.abs(Table.get('L') - Table.get('R'));
		int temp2 = Math.abs(Table.get('U') - Table.get('D'));
		// --------------------------------------------------------------------
		if( temp1 % 2 != 0 ) {
			ans += (int)Math.floor(temp1 / 2);
			X = 1;
		}
		else {
			ans += temp1 / 2;
			X = 0;
		}
		// --------------------------------------------------------------------
		if( temp2 % 2 != 0 ) {
			ans += (int)Math.floor(temp2 / 2);
			Y = 1;
		}
		else {
			ans += temp2 / 2;
			Y = 0;
		}
		// --------------------------------------------------------------------
		if(X == 1 && Y == 1)
			ans++;
		// --------------------------------------------------------------------
		if( (X+Y) % 2 == 0)
			return ans;
		else
			return -1;
		// --------------------------------------------------------------------
	}
	
	public static void main(String[] args) {
		// --------------------------------- SEPARATOR ---------------------------------
		Scanner Reader = new Scanner(System.in);
		String Input = Reader.next();
		System.out.println(SolverA(Input));
		Reader.close();
		// --------------------------------- SEPARATOR ---------------------------------
	}

}
