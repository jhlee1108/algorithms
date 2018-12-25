import java.util.Arrays;
import java.util.Scanner;

public class Main {
	private static boolean[] prime = new boolean[1000001];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Arrays.fill(prime,  true);
		
		prime[0] = prime[1] = false;
		for(int i=2; i<=Math.sqrt(1000000); i++) {
			if(!prime[i]) continue;
			for(int j=i+i; j<=1000000; j+=i)
				prime[j] = false;
		}
		
		while(true) {
			int n = sc.nextInt();
			if(n == 0) break;
			boolean flag = true;
			
			for(int i=2; i<=n/2; i++)
				if(prime[i] && prime[n-i]) {
					System.out.println(n + " = " + i + " + " + (n-i));
					flag = false;
					break;
				}
			
			if(flag) System.out.println("Goldbach's conjecture is wrong.");
		}
		
		sc.close();
	}
}
