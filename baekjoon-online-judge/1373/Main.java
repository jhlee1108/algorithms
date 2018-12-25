import java.util.Scanner;

public class Main {
	private static char binaryNumber[];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		binaryNumber = sc.nextLine().toCharArray();
		
		StringBuilder otalNumber = new StringBuilder();
		int n = 0;
		int length = binaryNumber.length;
		for(int i=1; i<=length; i++) {
			n += (binaryNumber[length - i]-'0')*Math.pow(2, (i-1)%3);
			if(i%3 == 0 || i == length) {
				otalNumber.insert(0, n);
				n = 0;
			}
		}
		
		System.out.println(otalNumber);
		sc.close();
	}
}
