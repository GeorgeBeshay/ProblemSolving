/*
 * Problem Link:		https://codeforces.com/problemset/problem/988/B
 * Problem Status:	Accepted.
 */

package String;

import java.util.*;
import java.awt.*;

public class P988B_SubstringsSort {
	
	public static void SolverA(String[] Arr) {
		ArrayList<Point> StringLength = new ArrayList<Point>(Arr.length);
		for(int i = 0 ; i < Arr.length ; i++)
			StringLength.add( new Point(Arr[i].length(), i) );
		StringLength = QuickSort(StringLength);
		String[] Arr2 = new String[Arr.length];
		for(int i = 0 ; i < Arr.length ; i++)
			Arr2[i] = Arr[(int)StringLength.get(i).getY()];
		if(Check(Arr2)) {
			System.out.println("YES");
			for(int i = 0 ; i < Arr2.length ; i++) 
				System.out.println(Arr2[i]);
		} else 
			System.out.println("NO");
	}
	
	public static boolean Check(String[] Arr) {
		for(int i = 0 ; i < Arr.length-1 ; i++) {
			String tempA = Arr[i];
			String tempB = Arr[i+1];
			boolean Flag = false;
			for(int j = 0 ; j <= (tempB.length() - tempA.length()) ; j++) {
				if(tempB.substring(j, j+tempA.length()).equals(tempA)) {
					Flag = true;
					break;
				}
			}
			if (!Flag)
				return false;
		}
		return true;
	}
	
	public static ArrayList<Point> QuickSort(ArrayList<Point> Arr) {
		if (Arr.size() < 2)
			return Arr;
		else {
			Point Pivot = Arr.get(Arr.size()/2);
			ArrayList<Point> Pivot1 = new ArrayList<Point>(1);
			Pivot1.add(Pivot);
			ArrayList<Point> Less = new ArrayList<Point>();
			ArrayList<Point> Greater = new ArrayList<Point>();
			for(int i = 0 ; i < Arr.size() ; i++) {
				if(i == Arr.size()/2)
					continue;
				else {
					if(Arr.get(i).getX() <= Pivot.getX())
						Less.add(Arr.get(i));
					else
						Greater.add(Arr.get(i));
				}
			}
			ArrayList<Point> Final;
			Final = QuickSort(Less);
			Final.addAll(Pivot1);
			Greater = QuickSort(Greater);
			Final.addAll(Greater);
			return Final;
		}
	}

	public static void main(String[] args) {
		// -------------------------------- SEPARATOR --------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		String[] Arr = new String[N];
		for(int i = 0 ; i < N ; i++) 
			Arr[i] = Reader.next();
		Reader.close();
		SolverA(Arr);
		// -------------------------------- SEPARATOR --------------------------------
	}

}
