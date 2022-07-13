/*
 * Problem Link:				https://codeforces.com/contest/1703/problem/D
 * Problem Status:			Accepted.
 */

package Competitions.CodeForcesContests.R806_D4;

import java.util.*;

public class PD_DoubleStrings {

//	public static String EssentialSolver(String[] A) {
//		String ans = "";
//		Hashtable<String, Integer> Table = new Hashtable<String, Integer>((int)Math.pow(A.length, A.length));
//		for(int i = 0 ; i < A.length ; i++) {
//			for(int j = i ; j < A.length ; j++) {
//				Table.put(A[i].concat(A[j]), 1);
//				Table.put(A[j].concat(A[i]), 1);
//			}
//		}
//		for(int i = 0 ; i < A.length ; i++) {
//			if(Table.get(A[i]) != null && Table.get(A[i]) == 1)
//				ans += "1";
//			else
//				ans += "0";
//		}
//		return ans;
//	}
	
//	public static String EssentialSolverB(String[] A) {
//		String ans = "0".repeat(A.length);
//		Hashtable<String, Integer> Table = new Hashtable<String, Integer>();
//		for(int i = 0 ; i < A.length ; i++) 
//			Table.put(A[i], i);
//		for(int i = 0 ; i < A.length ; i++) {
//			for(int j = 0 ; j < A.length ; j++) {
//				
//				if(  Table.get(A[i].concat(A[j])) !=  null   || Table.get(A[j].concat(A[i])) != null ) {				
//					if(Table.get(A[i].concat(A[j])) != null && Table.get(A[i].concat(A[j])) >= 0 )
//						ans = ChangeChar(ans, (int)Table.get(A[i].concat(A[j])) );
//					if(Table.get(A[j].concat(A[i])) != null && Table.get(A[j].concat(A[i])) >= 0)
//						ans = ChangeChar(ans, (int)Table.get(A[j].concat(A[i])) );
//				}
//				
//			}
//		}
//		return ans;
//	}
	
	public static void EssentialSolverC(String[] A) {
		// ------------------------------------------------------------
//		String ans = "0".repeat(A.length);
		Hashtable<String, Integer> Table = new Hashtable<String, Integer>(A.length);
		// ------------------------------------------------------------
		for(int i = 0 ; i < A.length ; i++) {
			Table.put(A[i], 0);
		}
		// ------------------------------------------------------------
		for(int i = 0 ; i < A.length ; i++) {
			// ------------------------------------------------------------
			StringBuilder tempSubstring = new StringBuilder("");
			// ------------------------------------------------------------
			for(int j = 0 ; j < A[i].length() - 1 ; j++) {
				// ------------------------------------------------------------
				tempSubstring.append( A[i].charAt(j) );
				if(Table.get(tempSubstring.toString()) != null) {
					String tempSubstring2 = A[i].substring(j+1);
					if(Table.get(tempSubstring2) != null){
						Table.put(A[i], 1);
//						ans = ChangeChar(ans, i);
						break;
					} else
						continue;
				} else
					continue;
				// ------------------------------------------------------------
			}
			// ------------------------------------------------------------
		}
		for(int i = 0 ; i < A.length ; i++)
			System.out.print((int)Table.get(A[i]));
		System.out.println();
		// ------------------------------------------------------------
	}
	
//	public static String ChangeChar(String A, int index) {
//		char[] temp = A.toCharArray();
//		temp[index] = '1';
//		return String.valueOf(temp);
//	}
	
	public static void main(String[] args) {
		// ------------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// ------------------------------------------------------------------------
		int T = Reader.nextInt();
		while(T > 0) {
			int N = Reader.nextInt();
			String[] Arr = new String[N];
			for(int i = 0 ; i < N ; i++) 
				Arr[i] = Reader.next();
//			System.out.println(EssentialSolver(Arr));
//			System.out.println(EssentialSolverB(Arr));
//			System.out.println(EssentialSolverC(Arr));
			EssentialSolverC(Arr);
			T--;
		}
		// ------------------------------------------------------------------------
		Reader.close();
		// ------------------------------------------------------------------------
	}

}
