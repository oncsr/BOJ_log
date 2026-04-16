import java.util.*;
import java.io.*;

class Main
{
	public static int gcd(int a, int b) {
		if(a > b) return a%b!=0 ? gcd(b,a%b) : b;
		return b%a!=0 ? gcd(a, b%a) : a;
	}
	
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(br.readLine());
		while(T-->0) {
			int N = Integer.parseInt(br.readLine());
			int ans = 0;
			for(int i=1;i*i<=N;i++) {
				if((N/i)*i != N) continue;
				if(gcd(i,N/i) == 1) ans++;
			}
			bw.write(ans+"\n");
		}
		
		bw.flush();
		bw.close();
	}
}