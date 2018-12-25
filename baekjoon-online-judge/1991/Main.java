import java.util.Scanner;

public class Main {
	private static int N;
	private static Node[] g = new Node[26];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		sc.nextLine();
		
		for(int i=0; i<N; i++) {
			String[] x = sc.nextLine().split(" ");
			char root = x[0].charAt(0);
			char left = x[1].charAt(0);
			char right = x[2].charAt(0);
			g[root-'A'] = new Node();
			g[root-'A'].left = left - 'A';
			g[root-'A'].right = right - 'A';
		}
		
		preOrder(0);
		System.out.println("");
		inOrder(0);
		System.out.println("");
		postOrder(0);
		System.out.println("");
		
		sc.close();
	}
	
	private static void preOrder(int root) {
		System.out.print((char)(root+'A'));
		if(g[root].left >= 0) preOrder(g[root].left);
		if(g[root].right >= 0) preOrder(g[root].right);
	}
	
	private static void inOrder(int root) {
		if(g[root].left >= 0) inOrder(g[root].left);
		System.out.print((char)(root+'A'));
		if(g[root].right >= 0) inOrder(g[root].right);
	}
	
	private static void postOrder(int root) {
		if(g[root].left >= 0) postOrder(g[root].left);
		if(g[root].right >= 0) postOrder(g[root].right);
		System.out.print((char)(root+'A'));
	}
	
	private static class Node {
		public int left, right;
	}
}
