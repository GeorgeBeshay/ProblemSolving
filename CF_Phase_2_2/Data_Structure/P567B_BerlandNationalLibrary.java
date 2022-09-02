/*
 * Problem Link:			https://codeforces.com/problemset/problem/567/B
 * Problem Status:		Accepted.
 */

package Data_Structure;

import java.util.*;

public class P567B_BerlandNationalLibrary {

	public static void main(String[] args) {
		// ------------------- SEPARATOR -------------------
		int N;
		int[] IDs;
		char[] OPs;
		Scanner Reader;
		// ------------------- SEPARATOR ------------------- 
		Reader = new Scanner(System.in);
		N = Reader.nextInt();
		IDs = new int[N];
		OPs = new char[N];
		for(int i = 0 ; i < N ; i++) {
			OPs[i] = Reader.next().charAt(0);
			IDs[i] = Reader.nextInt();
		}
		Reader.close();
		// ------------------- SEPARATOR -------------------
		System.out.println(TheAmazingFunction(IDs, OPs));
		// ------------------- SEPARATOR -------------------
	}
	
	public static int TheAmazingFunction(int[] A, char[] B) {
		Hashtable<Integer, Integer> Table = new Hashtable<Integer, Integer>();
		ArrayList<Integer> Sizes = new ArrayList<>(A.length);
		int[] Bonus = new int[A.length];
		// ------------------- SEPARATOR -------------------
		for(int i = 0 ; i < A.length ; i++) {
			if(B[i] == '+') 
				Table.put(A[i], 1);
			else 
				if(Table.get(A[i]) == null) 
					Bonus[i] = 1;
				 else 
					Table.remove(A[i]);
				Sizes.add(Table.size());
		}
		// ------------------- SEPARATOR -------------------
		for(int i = A.length-2 ; i >= 0 ; i--) 
			Bonus[i] += Bonus[i+1];
		for(int i = 0 ; i < A.length ; i++) 
			Sizes.add(Sizes.get(i) + Bonus[i]);
		// ------------------- SEPARATOR -------------------
		Collections.sort(Sizes);
		return Sizes.get(Sizes.size()-1);
	}
	
	public static void showArr(char[] A, int[] B) {
		if (B == null) {
			for(int i = 0 ; i < A.length ; i++) {
				System.out.print(A[i] + " ");
			System.out.println();
			}
		} else {
			for(int i = 0 ; i < B.length ; i++) {
				System.out.print(B[i] + " ");
			System.out.println();
			}
		}
	}
	
}
