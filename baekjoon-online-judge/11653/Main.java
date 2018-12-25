import java.util.Scanner;

public class Main {
	private static int N;
	private static boolean check[];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		check = new boolean[N+1];
		
		for(int i=2; i<=Math.sqrt(N); i++) {
			if(check[i]) continue;
			for(int j=i+i; j<=N; j+=i)
				check[j] = true;
		}
		
		for(int i=2; i<=N; i++)
			if(!check[i])
				while(N > 0 && N % i == 0) {
					System.out.println(i);
					N /= i;
				}
		
		sc.close();
	}
}
