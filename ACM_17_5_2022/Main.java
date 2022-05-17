package Competitions.ACM_17_5_2022;

import java.util.*;
import java.io.*;

public class Main {
	
	/* 	
	 * ######################## Problem D ########################
	 * Status: Time limit exceeded on test 2 
	 */
	public static boolean searchString(String Input, char C) {
		boolean foundFlag = false;
		for(int i = 0 ; i < Input.length() ; i++) {
			if(Input.charAt(i) == C) {
				foundFlag = true;
				break;
			}
		}
//		System.out.println(Input + " -- " + C + " --- " + foundFlag);
		return foundFlag;
	}
	
	public static String removeChar(String Input, char C) {
		char[] Arr = Input.toCharArray();
		String ans = "";
		for(int i = 0 ; i < Input.length() ; i++) {
			if(Input.charAt(i) == C) {
				Arr[i] = ' ';
				break;
			}
		}
		for(int j = 0 ; j < Arr.length ; j++) {
			if(Arr[j] != ' ') {
				ans = ans + Arr[j];
			}
		}
//		System.out.println(Input + " " + ans);
		return ans;
	}
	
	public static void LongestPrefix(String[] input) {
		
		for(int i = 0 ; i < input.length / 2 ; i++) {	
			int h = 2*i ;
			int counter = 0;
			
			String principal = input[h];
			String auxiliary = input[h+1]; 
			
			for(int j = 0 ; j < principal.length() ; j++) {
				if(searchString( auxiliary , principal.charAt(j) ) ) {
					counter++;
					auxiliary = removeChar( auxiliary , principal.charAt(j) );
				} else {
					break;
				}
			}
			
			System.out.println(counter);
		}
		
	}

	/* 	
	 * ######################## Problem C ########################
	 * Status: Wrong Answer on test 5
	 */

	
//	public static void T_Prime(long[] input) {
//		for(int i = 0 ; i < input.length ; i++) {
//			int c = 2 ;
//			for(long j = 2  ; j < 10 && j < input[i] ; j++) {
//				if(c>3)
//					break;
//				if(input[i] % j == 0)
//					c++;
//			}
//			if(c == 3)
//				System.out.println("YES");
//			else
//				System.out.println("NO");
//		}
//	}
	
	
	/* 	
	 * ######################## Problem B ########################
	 * Status: Accepted
	 */
	
	
//	public static int SlimesCount(String in) {
//		int ans = 1;
//		for(int i = 1 ; i < in.length() ; i++) {
//			if(in.charAt(i) != in.charAt(i-1)) {
//				ans++;
//			}
//		}
//		return ans;
//	}
	
	
	/* 	
	 * ######################## Problem A ########################
	 * Status: Accepted
	 */
	
//	public static int cyclicShift(String in) {
//	int counter = 0;
//	String temp2 = "";
//		for(int i = 0 ; i < in.length() ; i++) {
//			String temp = "";
//			String tempC = "";
//			tempC = tempC + in.substring(0,i+1);
//			temp = temp + in.substring(i+1) + tempC;
//			if( temp2.contains(temp) )
//				continue;
//			counter++;
//			temp2 = temp2 + " " + temp;
//		}
//	return counter;
//}
	
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int arrLength = Integer.parseInt(sc.nextLine());
		
		String[] list = new String[arrLength * 2];
		for(int i = 0 ; i < arrLength ; i++) {
			String temp = (sc.nextLine());
			list[i*2] = temp.substring(0,temp.indexOf(' '));
			list[i*2 + 1] = temp.substring(temp.indexOf(' ') + 1 , temp.length());
		}
//		for(int i = 0 ; i < list.length ; i++) {
//			System.out.println(list[i]);
//		}
		LongestPrefix(list);
	
		
//		int arrLength = sc.nextInt();
//		long[] Arr = new long[arrLength];
//		for(int i = 0 ; i < arrLength ; i++) {
//			Arr[i] = sc.nextLong();
//		}
//		T_Prime(Arr);
		
//		int SlimesLength = Integer.parseInt(sc.nextLine()) ;
//		String Slimes = sc.nextLine();
		
//		String Input = sc.nextLine();
		
		sc.close();
		
//		System.out.println();
	}

}
