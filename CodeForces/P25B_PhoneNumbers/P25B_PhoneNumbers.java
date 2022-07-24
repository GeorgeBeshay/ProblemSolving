/*
 * Problem Link:				https://codeforces.com/problemset/problem/25/B
 * Problem Status:			Accepted.
 */

package CodeForces.P25B_PhoneNumbers;

import java.util.*;

public class P25B_PhoneNumbers {

	public static void main(String[] args) {
		// -------------------------- SEPARATOR --------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		char[] Number = Reader.next().toCharArray();
		Reader.close();
		// -------------------------- SEPARATOR --------------------------
		StringBuilder Output=  new StringBuilder("");
		int Remaining;
		// -------------------------- SEPARATOR --------------------------
		if(N % 2 != 0)  
			Remaining = 3;
		else
			Remaining = 2;
		// -------------------------- SEPARATOR --------------------------
		for(int i = 0 ; i < Number.length - Remaining ; i++) {
			Output.append(Number[i]);
			if(i % 2 == 1)
				Output.append('-');
		}
		Output.append(String.copyValueOf(Number).substring(Number.length-Remaining));
		// -------------------------- SEPARATOR --------------------------
		System.out.println(Output.toString());
		// -------------------------- SEPARATOR --------------------------
	}

}
