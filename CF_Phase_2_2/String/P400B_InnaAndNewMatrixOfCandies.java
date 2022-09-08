/*
 * Problem Link:					https://codeforces.com/problemset/problem/400/B
 * Problem Status:				Accepted.
 */

package String;

import java.util.*;

public class P400B_InnaAndNewMatrixOfCandies {

	public static void main(String[] args) {
		int N, M;
		char[][] Grid;
		// --------------------------- Separator ---------------------------
		Scanner Reader = new Scanner(System.in);
		N = Reader.nextInt();
		M = Reader.nextInt();
		Grid = new char[N][M];
		for(int i = 0 ; i < N ; i++)
			Grid[i] = Reader.next().toCharArray();
		Reader.close();
		// --------------------------- Separator ---------------------------
		System.out.println(TheAmazingFunction(Grid));
		// --------------------------- Separator ---------------------------
	}
	
	public static int TheAmazingFunction(char[][] A) {
		HashSet<Integer> H = new HashSet<Integer>();
		// --------------------------- Separator ---------------------------
		for(int i = 0 ; i < A.length ; i++) {
			int found_G_at = -1;
			// --------------------------- Separator ---------------------------
			for(int j = 0 ; j < A[0].length ; j++) {
				// --------------------------- Separator ---------------------------
				if(A[i][j] == 'G')
					found_G_at = j;
				else if(A[i][j] == 'S') {
					if(found_G_at == -1) 
						return -1;
					else 
						H.add(j - found_G_at);
				}
				// --------------------------- Separator ---------------------------
			}
			// --------------------------- Separator ---------------------------
		}
		// --------------------------- Separator ---------------------------
		return H.size();
	}

}
