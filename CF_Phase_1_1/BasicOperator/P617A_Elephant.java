/*
 * Problem Link:				https://codeforces.com/problemset/problem/617/A
 * Problem Status: 		Accepted
 */

package BasicOperator;

import java.util.*;

public class P617A_Elephant {

	public static void main(String[] args) {
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		Reader.close();
		int ans = 0;
		while(N > 0) {
			if(N >= 5) {
				ans++;
				N-=5;
			}
			else if(N >= 4) {
				ans++;
				N-=4;
			} else if(N >= 3) {
				ans++;
				N-=3;
			} else if(N >= 2) {
				ans++;
				N-=2;
			} else if(N >= 1) {
				ans++;
				N-=1;
			}
		}
		System.out.println(ans);
	}

}
