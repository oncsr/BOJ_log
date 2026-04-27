import java.io.*;
import java.util.*;

public class Main {
    static class Food implements Comparable<Food> {
        int time, scoreA, scoreB;
        Food(int time, int scoreA, int scoreB) {
            this.time = time;
            this.scoreA = scoreA;
            this.scoreB = scoreB;
        }

        @Override
        public int compareTo(Food o) {
            return this.time-o.time;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st = new StringTokenizer("");

    static int N, D;
    static Food[] arr;
    static int[] maxA, maxB;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        arr = new Food[N];

        int answer = 0;
        for(int i=0;i<N;i++) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr[i] = new Food(t, a, b);
            if(t <= D) {
                answer = Math.max(answer, a+b);
            }
        }

        Arrays.sort(arr);
        int a = 0, b = 0;
        maxA = new int[N];
        maxB = new int[N];
        for(int i=0;i<N;i++) {
            a = Math.max(a, arr[i].scoreA);
            b = Math.max(b, arr[i].scoreB);
            maxA[i] = a;
            maxB[i] = b;
        }

        for(int i=0;i<N;i++) {
            int s = i+1, e = N-1, m = (s+e+1) >> 1;
            while(s < e) {
                if(arr[m].time > D - arr[i].time) {
                    e = m-1;
                }
                else {
                    s = m;
                }
                m = (s+e+1) >> 1;
            }
            if(i<m && m<N && arr[i].time + arr[m].time <= D) {
                answer = Math.max(answer, maxA[i] + maxB[m]);
                answer = Math.max(answer, maxB[i] + maxA[m]);
            }
        }

        bw.write(answer + "\n");
        bw.close();
    }

}