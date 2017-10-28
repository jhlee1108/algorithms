import java.util.Arrays;
import java.util.Scanner;

public class Main {
	private static int N, S;
	private static int[] num = new int[20];
	private static boolean[] check = new boolean[20];
	private static int ans = 0;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		S = sc.nextInt();
		for(int i=0; i<N; i++)
			num[i] = sc.nextInt();
		Arrays.fill(check, false);
		
		go(0, 0);
		
		System.out.println(ans);
		sc.close();
	}
	
	private static void go(int sum, int cnt) {
		if(cnt == N) return;
		if(sum + num[cnt] == S) ans++;
		go(sum, cnt+1);
		go(sum + num[cnt], cnt+1);
	}
}
