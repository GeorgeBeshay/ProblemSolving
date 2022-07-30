/*
 * Problem Link:			https://codeforces.com/problemset/problem/389/B
 * Problem Status:		Accepted.
 */

package String;

import java.util.*;

public class P389B_FoxAndCross {
	
	public static String SolverA(char[][] Map) {
		int HashCounter = 0;
		int[][] Visited = new int[Map.length][Map.length];
		// ------------------------------------ SEPARATOR ------------------------------------
		for(int i = 0 ; i < Map.length ; i++) {
			for(int j = 0 ; j <Map[0].length ; j++) {
				if(Map[i][j] == '#') {
					HashCounter++;
					if(checkCross(Visited, Map, i, j))
						HashCounter -= 5;
				}
			}
		}
		// ------------------------------------ SEPARATOR ------------------------------------
		if(HashCounter == 0)
			return "YES";
		return "NO";
	}
	
	public static boolean checkCross(int[][] Visited, char[][] Map, int i, int j) {
		if(i == 0 || i == Map.length-1 || j == 0 || j == Map.length-1)
			return false;
		if(Map[i-1][j] == '#' && Map[i+1][j] == '#' && Map[i][j-1] == '#' && Map[i][j+1] == '#') {
			if( Visited[i-1][j] == 0 && Visited[i+1][j] == 0 && Visited[i][j-1] == 0 && Visited[i][j+1] == 0 ) {
				Visited[i][j] = 1;
				Visited[i-1][j] = 1;
				Visited[i+1][j] = 1;
				Visited[i][j-1] = 1;
				Visited[i][j+1] = 1;
				return true;
			}
			else
				return false;
		}
		return false;
	}

	public static void main(String[] args) {
		Scanner Reader = new Scanner(System.in);
		// ------------------------------------ SEPARATOR ------------------------------------
		int N = Reader.nextInt();
		char[][] Map = new char[N][N];
		for(int i = 0 ; i < N ; i++) {
			Map[i] = Reader.next().toCharArray();
		}
		// ------------------------------------ SEPARATOR ------------------------------------
		Reader.close();
		System.out.println(SolverA(Map));
	}

}
