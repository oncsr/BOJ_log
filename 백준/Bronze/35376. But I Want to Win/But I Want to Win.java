import java.io.*;
import java.util.*;

public class Main {

    static class IOManager {
        static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        static StringTokenizer st = new StringTokenizer("");

        private IOManager(){}

        static String nextLine() throws Exception {
            String line = br.readLine();
            st = new StringTokenizer(line);
            return line;
        }

        static String nextToken() throws Exception {
            while (!st.hasMoreTokens())
                nextLine();
            return st.nextToken();
        }

        static int nextInt() throws Exception {
            return Integer.parseInt(nextToken());
        }

        static long nextLong() throws Exception {
            return Long.parseLong(nextToken());
        }

        static double nextDouble() throws Exception {
            return Double.parseDouble(nextToken());
        }

        static void write(String content) throws Exception {
            bw.write(content);
        }

        public static void close() throws Exception {
            bw.flush();
            bw.close();
            br.close();
        }
    }

    //

    static int N;
    static int[] arr;

    public static void main(String[] args) throws Exception {
        N = IOManager.nextInt();
        arr = new int[N];
        int sum = 0;
        for(int i=0;i<N;i++) {
            arr[i] = IOManager.nextInt();
            sum += arr[i];
        }
        int standard = (sum + 2) / 2;
        Arrays.sort(arr);

        if(arr[N-1] >= standard) {
            IOManager.write("IMPOSSIBLE TO WIN");
            IOManager.close();
            return;
        }

        for (int i=0;i<N-2;i++) {
            arr[N-2] += arr[i];
            if(arr[N-2] >= standard) {
                IOManager.write((i+1) + "\n");
                IOManager.close();
                return;
            }
        }
        IOManager.write("IMPOSSIBLE TO WIN");
        IOManager.close();
    }
}