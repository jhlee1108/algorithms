import java.util.Scanner;

public class Main {
	private static char input[];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		input = sc.nextLine().toCharArray();
		
		for(int i=0; i<input.length; i++) {
			char c = input[i];
			if('a' <= c && c <= 'z') c -= 32;
			else c += 32;
			input[i] = c;
		}
		
		System.out.println(input);
		sc.close();
	}
}
