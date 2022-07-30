/*
 * Problem Link:			https://codeforces.com/problemset/problem/723/B
 * Problem Status:		Accepted.
 */

package Data_Structure;

import java.util.*;

public class P723B_TextDocumentAnalysis {
	
	public static void SolverB(int N, String S) {
		// ------------------------------------- SEPARATOR ------------------------------------- 
		String NewString = "";
		boolean ParenthesisOpenFlag = false;
		ArrayList<String> Arr = new ArrayList<String>(100);
		int CurrentIndex = -1;
		// ------------------------------------- SEPARATOR ------------------------------------- 
		for(int i = 0 ; i < N ; i++) {
			char TempChar = S.charAt(i);
			// ------------------------------------- SEPARATOR ------------------------------------- 
			if(TempChar == '(') {
				ParenthesisOpenFlag = true;
				Arr.add("");
				CurrentIndex ++;
			}
			// ------------------------------------- SEPARATOR ------------------------------------- 
			else if(TempChar == ')') {
				ParenthesisOpenFlag = false;
				NewString += "_";
			}
			// ------------------------------------- SEPARATOR ------------------------------------- 
			else if(TempChar == '_') {
				// ------------------------------------- SEPARATOR ------------------------------------- 
				if(ParenthesisOpenFlag) {
					if(Arr.get(CurrentIndex).length() > 0) {
						if (Arr.get(CurrentIndex).charAt(Arr.get(CurrentIndex).length()-1) != '_')
							Arr.set(CurrentIndex, Arr.get(CurrentIndex)+TempChar );
					}
					else
						Arr.set(CurrentIndex, TempChar+"");
				}
				// ------------------------------------- SEPARATOR ------------------------------------- 
				else {
					if(NewString.length() > 0) {
						if(NewString.charAt(NewString.length()-1) != '_')
							NewString += TempChar;
					} else 
						NewString += TempChar;
				}
			}
			// ------------------------------------- SEPARATOR ------------------------------------- 
			else {
				if(ParenthesisOpenFlag) {
					if(Arr.get(CurrentIndex) != null)
						Arr.set(CurrentIndex, Arr.get(CurrentIndex)+TempChar );
					else
						Arr.set(CurrentIndex, TempChar+"");
				} else 
					NewString += TempChar;
			}
		}
		// ------------------------------------- SEPARATOR ------------------------------------- 
		String[] Arr2 = NewString.split("_");
		int CurrentMax1 = 0;
		int WordsCounter = 0;
		// ------------------------------------- SEPARATOR ------------------------------------- 
		for(int i = 0 ; i < Arr2.length ; i++) {
			if(CurrentMax1 < Arr2[i].length())
				CurrentMax1 = Arr2[i].length();
		}
		// ------------------------------------- SEPARATOR ------------------------------------- 
		for(int i = 0 ; i < Arr.size() ; i++) {
			String[] tempArr = Arr.get(i).split("_");
			for(int j = 0 ; j < tempArr.length ; j++) {
				if(tempArr[j].length() > 0) 
					WordsCounter++;				
			}
		}
		// ------------------------------------- SEPARATOR ------------------------------------- 
		System.out.println(CurrentMax1 + " " + WordsCounter);
	}
	
//	public static void SolverA(int N, String S) {
//		int LWL = 0;														// Longest Word Length
//		int PWC = 0;														// Parentheses Words Counter
//		int TempWordLength = 0;
//		boolean WordStartFlag = false;
//		boolean ParenthesisStartFlag = false;
//		for(int i = 0 ; i < N ; i++) {
//			char TempChar = S.charAt(i);
//			// -------------------------------------------------- SEPARATOR --------------------------------------------------
//			if(TempChar == '_' || TempChar =='(') {
//				if(TempChar == '(') {
//					ParenthesisStartFlag = true;
//				}
//				if(WordStartFlag) {
//					if(TempWordLength > LWL) 
//						LWL = TempWordLength;
//					if(ParenthesisStartFlag && TempChar =='_' )
//						PWC++;
//				} else 
//					WordStartFlag = true;
//				TempWordLength = 0;
//			}
//			// -------------------------------------------------- SEPARATOR --------------------------------------------------
//			else if(TempChar == ')') {
//				if(WordStartFlag){
//					if(TempWordLength > LWL) 
//						LWL = TempWordLength;
//					if(ParenthesisStartFlag && (S.charAt(i-1) != '(' || S.charAt(i-1) != '_') )
//						PWC++;
//				}
//				ParenthesisStartFlag = false;
//			}
//			// -------------------------------------------------- SEPARATOR --------------------------------------------------
//			else 
//				TempWordLength++;
//			System.out.println(LWL + " " + PWC);
//		}
//		// -------------------------------------------------- SEPARATOR --------------------------------------------------
//		if(TempWordLength > LWL) 
//			LWL = TempWordLength;
//		// -------------------------------------------------- SEPARATOR --------------------------------------------------
////		System.out.println(LWL + " " + PWC);
//	}

	public static void main(String[] args) {
		// -------------------------------------------------- SEPARATOR --------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// -------------------------------------------------- SEPARATOR --------------------------------------------------
		int N = Reader.nextInt();
		String Input = Reader.next();
		// -------------------------------------------------- SEPARATOR --------------------------------------------------
		Reader.close();
		// -------------------------------------------------- SEPARATOR --------------------------------------------------
//		SolverA(N, Input);
		SolverB(N, Input);
		// -------------------------------------------------- SEPARATOR --------------------------------------------------
	}

}
