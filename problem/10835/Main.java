import java.util.Scanner;

public class Main {
	private static int N;
	private static int[][] dp = new int[2001][2001];
	private static int[][] cards = new int[2001][2001];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		
		for(int i=0; i<2; i++)
			for(int j=0; j<N; j++)
				cards[i][j] = sc.nextInt();
		
		for(int i=0; i<=N; i++)
			for(int j=0; j<=N; j++)
				dp[i][j] = -1;
		
		System.out.println(go(0, 0));
		
		sc.close();
	}
	
	private static int go(int y, int x) {
		if(y > N || x > N) return 0;
		if(dp[y][x] != -1) return dp[y][x];
		int ret = Math.max(go(y+1, x), go(y+1, x+1));
		if(cards[0][y] > cards[1][x]) ret = Math.max(ret, go(y, x+1) + cards[1][x]);
		return dp[y][x] = ret;
	}
}
