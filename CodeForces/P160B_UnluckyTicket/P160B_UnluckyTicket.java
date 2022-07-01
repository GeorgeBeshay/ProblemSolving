package CodeForces.P160B_UnluckyTicket;

/*
 * Problem Link:			https://codeforces.com/problemset/problem/160/B
 * Problem Status:		Accepted
 */

import java.util.*;

public class P160B_UnluckyTicket {

	public static void main(String[] args) {
		Scanner S = new Scanner(System.in);
		int n = S.nextInt();
		String tempText = S.next();
		S.close();
		char[] text = tempText.toCharArray();
		List<Integer> textPro1 = new ArrayList<>(n);
		List<Integer> textPro2 = new ArrayList<>(n);
		boolean Flag = true;				// true => YES, false => NO
		boolean lessThanFlag = true;
		for(int i = 0 ; i < n ; i++) {
			textPro1.add(Integer.parseInt(text[i]+""));
			textPro2.add(Integer.parseInt(text[i+n]+""));
		}
		Collections.sort(textPro1);
		Collections.sort(textPro2);
		if( textPro1.get(0) < textPro2.get(0) )
			lessThanFlag = true;
		else if ( textPro1.get(0) > textPro2.get(0) )
			lessThanFlag = false;
		else {
			System.out.println("NO");
			System.exit(0);
		}
		for(int i = 1 ; i < n ; i++) {
			if( textPro1.get(i) < textPro2.get(i) ) {
				if(!lessThanFlag) {
					Flag = false;
					break;
				}
				lessThanFlag = true;
			} else if(textPro1.get(i) > textPro2.get(i)) {
				if(lessThanFlag) {
					Flag = false;
					break;
				}
				lessThanFlag = false;
			} else {
				System.out.println("NO");
				System.exit(0);
			}
		}
		if (Flag)
			System.out.println("YES");
		else
			System.out.println("NO");
		
	}

}
