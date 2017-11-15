import java.util.Scanner;

public class Main {
	private static int N;
	private static int cnt[];
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		N = Integer.parseInt(sc.nextLine());
		
		cnt = new int[26];
		for(int i=0; i<N; i++) {
			String name = sc.nextLine();
			cnt[name.charAt(0)-'a']++;
		}
		
		boolean fivePlayers = false;
		for(int i=0; i<26; i++)
			if(cnt[i] >= 5) {
				fivePlayers = true;
				System.out.print((char)(i+'a'));
			}
		if(!fivePlayers) System.out.print("PREDAJA");
		System.out.println("");
		
		sc.close();
	}
}
