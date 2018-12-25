package p2493;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Stack<Integer> s = new Stack<>();
		int N = sc.nextInt();
		int[] heights = new int[N+1];
		int[] ans = new int[N+1];
		heights[0] = 1000000000; s.push(0);
		for(int i=1; i<=N; i++) {
			heights[i] = sc.nextInt();
			while (heights[s.peek()] < heights[i]) {
				s.pop();
			}
			ans[i] = s.peek();
			s.push(i);
		}
		
		for(int i=1; i<=N; i++)
			System.out.print(ans[i] + " ");
		
		sc.close();
	}
}
