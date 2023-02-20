import java.io.*;
import java.util.*;
public class mootube {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("mootube.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("mootube.out")));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int q = Integer.parseInt(st.nextToken());
		Edge[] edges = new Edge[n-1];
		for(int i = 0; i < edges.length; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken())-1;
			int y = Integer.parseInt(st.nextToken())-1;
			int w = Integer.parseInt(st.nextToken());
			edges[i] = new Edge(x, y, w);
		}
		Arrays.sort(edges);
		par = new int[n];
		sz = new int[n];
		for(int i = 0; i < n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
		Query[] queries = new Query[q];
		for(int query = 0; query < q; query++) {
			st = new StringTokenizer(br.readLine());
			int threshold = Integer.parseInt(st.nextToken());
			int start = Integer.parseInt(st.nextToken())-1;
			queries[query] = new Query(start, threshold, query);
		}
		Arrays.sort(queries);
		int[] ret = new int[q];
		int idx = 0;
		for(Query query: queries) {
			while(idx < edges.length && edges[idx].w >= query.w) {
				merge(edges[idx].a, edges[idx].b);
				idx++;
			}
			ret[query.i] = sizeOf(query.v)-1;
		}
		for(int out: ret) {
			pw.println(out);
		}
		pw.close();
	}

	static int[] par;
	static int[] sz;
	public static int sizeOf(int x) {
		return sz[find(x)];
	}
	public static int find(int x) {
		return par[x] == x ? x : (par[x] = find(par[x]));
	}
	public static void merge(int x, int y) {
		int fx = find(x);
		int fy = find(y);
		sz[fy] += sz[fx];
		par[fx] = fy;
	}

	static class Edge implements Comparable<Edge> {
		public int a, b, w;
		public Edge(int x, int y, int z) {
			a=x;
			b=y;
			w=z;
		}
		public int compareTo(Edge e) {
			return e.w - w;
		}
	}

	static class Query implements Comparable<Query> {
		public int v, w, i;
		public Query(int x, int y, int z) {
			v=x;
			w=y;
			i=z;
		}
		public int compareTo(Query q) {
			return q.w - w;
		}
	}

}
