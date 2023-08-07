package LeetCode._20_5_22;

/*
 * Problem Link:				https://leetcode.com/problems/unique-paths-ii/
 * Problem Status: 			Accepted.
 */
public class Solution {

	public int uniquePathsWithObstacles(int[][] obstacleGrid) {	
        for(int i = 0 ; i < obstacleGrid.length ; i++) {
        	for(int j = 0 ; j < obstacleGrid[0].length ; j++) {
        		if(obstacleGrid[i][j] == 1) {
        			if(i == 0 && j == 0)
        				return 0;
        			obstacleGrid[i][j] = 0;
        			continue;
        		}
        		if(i == 0 && j == 0) {
        				obstacleGrid[i][j] = 1;
        		} else if (i == 0 && j != 0) {			// first row
        			obstacleGrid[i][j] = obstacleGrid[i][j-1]; 
        		} else if (j == 0 && i != 0) {
        			obstacleGrid[i][j] = obstacleGrid[i-1][j];
        		} else {
        			if (obstacleGrid[i][j] != 1)
        				obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
        			else 
        				obstacleGrid[i][j] = 0;
        		}
        	}
        }
        
//        for(int i = 0 ; i < obstacleGrid.length ; i++) {
//        	for(int j = 0 ; j < obstacleGrid[0].length ; j++) {
//        		System.out.print(obstacleGrid[i][j]);
//        	}
//        	System.out.print("\n");
//        }
        
        return obstacleGrid[obstacleGrid.length-1][obstacleGrid[0].length-1];     
    }
	
//	public int recursionMethod(int[][] obstacleGrid, int i, int j) {
//		if(i >= obstacleGrid.length || j >= obstacleGrid[0].length) {			// To overcome getting out of the boundaries of the 2D Array.
//			return 0;
//		}
//		if(i == obstacleGrid.length-1 && j == obstacleGrid[0].length-1 && obstacleGrid[i][j] == 0) {
//			return 1;																					// Base Case 1, Arrived.
//		} else {
//			if (obstacleGrid[i][j] == 1)
//				return 0;																			// Base Case 2, Obstacle was found.
//			else {
//				return ( recursionMethod(obstacleGrid,i, j+1) + recursionMethod(obstacleGrid, i+1, j) );	
//			}
//		}
//	}
	
//	public int recursionMethod2(int[][] obstacleGrid, int i, int j) {
//		if(obstacleGrid[0][0] == 1)
//			return 0;
//		if(i == obstacleGrid.length-1 && j == obstacleGrid[0].length-1 && obstacleGrid[i][j] == 0) {
//			return 1;																					// Base Case 1, Arrived.
//		} else {
//			if( !(i+1 >= obstacleGrid.length) && obstacleGrid[i+1][j] != 1) {			// if true, you can move south
//				if(!(j+1 >= obstacleGrid[0].length) && obstacleGrid[i][j+1] != 1) {	// if true, you can move east
//					return ( recursionMethod2(obstacleGrid ,i+1,j) + recursionMethod2(obstacleGrid, i,j+1) );	// move east and south
//				} else {	
//					return ( recursionMethod2(obstacleGrid ,i+1,j) );															// move south only.
//				}
//			} else {
//				if(!(j+1 >= obstacleGrid[0].length) && obstacleGrid[i][j+1] != 1) {	// if true, you can move east
//					return ( recursionMethod2(obstacleGrid, i,j+1) );	// move east only.
//				} else {	
//					return (0);															// No path.
//				}
//			}
//		}
//	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

//		int[][] obstacleGrid = {
//				{0,0,0},
//				{0,1,0},
//				{0,0,0}
//				};
		
//		int[][] obstacleGrid = {
//				{0,1},
//				{0,0},
//				};
		
//		Solution sol = new Solution();
//		System.out.println(sol.uniquePathsWithObstacles(obstacleGrid));
	}

}
