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

    static int N, M, Q;
    static Map<String, Integer> map;

    public static void main(String[] args) throws Exception {
        N = IOManager.nextInt();
        M = IOManager.nextInt();
        Q = IOManager.nextInt();
        map = new TreeMap<>();
        for(int i=0;i<M;i++) {
            int a = IOManager.nextInt(), b = IOManager.nextInt(), c = IOManager.nextInt();
            String key = Math.min(a,b) + "," + Math.max(a,b);
            if(map.containsKey(key)) {
                if(map.get(key) > c) {
                    map.put(key, c);
                }
            }
            else {
                map.put(key, c);
            }
        }

        while(Q-- > 0) {
            int s = IOManager.nextInt(), e = IOManager.nextInt();
            String key = Math.min(s,e) + "," + Math.max(s,e);
            int res = map.getOrDefault(key, -1);
            IOManager.write(res + "\n");
        }

        IOManager.close();
    }
}