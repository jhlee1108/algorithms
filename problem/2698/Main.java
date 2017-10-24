import java.util.Scanner;

public class Main {
	private static int T, n, k;
	private static int dp[][][] = new int[2][101][101];
	
    public static void main(String[] args) {
		dp[0][1][0] = 1;
		dp[1][1][0] = 1;
		for(int y=2; y<=100; y++) {
			for(int z=0; z<y; z++) {
				dp[0][y][z] = dp[0][y-1][z] + dp[1][y-1][z];
				if(z > 0) dp[1][y][z] = dp[0][y-1][z] + dp[1][y-1][z-1];
				else dp[1][y][z] = dp[0][y-1][z];
			}
		}
		
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for(int t=1; t<=T; t++) {
			n = sc.nextInt();
			k = sc.nextInt();
			System.out.println(dp[0][n][k] + dp[1][n][k]);
		}
		sc.close();
	}
}
