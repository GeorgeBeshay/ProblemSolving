/*
 * Problem Link: 		https://codeforces.com/contest/1722/problem/C
 * Problem Status:		Accepted.
 */

package R817_D4;

import java.util.*;

public class PC_WordGame {

	public static void main(String[] args) {
		// -------------------------------- SEPARATOR --------------------------------
		Scanner Reader = new Scanner(System.in);
		int T = Reader.nextInt();
		while(T > 0) {
			int N = Reader.nextInt();
			String[][] A = new String[3][N];
			for(int i = 0 ; i < 3 ; i++) 
				for(int j = 0 ; j < N ; j++)
					A[i][j] = Reader.next();
			TheAmazingFunction(A);
			T--;
		}
		Reader.close();
		// -------------------------------- SEPARATOR --------------------------------
	}
	
	public static void TheAmazingFunction(String[][] A) {
		Hashtable<String, ArrayList<Integer>> Table = new Hashtable<String, ArrayList<Integer>>();
		for(int i = 0 ; i < 3 ; i++) {
			for(int j = 0 ; j < A[0].length ; j++) {
				if(Table.get(A[i][j]) == null) {
					ArrayList<Integer> tempList = new ArrayList<Integer>();
					tempList.add(i);
					Table.put(A[i][j], tempList);
				} else {
					ArrayList<Integer> tempList = Table.get(A[i][j]);
					tempList.add(i);
					Table.put(A[i][j], tempList);
				}
			}
		}
		// -------------------------------- SEPARATOR --------------------------------
		int[] Scores = {0, 0, 0};
		Enumeration<String> E = Table.keys();
		while(E.hasMoreElements()) {
			String temp = E.nextElement();
			if(Table.get(temp).size() == 1) {
				Scores[Table.get(temp).get(0)] += 3;
			} else if (Table.get(temp).size() == 2) {
				Scores[Table.get(temp).get(0)] += 1;
				Scores[Table.get(temp).get(1)] += 1;
			}
			Table.remove(temp);
		}
		// -------------------------------- SEPARATOR --------------------------------
		System.out.println(Scores[0] + " " + Scores[1] + " "+ Scores[2]);
		// -------------------------------- SEPARATOR --------------------------------
	}

}
