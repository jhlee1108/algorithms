import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	private static int V, E, K;
	private static ArrayList<ArrayList<Pair>> graph = new ArrayList<>();
	private static PriorityQueue<Pair> pq = new PriorityQueue<>();
	private static int[] dist;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		V = sc.nextInt();
		E = sc.nextInt();
		K = sc.nextInt() - 1;
		for(int i=0; i<V; i++)
			graph.add(new ArrayList<Pair>());
		dist = new int[V];
		Arrays.fill(dist, Integer.MAX_VALUE);
		
		for(int i=0; i<E; i++) {
			int u = sc.nextInt() - 1;
			int v = sc.nextInt() - 1;
			int c = sc.nextInt();
			graph.get(u).add(new Pair(v, c));
		}

		dist[K] = 0;
		pq.add(new Pair(K, 0));
		while(!pq.isEmpty()) {
			Pair p = pq.remove();
			
			for(Pair ad : graph.get(p.v)) {
				if(dist[ad.v] > p.c + ad.c) {
					dist[ad.v] = p.c + ad.c;
					pq.add(new Pair(ad.v, dist[ad.v]));
				}
			}
		}
		
		for(int i=0; i<V; i++)
			System.out.println(dist[i] == Integer.MAX_VALUE ? "INF" : dist[i]);
		
		sc.close();
	}
	
	private static class Pair implements Comparable<Pair>{
		public int v, c;
		
		public Pair(int v, int c) {
			this.v = v;
			this.c = c;
		}

		@Override
		public int compareTo(Pair p) {
			return this.c < p.c ? -1 : 1;
		}
	}
}
