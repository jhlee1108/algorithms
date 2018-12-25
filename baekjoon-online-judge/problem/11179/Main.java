import java.util.Scanner;

public class Main {
	private static int N;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		
		int ans = 0;
		while(N > 0) {
			ans = (ans | N%2) << 1;
			N = N >> 1;
		}
		
		System.out.println(ans >> 1);
		
		sc.close();
	}
}
