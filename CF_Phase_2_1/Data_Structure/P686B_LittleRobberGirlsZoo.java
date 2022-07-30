package Data_Structure;

/*
 * Problem Link: 	https://codeforces.com/problemset/problem/686/B
 * Problem Status:	Accepted
 */

import java.util.*;

public class P686B_LittleRobberGirlsZoo {
	
	public static void methodB(int[] A) {
		
		while(!ordered(A)) {
			
			int st = -1 ;
			int end = -1;
			int len = 1;
			
			for(int i = 1 ; i < A.length ; i++) {
				
				len ++;
				
				if( A[i] < A[i-1]) {
					end = i;
					if(st == -1) {
						st = i-1;
						len = 2;
					}
					len = end - st + 1;
				}
				
				else if(st != -1 && end != -1 && len % 2 == 0) {
					A = recursionMethod(A, st, end);
					i++;
					st = -1;
					end = -1;
					len = -1;
				}
				
				
				if( (i ==  A.length-1) && (st != -1) && (end != -1)) {
					if(len % 2 == 0) {
					A = recursionMethod(A, st, end);
					i++;
					st = -1;
					end = -1;
					len = -1;
					} else {
						if(end == A.length-1) {
						A = recursionMethod(A, st, end-1);
						i++;
						st = -1;
						end = -1;
						len = -1;
						} else {
							A = recursionMethod(A, st, end);
							i++;
							st = -1;
							end = -1;
							len = -1;
						}
					}
				}
				
			}
			
		}
		
	}
	
	public static boolean ordered(int[] A) {
		boolean flag = true;
		for(int i = 0 ; i < A.length-1 ; i++) {
			if(A[i] > A[i+1]) {
				flag = false;
				break;
			}
		}
		return flag;
	}
	
	public static void showArray(int[] A) {
		for(int i = 0 ; i < A.length ; i++)
			System.out.print(A[i] + " ");
		System.out.println();
	}
	
	public static int[] recursionMethod(int[] A, int i, int j) {
		if( (j-i+1) % 2 == 1) {
			j--;
		}
		System.out.println((i+1) + " " +( j+1));
		for(int u = i ; u< j ; u+=2) {
			int temp = A[u];
			A[u] = A[u+1];
			A[u+1] = temp;
		}
		return A;
	}
	
	public static void main(String[] args) {
		Scanner S = new Scanner(System.in);
		int n = S.nextInt();
		int[] A = new int[n];
		for(int i = 0 ; i < n ; i++) {
			A[i] = S.nextInt();
		}
		methodB(A);
		S.close();

	}

}
