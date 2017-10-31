import java.util.Scanner;
import java.util.Collections;
import java.util.PriorityQueue;

public class Main {
	private static int N, ans;
	private static PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		
		for(int i=0; i<N; i++) {
			ans = sc.nextInt();
			if(ans == 0) {
				if(!pq.isEmpty()) ans = pq.remove();
				System.out.println(ans);
			}
			else pq.add(ans);
		}
		
		sc.close();
	}
}
