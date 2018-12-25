import java.util.Arrays;
import java.util.Scanner;

public class Main {
	private static int L, C;
	private static String[] word;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		L = sc.nextInt();
		C = sc.nextInt();
		sc.nextLine();
		word = sc.nextLine().split(" ");
		
		Arrays.sort(word);
		go("", 0);
		
		sc.close();
	}
	
	private static void go(String ans, int cnt) {
		if(ans.length() == L) {
			if(check(ans)) System.out.println(ans);
			return;
		}
		
		for(int i=cnt; i<=C-(L-ans.length()); i++)
			go(ans+word[i], i+1);
	}
	
	private static boolean check(String s) {
		int x = 0, y = 0;
		
		for(int i=0; i<s.length(); i++) {
			char c= s.charAt(i);
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') x++;
			else y++;
		}
		
		return x > 0 && y > 1;
	}
}
