/*
 * Problem Link:				https://codeforces.com/problemset/problem/1015/B
 * Problem Status:			Accepted.
 */

package String;

import java.util.*;

public class P1015B_ObtainingTheString {

	public static void main(String[] args) {
		int N;
		char[] A;
		char[] B;
		// ------------------- Separator -------------------
		Scanner Reader = new Scanner(System.in);
		N = Reader.nextInt();
		A = new char[N];
		B = new char[N];
		A = Reader.next().toCharArray();
		B = Reader.next().toCharArray();
		Reader.close();
		// ------------------- Separator -------------------
		TheAmazingFunction(A, B);
		// ------------------- Separator -------------------
	}
	
	public static void TheAmazingFunction(char[] A, char[] B) {
		int Count = 0;
		ArrayList<Integer> Moves = new ArrayList<Integer>();
		Hashtable<Character, ArrayList<Integer>> T1 = new Hashtable<Character, ArrayList<Integer>>();
		Hashtable<Character, ArrayList<Integer>> T2 = new Hashtable<Character, ArrayList<Integer>>();
		JuniorMethod1(A, B, T1, T2);
		// ------------------- Separator -------------------
		for(int i = 0 ; i < B.length ; i++) {
			if(B[i] == A[i]) {
				T1.get(A[i]).remove(0);
				T2.get(A[i]).remove(0);
				continue;
			} 
			// ------------------- Separator -------------------
			else {
				Count += (2 * Math.abs(T2.get(B[i]).get(0) - T1.get(B[i]).get(0))) - 1;
				int j = i;
				for( ; j < T1.get(B[i]).get(0) ; j++)
					Moves.add(j);
				if( Math.abs( T2.get(B[i]).get(0) - T1.get(B[i]).get(0) ) > 1) {
					j -= 2;
					for( ; j >= i ; j--)
						Moves.add(j);
				}
				// ------------------- Separator -------------------
				T1.get(A[i]).remove(0);
				T1.get(A[i]).add(T1.get(B[i]).get(0));
				Collections.sort(T1.get(A[i]));
				char temp = A[i];
				A[i] = A[T1.get(B[i]).get(0)];
				A[T1.get(B[i]).get(0)] = temp;
				T1.get(B[i]).remove(0);
				T2.get(B[i]).remove(0);
				// ------------------- Separator -------------------
			}
			// ------------------- Separator -------------------
		}
		showAnswer(Count, Moves);
//		printCharArr(A);
//		printCharArr(B);
	}
	
	public static void printCharArr(char[] A) {
		for(int i = 0 ; i < A.length ; i++)
			System.out.print(A[i]);
		System.out.println();
	}
	
	public static void showAnswer(int C, ArrayList<Integer> M) {
		System.out.println(M.size());
		for(int i = 0 ; i < M.size() ; i++)
			System.out.print(M.get(i)+1+ " ");
		System.out.println();
	}
	
	public static void JuniorMethod1(char[] A, char[] B, Hashtable<Character, ArrayList<Integer>> T1, Hashtable<Character, ArrayList<Integer>> T2) {
		for(int i = 0 ; i < A.length ; i++) {
			if(T1.get(A[i]) == null) 
				T1.put(A[i], new ArrayList<Integer>());
			if(T2.get(B[i]) == null)
				T2.put(B[i], new ArrayList<Integer>());
			T1.get(A[i]).add(i);
			T2.get(B[i]).add(i);
		}
		// ------------------- Separator -------------------
		if(T1.size() != T2.size()) {
			System.out.println(-1);
			System.exit(0);
		}
		// ------------------- Separator -------------------
		Enumeration<Character> E1 = T1.keys();
		Enumeration<Character> E2 = T2.keys();
		while(E1.hasMoreElements() && E2.hasMoreElements()) {
			char temp = E1.nextElement();
			if(T2.get(temp) == null) {
				System.out.println(-1);
				System.exit(0);
			}
			else if (T1.get(temp).size() != T2.get(temp).size()) {
				System.out.println(-1);
				System.exit(0);
			} else {
				Collections.sort(T1.get(temp));
				Collections.sort(T2.get(temp));
			}
		}
		// ------------------- Separator -------------------
	}

}
