/*
 * Problem Link:					https://codeforces.com/problemset/problem/151/B
 * Problem Status:				Accepted.
 */

package String;

import java.util.*;

public class P151B_PhoneNumbers {
	
	/*
	 * Taxi Numbers: 6 Identical Digits									22-22-22
	 * Pizza Deliveries: Decreasing Sequence						97-64-31
	 * Girls: Other																		99-87-93 / 12-34-56
	 */

	public static void main(String[] args) {
		// ---------------------------------- Variables ----------------------------------
		int N;
		String[] friends;
		Hashtable<String, String[]> Table;
		int temp;
		int MaxTaxi = 0;
		int MaxPizza = 0;
		int MaxGirls = 0;
		ArrayList<String> Taxi = new ArrayList<String>();
		ArrayList<String> Pizza = new ArrayList<String>();
		ArrayList<String> Girls = new ArrayList<String>();
		// -------------------------------- SEPARATOR --------------------------------
		Scanner Reader = new Scanner(System.in);
		N = Reader.nextInt();
		friends = new String[N];
		Table = new Hashtable<String, String[]>(N);
		for(int i = 0 ; i < N ; i++) {
			temp = Reader.nextInt();
			friends[i] = Reader.next();
			Table.put(friends[i], new String[temp]);
			for(int j = 0 ; j < temp ; j++) 
				Table.get(friends[i])[j] = Reader.next();
		}
		Reader.close();
		// -------------------------------- SEPARATOR --------------------------------
		for(int i = 0 ; i < N ; i++) {
			int[] TempArr = Categorize(Table.get(friends[i]));
			// ----------------------------------------------------
			if(TempArr[0] > MaxTaxi) {
				Taxi.clear();
				Taxi.add(friends[i]);
				MaxTaxi = TempArr[0];
			} else if(TempArr[0] == MaxTaxi)
				Taxi.add(friends[i]);
			// ----------------------------------------------------
			if(TempArr[1] > MaxPizza) {
				Pizza.clear();
				Pizza.add(friends[i]);
				MaxPizza = TempArr[1];
			} else if(TempArr[1] == MaxPizza)
				Pizza.add(friends[i]);
			// ----------------------------------------------------
			if(TempArr[2] > MaxGirls) {
				Girls.clear();
				Girls.add(friends[i]);
				MaxGirls = TempArr[2];
			} else if(TempArr[2] == MaxGirls)
				Girls.add(friends[i]);
			// ----------------------------------------------------
		}
		// -------------------------------- SEPARATOR --------------------------------
		showAnswer(Taxi, Pizza, Girls);
		// -------------------------------- SEPARATOR --------------------------------
	}
	
	public static void showAnswer(ArrayList<String> Taxi, ArrayList<String> Pizza, ArrayList<String>Girl) {
		String S1 = "If you want to call a taxi, you should call: ";
		String S2 = "If you want to order a pizza, you should call: ";
		String S3 = "If you want to go to a cafe with a wonderful girl, you should call: ";
		for(int i = 0 ; i < Taxi.size() ; i++)
			S1 += Taxi.get(i) + ", ";
		for(int i = 0 ; i < Pizza.size() ; i++)
			S2 += Pizza.get(i) + ", ";
		for(int i = 0 ; i < Girl.size() ; i++)
			S3 += Girl.get(i) + ", ";
		S1 = S1.substring(0, S1.length()-2);
		S2 = S2.substring(0, S2.length()-2);
		S3 = S3.substring(0, S3.length()-2);
		S1 += ".";
		S2 += ".";
		S3 += ".";
		System.out.println(S1);
		System.out.println(S2);
		System.out.println(S3);
	}
	
	public static void showHash(Hashtable<String, String[]> Table, String[] Names) {
		for(int i = 0 ; i < Names.length ; i++) {
			System.out.print(Names[i] + ": ");
			for(int j = 0 ; j < Table.get(Names[i]).length ; j++) {
				System.out.print(Table.get(Names[i])[j] + ", ");
			}
			System.out.println();
		}
	}
	
	public static int[] Categorize(String[] Nums) {
		int[] Ans = new int[3];										//		[Taxis, Pizza, Girls]
		for(int i = 0 ; i < Nums.length ; i++) {
			int Temp = getType(Nums[i]);
			if(Temp == 1)
				Ans[0]++;
			else if(Temp == 2)
				Ans[1]++;
			else
				Ans[2]++;
		}
		return Ans;
	}
	
	public static int getType(String S) {
		int Ans = 0;					// 1 > Taxi, 2 > Pizza, 3 > Girls
		char[] SPro = S.toCharArray();
		boolean TaxiFlag = true;
		boolean PizzaFlag = true;
		for(int i = 1 ; i < S.length() ; i++) {
			if(SPro[i] == '-')
				continue;
			else {
				if(SPro[i-1] == '-') {
					if(SPro[i] != SPro[i-2])
						TaxiFlag = false;
					if(SPro[i] >= SPro[i-2])
						PizzaFlag = false;
				} else {
					if(SPro[i] != SPro[i-1])
						TaxiFlag = false;
					if(SPro[i] >= SPro[i-1])
						PizzaFlag = false;
				}
			}
			if(!TaxiFlag && !PizzaFlag)
				break;
		}
		if(TaxiFlag)
			Ans = 1;
		else if(PizzaFlag)
			Ans = 2;
		else
			Ans = 3;
		return Ans;
	}
	

}
