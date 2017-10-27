import java.util.Scanner;

public class Main {
	private static int n, m;
	private static int[][] dist = new int[101][101];
	private static int INF = 1000000000;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				dist[i][j] = (i == j ? 0 : INF);
		
		for(int i=0; i<m; i++) {
			int u = sc.nextInt();
			int v = sc.nextInt();
			int c = sc.nextInt();
			if(dist[u][v] > c) dist[u][v] = c;
		}
		
		for(int k=1; k<=n; k++)
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++)
				System.out.print((dist[i][j] == INF ? 0 : dist[i][j]) + " ");
			System.out.println("");
		}
		
		sc.close();
	}
}
