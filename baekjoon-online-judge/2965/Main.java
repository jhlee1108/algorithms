import java.util.Scanner;

public class Main {
	private static int A, B, C;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		A = sc.nextInt();
		B = sc.nextInt();
		C = sc.nextInt();
				
		System.out.println(Math.max(B-A-1, C-B-1));
		sc.close();
	}
}
