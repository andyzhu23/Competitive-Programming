import java.util.*;
import java.io.*;

public class B {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static String read() throws IOException{
        while(st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        }
        return st.nextToken();
    }
    static int readInt() throws IOException {
        return Integer.parseInt(read());
    }
    static Long readLong() throws IOException {
        return Long.parseLong(read());
    }

    public static void main(String[] args) throws IOException {
        int t = readInt();
        while(t > 0) {
            solve();
            t--;
        }
    }
    public static void solve() throws IOException {
        Long k = readLong();
        Long a = k;
        int cnt = 0;
        while(a > 0) {
            Long cur = a % 10;
            if(cur == 0) {
                break;
            }
            a /= 10;
            cnt++;
        }
        a /= 10;
        while(a > 0) {
            Long cur = a % 10;
            if(cur == 5 || cur == 0) {
                break;
            }
            a /= 10;
            cnt++;
        }


        a = k;
        int cnt2 = 0;
        while(a > 0) {
            Long cur = a % 10;
            if(cur == 5) {
                break;
            }
            a /= 10;
            cnt2++;
        }
        a /= 10;
        while(a > 0) {
            Long cur = a % 10;
            if(cur == 2 || cur == 7) {
                break;
            }
            a /= 10;
            cnt2++;
        }
        System.out.println(Math.min(cnt2, cnt));
    }
}
