/*
 * Problem Link:			https://codeforces.com/problemset/problem/263/B
 * Problem Status:		Accepted.
 */

package Greedy;

import java.util.*;

public class P263B_Squares {
	
	public static void solvingFunctionA(int[] Arr, int K) {
		Hashtable<Integer, Integer> T = new Hashtable<Integer, Integer>(Arr.length);
		ArrayList<Integer> E = new ArrayList<Integer>(Arr.length);
		int Temp = 1;
		// ------------------------------- SEPARATOR -------------------------------
		for(int i = 0 ; i < Arr.length ; i++)
			E.add(Arr[i]);
		// ------------------------------- SEPARATOR -------------------------------
		Collections.sort(E);
		// ------------------------------- SEPARATOR -------------------------------
		for(int i = Arr.length-1 ; i >= 0 ; i--) {
			T.put(Temp, E.get(i));
			Temp++;
		}
		// ------------------------------- SEPARATOR -------------------------------
		if(T.get(K) == null) {
			System.out.println(-1);
			return;
		} else {
			System.out.println(T.get(K) + " " + 0);
		}
		// ------------------------------- SEPARATOR -------------------------------
	}

	public static void main(String[] args) {
		// ------------------------------- SEPARATOR -------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int K = Reader.nextInt();
		int[] A = new int[N];
		for(int i = 0 ; i < N ; i++)
			A[i] = Reader.nextInt();
		Reader.close();
		// ------------------------------- SEPARATOR -------------------------------
		solvingFunctionA(A, K);
		// ------------------------------- SEPARATOR -------------------------------
	}

}
