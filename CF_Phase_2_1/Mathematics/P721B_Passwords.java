/*
 * Problem Link:			https://codeforces.com/problemset/problem/721/B
 * Problem Status:		Accepted.
 */

package Mathematics;

import java.util.*;

public class P721B_Passwords {
	
	public static void SolverA(ArrayList<String> A, int K, String RealPassword) {
		ArrayList<Double> B = new ArrayList<Double>(A.size()+1);
		int Best = -1;
		int Worst = -1;
		// ------------------------------- SEPARATOR -------------------------------
		for(int i = 0 ; i < A.size() ; i++) {
			if(A.get(i).compareTo(RealPassword) == 0) {
				B.add(A.get(i).length() - 0.5);
				B.add(A.get(i).length() + 0.5);
			}
			else
				B.add((double)A.get(i).length());
		}
		// ------------------------------- SEPARATOR -------------------------------
		Collections.sort(B);
		// ------------------------------- SEPARATOR -------------------------------
		int Time = 0;
		int Counter = 0;
		for(int i = 0 ; i < B.size() ; i++) {
			if(Counter == K) {
				Time += 5;
				Counter = 0;
			}
			Time++;
			if( (B.get(i)%1) != 0.5) {
				Counter++;
			}
			else {
				if(Best == -1) {
					Best = Time;
					Time--;
				}
				else if (Worst == -1)
					Worst = Time;
			}
			if(Best != -1 && Worst != -1)
				break;
		}
		// ------------------------------- SEPARATOR -------------------------------
		System.out.println(Best + " " + Worst);
	}

	public static void main(String[] args) {
		// ------------------------------- SEPARATOR -------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();									// Number Of Passwords
		int K = Reader.nextInt();									// Number Of Maximum Wrong Passwords to be entered.
		ArrayList<String> A = new ArrayList<String>(N);
		for(int i = 0 ; i < N ; i++)
			A.add(Reader.next());
		String RealPassword = Reader.next();
		Reader.close();
		// ------------------------------- SEPARATOR -------------------------------
		SolverA(A, K, RealPassword);
		// ------------------------------- SEPARATOR -------------------------------
	}

}
