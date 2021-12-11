import java.util.*;
import java.io.*;

public class haircut {
    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;

    static String read() throws IOException {
        while(st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
    static int readInt() throws IOException {
        return Integer.parseInt(read());
    }
    static int n;
    static int[] a;
    static long[] b;
    static fenwick fen;
    public static void main(String[] args) throws IOException{
        br = new BufferedReader(new FileReader("haircut.in"));
        out = new PrintWriter(new BufferedWriter(new FileWriter("haircut.out")));
        n = readInt();
        a = new int[n + 10];
        b = new long[n + 10];
        for(int i = 1;i<=n;++i) a[i] = readInt();
        br.close();
        fen = new fenwick(n + 10);
        for(int i = 1;i<=n;++i) {
            b[a[i] + 1] += fen.query(a[i] + 2, n + 5);
            fen.update(a[i] + 1, 1);
        }
        for(int i = 1;i<=n;++i) {
            b[i] += b[i - 1];
            out.println(b[i - 1]);
        }
        out.close();
    }
}

class fenwick {
    int[] c;
    int n;
    public fenwick(int N) {
        n = N;
        c = new int[n + 10];
    }
    public int query(int a, int b) {
        return query(b) - query(a - 1);
    }
    private int query(int a) {
        int ans = 0;
        for(int i = a;i > 0;i-=i & (-i)) ans += c[i];
        return ans;
    }
    public void update(int a, int b) {
        for(int i = a;i<=n;i+=i & (-i)) c[i] += b;
    }
}
