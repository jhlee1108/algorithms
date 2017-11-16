import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	private static int N, M;
	private static BigInteger dp[][];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		dp = new BigInteger[101][101];
		N = sc.nextInt();
		M = sc.nextInt();
		
		System.out.println(combination(N, M));
	}
	
	private static BigInteger combination(int n, int m) {
		if(n == m || m == 0) return new BigInteger("1");
		if(dp[n][m] != null) return dp[n][m];
		return dp[n][m] = combination(n-1, m-1).add(combination(n-1, m));
	}
}
