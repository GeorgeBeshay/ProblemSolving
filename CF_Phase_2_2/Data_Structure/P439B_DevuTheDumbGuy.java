/*
 * Problem Link:				https://codeforces.com/problemset/problem/439/B
 * Problem Status:			Accepted.
*/	

package Data_Structure;

import java.util.*;
import java.math.BigInteger;

public class P439B_DevuTheDumbGuy {
	
	public static BigInteger solvingFunctionA(int[] A, int X) {
		BigInteger Ans = new BigInteger("0");
		ArrayList<Integer> APro = new ArrayList<Integer>(A.length);
		// ------------------------------- SEPARATOR -------------------------------
		for(int i = 0 ; i < A.length ; i++)
			APro.add(A[i]);		
		// ------------------------------- SEPARATOR -------------------------------
		Collections.sort(APro);
		// ------------------------------- SEPARATOR -------------------------------
		for(int i = 0 ; i < A.length ; i++) {
			long O = (long)APro.get(i);
			long P = (long)X;
			BigInteger Temp;
			Temp = BigInteger.valueOf(O);
			Temp = Temp.multiply(BigInteger.valueOf(P));
			Ans = Ans.add(Temp);
			if(X > 1)
				X--;
		}
		// ------------------------------- SEPARATOR -------------------------------
		return Ans;
	}

	public static void main(String[] args) {
		// ------------------------------- SEPARATOR -------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int X = Reader.nextInt();
		int[] Arr = new int[N];
		for(int i = 0 ; i < N ; i++)
			Arr[i] = Reader.nextInt();
		Reader.close();
		// ------------------------------- SEPARATOR -------------------------------
		System.out.println(solvingFunctionA(Arr, X));
		// ------------------------------- SEPARATOR -------------------------------
	}

}
