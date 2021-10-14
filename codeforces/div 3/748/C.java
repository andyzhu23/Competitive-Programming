import java.util.*;
import java.io.*;
 
public class C {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static String read() throws IOException{
        while(st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt() throws IOException {
        return Integer.parseInt(read());
    }
    static Long readLong() throws IOException {
        return Long.parseLong(read());
    }
    static final int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    public static void main(String[] args) throws IOException{
        int t = readInt();
        while(t > 0) {
            solve();
            t--;
        }
    }
    static int gcd(int a, int b) {
        if(b == 0) return a;
        if(a == 0) return b;
        return gcd(b, a % b);
    }
    static Long n;
    static int k;
    static ArrayList<Integer> a;
    static void solve() throws IOException{
        n = readLong();
        k = readInt();
        a = new ArrayList<>();
        a.add(-1);
        for(int i = 1;i<=k;++i) a.add(readInt());
        int l = 1, r = k, ans = 0;
        Collections.sort(a);
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(ok(mid)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        System.out.println(k - ans + 1);
    }
    static boolean ok(int mid) {
        Long tot = 0l;
        for(int i = mid;i<=k;++i) {
            tot += n - a.get(i);
        }
        return tot < n;
    }
}
