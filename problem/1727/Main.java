import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	private static ArrayList<Integer>[] score = new ArrayList[2];
	private static int[][] dp = new int[1000][1000];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		for(int i=0; i<2; i++)
			score[i] = new ArrayList<Integer>();
		
		for(int i=0; i<n; i++) {
			int x = sc.nextInt();
			score[0].add(x);
		}
		
		for(int i=0; i<m; i++) {
			int x = sc.nextInt();
			score[1].add(x);
		}
		
		Collections.sort(score[0]);
		Collections.sort(score[1]);
		
		go(n, m);
		
		sc.close();
	}
	
	private static void go(int n, int m) {
		int man = 0, woman = 1;
		if(n > m) {
			man ^= woman; woman ^= man; man ^= woman;
			n ^= m; m ^= n; n ^= m;
		}
		
		dp[0][0] = Math.abs(score[0].get(0) - score[1].get(0));
		for(int i=1; i<n; i++)
			dp[i][0] = Math.min(dp[i-1][0], Math.abs(score[man].get(i) - score[woman].get(0)));
		for(int i=1; i<m; i++)
			dp[0][i] = Math.min(dp[0][i-1], Math.abs(score[man].get(0) - score[woman].get(i)));
			
		for(int i=1; i<n; i++)
			for(int j=1; j<m; j++) {
				dp[i][j] = dp[i-1][j-1] + Math.abs(score[man].get(i) - score[woman].get(j));
				if(i < j) dp[i][j] = Math.min(dp[i][j-1], dp[i][j]);
			}

		System.out.println(dp[n-1][m-1]);
	}
	
}
