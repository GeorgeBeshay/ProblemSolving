/*
 * Problem Link:			https://codeforces.com/contest/758/problem/B
 * Problem Status:		Accepted.
 */

package CodeForces.P758B_BlownGarland;

import java.util.*;

public class P758B_BlownGarland {
	
	static int Kr = 0;  static int Kb =0; static int Ky =0; static int Kg = 0;
	
	public static String SolverA(char[] Input) {
		int dead = 0;
		for(int i = 0 ; i < Input.length ; i++) {
			if(Input[i] == '!')
				dead++;
		}
		// ---------------------------------- SEPARATOR ----------------------------------
		while(dead != 0) {
			for(int h = 0 ; h < Input.length ; h++) {
				if(Input[h] == '!') {
					if(h >= 4) {
						if(Input[h-4] != '!') {
							Input[h] = Input[h-4];
							dead--;
							Update(Input[h]);
						}
					}
					if (h <= Input.length - 4 && Input[h] == '!') {
						if(Input[h+4] != '!') {
							Input[h] = Input[h+4];
							dead--;
							Update(Input[h]);
						}
					}
				}
			}
		}
		// ---------------------------------- SEPARATOR ----------------------------------
		return (Kr + " " + Kb + " " + Ky + " " + Kg);
	}
	
	public static void Update(char X) {
		if(X == 'R')
			Kr++;
		if(X == 'B')
			Kb++;
		if(X == 'Y')
			Ky++;
		if(X == 'G')
			Kg++;
	}
	
	public static void main(String[] args) {
		Scanner Reader = new Scanner(System.in);
		String Input = Reader.next();
		System.out.println(SolverA(Input.toCharArray()));
		Reader.close();
	}

}
