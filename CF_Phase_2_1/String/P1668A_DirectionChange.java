package String;

// https://codeforces.com/problemset/problem/1668/A
// Status: Accepted

import java.util.*;
import java.awt.Point;

public class P1668A_DirectionChange {
	
	public static int changeDirectionPro2(int n, int m) {
		
		if(n*m == n || n*m == m) {
			if (n*m > 2) {
				return -1;
			} else {
				if(n*m == 2) {
					return 1;
				}
			}
		}
		
		int ans = 0;
		
		if(n == m) {
			ans = 2*(n - 1);
		} else {
			int min = Math.min(n, m);
			int max = Math.max(n, m);
			ans = 2*(min-1);
			if((max-min)%2 == 0) {
				ans += 2*(max-min);
			} else {
				ans += 2*(max-min-1) + 1;
			}
		}
		
		return ans;
	}
	
//	public static int changeDirectionPro(int n, int m) {
//		if(n*m == n || n*m == m) {
//			if (n*m > 2) {
//				return -1;
//			}
//		}
//		int ans = recursionMethod(1,1,n,m,-1,0,0);
//		return ans;
//	}
//	public static int recursionMethod(int i, int j, int n, int m,int LastDirection, int LastI, int LastJ) {		// 4, 6
//		// Last Direction Codes:
//		// 0 >> East
//		// 1 >> South
//		// 2 >> West
//		// 3 >> North
//		// Priority should depend on the current location, i & j
//		// if the point is currently in the last row, then probably it should move
//		// to the East and North as a Priority not South and East
//		// on the other hand if it is in the last column then the point should  move
//		// South and West
//		// Else, South and East.
//		System.out.println("t");
//		int ans = 0;
//		if(i == n && j == m)
//			return 0;
//		
//		if(LastDirection != 1 && i+1 <= n && LastI != i+1) {				// South
//			ans = 1 + recursionMethod(i+1,j,n,m,1,i,j);
//		} else if (LastDirection != 0 && j+1 <= m && LastJ != j+1) {	// East
//			ans = 1 + recursionMethod(i,j+1,n,m,0,i,j);
//		} else if (LastDirection != 3 && i-1 >= 1 && LastI != i-1) {		// North
//			ans = 1 + recursionMethod(i-1,j,n,m,3,i,j);
//		} else if (LastDirection != 2 && j-1 >= 1 && LastJ != j-1) {		// West
//			ans = 1 + recursionMethod(i,j-1,n,m,2,i,j);
//		}
//		return ans;
//	}

//	public static int changeDirection(int n, int m) {
//		
//		if(n*m == n || n*m == m) {
//			if (n*m > 2) {
//				return -1;
//			}
//		}
//		
//		List <Point> PPList = new ArrayList<Point>(); // Passed Points List
//		int i = 1, j = 1;												// Current Location
//		int ans = 0;													// Number of Moves.
//		int lastMove = -2;
//		Point pt1 = new Point();
//		Point pt2 = new Point();
//		Point pt3 = new Point();
//		Point pt4 = new Point();
//		
//		int h = 0;
//		
//		while(i != n || j != m) {
//											// 2,2
//			pt1.setLocation(i,j+1);	// 2,3
//			pt2.setLocation(i+1,j);	// 3,2
//			pt3.setLocation(i,j-1);	// 2,1
//			pt4.setLocation(i-1,j);	// 1,2
//			
////			if(			j+1 <= m 		&& 		lastMove != 0 	&&	!PPList.contains(pt1) 	) {
////				j++;
////				ans++;
////				lastMove = 0;
////				PPList.add((Point)pt1.clone());
////				System.out.println(h);}
//			if (		i+1 <= n	&& 		lastMove != 1 	&&	!PPList.contains(pt2)	) {
//				i++;
//				ans++;
//				lastMove = 1;
//				PPList.add((Point)pt2.clone());
////				System.out.println(h);
//			} 
//			else if(			j+1 <= m 		&& 		lastMove != 0 	&&	!PPList.contains(pt1) 	) {
//				j++;
//				ans++;
//				lastMove = 0;
//				PPList.add((Point)pt1.clone());
////				System.out.println(h);
//			}
//			else if (		j-1 >= 1 		&& 		lastMove != 2 	&&	!PPList.contains(pt3)	) {
//				j--;
//				ans++;
//				lastMove = 2;
//				PPList.add((Point)pt3.clone());
////				System.out.println(h);
//			} else if (		i-1 >= 1	&& 		lastMove != 3 	&&	!PPList.contains(pt4)	) {
//				i--;
//				ans++;
//				lastMove = 3;
//				PPList.add((Point)pt4.clone());
////				System.out.println(h);
//			}
////			System.out.println(PPList.toString());	
////			System.out.println(PPList.get(PPList.size()-1));
////			
////			h++;
////			if(h == 10)
////				break;
//		}
//		
////		System.out.println(PPList.toString());	
//		return ans;
//	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int NoOfTests = Integer.parseInt(sc.nextLine());
		String temp;
		int tempN = 0;
		int tempM= 0;
		while(NoOfTests > 0) {
			temp = sc.nextLine();
			tempN = Integer.parseInt(temp.substring(0, temp.indexOf(" ")));
			tempM = Integer.parseInt(temp.substring(temp.indexOf(" ")+1, temp.length()));
//			System.out.println(changeDirection(tempN,tempM));
//			System.out.println(changeDirectionPro(tempN,tempM));
			System.out.println(changeDirectionPro2(tempN,tempM));
			NoOfTests--;
		}
	}

}
