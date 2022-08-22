/*
 * Problem Link:			https://codeforces.com/problemset/problem/315/B
 * Problem Status:		Accepted.
 */

package Data_Structure;

import java.util.*;

public class P315B_SerejaAndArray {
	
	public static void TheAmazingFunction(int[] A, int M, Scanner MyReader) {
		int Stored = 0;
		// ----------------------------------------- SEPARATOR -----------------------------------------
		while(M > 0) {
			int T = MyReader.nextInt();
			// ----------------------------------------- SEPARATOR -----------------------------------------
			if(T == 3) 
				System.out.println(A[MyReader.nextInt()-1]+Stored);
			// ----------------------------------------- SEPARATOR -----------------------------------------
			else if (T == 2) 
				Stored  += MyReader.nextInt();
			// ----------------------------------------- SEPARATOR -----------------------------------------
			else 
				A[MyReader.nextInt()-1] = MyReader.nextInt()-Stored;
			// ----------------------------------------- SEPARATOR -----------------------------------------
			M--;
		}
	}
	
	public static void scanArr(int[] A, Scanner MyReader) {
		for(int i = 0 ; i < A.length ; i++)
			A[i] = MyReader.nextInt();
	}
	
	public static void showArr(int[] A) {
		for(int i = 0 ; i < A.length ; i++)
			System.out.print(A[i] + " ");
	}

	public static void main(String[] args) {
		// ----------------------------------------- SEPARATOR -----------------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int M = Reader.nextInt();
		int[] A= new int[N];
		scanArr(A, Reader);
		TheAmazingFunction(A, M, Reader);
		Reader.close();
		// ----------------------------------------- SEPARATOR -----------------------------------------
	}

}
