/*
 * Problem Link: 			https://codeforces.com/problemset/problem/766/B
 * Problem Status:			Accepted Using Method (SolverB)
 */

package CodeForces.P766B_MahmoudAndATriangle;

import java.util.*;

public class P766B_MahmoudAndATriangle {
	
	public static String SolverB(ArrayList<Integer> A) {
		String Answer = "NO";
		Collections.sort(A);
		int X;
		int Y;
		int Z ;
		// -------------------------------- SEPARATOR --------------------------------
		for(int i = 0 ; i < A.size()-2 ; i++) {
			X = A.get(i);
			Y = A.get(i+1);
			Z = A.get(i+2);
			if(X + Y > Z)
				if(X + Z > Y)
					if(Y + Z > X)
						return "YES";			
		}
		// -------------------------------- SEPARATOR --------------------------------
		return Answer;
	}
	
	public static String SolverA(ArrayList<Integer> A) {
		String Answer = "NO";
		Collections.sort(A);
		int X;
		int Y;
		int Z ;
		// -------------------------------- SEPARATOR --------------------------------
		for(int i = 0 ; i < A.size() ; i++) {
			X = A.get(i);
			for(int j = 0 ; j < A.size() ; j++) {
				if(j == i)
					continue;
				else {
					Y = A.get(j);
					for(int t = 0 ; t < A.size() ; t++) {
						if(t == i || t ==j)
							continue;
						else {
							Z = A.get(t);
							if(X + Y > Z)
								if(X + Z > Y)
									if(Y + Z > X) {
//										System.out.println(X + " " + Y + " " + Z);
										return "YES";
									}
						}
					}
				}
			}
		}
		// -------------------------------- SEPARATOR --------------------------------
		return Answer;
	}

	public static void main(String[] args) {
		Scanner Reader = new Scanner(System.in);
		// -------------------------------- SEPARATOR --------------------------------
		int N = Reader.nextInt();
		ArrayList<Integer> A = new ArrayList<Integer>(N);
		for(int i = 0 ; i < N ; i++)
			A.add(Reader.nextInt());
		// -------------------------------- SEPARATOR --------------------------------
		Reader.close();
		//-------------------------------- SEPARATOR --------------------------------
//		System.out.println(SolverA(A));
		System.out.println(SolverB(A));
	}

}
