import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) throws Exception {
		//--------------솔루션 코드를 작성하세요.--------------------------------
		Scanner sc = new Scanner(System.in);
		
		final int INF = (int)2e9;
		/*
		 * 1. 가장 왼쪽 수직 선분의 아랫 점에서부터 시작.
		 * 2. 위로 가면서 x축을 두 번 지날 때마다 봉우리를 (x1, x2)형태로 저장
		 * 3. 봉우리 정렬 후 스택으로 포함관계 구해서 정답 도출
		 * 
		 * => O(NlogN)
		 */
		
		int N = sc.nextInt();
		
		int[][] Points = new int[N][2];
		int min_x = INF;
		for(int i=0;i<N;i++) {
			Points[i][0] = sc.nextInt();
			Points[i][1] = sc.nextInt();
			min_x = Math.min(min_x, Points[i][0]);
		}
		
		int id = 1;
		while(id <= N) {
			int now = id%N, prev = (id-1)%N;
			
			if(Points[now][0] == min_x && Points[prev][0] == min_x && Points[now][1] > 0 && Points[prev][1] < 0) {
				id--;
				break;
			}
			
			id++;
		}
		
		List<int[]> lines = new ArrayList<>();
		int x = INF;
		for(int i=id;i<id+N;i++) {
			int now = i%N, next = (i+1)%N;
			if((long)Points[now][1] * (long)Points[next][1] < 0L) {
				if(x == INF) x = Points[now][0];
				else {
					lines.add(new int[] {Math.min(x,Points[now][0]),Math.max(x, Points[now][0])});
					x = INF;
				}
			}
		}
		
		Collections.sort(lines, (a,b) -> a[0]-b[0]);
		
		
		int ansA = 0; // 포함되지 않는 (가장 바깥 봉우리)
		int ansB = 0; // 포함하지 않는 (가장 안쪽 봉우리)
		Stack<int[]> stack = new Stack<>();
		for(int[] now:lines) {
			if(stack.isEmpty()) {
				stack.add(now);
				continue;
			}
			
			if(stack.peek()[1] < now[0]) {
				ansB++;
				while(!stack.isEmpty() && stack.peek()[1] < now[0]) stack.pop();
				if(stack.isEmpty()) ansA++;
			}
			stack.add(now);
			
		}
		
		if(!stack.isEmpty()) {
			ansB++;
			ansA++;
		}
		
		System.out.println(ansA + " " + ansB);
		
		sc.close();
	}

}
