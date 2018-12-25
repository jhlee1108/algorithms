import java.util.Scanner;

public class Main {
	private static int A, I;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		A = sc.nextInt();
		I = sc.nextInt();
		
		System.out.println(A*(I-1) + 1);
		sc.close();
	}
}
