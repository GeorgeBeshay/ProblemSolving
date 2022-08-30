/*
 * Problem Link:			https://codeforces.com/contest/1722/problem/D
 * Problem Status:		Accepted.
 */

package R817_D4;

import java.util.*;

public class PD_Line {

	public static void main(String[] args) {
		// ------------------------------ SEPARATOR ------------------------------
		Scanner Reader = new Scanner(System.in);
		int T = Reader.nextInt();
		while(T > 0) {
			int N = Reader.nextInt();
			char[] A = new char[N];
			A = Reader.next().toCharArray();
			TheAmazingFunction(A);
			T--;
		}
		Reader.close();
		// ------------------------------ SEPARATOR ------------------------------
	}
	
	public static void TheAmazingFunction(char[] A) {
		long Sum;
		long[] currentSum = new long[A.length];
		ArrayList<Long> myList = new ArrayList<Long>();
		// ------------------------------ SEPARATOR ------------------------------
		for(int i = 0 ; i < A.length ; i++) {
			if(A[i] == 'L')
				currentSum[i] = i;
			else
				currentSum[i] = A.length- (i+1);
		}
		// ------------------------------ SEPARATOR ------------------------------
		Sum = getSum(currentSum);
		// ------------------------------ SEPARATOR ------------------------------
		for(int i = 0 ; i < A.length ; i++) {
			if(A[i] == 'L') {
				if(A.length- (i+1) > i) {
					myList.add(Long.valueOf((A.length - (i+1)) - i )) ;
				}
			} else { 
				if(i > A.length - (i+1)) {
					myList.add(Long.valueOf(i - (A.length - (i+1))));
				}
			 }
		}
		// ------------------------------ SEPARATOR ------------------------------
		Collections.sort(myList);
		// ------------------------------ SEPARATOR ------------------------------
		long[] H = new long[myList.size()];
		int u = 0;
		long ans = 0;
		for(int i = myList.size()-1 ; i >= 0 ; i--) {
			H[u] = ans + myList.get(i);
			ans = H[u];
			u++;
		}
		// ------------------------------ SEPARATOR ------------------------------
		for(int i = 0 ; i < A.length ; i++)
			System.out.print(Long.valueOf(Sum + getListSum(H, i)) + " ");
		System.out.println();
		// ------------------------------ SEPARATOR ------------------------------
	}
	
	public static void ShowArr(int[] A) {
		for(int i = 0 ; i < A.length ; i++)
			System.out.print(A[i] + " ");
		System.out.println();
	}
	
	public static long getListSum(long[] S, int X) {
		if(S.length == 0)
			return 0;
		if(X >= S.length)
			return S[S.length-1];
		 else 
			 return S[X];
	}
	
	public static long getSum(long[] A) {
		long Answer = 0;
		for(int i = 0 ; i < A.length ; i++) {
			Answer += A[i];
		}
		return Answer;
	}

}
