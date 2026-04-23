import java.util.Scanner;
import java.util.Arrays;
import java.util.Vector;
import java.util.Collections;

public class Main {

    static Vector<String> triplesFound = null;

    /* Add a triple to the answer so far. Make sure: i < j < k. */
    private static void addTripleToAnswer(int i, int j, int k) {
        String s = "{" + i + " " + j + " " + k + "}";
        triplesFound.add(s);
    }

    private static void solveTriples(int[] sequence) {

        /* ------------------- INSERT CODE HERE --------------------
         *
         * Your code should appropriately call the addTripleToAnswer() function 
         * above for every Pythogorean triple it finds. 
         *
         * */
        
        Arrays.sort(sequence);
        for(int a=0;a<sequence.length;a++){
            for(int b=a+1;b<sequence.length;b++){
                for(int c=b+1;c<sequence.length;c++){
                    Long al = new Long(sequence[a]);
                    Long bl = new Long(sequence[b]);
                    Long cl = new Long(sequence[c]);
                    if(al*al+bl*bl==cl*cl){
                        addTripleToAnswer(sequence[a],sequence[b],sequence[c]);
                    }
                }
            }
        }

        /* -------------------- END OF INSERTION --------------------*/
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numCases = sc.nextInt();

        for(int i = 0; i < numCases; i++) 
        {

            int num = sc.nextInt();

            int[] sequence = new int[num];

            for(int j = 0; j < num; j++) 
                sequence[j] = sc.nextInt();

            triplesFound = new Vector<String>();

            solveTriples(sequence);
            
            if(triplesFound.size() == 0) {
                System.out.println("No Pythogorean triples found in the sequence."); 
            } else {

                /* Sort the triples. */
                Collections.sort(triplesFound);

                System.out.print("Found Pythogorean triples: ");
                for(String s : triplesFound) 
                    System.out.print(" " + s);
                System.out.println();
            }
        }
    }
}
