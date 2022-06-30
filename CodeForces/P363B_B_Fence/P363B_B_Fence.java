package CodeForces.P363B_B_Fence;

/*
 * Problem Link: 	https://codeforces.com/problemset/problem/363/B
 * Problem Status:	Accepted.
 */

import java.util.*;

public class P363B_B_Fence {
	
	public static void methodB() {
		
	}
	
	public static int methodA(int[] A, int k, int minHeight) {
		int ans = 1;
		for(int i = 0 ; i < A.length-k+1 ; i++) {
			int tempMin = 0;
			for(int j = i ; j < i +k ; j++) {
				tempMin+=A[j];
			}
			if(tempMin < minHeight) {
				minHeight = tempMin;
				ans = i+1;
			}
		}
		return ans;
	}
	
	public static void main(String[] args) {
		Scanner S = new Scanner(System.in);
		int n = S.nextInt();
		int k = S.nextInt();
		int k_ = k;
		int min = 0;
		int minHeight = 0;
		int minIndex = 1;
		int[] A = new int[n];
		for(int i = 0 ; i < n ; i++) {
			A[i] = S.nextInt();
				if(k_ != 0) {
					min+= A[i];
					k_--;
				} else {
						if(i-k == 0) {
							minHeight = min;
						}
						min = min - A[i-k] + A[i];
						if(min < minHeight) {
							minHeight = min;
							minIndex = i - k + 2;
						}
						
				}
		}
		S.close();
//		System.out.println(methodA(A, k, min));
		System.out.println(minIndex);
	}

}
