/*
 * Problem Link: 			https://codeforces.com/problemset/problem/569/B
 * Problem Status:			Accepted.
 */

package Data_Structure;

import java.util.*;

public class P569B_Inventory {
	
	public static void solvingFunctionA(int[] Arr) {
		// -------------------------------- SEPARATOR --------------------------------
		Hashtable<Integer, Integer> NumbersCounter = new Hashtable<Integer, Integer>(Arr.length);
		HashSet<Integer> MissingNumbersPro = new HashSet<Integer>();
		ArrayList<Integer> Ans = new ArrayList<Integer>(Arr.length); 
		// -------------------------------- SEPARATOR --------------------------------
		for(int i = 1 ; i <= Arr.length ; i++) 
			NumbersCounter.put(i, 0);
		for(int i = 0 ; i < Arr.length ; i++)
			if(Arr[i] <= Arr.length && Arr[i] >= 1 )
				NumbersCounter.put(Arr[i], NumbersCounter.get(Arr[i])+1);
		for(int i = 1 ; i <= Arr.length ; i++)
			if(NumbersCounter.get(i) == 0)
				MissingNumbersPro.add(i);
		for(int i = 1 ; i <= Arr.length ; i++) 
			NumbersCounter.put(i, 0);
		// -------------------------------- SEPARATOR --------------------------------
		Iterator<Integer> it = MissingNumbersPro.iterator();
		// -------------------------------- SEPARATOR --------------------------------
		for(int i  = 0 ; i < Arr.length ; i++) {
			// -------------------------------- SEPARATOR --------------------------------
			if(Arr[i] >= 1 && Arr[i] <= Arr.length) {
				if(NumbersCounter.get(Arr[i]) == 0) {
					Ans.add(Arr[i]);
					NumbersCounter.put(Arr[i], 1);
				} else 
					Ans.add(it.next());
			}
			// -------------------------------- SEPARATOR --------------------------------
			else 
				Ans.add(it.next());
			// -------------------------------- SEPARATOR --------------------------------
		}
		// -------------------------------- SEPARATOR --------------------------------
		showList(Ans);
	}
	
	public static void showList(ArrayList<Integer> A) {
		for(int i = 0 ; i < A.size() ; i++) 
			System.out.print(A.get(i) + " ");
	}

	public static void main(String[] args) {
		// -------------------------------- SEPARATOR --------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int[] A = new int[N];
		for(int i = 0 ; i < N ; i++)
			A[i] = Reader.nextInt();
		Reader.close();
		// -------------------------------- SEPARATOR --------------------------------
		solvingFunctionA(A);
		// -------------------------------- SEPARATOR --------------------------------
	}

}
