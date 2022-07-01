package CodeForces.P242B_BigSegment;

/*
 * Problem Link: 		https://codeforces.com/problemset/problem/242/B
 * Problem Status: 		Accepted
 */

import java.util.*;
import java.awt.*;

public class P242B_BigSegment {

	public static void main(String[] args) {
		
		Scanner S= new Scanner(System.in);
		int n = S.nextInt();
		Point[] A = new Point[n];
		int ans = 1;
		Point Range = new Point();
		for(int i = 0 ; i < n ; i++) {
			A[i] = new Point();
			A[i].x = S.nextInt();
			A[i].y = S.nextInt();
			if(i == 0){
				Range.x = A[i].x;
				Range.y = A[i].y;
			} else {
				if(A[i].x < Range.x)
					Range.x = A[i].x;
				if(A[i].y > Range.y)
					Range.y = A[i].y;
				if(A[i].x == Range.x && A[i].y == Range.y)
					ans = i+1;
			}
		}
		S.close();
		if(A[ans-1].x == Range.x && A[ans-1].y == Range.y) {
			System.out.println(ans);
		} else {
			System.out.println(-1);
		}
	}

}
