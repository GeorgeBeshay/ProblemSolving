package CodeForces.P706B_B_InterestingDrink;

/*
 * Problem Link 		=> https://codeforces.com/problemset/problem/706/B
 * Problem Status 	=> Accepted using "methodC"
 */

import java.util.*;

public class P706B_B_InterestingDrink {
	
	public static void methodC(List<Integer> A, int[]B) {
		Collections.sort(A);
		int[] results = new int[A.get(A.size()-1)];
		for(int i = 0 ; i < A.size() ; i++) {
			results[A.get(i)-1] = i+1;
		}
		int current = results[0];
		for(int i = 0 ; i < results.length ; i++) {
			if(results[i] == 0)
				results[i] = current;
			else
				current = results[i];
		}
		for(int i = 0 ; i < B.length ; i++) {
			if(B[i] > A.get(A.size()-1)) {
				System.out.println(A.size());
			} else {
			System.out.println(results[B[i]-1]);
			}
		}
	}
	
	public static void methodB(List<Integer> A, int[] B) {
		Collections.sort(A);
		int min = A.get(0);
		int max = A.get(A.size()-1);
		for(int i = 0 ; i < B.length ; i++) {
			if(B[i] >= max) {
				System.out.println(A.size());
				continue;
			};
			int ans = A.lastIndexOf(B[i]);
			int c = 1;
			while(ans == -1 && B[i] >= min && B[i] < max) {
				ans = A.lastIndexOf(B[i]-c);
				c++;
			}
			if(B[i] >=  max)
				System.out.println(A.size());
			else
				System.out.println(ans + 1);
		}
	}
	
	public static void methodA(int[] A, int[] B) {
		for(int i = 0 ; i < B.length ; i++) {
			int ans = 0;
			for(int j = 0 ; j < A.length ; j++) {
				if(B[i] >= A[j])
					ans++;
			}
			System.out.println(ans);
		}
	}
	
	public static void showArray(int[] A) {
		for(int i = 0 ; i < A.length ; i++)
			System.out.print(A[i] + " ");
		System.out.println();
	}
	
	public static void main(String[] args) {
		
		Scanner myScanner = new Scanner(System.in);
		int n = myScanner.nextInt();					// Number of Shops in the City.
//		int[] A = new int[n];								// Price of the bottle in each shop.
		List<Integer> myList = new ArrayList<Integer>(n);
		for (int i = 0 ; i < n ; i++)
			myList.add(myScanner.nextInt());
		int q = myScanner.nextInt();					// Number of Consecutive days that Vasiliy will buy in
		int[] B = new int[q];								// Number of coins to spend in each day
		for(int i = 0 ; i < q ; i++)
			B[i] = myScanner.nextInt();
		myScanner.close();
		
		// Checking Input was scanned correctly
//		showArray(A);
//		showArray(B);
		
//		methodB(myList,B);
		methodC(myList,B);
		

	}

}
