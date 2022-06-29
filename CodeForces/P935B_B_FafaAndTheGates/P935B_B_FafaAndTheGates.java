/*
 * Problem Link: 	https://codeforces.com/problemset/problem/935/B
 * Status: 				Accepted.
 */

package CodeForces.P935B_B_FafaAndTheGates;

import java.util.*;
import java.awt.Point;

public class P935B_B_FafaAndTheGates {

	public static int MethodA(String seq) {
		int ans = 0;
		
		int i = 0;
		Point p = new Point(0,0);
		Point k = new Point(-1,-1);	
		
		/*		R		U		R		U		U		R
		 * 		0		1		2		3		4		5
		 * 		1,0	1,1		2,1	2,2	2,3	3,3
		 * 										+
		 */		
		
		
		while(i < seq.length()) {
			if(p.x == p.y) {
				if(seq.charAt(i) == 'U') {
					if(k.x > k.y) {
						ans++;
					}
				} else if(seq.charAt(i) == 'R') {
					if(k.y > k.x) {
						ans++;
					}
				}
			}
			if(seq.charAt(i) == 'U') {
				k.setLocation(p);
				p.setLocation(p.x, p.y+1);
			} else {
				k.setLocation(p);
				p.setLocation(p.x+1, p.y);
			}
			i++;
		}
		
		return ans;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String seq;
		Scanner sc = new Scanner(System.in);
		String len = sc.nextLine();
		seq = sc.nextLine();
		sc.close();
		System.out.println(MethodA(seq));
	}

}
