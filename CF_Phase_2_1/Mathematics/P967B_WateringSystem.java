/*
 * Problem Link:			https://codeforces.com/problemset/problem/967/B
 * Problem Status:		Accepted.
 */

package Mathematics;

import java.util.*;

public class P967B_WateringSystem {
	
	public static int SolverA(int[] Sizes, int A, int B) {
		int ans = 0;
		// --------------------------------------- SEPARATOR ---------------------------------------
		double S = Sizes[0] * A / B;
		S -= Sizes[0];
		int Counter = 1;
		ArrayList<Integer> SizesPro = new ArrayList<Integer>(Sizes.length-1);
		// --------------------------------------- SEPARATOR ---------------------------------------
		for(int i = 1 ; i < Sizes.length ; i++)
			SizesPro.add(Sizes[i]);
		Collections.sort(SizesPro);
		// --------------------------------------- SEPARATOR ---------------------------------------
		for(int i = 0 ; i < SizesPro.size() ; i++) {
			if(S - SizesPro.get(i) >= 0) {
				Counter++;
				S-= SizesPro.get(i);
			} else
				break;
		}
		// --------------------------------------- SEPARATOR ---------------------------------------
		ans = Sizes.length - Counter;
		// --------------------------------------- SEPARATOR ---------------------------------------
		return ans;
	}
	
	public static void main(String[] args) {
		// --------------------------------------- SEPARATOR ---------------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt(); int A = Reader.nextInt(); int B = Reader.nextInt();
		int[] Sizes = new int[N];
		for(int i = 0 ; i < N ; i++)
			Sizes[i] = Reader.nextInt();
		Reader.close();
		// --------------------------------------- SEPARATOR ---------------------------------------
		System.out.println(SolverA(Sizes, A, B));
		// --------------------------------------- SEPARATOR ---------------------------------------
	}
	
}
