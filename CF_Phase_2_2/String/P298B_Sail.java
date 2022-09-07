/*
 * Problem Link:			https://codeforces.com/problemset/problem/298/B
 * Problem Status:		Accepted.
 */

package String;

import java.util.*;
import java.awt.Point;

public class P298B_Sail {

	public static void main(String[] args) {
		// --------------------------------- Variables --------------------------------
		int T;
		Point S = new Point();
		Point E = new Point();
		String Directions;
		// ------------------------------- SEPARATOR -------------------------------
		Scanner Reader = new Scanner(System.in);
		T = Reader.nextInt();
		S.setLocation(Reader.nextInt(), Reader.nextInt());
		E.setLocation(Reader.nextInt(), Reader.nextInt());
		Directions = Reader.next();
		Reader.close();
		// ------------------------------- SEPARATOR -------------------------------
		System.out.println(TheAmazingFunction(T, Directions, S, E));
		// ------------------------------- SEPARATOR -------------------------------
	}
	
	public static int TheAmazingFunction(int T, String Directions, Point S, Point E) {
		int Answer = -1;
		char[] DirectionsPro = Directions.toCharArray();
		Hashtable<Character, Integer> Table = new Hashtable<Character, Integer>();
		char Var1 = '-';
		char Var2 = '-';
		// ------------------------------- SEPARATOR -------------------------------
		int[] Needed = {0, 0, 0, 0};					// {N, E, W, S}
		getNeededDirections(S, E, Needed);
		for(int i = 0 ; i < 4 ; i++) {
			if(Needed[i] != 0) {
				switch(i) {
					case 0:
						Table.put('N', Needed[i]);
						if(Var1 != '-')
							Var2 = 'N';
						else
							Var1 = 'N';
						break;
					case 1:
						Table.put('E', Needed[i]);
						if(Var1 != '-')
							Var2 = 'E';
						else
							Var1 = 'E';
						break;
					case 2:
						Table.put('W', Needed[i]);
						if(Var1 != '-')
							Var2 = 'W';
						else
							Var1 = 'W';
						break;
					case 3:
						Table.put('S', Needed[i]);
						if(Var1 != '-')
							Var2 = 'S';
						else
							Var1 = 'S';
						break;
					default:
						break;
				}
			}
		}
		for(int i = 0 ; i < Directions.length() ; i++) {
			if(DirectionsPro[i] == Var1)
				try {Table.put(Var1, Table.get(Var1)-1);} catch(Exception U) {}
			else if(DirectionsPro[i] == Var2)
				try {Table.put(Var2, Table.get(Var2)-1);} catch(Exception U) {}
			if(checkTable(Table)) {
				Answer = i+1;
				break;
			}
		}
		// ------------------------------- SEPARATOR -------------------------------
		return Answer;
	}
	
	public static boolean checkTable(Hashtable<Character, Integer> Table) {
		boolean ans = false;
		Enumeration<Character> E = Table.keys();
		while(E.hasMoreElements()) {
			char Temp = E.nextElement();
			if(Table.get(Temp) == 0)
				Table.remove(Temp);
		}
		if(Table.size() == 0)
			ans = true;
		return ans;
	}
	
	public static void getNeededDirections(Point S, Point E, int[] Needed) {
		if(E.getX() >= S.getX())
			Needed[1] = (int)(E.getX() - S.getX());
		else
			Needed[2] = (int)(S.getX() - E.getX());
		if(E.getY() >= S.getY())
			Needed[0] = (int)(E.getY() - S.getY());
		else
			Needed[3] = (int)(S.getY() - E.getY());
	}

}
