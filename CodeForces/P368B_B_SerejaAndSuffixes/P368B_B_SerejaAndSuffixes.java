package CodeForces.P368B_B_SerejaAndSuffixes;

/*
 * Problem Link: https://codeforces.com/contest/368/problem/B
 * Status: 			Time limit exceeded on test case 26
 * Note: 			Same code was submitted by another person and was Accepted
 */

import java.util.*;

public class P368B_B_SerejaAndSuffixes {

	public static int[] methodB(int[] A) {
		
		int[] results = new int[A.length];
		Set<Integer> mySet = new LinkedHashSet<>();
		for(int i = A.length-1 ; i >= 0 ; i--) {
			mySet.add(A[i]);
			results[i] = mySet.size();
		}
		return results;

//		showArray(B);
		
//		for(int k = 0 ; k < A.length ; k++) {
//			System.out.println(results[k]);
//		}
		
	}
	
	
	public static void methodA(int[] A, int[] B) {
		for(int u = 0 ; u < B.length ; u++) {
			int k = B[u];
			int ans = 1;
			
			for(int i = k ; i<A.length ; i++) {
				boolean Flag = false;
				for(int j = k ; j < i ; j++) {
					if(A[j] == A[i]) {
						Flag = true;
						break;
					}
				}
				if(!Flag && A[i] != A[k-1])
					ans++;
			}
			
			System.out.println(ans);
		}
	}
	
	public static void showArray(int[] A) {
		for(int i = 0 ; i<A.length ; i++) {
			System.out.print(A[i] + " ");
		}
		System.out.println();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner myScanner = new Scanner(System.in);
		int n = myScanner.nextInt();
		int m = myScanner.nextInt();
		int[] A = new int[n];
		for(int i = 0 ; i < n ; i++) {
			A[i] = myScanner.nextInt();
		}
		int[] results = methodB(A);
		while(m > 0) {
			System.out.println(results[myScanner.nextInt()-1]);
			m--;
		}
		myScanner.close();
		
//		String[] tempS1 = myScanner.nextLine().split(" ");
//		int n = Integer.parseInt(tempS1[0]);
//		int m = Integer.parseInt(tempS1[1]);
//		int[] A = new int[n];
//		int[] B= new int[m];
//		tempS1 = myScanner.nextLine().split(" ");
//		if(tempS1.length == 1 && tempS1[0].isEmpty())
//			A = new int[] {};
//		else {
//			for(int i = 0 ; i < tempS1.length ; i++) {
//				A[i] = Integer.parseInt(tempS1[i]);
//			}
//		}
//		int[] results = methodB(A);
//		for(int i = 0 ; i < m ; i++) {
//			B[i] = Integer.parseInt(myScanner.nextLine());
//			System.out.println(results[B[i] - 1]);
//		}
		
		// Checking Input was scanned successfully
//		System.out.println(n + " " +  m);
//		showArray(A);
//		showArray(B);
		
//		methodA(A, B);
//		methodB(A);
		
	}

}
