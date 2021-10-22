
import java.util.*;
import java.io.*;

public class S5 {
    static BufferedReader br;
    static StringTokenizer stream;
    static String read() throws IOException {
        while(stream == null || !stream.hasMoreTokens()) {
            stream = new StringTokenizer(br.readLine().trim());
        }
        return stream.nextToken();
    }
    static int readInt() throws IOException {
        return Integer.parseInt(read());
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        int t = readInt();
        for(int i = 1;i<=t;++i) solve();
        br.close();
    }
    static int[] y;
    static segtree st;
    static void solve() throws IOException {
        int n = readInt();
        y = new int[n + 1];
        st = new segtree(100000);
        for(int i = 1;i<=n;++i) st.update(1, 1, 100000, readInt(), i);
        int ans = 0;
        for(int i = 1;i<=n;++i) ans = Math.max(ans, i - st.query(1, 1, 100000, 1, readInt()));
        System.out.printf("The maximum distance is %d\n", ans);
    }
}

class segtree {
    int[] st;
    segtree(int n) {
        st = new int[(n << 2) + 10];
        for(int i = 0;i<st.length;++i) st[i] = 0x3f3f3f3f;
    }
    void push_up(int rt) {
        st[rt] = Math.min(st[rt << 1], st[rt << 1 | 1]);
    }
    void update(int rt, int l, int r, int pos, int val) {
        if(l == r) {
            st[rt] = Math.min(st[rt], val);
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) update(rt << 1, l, mid, pos, val);
        else update(rt << 1 | 1, mid + 1, r, pos, val);
        push_up(rt);
    }
    int query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = (l + r) >> 1;
        if(y <= mid) return query(rt << 1, l, mid, x, y);
        else if(x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
        else return Math.min(query(rt << 1, l, mid, x, mid), query(rt << 1 | 1, mid + 1, r, mid + 1, y));
    }
}
