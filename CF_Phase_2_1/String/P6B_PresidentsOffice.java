/*
 * Problem Link:				https://codeforces.com/problemset/problem/6/B
 * Problem Status:			Accepted.
 */

package String;

import java.util.*;

public class P6B_PresidentsOffice {

	public static int SolverA(char[][] Office, char C) {
		ArrayList<Character> Adjacent = new ArrayList<Character>();
		for(int i = 0 ; i < Office.length ; i++)
			for(int j = 0 ; j < Office[0].length ; j++) {
				char temp = Office[i][j];
				if(temp == C)
					CheckAndUpdate(Adjacent, Office, i, j);
				else
					continue;
			}
		return Adjacent.size();
	}
	
	public static void CheckAndUpdate(ArrayList<Character> Adjacent, char[][] Office, int i, int j) {
		// Adjacent cells are => [ (i-1, j), (i+1, j), (i, j-1), (i, j+1) ]
		char C = Office[i][j];
		// ----------------------------------- SEPARATOR -----------------------------------
		try {
			char tempA = Office[i-1][j];
			if(tempA != C && tempA != '.') {
				if(!Adjacent.contains(tempA)) {
					Adjacent.add(tempA);
				}
			}
		} catch (Exception E) {}
		// ----------------------------------- SEPARATOR -----------------------------------
		try {
			char tempB = Office[i+1][j];
			if(tempB != C && tempB != '.') {
				if(!Adjacent.contains(tempB)) {
					Adjacent.add(tempB);
				}
			}
		} catch (Exception E) {}
		// ----------------------------------- SEPARATOR -----------------------------------
		try {
			char tempC = Office[i][j-1];
			if(tempC != C && tempC != '.') {
				if(!Adjacent.contains(tempC)) {
					Adjacent.add(tempC);
				}
			}
		} catch (Exception E) {}
		// ----------------------------------- SEPARATOR -----------------------------------
		try {
			char tempD = Office[i][j+1];
			if(tempD != C && tempD != '.') {
				if(!Adjacent.contains(tempD)) {
					Adjacent.add(tempD);
				}
			}
		} catch (Exception E) {}
		// ----------------------------------- SEPARATOR -----------------------------------
	}
	
	public static void main(String[] args) {
		// ----------------------------------- SEPARATOR -----------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int M = Reader.nextInt();
		char C = Reader.next().charAt(0);
		char[][] Office = new char[N][M];
		for(int i = 0 ; i < N ; i++) 
			Office[i] = Reader.next().toCharArray();	
		Reader.close();
		System.out.println(SolverA(Office, C));
		// ----------------------------------- SEPARATOR -----------------------------------
	}

}
