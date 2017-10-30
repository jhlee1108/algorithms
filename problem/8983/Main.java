import java.util.Arrays;
import java.util.Scanner;

public class Main {
	private static int M, N, L;
	private static Point[] a;
	private static Point[] b;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		M = sc.nextInt();
		N = sc.nextInt();
		L = sc.nextInt();
		a = new Point[M];
		b = new Point[N];
		
		for(int i=0; i<M; i++) {
			int x = sc.nextInt();
			a[i] = new Point(x, 0);
		}
		
		for(int i=0; i<N; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			b[i] = new Point(x, y);
		}
		
		Arrays.sort(a);
		Arrays.sort(b);
		
		int ans = 0;
		int curA = 0;
		for(int i=0; i<N; i++) {
			while(curA+1 < M && a[curA+1].x < b[i].x) curA++;
			if(dist(a[curA], b[i]) <= L) {
				ans ++;
			}
			else if(curA+1 < M && dist(a[curA+1], b[i]) <= L) {
				ans++;
			}
		}
		
		System.out.println(ans);
		sc.close();
	}
	
	private static int dist(Point u, Point v) {
		return Math.abs(u.x - v.x) + Math.abs(u.y - v.y);
	}
	
	private static class Point implements Comparable<Point>{
		public int x, y;
		
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Point p) {
			if(this.x == p.x)
				return this.y < p.y ? -1 : 1;
			return this.x < p.x ? -1 : 1;
		}
	}
}
