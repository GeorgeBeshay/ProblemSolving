/*
 * Problem Link:			https://codeforces.com/contest/133/problem/B
 * Problem Status:		Accepted.
 */

package String;

import java.util.*;
import java.math.*;

public class P133B_Unary {
	
	public static Hashtable<Character, String> Table = new Hashtable<Character, String>();

	public static void main(String[] args) {
		// --------------------- Separator ---------------------
		Table.put('>', "1000");
		Table.put('<', "1001");
		Table.put('+', "1010");
		Table.put('-', "1011");
		Table.put('.', "1100");
		Table.put(',', "1101");
		Table.put('[', "1110");
		Table.put(']', "1111");
		// --------------------- Separator ---------------------
		Scanner Reader = new Scanner(System.in);
		String Input = Reader.next(); 
		Reader.close();
		// --------------------- Separator ---------------------
		char[] Binary = getBinary(Input);
		// --------------------- Separator ---------------------
		System.out.println(GetDecimal(Binary));
		// --------------------- Separator ---------------------
	}

	public static BigInteger GetDecimal(char[] A) {
		BigInteger Answer = BigInteger.ZERO;
		BigInteger X = BigInteger.ONE;
		for(int i = A.length - 1 ; i >= 0 ; i--) {
			Answer = Answer.add((new BigInteger(A[i] + "")).multiply(X));
			X = X.multiply(new BigInteger("2"));
		}
		Answer = Answer.mod(new BigInteger("1000003"));
		return Answer;
	}
	
	public static void printArr(char[] A) {
		for(int i = 0 ; i < A.length ; i++)
			System.out.print(A[i] + " ");
		System.out.println();
	}
	
	public static char[] getBinary(String S) {
		char[] Answer = new char[S.length() * 4];
		int H = 0;
		char[] S_Char = S.toCharArray();
		for(int i = 0 ; i < S.length() ; i++) {
			char[] Temp = Table.get(S_Char[i]).toCharArray();
			Answer[H] = Temp[0];
			H++;
			Answer[H] = Temp[1];
			H++;
			Answer[H] = Temp[2];
			H++;
			Answer[H] = Temp[3];
			H++;
		}
		return Answer;
	}

}
