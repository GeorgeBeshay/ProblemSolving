/*
 * Problem Link:					https://codeforces.com/problemset/problem/385/B
 * Problem Status:				Accepted.
 */

package String;

import java.util.*;

public class P385B_BearAndStrings {

	public static void main(String[] args) {
		// ----------------------------------- Variables -----------------------------------
		String Input;
		int[] A;
		// ----------------------------------- Separator -----------------------------------
		Scanner Reader = new Scanner(System.in);
		Input = Reader.next();
		Reader.close();
		// ----------------------------------- Separator -----------------------------------
		A = new int[Input.length()];
		A = getNearestBearToTheRight(Input, A);
		// ----------------------------------- Separator -----------------------------------
		System.out.println(getTheAnswer(A));
		
	}
	
	public static int getTheAnswer(int[] A_) {
		int Answer = 0;
		for(int i = 0 ; i < A_.length ; i++) {
			if(A_[i] != -1) {
				Answer += (A_.length - A_[i]);
			} else 
				continue;
		}
		return Answer;
	}
	
	public static int[] getNearestBearToTheRight(String S_, int[] A) {
		char[] S = S_.toCharArray();
		// ----------------------------------- Separator -----------------------------------
		for(int i = 0 ; i < S.length - 3 ; i++) {
			if (S[i] == 'b' && S[i+1] == 'e' && S[i+2] == 'a' && S[i+3] == 'r')
				A[i] = i+3;
			else
				A[i] = -1;
		}
		try{ A[A.length-1] = -1; } catch(Exception E) {}
		try{ A[A.length-2] = -1;  } catch(Exception E) {}
		try{ A[A.length-3] = -1;  } catch(Exception E) {}
		// ----------------------------------- Separator -----------------------------------
		int temp = -1;
		for(int i = A.length - 4 ; i >= 0 ; i--) {
			if(A[i] == -1)
				A[i] = temp;
			else
				temp = A[i];
		}
		// ----------------------------------- Separator -----------------------------------
		return A;
	}
	
	public static void printArr(int[] Arr) {
		for(int i = 0  ; i < Arr.length ; i++)
			System.out.print(Arr[i] + " ");
		System.out.println();
	}

}
