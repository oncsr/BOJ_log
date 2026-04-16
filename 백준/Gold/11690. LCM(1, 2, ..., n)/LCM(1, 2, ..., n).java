import java.util.*;
import java.io.*;

class Main
{
	static boolean[] E = new boolean[100000001];
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		long n = Long.parseLong(br.readLine());
		long ans = 1L, mod = 4294967296L;
		
		long i=2;
		for(;i<=n;i++) {
			if(i*i<=n) {
				if(!E[(int)i]) {
					long j=i*i;
					for(;j<=n;j+=i) E[(int)j]=true;
					long g = i;
					while(g <= n) g*=i;
					g /=i;
					ans = (ans * g)%mod;
					
				}				
			}
			else {
				if(!E[(int)i]) {
					ans = (ans * i)%mod;
				}
			}
		}
		bw.write(ans+"\n");
		
		bw.flush();
		bw.close();
	}
}