/*
 * Problem Link:				https://codeforces.com/problemset/problem/519/B
 * Problem Status:			Accepted.
 */

package Mathematics;

import java.util.*;

public class P519B_AAndBAndCompliationErrors {
	
	public static void SolverA(ArrayList<Integer> A1, ArrayList<Integer> B1, ArrayList<Integer> C1) {
		// ------------------------------- SEPARATOR -------------------------------
		Collections.sort(A1);
		Collections.sort(B1);
		Collections.sort(C1);
		// ------------------------------- SEPARATOR -------------------------------
		Hashtable<Integer, Integer> A11 = new Hashtable<Integer, Integer>(A1.size());
		Hashtable<Integer, Integer> B11 = new Hashtable<Integer, Integer>(B1.size());
		// ------------------------------- SEPARATOR -------------------------------
		for(int i = 0 ; i < A1.size() ; i++) {
			A11.put(A1.get(i), 0);
			if(i < B1.size())
				B11.put(B1.get(i), 0);
		}
		// ------------------------------- SEPARATOR -------------------------------
		for(int i = 0 ; i < A1.size() ; i++) {
			A11.replace( A1.get(i), A11.get(A1.get(i))+1 );
		}
		for(int i = 0 ; i < B1.size() ; i++) {
			B11.replace( B1.get(i), B11.get(B1.get(i))+1 );
		}
		// ------------------------------- SEPARATOR -------------------------------
		for(int i = 0 ; i < B1.size() ; i++) {
			A11.replace(B1.get(i), A11.get(B1.get(i)) - 1);
		}
		for(int i = 0 ; i < C1.size() ; i++) {
			B11.replace(C1.get(i), B11.get(C1.get(i)) - 1);
		}
		// ------------------------------- SEPARATOR -------------------------------
		for(int i = 0 ; i < A1.size() ; i++) {
			if(A11.get(A1.get(i)) == 1) {
				System.out.println(A1.get(i));
				break;
			}
		}
		for(int i = 0 ; i < B1.size() ; i++) {
			if(B11.get(B1.get(i)) == 1) {
				System.out.println(B1.get(i));
				break;
			}
		}
		// ------------------------------- SEPARATOR -------------------------------
	}

	public static void main(String[] args) {
		// ------------------------------- SEPARATOR -------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		ArrayList<Integer> A1 = new ArrayList<Integer>(N);
		ArrayList<Integer> B1 = new ArrayList<Integer>(N-1);
		ArrayList<Integer> C1 = new ArrayList<Integer>(N-2);
		for(int i = 0 ; i < N ; i++)
			A1.add(Reader.nextInt());
		for(int i = 0 ; i < N-1 ; i++)
			B1.add(Reader.nextInt());
		for(int i = 0 ; i < N-2 ; i++)
			C1.add(Reader.nextInt());
		Reader.close();
		// ------------------------------- SEPARATOR -------------------------------
		SolverA(A1, B1, C1);
		// ------------------------------- SEPARATOR -------------------------------
	}

}
