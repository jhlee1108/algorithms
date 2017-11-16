import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	private static int V, startNode, maxDist;
	private static ArrayList<ArrayList<Node>> graph;
	private static boolean check[];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		V = sc.nextInt();
		
		check = new boolean[V+1];
		graph = new ArrayList<ArrayList<Node>>();
		for(int i=0; i<=V; i++) {
			graph.add(new ArrayList<Node>());
		}
		
		for(int i=0; i<V; i++) {
			int currentNode = sc.nextInt();
			int adjacentNode;
			while((adjacentNode = sc.nextInt()) != -1) {
				int dist = sc.nextInt();
				graph.get(currentNode).add(new Node(adjacentNode, dist));
			}
		}
		
		dfs(1, 0);
		Arrays.fill(check, false);
		dfs(startNode, 0);
		System.out.println(maxDist);
		
		sc.close();
	}
	
	private static void dfs(int currentNode, int dist) {
		check[currentNode] = true;
		if(dist > maxDist) {
			startNode = currentNode;
			maxDist = dist;
		}
	
		for(Node adj : graph.get(currentNode))
			if(!check[adj.number]) dfs(adj.number, dist + adj.dist);
	}
	
	private static class Node {
		int number, dist;
		
		public Node(int number, int dist) {
			this.number = number;
			this.dist = dist;
		}
	}
}
