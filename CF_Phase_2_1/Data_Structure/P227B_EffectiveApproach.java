package Data_Structure;

/*
 * Problem Link: 	https://codeforces.com/problemset/problem/227/B
 * Problem Status: 	Accepted
 */

import java.util.*;
import java.awt.*;

public class P227B_EffectiveApproach {

	public static void main(String[] args) {
		Scanner S = new Scanner(System.in);
		int n = S.nextInt();
		int[] A = new int[n];
		Hashtable<Integer , Point> ht = new Hashtable<>(100000);
		for(int i = 0 ; i < n ; i++) {
			A[i] = S.nextInt();
			Point temp = new Point(i+1, n-i);
			ht.put(A[i], temp);
		}
		int m = S.nextInt();
		int[] q = new int[m];
		long Vasya = 0;
		long Petya = 0;
		for(int i = 0 ; i < m ; i++) {
			q[i] = S.nextInt();
			Vasya += ht.get(q[i]).x;
			Petya += ht.get(q[i]).y;
		}
		S.close();
		System.out.println(Vasya + " " + Petya);
	}

}
