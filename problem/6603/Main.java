import java.util.Scanner;

public class Main {
	private static int k;
	private static int[] num = new int[13];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while(true) {
			k = sc.nextInt();
			if(k == 0) break;
			
			for(int i=0; i<k; i++)
				num[i] = sc.nextInt();
			
			for(int i=0; i<=k-6; i++)
				go(num[i] + " ", i, 1);
			
			System.out.println("");
		}
		
		sc.close();
	}
	
	private static void go(String ans, int index, int cnt) {
		if(cnt == 6) {
			System.out.println(ans);
			return;
		}
		
		for(int i=index+1; i<=k-(6-cnt); i++)
			go(ans + num[i] + " ", i, cnt+1);
	}
}
