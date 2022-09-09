/*
 * Problem Link:				https://codeforces.com/problemset/problem/625/B
 * Problem Status:			Accepted.
 */

package String;

import java.util.*;

public class P625B_WarOfTheCorporations {

	public static void main(String[] args) {
		char[] Name;
		char[] PhoneName;
		// -------------------- Separator --------------------
		Scanner Reader = new Scanner(System.in);
		Name = Reader.next().toCharArray();
		PhoneName = Reader.next().toCharArray();
		Reader.close();
		// -------------------- Separator --------------------
		System.out.println(getNumOfSubStrings(Name, PhoneName));
		// -------------------- Separator --------------------
	}
	
	public static int getNumOfSubStrings(char[] Name, char[] PhoneName) {
		int Answer = 0;
		int Z = PhoneName.length-1;
		if(!String.copyValueOf(Name).contains(String.copyValueOf(PhoneName)))
			return 0;
		// -------------------- Separator --------------------
		for(int i = Name.length-1; i >= 0 ; i--) {
			// -------------------- Separator --------------------
			if(Name[i] == PhoneName[Z]) {
				Z--;
				if(Z == -1) {
					Answer++;
					Z = PhoneName.length-1;
				}
			}
			// -------------------- Separator --------------------
			else {
				Z = PhoneName.length-1;
				if(Name[i] == PhoneName[Z]) {
					Z--;
					if(Z == -1) {
						Answer++;
						Z = PhoneName.length-1;
					}
				}
			}
		}
		// -------------------- Separator --------------------
		return Answer;
	}

}
