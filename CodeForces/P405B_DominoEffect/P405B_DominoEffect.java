/*
 * Problem Link:				https://codeforces.com/problemset/problem/405/B
 * Problem Status:			Accepted.
 */

package CodeForces.P405B_DominoEffect;

import java.util.*;

public class P405B_DominoEffect {
	
	public static int SolverA(int N, String Input) {
		int Answer = 0;
		char[] FromLeft = new char[Input.length()];
		char[] FromRight = new char[Input.length()];
		// ---------------------------------------------	 SEPARATOR ---------------------------------------------
		for(int i = 0 ; i < N ; i++) {
			int LIndex = i;
			int RIndex = Input.length()-1-i;
			char tempCharL = Input.charAt(i);
			char tempCharR = Input.charAt(Input.length()-1-i);
			if(i == 0) {
				FromLeft[LIndex] = tempCharL ;
				FromRight[RIndex] = tempCharR;
			} else {
				// From Left
				if(tempCharL == 'L' || tempCharL == 'R') {
					FromLeft[LIndex] = tempCharL;
				}
				else if(FromLeft[LIndex - 1] == 'R')
					FromLeft[LIndex] = 'R';
				else
					FromLeft[LIndex] = tempCharL;
				// From Right
				if(tempCharR == 'R' || tempCharR == 'L') {
					FromRight[RIndex] = tempCharR;
				}
				else if(FromRight[RIndex + 1] == 'L')
					FromRight[RIndex] = 'L';
				else
					FromRight[RIndex] = tempCharR;
			}
		}
		// ---------------------------------------------	 SEPARATOR ---------------------------------------------
//		for(int i = 0 ; i < N ; i++) {
//			System.out.print( Input.charAt(i) + " ");
//		}
//		System.out.println();
//		for(int i = 0 ; i < N ; i++) {
//			System.out.print( FromLeft[i] + " ");
//		}
//		System.out.println();
//		for(int i = 0 ; i < N ; i++) {
//			System.out.print( FromRight[i] + " ");
//		}
//		System.out.println();
		// ---------------------------------------------	 SEPARATOR ---------------------------------------------
		int[] Final = new int[N];
		boolean Flag = false;
		int temp = 0;
		for(int i = 0 ; i < N ; i++) {
			if(FromLeft[i] == '.' || FromRight[i] == '.') {
				if(FromLeft[i] == '.')
					Final[i] = FromRight[i];
				else
					Final[i] = FromLeft[i];
				if(Final[i] == '.')
					Answer++;
				if(Flag) {
					Flag = false;
					if(temp % 2 == 1)
						Answer++;
					temp = 0;
				}
			} else if (FromLeft[i] == FromRight[i]) {
				Final[i] = FromLeft[i];
				if(Flag) {
					Flag = false;
					if(temp % 2 == 1)
						Answer++;
					temp = 0;
				}
			} else {
				Flag = true;
				temp++;
			}
		}
		if(Flag) {
			Flag = false;
			if(temp % 2 == 1)
				Answer++;
			temp = 0;
		}
		return Answer;
	}

	public static void main(String[] args) {
		// ---------------------------------------- SEPARATOR ----------------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		String Input = Reader.next();
		Reader.close();
		// ---------------------------------------- SEPARATOR ----------------------------------------
		System.out.println(SolverA(N, Input));
	}

}
