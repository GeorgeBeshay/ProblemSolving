/*
 * Problem Link:			https://codeforces.com/problemset/problem/432/B
 * Problem Status:		Accepted.
 */

package Data_Structure;

import java.awt.Point;
import java.util.*;

public class P432B_FootballKit {
	
	public static void solvingFunctionA(Point[] A) {
		Point[] Answers = new Point[A.length];
		Hashtable<Integer, Integer> HomeKits = new Hashtable<Integer, Integer>(A.length);
		// ------------------------------------ SEPARATOR ------------------------------------
		for(int i = 0 ; i < A.length ; i++) {
			Answers[i] = new Point();
			if(HomeKits.get((int)A[i].getX()) != null)
				HomeKits.put((int)A[i].getX(), (int)HomeKits.get((int)A[i].getX())+1);
			else
				HomeKits.put((int)A[i].getX(), 1);
		}
		// ------------------------------------ SEPARATOR ------------------------------------
		for(int i = 0 ; i < A.length ; i++) {
			int AT1 = (int)A[i].getY();
			if(HomeKits.get(AT1) != null)
				Answers[i].setLocation(A.length-1+HomeKits.get(AT1), A.length-1-HomeKits.get(AT1));
			else
				Answers[i].setLocation(A.length-1, A.length-1);
		}
		// ------------------------------------ SEPARATOR ------------------------------------
		for(int i = 0 ; i < A.length ; i++)
			System.out.println((int)Answers[i].getX() + " " + (int)Answers[i].getY());
		// ------------------------------------ SEPARATOR ------------------------------------
	}

	public static void main(String[] args) {
		// ------------------------------------ SEPARATOR ------------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		Point[] Arr = new Point[N];
		for(int i = 0 ; i < N ; i++) {
			int X = Reader.nextInt();
			int Y = Reader.nextInt();
			Arr[i] = new Point(X, Y);
		}
		Reader.close();
		// ------------------------------------ SEPARATOR ------------------------------------
		solvingFunctionA(Arr);
		// ------------------------------------ SEPARATOR ------------------------------------
	}

}
