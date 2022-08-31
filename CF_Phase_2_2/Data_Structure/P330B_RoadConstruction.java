/*
 * Problem Link:				https://codeforces.com/problemset/problem/330/B
 * Problem Status:			Accepted.
 */

package Data_Structure;

import java.util.*;

public class P330B_RoadConstruction {

	public static void main(String[] args) {
		// ----------------------------- Problem Variables -----------------------------
		Scanner Reader;
		int N;
		int M;
		Hashtable<Integer, Integer> Banned;
		myNode[] Nodes;
		myNode TheAmazingNode = null;
		// ----------------------------- SEPARATOR -----------------------------
		Reader = new Scanner(System.in);
		N = Reader.nextInt();
		M = Reader.nextInt();
		Banned = new Hashtable<Integer, Integer>(M*2);
		for(int i = 0 ; i < M ; i ++) {
			Banned.put(Reader.nextInt(), 1);
			Banned.put(Reader.nextInt(), 1);
		}
		Nodes = new myNode[N];
		for(int i = 0 ; i < N ; i++) {
			Nodes[i] = new myNode(i+1, null);
			if(Banned.get(i+1) == null)
				TheAmazingNode = Nodes[i];
		}
		Reader.close();
		// ----------------------------- SEPARATOR -----------------------------
		myPrimaryFunction(Nodes, TheAmazingNode);
		// ----------------------------- SEPARATOR -----------------------------
	}
	
	public static void myPrimaryFunction(myNode[] Nodes, myNode TheAmazingNode) {
		// ----------------------------- SEPARATOR -----------------------------
		if(TheAmazingNode == null) {
			System.out.println("Error: No Amazing Node !!!");
			return;
		}
		// ------------------------------- Function Variables -------------------------------
		int RoadsCount = 0;
		ArrayList<Road> CityRoads = new ArrayList<Road>();
		// ------------------------------- SEPARATOR -------------------------------
		for(int i = 0 ; i < Nodes.length ; i++) {
			if(Nodes[i] == TheAmazingNode)
				continue;
			else {
				CityRoads.add(new Road(TheAmazingNode, Nodes[i]));
				RoadsCount++;
			}
		}
		// ------------------------------- SEPARATOR -------------------------------
		System.out.println(RoadsCount);
		printRoads(CityRoads);
		// ------------------------------- SEPARATOR -------------------------------
	}
	
	public static void printRoads(ArrayList<Road> CityRoads) {
		for(int i = 0 ; i < CityRoads.size() ; i++)
			System.out.println(CityRoads.get(i).getA().getNodeNumber() + " " + CityRoads.get(i).getB().getNodeNumber());
	}
	
}
	
	 class myNode {
		// -------- Class Fields --------
		int NodeNumber;
		ArrayList<myNode> AdjacentNodes;
		// -------- Class Constructor --------
		public myNode(int nodeNumber, ArrayList<myNode> adjacentNodes) {
			NodeNumber = nodeNumber;
			if(adjacentNodes == null)
				AdjacentNodes = new ArrayList<myNode>();
			else
				AdjacentNodes = adjacentNodes;
		}
		// -------- Class Setters & Getters --------
		public int getNodeNumber() {
			return NodeNumber;
		}
		public void setNodeNumber(int nodeNumber) {
			NodeNumber = nodeNumber;
		}
		public ArrayList<myNode> getAdjacentNodes() {
			return AdjacentNodes;
		}
		public void setAdjacentNodes(ArrayList<myNode> adjacentNodes) {
			AdjacentNodes = adjacentNodes;
		}
		// -------- Separator --------
	}
	
	class Road {
		// -------- Class Fields --------
		myNode A;
		myNode B;
		// -------- Class Constructor --------
		public Road(myNode a, myNode b) {
			A = a;
			B = b;
			A.AdjacentNodes.add(B);
			B.AdjacentNodes.add(A);
		}
		// -------- Class Setters & Getters --------
		public myNode getA() {
			return A;
		}
		public void setA(myNode a) {
			A.AdjacentNodes.remove(B);
			A = a;
			A.AdjacentNodes.add(B);
		}
		public myNode getB() {
			return B;
		}
		public void setB(myNode b) {
			B.AdjacentNodes.remove(A);
			B = b;
			B.AdjacentNodes.add(A);
		}
		// -------- Separator --------
	}
