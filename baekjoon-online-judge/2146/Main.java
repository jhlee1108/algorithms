package p2146;

import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	private static int map[][] = new int[100][100];
	private static int group[][] = new int[100][100];
	private static int d[][] = new int[100][100];
	private static int N;
	private static int dx[] = {-1, 1, 0, 0};
	private static int dy[] = {0, 0, -1, 1};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Queue<Pair> q = new LinkedList<>();
		
		N = sc.nextInt();
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++) {
				map[i][j] = sc.nextInt();
				if(map[i][j] == 1) q.add(new Pair(i, j));
			}
		
		int cnt = 1;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(map[i][j] == 1 && group[i][j] == 0)
					make_group(i, j, cnt++);
		
		while(!q.isEmpty()) {
			int y = q.peek().y;
			int x = q.peek().x;
			q.remove();
			
			for(int i=0; i<4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if(0 <= ny && ny < N && 0 <= nx && nx < N)
					if(d[ny][nx] == 0 && group[ny][nx] == 0) {
						group[ny][nx] = group[y][x];
						d[ny][nx] = d[y][x] + 1;
						q.add(new Pair(ny, nx));
					}
			}
		}
		
		
		int ans = 987654321;
		
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				for(int k=0; k<4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					
					if(0 <= ny && ny < N && 0 <= nx && nx < N)
						if(group[i][j] != group[ny][nx])
							ans = Math.min(ans, d[i][j] + d[ny][nx]);
				}
		
		System.out.println(ans);
		
		sc.close();
	}

	private static void make_group(int y, int x, int cnt) {
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(y, x));
		group[y][x] = cnt;
		
		while(!q.isEmpty()) {
			y = q.peek().y;
			x = q.peek().x;
			q.remove();
			
			for(int i=0; i<4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if(0 <= ny && ny < N && 0 <= nx && nx < N)
					if(map[ny][nx] == 1 && group[ny][nx] == 0) {
						group[ny][nx] = cnt;
						q.add(new Pair(ny, nx));
					}
			}
		}
	}
	
	private static class Pair {
		public int y;
		public int x;

		public Pair(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}
}
