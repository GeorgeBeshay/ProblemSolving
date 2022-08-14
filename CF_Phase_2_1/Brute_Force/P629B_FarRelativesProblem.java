/*
 * Problem Link:				https://codeforces.com/problemset/problem/629/B
 * Problem Status:			Accepted.
 */

package Brute_Force;

import java.util.*;
import java.awt.*;

public class P629B_FarRelativesProblem {
	
	public static int PrimarySolverMethod(ArrayList<Point> M, ArrayList<Point> F) {
		int Answer = 0;
		int[] U = new int[366];
		// ---------------------------------- SEPARATOR ----------------------------------
		for(int i = 0 ; i < 366 ; i++) {
			int Ms = 0;
			int Fs = 0;
			int Min;
			// ---------------------------------- SEPARATOR ----------------------------------
			for(int j = 0 ; j < M.size() ; j++) 
				if(i+1 >= M.get(j).getX() && i+1 <= M.get(j).getY())
					Ms++;
			for(int j = 0 ; j < F.size() ; j++) 
				if(i+1 >= F.get(j).getX() && i+1 <= F.get(j).getY())
					Fs++;
			// ---------------------------------- SEPARATOR ----------------------------------
			if(Ms <= Fs)
				Min = Ms;
			else
				Min = Fs;
			// ---------------------------------- SEPARATOR ----------------------------------
			U[i] = Min * 2;
		}
		for(int i = 0 ; i < 366 ; i ++) {
			if(U[i] > Answer)
				Answer = U[i];
		}
		// ---------------------------------- SEPARATOR ----------------------------------
		return Answer;
	}

	public static void main(String[] args) {
		// ---------------------------------- SEPARATOR ----------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Integer.parseInt(Reader.nextLine());
		ArrayList<Point> Males = new ArrayList<Point>();
		ArrayList<Point> Females = new ArrayList<Point>();
		// ---------------------------------- SEPARATOR ----------------------------------
		for(int i = 0 ; i < N ; i++) {
			String Line = Reader.nextLine();
			char Char = Line.charAt(0);
			String[] Y = Line.substring(2).split(" ");
			int A = Integer.parseInt(Y[0]);
			int B = Integer.parseInt(Y[1]);
			Point P = new Point(A, B);
			if(Char == 'M')
				Males.add(P);
			else
				Females.add(P);
		}
		// ---------------------------------- SEPARATOR ----------------------------------
		Reader.close();
		// ---------------------------------- SEPARATOR ----------------------------------		
		System.out.println(PrimarySolverMethod(Males, Females));
		// ---------------------------------- SEPARATOR ----------------------------------
	}

}
