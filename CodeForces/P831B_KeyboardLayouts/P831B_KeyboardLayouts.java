/*
 * Problem Link: https://codeforces.com/problemset/problem/831/B
 * Problem Status: Accepted
 */

package CodeForces.P831B_KeyboardLayouts;

import java.util.*;

public class P831B_KeyboardLayouts {
	
	public static void Solver(char[] Layout1, char[] Layout2, char[] Text) {
		// -----------------------------------------------------------------
		int[] Storage = new int[26];
		// -----------------------------------------------------------------
		for(int i = 0 ; i < Layout1.length ; i++) {
			Storage[(int)Layout1[i] - 97] = i;
		}
		// -----------------------------------------------------------------
		for(int j = 0 ; j < Text.length ; j++) {
			
			boolean UpperCaseFlag = false;
			
			if( (int)(Text[j]) >= 48 && (int)(Text[j]) <= 57) {
				System.out.print(Text[j]);
				continue;
			}
			
			int codeOfCharacter = (int)(Text[j]) - 97;
			if (codeOfCharacter < 0) {
				codeOfCharacter += 32;
				UpperCaseFlag = true;
			}
			
			int indexOfCorrespondingInLayout2 = Storage[codeOfCharacter];
			char toBePrinted = Layout2[indexOfCorrespondingInLayout2];
			
			if(UpperCaseFlag)
				toBePrinted = (char)((int)(toBePrinted) - 32);
			
			System.out.print(toBePrinted);		
			
		}
		// -----------------------------------------------------------------
	}

	public static void main(String[] args) {
		// -----------------------------------------------------------------
		Scanner Reader = new Scanner(System.in);
		// -----------------------------------------------------------------
		String Layout1, Layout2, Text;
		Layout1 = Reader.nextLine();
		Layout2 = Reader.nextLine();
		Text = Reader.nextLine();
		// -----------------------------------------------------------------
		Reader.close();
		// -----------------------------------------------------------------
		Solver(Layout1.toCharArray(), Layout2.toCharArray(), Text.toCharArray());
		// -----------------------------------------------------------------
		
	}

}
