import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N;
    static int[][] arr;
    static int answer;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        arr = new int[N][N];
        for(int i=0;i<N;i++) {
            char[] temp = br.readLine().toCharArray();
            for(int j=0;j<N;j++) {
                if(temp[j] == 'H') {
                    arr[i][j] = 0;
                }
                else {
                    arr[i][j] = 1;
                }
            }
        }

        answer = N*N+1;
        search(0);

        bw.write(answer + "\n");
        bw.close();
    }

    public static void search(int curRow) {
        if(curRow == N) {
            int result = 0;
            for(int j=0;j<N;j++) {
                int count = 0;
                for(int i=0;i<N;i++) {
                    count += arr[i][j];
                }
                result += Math.min(count, N-count);
            }
            answer = Math.min(answer, result);
            return;
        }
        for(int j=0;j<N;j++) {
            arr[curRow][j] ^= 1;
        }
        search(curRow + 1);
        for(int j=0;j<N;j++) {
            arr[curRow][j] ^= 1;
        }
        search(curRow + 1);
    }
}
