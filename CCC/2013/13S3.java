import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int t=0;
		int g=0;
		Scanner sc = new Scanner(System.in);
		
		t = sc.nextInt();
		t--;
		g = sc.nextInt();
		int game[] = new int[4];
		int team1;
		int team2;
		int score1;
		int score2;
		boolean played[][] = new boolean[4][4];
		for (int i = 0; i < g; i++) {
			team1 = sc.nextInt();
			team2 = sc.nextInt();
			score1 = sc.nextInt();
			score2 = sc.nextInt();
			played[team1 - 1][team2 - 1] = true;
			played[team2 - 1][team1 - 1] = true;
			if (score1 > score2) {
				game[team1 - 1] += 3;
			} else if (score1 < score2) {
				game[team2 - 1] += 3;
			} else {
				game[team1 - 1]++;
				game[team2 - 1]++;
			}
		}
		sc.close();
		ArrayList<ArrayList<Integer>> vec = new ArrayList<>();
		ArrayList<Integer> games = new ArrayList<>();
		for(int i = 0;i<4;i++) {
			games.add(game[i]);
		}
		vec.add(games);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (j == i || played[i][j]) {
					continue;
				}
				played[i][j] = true;
				played[j][i] = true;
				int size = vec.size();
				for (int a = 0; a < size; a++) {
					ArrayList<Integer> p1 = vec.get(0);
					vec.remove(0);
					ArrayList<Integer> p2= new ArrayList<>();
					ArrayList<Integer> p3 = new ArrayList<>();
					for (int c = 0; c < 4; c++) {
						p2.add(p1.get(c));
					}
					for (int b = 0; b < 4; b++) {
						p3.add(p2.get(b));
					}
					p1.set(i,p1.get(i)+3);
					p2.set(j,p2.get(j)+3);
					p3.set(i,p3.get(i)+1);
					p3.set(j,p3.get(j)+1);
					vec.add(p1);
					vec.add(p2);
					vec.add(p3);
				}
			}
		}
		int ans = 0;
		int curt;
		for (int i = 0; i < vec.size(); i++) {
			curt = vec.get(i).get(t);
			boolean max = true;
			for (int j = 0; j < 4; j++) {
				if (j == t) {
					continue;
				}
				if (vec.get(i).get(j) >= curt) {
					max = false;

					break;
				}
			}
			if (max) {
				ans++;
			}
		}
		System.out.println(ans);

	}
}
