/*
 * Problem Link:			https://codeforces.com/contest/902/problem/B
 * Problem Status: 	Accepted
 */

package Data_Structure;

import java.util.*;

public class P902B_ColoringATree {
	
	public static void main(String[] args) {
		Node Root = new Node(null, 1);
		Hashtable<Integer, ArrayList<Integer>> ColorTable = new Hashtable<Integer, ArrayList<Integer>>();
//		ArrayList<ArrayList<Integer>> DegreeToNodeTable = new ArrayList<ArrayList<Integer>>();
		int MaxDegree = 0;
		// ----------------------------------------- SEPARATOR -----------------------------------------
		Scanner Reader = new Scanner(System.in);
		int N = Reader.nextInt();
		int[] ColorArray = new int[N];
		Hashtable<Integer, Node> Table = new Hashtable<Integer, Node>(N);
		Table.put(1, Root);
		// ----------------------------------------- SEPARATOR -----------------------------------------
		for(int i = 2 ; i < N+1 ; i++) {
			Table.put(i, new Node(Table.get(Reader.nextInt()), i));
			if(Table.get(i).getDegree() > MaxDegree)
				MaxDegree = Table.get(i).getDegree();
		}
		ArrayList<Integer>[] DegreeToNodeTable = new ArrayList[MaxDegree+1];
		for(int i = 0 ; i < DegreeToNodeTable.length ; i++) {
			DegreeToNodeTable[i] = new ArrayList<Integer>();
		}
		// ----------------------------------------- SEPARATOR -----------------------------------------
		for(int i = 0 ; i < N ; i++) {
			DegreeToNodeTable[Table.get(i+1).getDegree()].add(i+1);
			int Temp = Reader.nextInt();
			ColorArray[i] = Temp;
			if(ColorTable.get(Temp) == null) {
				ArrayList<Integer> tempList = new ArrayList<Integer>();
				tempList.add(i+1);
				ColorTable.put(Temp, tempList);
			}
			// ----------------------------------------- SEPARATOR -----------------------------------------
			else {
				ArrayList<Integer> tempList = ColorTable.get(Temp);
				tempList.add(i+1);
				ColorTable.put(Temp, tempList);
			}
			// ----------------------------------------- SEPARATOR -----------------------------------------
		}
		Reader.close();
		// ---------------------- Checking That The Input Was Scanned Correctly. ----------------------
		// Checking That The Input Was Scanned Correctly.
//		for(int i = 0 ; i < N ; i++) {
//			Table.get(i+1).printInfo();
//		}
//		showArray(ColorArray);
//		for(int i = 0 ; i < DegreeToNodeTable.length ; i++) {
//			System.out.println((i+1) + ": " + DegreeToNodeTable[i].toString());
//		}
//		Enumeration<Integer> E = ColorTable.keys();
//		for(int i = 0 ; i < N ; i++) {
//			if(!E.hasMoreElements())
//				break;
//			int tempColor = E.nextElement();
//			System.out.println((tempColor) + ": " + ColorTable.get(tempColor).toString());
//		}
		// ----------------------------------------- Solution -----------------------------------------
		int Answer = 0;
		for(int i = 0 ; i < DegreeToNodeTable.length ; i++) {
			for(int j = 0 ; j < DegreeToNodeTable[i].size() ; j++) {
				if( Table.get(DegreeToNodeTable[i].get(j)).getColor() != ColorArray[DegreeToNodeTable[i].get(j)-1] ) {
					Answer++;
					Table.get(DegreeToNodeTable[i].get(j)).setColor(ColorArray[DegreeToNodeTable[i].get(j)-1]);
				}
			}
		}
		// ----------------------------------------- Answer -----------------------------------------
		System.out.println(Answer);
	}
	
	public static void showArray(int[] A) {
		for(int i = 0 ; i < A.length ; i++)
			System.out.print(A[i] + " ");
		System.out.println();
	}

}


class Node {
	// Fields
	private Node P;
	private ArrayList<Node> S = new ArrayList<Node>();
	private int Number;
	private int Color;
	// Constructor
	public Node(Node p, int number) {
		P = p;
		Number = number;
		Color = 0;
		if(p != null)
			p.getS().add(this);
	}
	// Methods
	public Node getP() {
		return P;
	}
	public void setP(Node p) {
		P = p;
	}
	public ArrayList<Node> getS() {
		return S;
	}
	public void setS(ArrayList<Node> s) {
		S = s;
	}
	public int getNumber() {
		return Number;
	}
	public void setNumber(int number) {
		Number = number;
	}
	public int getColor() {
		return Color;
	}
	public void setColor(int color) {
		Color = color;
		if(this.getS().size() != 0) {
			for(int i = 0 ; i < this.getS().size() ; i++) {
				this.getS().get(i).setColor(color);
			}
		}
	}
	public int getDegree() {
		int Answer = 0;
		Node Current = this;
		while(Current.getP() != null) {
			Current = Current.getP();
			Answer++;
		}
		return Answer;
	}
	public void printInfo() {
		if(this.getP() != null)
			System.out.println( "Node Number: " + this.getNumber() + " - Parent: " + this.getP().getNumber() + " - Degree: " + this.getDegree() );
		else
			System.out.println("Node Number: " + this.getNumber() + " - Parent: Nulll" + " - Degree: " + this.getDegree());
	}
	// ------------------------------------ SEPARATOR ------------------------------------
}