
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N = 10;
    static int n;
    static int a[], b[];
    static Queue <int[]> q;
    static HashSet <String> vis;
    public static void main(String[] args) throws IOException{
        while(true){
            n = Integer.parseInt(br.readLine());
            if(n == 0) break;
            solve();
        }
    }

    static void solve() throws IOException{
        vis = new HashSet<String>();
        String[] input = br.readLine().split(" ");
        a = new int[N];
        b = new int[N];
        for(int i = 1;i<=n;i++){
            a[i] = Integer.parseInt(input[i - 1]);
            b[i] = a[i];
        }
        Arrays.sort(b, 1, 1 + n);
        q = new LinkedList<>();
        q.offer(a);
        while(!q.isEmpty()){
            int[] cur = q.poll();
            if(isAns(cur)) {
                System.out.println(cur[n + 1]);
                return;
            }
            for(int i = 1;i<n;i++){
                if(isOk(cur[i], cur[i + 1])){
                    int[] nxt = new int[N];
                    for(int j = 1;j<N;j++) nxt[j] = cur[j];
                    move(nxt, i, i + 1);
                    if(Visited(nxt)) continue;
                    nxt[n + 1] ++;
                    q.offer(nxt);
                }
            }
        }
        System.out.println("IMPOSSIBLE");
    }

    static boolean isAns(int[] cur){
        for(int i = 1;i<=n;i++){
            if(cur[i] != i) return false;
        }
        return true;
    }

    static boolean isOk(int A, int B){
        if(A == 0 && B == 0) return false;
        return true;
    }

    static void move(int[] nxt, int A, int B){
        if(nxt[B] == 0){
            nxt[B] = nxt[A] % 10;
            nxt[A] /= 10;
            return;
        } else if(nxt[A] == 0){
            nxt[A] = nxt[B] % 10;
            nxt[B] /= 10;
            return;
        }
        int a = nxt[A] % 10;
        int b = nxt[B] % 10;
        if(a < b){
            nxt[B] = nxt[B] * 10 + a;
            nxt[A] /= 10;
        } else {
            nxt[A] = nxt[A] * 10 + b;
            nxt[B] /= 10;
        }
    }

    static boolean Visited(int[] nxt){
        String cur = "";
        for(int i = 1;i<=n;i++){
            cur += "|" + nxt[i];
        }
        cur += "|";
        if(vis.contains(cur)) return true;
        vis.add(cur);
        return false;
    }
}
