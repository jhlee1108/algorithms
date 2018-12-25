import java.util.Scanner;

public class Main {
	private static int T;
	private static long[][] dp = new long[10][65];
	
	public static void main(String[] args) {
		for(int i=0; i<10; i++)
			dp[i][1] = 1;
		for(int i=0; i<10; i++)
			go(i, 64);
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for(int t=1; t<=T; t++) {
			int n = sc.nextInt();
			long ans = 0;
			for(int i=0; i<10; i++)
				ans += dp[i][n];
			System.out.println(ans);
		}
		sc.close();
	}
	
	private static long go(int k, int n) {
		if(n <= 0) return 0;
		if(dp[k][n] > 0) return dp[k][n];
		long ret = 0;
		for(int i=k; i<10; i++)
			ret += go(i, n-1);
		dp[k][n] = ret;
		return ret;
	}
}
