import java.util.*;
import java.io.*;

public class S3v2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n;
    static ArrayList<node> nodes = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        for(int i = 0;i<n;i++) {
            String[] input = br.readLine().split(" ");
            int p = Integer.parseInt(input[0]);
            int w = Integer.parseInt(input[1]);
            int d = Integer.parseInt(input[2]);
            nodes.add(new node(p, w, d));
        }
        Collections.sort(nodes);
        int l = 0, r = 2000000010, ans = 0;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(getAns(mid) > getAns(mid + 1)) {
                ans = mid + 1;
                l = mid + 1;
            } else {
                ans = mid;
                r = mid - 1;
            }
        }
        System.out.println(getAns(ans));
    }

    static long getAns(int x) {
        long ans = 0;
        for(node i : nodes) {
            if(Math.abs(i.p - x) > i.d) {
                long tmp = Math.abs(i.p - x) - i.d;
                ans += tmp * i.w;
            }
        }
        return ans;
    }
}

class node implements Comparable<node>{
    int p, w, d;
    node(int P, int W, int D) {
        p = P;
        w = W;
        d = D;
    }
    public int compareTo(node other) {
        return this.p < other.p ? 1 : 0;
    }
}
