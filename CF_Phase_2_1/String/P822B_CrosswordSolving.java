/*
 * Problem Link:			https://codeforces.com/problemset/problem/822/B
 * Problem Status:	Accepted.
 */

package String;

import java.util.*;

public class P822B_CrosswordSolving {

	/*
	 * IDEA:
	 * 	1) Loop OVer The T String From index 0 To <= Length -  Length(S) 
	 * 	2) In Each Iteration Store the current substring formed, calculate no of '?'- different characters -
	 * 	3) if Number of '?' < currentlyStored ==>> Change The Currently Stored to this new one.
	 * 	4) Also You have to store the indices of the '?' taking in consideration that the indices starts from 1 not 0.  
	 */
	public static void SolverAMaster(String S, String T, int N, int M) {
		// ----------------------------------------------------------------------
		ArrayList<Integer> IndicesToBeReplaced = new ArrayList<Integer>();
		String Temp;
		String Ans = "";
		int NumberOfDifferentCharacters = -1;
		// ----------------------------------------------------------------------
		for(int i = 0 ; i <= T.length() -  S.length() ; i++) {
			// ----------------------------------------------------------------------
			Temp = "";
			Temp = T.substring(i, i+S.length());
			// ----------------------------------------------------------------------
			if(NumberOfDifferentCharacters != -1) {
				if(SolverAJunior(Temp, S) < NumberOfDifferentCharacters) {
					NumberOfDifferentCharacters = SolverAJunior(Temp, S);
					Ans = Temp;
				}
			} else {
				NumberOfDifferentCharacters = SolverAJunior(Temp, S);
				Ans = Temp;
			}
			// ----------------------------------------------------------------------
		}
		SolverAJunior2(Ans, S, IndicesToBeReplaced);
		System.out.println(NumberOfDifferentCharacters);
		ShowList(IndicesToBeReplaced);
	}
	
	/*
	 * Method Used To Calculate Number of Different Characters.
	 */
	public static int SolverAJunior(String A, String B) {
		if(A.length() != B.length()) {
			System.out.println("Error @ SolverAJunior.");
			return -1;
		}
		int ans = 0;
		for(int i = 0 ; i < A.length() ; i++) {
			if ( A.charAt(i) != B.charAt(i) ) {
					ans++;
			}
		}
		return ans;
	}
	
	/*
	 * Method Used To Get The Indices Of Different Characters
	 */
	public static void SolverAJunior2(String A, String B, ArrayList<Integer> X) {
		if(A.length() != B.length()) {
			System.out.println("Error @ SolverAJunior.");
			return ;
		}
		for(int i = 0 ; i < A.length() ; i++) {
			if ( A.charAt(i) != B.charAt(i) ) 
				X.add(i+1);
		}
	}
	
	/*
	 * Method Used To Print List Elements
	 */
	public static void ShowList(ArrayList<Integer> X) {
		for(int i = 0 ; i < X.size() ; i++) {
			System.out.print(X.get(i) + " ");
		}
		System.out.println();
	}
	
	/*
	 * Main Method
	 */
	public static void main(String[] args) {
		// ----------------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// ----------------------------------------------------------------------
		int N = Reader .nextInt();
		int M = Reader.nextInt();
		String S = Reader.next();
		String T = Reader.next();
		// ----------------------------------------------------------------------
		Reader.close();
		// ----------------------------------------------------------------------
		SolverAMaster(S, T, N, M);
		// ----------------------------------------------------------------------
	}

}
