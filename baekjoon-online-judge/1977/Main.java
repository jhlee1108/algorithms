import java.util.Scanner;

public class Main {
	private static int M, N;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		M = sc.nextInt();
		N = sc.nextInt();
		
		int sum = 0;
		int min = 100000;
		boolean isExist = false;
		for(int i=1; i<=100; i++) {
			int x = i*i;
			if(M <= x && x <= N) {
				sum += x;
				min = Math.min(x, min);
				isExist = true;
			}
		}
		
		if(isExist) System.out.println(sum + "\n" + min);
		else System.out.println(-1);
		sc.close();
	}
}
