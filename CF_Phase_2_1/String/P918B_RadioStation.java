/*
 * Problem Link:			https://codeforces.com/problemset/problem/918/B
 * Problem Status:		Accepted.
 */

package String;

import java.util.*;

public class P918B_RadioStation {

	public static void main(String[] args) {
		// ---------------------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// ---------------------------------------------------------------------------------------
		int N = Reader.nextInt();
		int M = Reader.nextInt();
		String Name;
		String IP;
		String temp;
		Hashtable<String, String> myTable = new Hashtable<String, String>(N);
		for(int i = 0 ; i < N ; i++) {
			Name = Reader.next();
			IP = Reader.next();
			myTable.put(IP, Name);
		}
		// ---------------------------------------------------------------------------------------
		for(int j = 0 ; j < M ; j++) {
			temp = Reader.next();
			IP = Reader.next();
			System.out.println (temp + " " + IP + " #" + ( myTable.get(IP.substring( 0, IP.length()-1 ) ) ) );
		}
		// ---------------------------------------------------------------------------------------
		Reader.close();
		// ---------------------------------------------------------------------------------------
	}

}
