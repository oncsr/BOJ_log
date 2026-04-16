import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N;
    static int[] arr, cnt;
    static int answer = 0;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());

        arr = new int[N];
        cnt = new int[N];
        Arrays.fill(arr, 1000001);
        for(int i=0;i<N;i++) {
            st = new StringTokenizer(br.readLine());
            List<Integer> list = new ArrayList<>();
            int prev = 1000001;
            for(int j=0;j<N;j++) {
                int a = Integer.parseInt(st.nextToken());
                if(arr[j] == a) {
                    cnt[j]++;
                }
                else {
                    cnt[j] = 1;
                }
                arr[j] = a;

                if(arr[j] != prev) {
                    answer = Math.max(answer, hist(list));
                    list = new ArrayList<>();
                }

                list.add(cnt[j]);
                prev = arr[j];
            }
            answer = Math.max(answer, hist(list));
        }

        bw.write(answer + "\n");
        bw.close();
    }

    public static int hist(List<Integer> h) {
        Stack<int[]> stack = new Stack<>();
        int ret = 0;
        for(int i=0;i<h.size();i++) {
            int cur = h.get(i), idx = i;
            while(!stack.isEmpty() && stack.peek()[0] >= cur) {
                int[] popped = stack.pop();
                ret = Math.max(ret, popped[0] * (i - popped[1]));
                idx = popped[1];
            }
            stack.add(new int[]{cur, idx});
        }
        while(!stack.isEmpty()) {
            int[] popped = stack.pop();
            ret = Math.max(ret, popped[0] * (h.size() - popped[1]));
        }
        return ret;
    }
}