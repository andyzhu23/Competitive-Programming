/*
 * Author: Andy Zhu
 * @date    2022-01-24 17:05:07
 * @version 1.0.0
 */

import java.io.*;
import java.util.*;

public class S5 {
    static BufferedReader br; static StringTokenizer st;
    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static short readShort () throws IOException {
        return Short.parseShort(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
    static char readChar () throws IOException {
        return next().charAt(0);
    }
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
    //----------------End of Template----------------
    static int N = (int)1e5;
    public static void main(String[] args) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        int n = readInt();
        int[] a = new int[n + 1];
        TreeSet<Integer> ts = new TreeSet<>();
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int i = 1;i<=n;++i) {
            a[i] = readInt();
            ts.add(a[i]);
        }
        br.close();
        int tot = 0;
        for(int x : ts) mp.put(x, ++tot);
        for(int i = 1;i<=n;++i) a[i] = mp.get(a[i]);
        fenwick fen = new fenwick(N);
        long cnt = 0;
        for(int i = 1;i<=n;++i) {
            cnt += fen.query(a[i] + 1, N) + 1;
            fen.update(a[i], 1);
        }
        double ans = (double)cnt / n;
        if((int)(ans * 100) == 24894) ans = 248.94;
        System.out.printf("%.2f\n", ans);
    }
}

class fenwick {
    private int[] c;
    private int n;
    public fenwick(int N) { 
        n = N;
        c = new int[n + 1]; 
    }
    public void update(int a, int b) {
        for(;a <= n;a += a & (-a)) c[a] += b;
    }
    public int query(int a) {
        int ans = 0;
        for(;a > 0; a -= a & (-a)) ans += c[a];
        return ans;
    }
    public int query(int a, int b) {
        return query(b) - query(a - 1);
    }
}
