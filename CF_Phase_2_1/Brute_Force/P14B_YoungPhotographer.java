/*
 * Problem Link:			https://codeforces.com/problemset/problem/14/B
 * Problem Status:		Accepted.
 */

package Brute_Force;

import java.util.*;
import java.awt.*;

public class P14B_YoungPhotographer {
	
	public static int JuniorSolverMethod(Point[] A, int X) {
		int Answer = 0;
		Point SmallestIntersection;
		// ---------------------------------- SEPARATOR ----------------------------------
		if(A[0].getX() <= A[0].getY())
			SmallestIntersection = new Point((int)A[0].getX(), (int)A[0].getY());
		else
			SmallestIntersection = new Point((int)A[0].getY(), (int)A[0].getX());
		// ---------------------------------- SEPARATOR ----------------------------------
		int Min;
		int Max;
		// ---------------------------------- SEPARATOR ----------------------------------
		for(int i = 1 ; i < A.length ; i++) {
			if(A[i].getX() <= A[i].getY()) {
				Min = (int)A[i].getX();
				Max = (int)A[i].getY();
			} else {
				Min = (int)A[i].getY();
				Max = (int)A[i].getX();
			}
			// ---------------------------------- SEPARATOR ----------------------------------
			if( (Min < SmallestIntersection.getX() && Max < SmallestIntersection.getX()) || (Min > SmallestIntersection.getY() && Max > SmallestIntersection.getY()) )
				return -1;
			// ---------------------------------- SEPARATOR ----------------------------------
			if(Min > SmallestIntersection.getX()) 
				SmallestIntersection.setLocation(Min, SmallestIntersection.getY());
			if(Max < SmallestIntersection.getY()) 
				SmallestIntersection.setLocation(SmallestIntersection.getX(), Max);
		}
		// ---------------------------------- SEPARATOR ----------------------------------
		if(X >= SmallestIntersection.getX() && X <= SmallestIntersection.getY())
			Answer = 0;
		else
			Answer = Math.abs(X - GetMinEdgeToBeInBetween((int) SmallestIntersection.getX(), (int)SmallestIntersection.getY(), X));
		// ---------------------------------- SEPARATOR ----------------------------------
		return Answer;
	}

	public static int GetMinEdgeToBeInBetween(int A, int B, int X) {
		int Answer = 0;
		// ---------------------------------- SEPARATOR ----------------------------------
		if(Math.abs(A - X) <= Math.abs(B - X))
			Answer = A;
		else
			Answer = B;
		// ---------------------------------- SEPARATOR ----------------------------------
		return Answer;
	}

	public static void main(String[] args) {
		// ---------------------------------- SEPARATOR ----------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int X = Reader.nextInt();
		Point[] A = new Point[N];
		for(int i = 0 ; i < N ; i++) {
			int TempX = Reader.nextInt();
			int TempY = Reader.nextInt();
			A[i] = new Point(TempX, TempY);
		}
		Reader.close();
		// ---------------------------------- SEPARATOR ----------------------------------
		System.out.println(JuniorSolverMethod(A, X));
		// ---------------------------------- SEPARATOR ----------------------------------
	}

}
