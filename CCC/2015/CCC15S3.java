

import java.util.*;
import java.io.*;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int g, p;
    private static ArrayList<Integer> free = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        g = Integer.parseInt(br.readLine());
        p = Integer.parseInt(br.readLine());
        for(int i = 1;i<=g;i++){
            free.add(i);
        }
        int ans = 0;
        for(int i = 1;i<=p;i++){
            int cur = Integer.parseInt(br.readLine());
            int k = binarySearch(cur);
            if(k == -1) {
                System.out.println(ans);
                return;
            } else {
                free.remove(k);
                ans++;
            }
        }
        System.out.println(ans);
        br.close();
    }
    private static int binarySearch(int x){
        int ans = -1, l = 0, r = free.size() - 1, mid;
        while(l<=r){
            mid = (l + r) / 2;
            if(free.get(mid) == x) return mid;
            else if(free.get(mid) < x){
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
}
