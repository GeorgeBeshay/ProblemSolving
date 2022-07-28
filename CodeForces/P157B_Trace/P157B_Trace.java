/*
 * Problem Link: 		https://codeforces.com/problemset/problem/157/B
 * Problem Status: 	Accepted.
 */

package CodeForces.P157B_Trace;

import java.util.*;

public class P157B_Trace {
	
	public static double SolverA(ArrayList<Integer> CirclesRadii) {
		// --------------------------------------------- SEPARATOR ---------------------------------------------
		double Answer = 0;
		Collections.sort(CirclesRadii);
		Object[] A = CirclesRadii.toArray();
		boolean redFlag = true;
		// --------------------------------------------- SEPARATOR ---------------------------------------------
		for(int i = A.length-1 ; i >= 0 ; i--) {
			if(redFlag) {
				Answer += Math.PI * Math.pow((int)(A[i]), 2);
				redFlag = false;
			} else {
				Answer -= Math.PI * Math.pow((int)(A[i]), 2);
				redFlag = true;
			}
		}
		// --------------------------------------------- SEPARATOR ---------------------------------------------
		return Answer;
		// --------------------------------------------- SEPARATOR ---------------------------------------------
	}

	public static void main(String[] args) {
		// --------------------------------------------- SEPARATOR ---------------------------------------------
		Scanner Reader = new Scanner(System.in);
		int NumberOfCircles = Reader.nextInt();
		ArrayList<Integer> CirclesRadii = new ArrayList<Integer>();
		for(int i = 0 ; i < NumberOfCircles ; i++)
			CirclesRadii.add(Reader.nextInt());
		Reader.close();
		// --------------------------------------------- SEPARATOR ---------------------------------------------
		System.out.println(SolverA(CirclesRadii));
		// --------------------------------------------- SEPARATOR ---------------------------------------------
	}

}
