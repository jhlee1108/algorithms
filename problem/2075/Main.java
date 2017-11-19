import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	private static int N;
	private static PriorityQueue<Integer> pq;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		pq = new PriorityQueue<>();
		N = sc.nextInt();
		
		for(int i=0; i<N; i++)
			pq.add(sc.nextInt());
		
		for(int i=1; i<N; i++)
			for(int j=0; j<N; j++) {
				int x = sc.nextInt();
				if(x > pq.peek()) {
					pq.remove();
					pq.add(x);
				}
			}
		
		System.out.println(pq.peek());
		sc.close();
	}
}
