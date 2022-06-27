package CodeForces.B_Cormen_TheBestFriendOfAMan;

import java.util.*;

/*
 * Problem Link: 	https://codeforces.com/problemset/problem/732/B
 * Status: 		Accepted		
 */

public class B_Cormen_TheBestFriendOfAMan {

	public static void methodA(int k, int[] A) {
		
		int Extra = 0;
		
		for(int i = 0 ; i < A.length-1 ; i++) {
			if(A[i] + A[i+1] >= k)
				continue;
			else {
				Extra += k - A[i] - A[i+1];
				A[i+1] = k - A[i];
			}
		}
		
		System.out.println(Extra);
		showArray(A);
		
	}
	
	
	public static void showArray(int[] A) {
		for(int i = 0 ; i<A.length ; i++) {
			System.out.print(A[i] + " ");
		}
	}
	
	
	public static void main(String[] args) {
		
		// Scanning Input
		Scanner MyScanner = new Scanner(System.in);
		String tempS1 = MyScanner.nextLine();
		String[] tempS2 = tempS1.split(" ");
		int n = Integer.parseInt(tempS2[0]);
		int k = Integer.parseInt(tempS2[1]);
		
//		System.out.println(n + " " + k);						// Checking input has been scanned successfully
		
		tempS1 = MyScanner.nextLine();
		MyScanner.close();
		tempS2 = tempS1.split(" ");
		int[] A = new int[tempS2.length];
		if (tempS2.length == 1 && tempS2[0].isEmpty())
	          A = new int[]{};
		else {
			for(int i = 0 ; i < tempS2.length ; i++)
				A[i] = Integer.parseInt(tempS2[i]);
		}
		
//		showArray(A);											// Checking input has been scanned successfully
		
		methodA(k, A);
		
		
		
	}
	
}
