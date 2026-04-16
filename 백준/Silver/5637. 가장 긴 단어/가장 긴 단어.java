import java.util.*;
import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String ans = "";
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			while(st.hasMoreTokens()) {
				String temp = st.nextToken();
				String res = "";
				for(int i=0;i<temp.length();i++) {
					char t = temp.charAt(i);
					
					if(('a' <= t && t <= 'z') || ('A' <= t && t <= 'Z') || (t == '-')) {
						res += t;
						continue;
					}
					if(res.length() > ans.length()) {
						ans = res;
					}
					res = "";
				}
				if(res.length() > ans.length()) {
					ans = res;
				}
				if(temp.equals("E-N-D")) {
					for(int i=0;i<ans.length();i++) {
						char t = ans.charAt(i);
						if(t != '-' && ('A' <= t && t <= 'Z')) t = (char)(t+32);
						bw.write(t);
					}
					bw.flush();
					bw.close();
					return;
				}
			}
		}
	}
}