import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st = new StringTokenizer("");

    static String[] morse;

    public static void fillMorse() {
        morse = new String[128];

        morse['A'] = "01";
        morse['B'] = "1000";
        morse['C'] = "1010";
        morse['D'] = "100";
        morse['E'] = "0";
        morse['F'] = "0010";
        morse['G'] = "110";
        morse['H'] = "0000";
        morse['I'] = "00";
        morse['J'] = "0111";
        morse['K'] = "101";
        morse['L'] = "0100";
        morse['M'] = "11";
        morse['N'] = "10";
        morse['O'] = "111";
        morse['P'] = "0110";
        morse['Q'] = "1101";
        morse['R'] = "010";
        morse['S'] = "000";
        morse['T'] = "1";
        morse['U'] = "001";
        morse['V'] = "0001";
        morse['W'] = "011";
        morse['X'] = "1001";
        morse['Y'] = "1011";
        morse['Z'] = "1100";

        for(char c='a';c<='z';c++) {
            morse[c] = morse[c - 32];
        }

        morse['0'] = "11111";
        morse['1'] = "01111";
        morse['2'] = "00111";
        morse['3'] = "00011";
        morse['4'] = "00001";
        morse['5'] = "00000";
        morse['6'] = "10000";
        morse['7'] = "11000";
        morse['8'] = "11100";
        morse['9'] = "11110";
    }

    public static void main(String[] args) throws Exception {
        fillMorse();

        char[] arr = br.readLine().toCharArray();
        String str = "";
        for(char c : arr) if(isAlpha(c) || isDigit(c)) {
            str += morse[c];
        }

        boolean isPalindrome = true;
        int s = 0, e = str.length() - 1;
        while(s < e) {
            if(str.charAt(s) != str.charAt(e)) {
                isPalindrome = false;
            }
            s++;
            e--;
        }

        bw.write(isPalindrome && str.length() > 0 ? "YES" : "NO");

        bw.close();
    }

    public static boolean isAlpha(char c) {
        return 'A' <= c && c <= 'Z' || 'a' <= c && c <= 'z';
    }

    public static boolean isDigit(char c) {
        return '0' <= c && c <= '9';
    }

}