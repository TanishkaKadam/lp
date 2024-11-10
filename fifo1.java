/*Experiment no :5
Write a program to  simulate page replacement Algorithm: FIFO
Write a program to  simulate page replacement Algorithm:  LRU
 Write a program to  simulate page replacement Algorithm: LFU */
 
 
 
 //1. fifo
 
 
 import java.util.Scanner;

public class FIFOPageReplacement {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int i, j, k, f, pf = 0, count = 0, n;
       
        
        System.out.print("Enter the length of reference string: ");
        n = scanner.nextInt();
        int[] rs = new int[n];
        System.out.print("Enter the reference string: ");
        for (i = 0; i < n; i++) {
            rs[i] = scanner.nextInt();
        }
        System.out.print("Enter number of frames: ");
        f = scanner.nextInt();
        int[] m = new int[f]; 
        for (i = 0; i < f; i++) {
            m[i] = -1;
        }
        System.out.println("\nThe Page Replacement Process is: ");
        for (i = 0; i < n; i++) {
            for (k = 0; k < f; k++) {
                if (m[k] == rs[i]) {
                    break;
                }
            }
            if (k == f) { 
                m[count++] = rs[i];
                pf++; 
            }
            for (j = 0; j < f; j++) {
                if (m[j] == -1) {
                    System.out.print("\t-"); 
                } else {
                    System.out.print("\t" + m[j]);
                }
            }
            if (k == f) {
                System.out.print("\tPF No. " + pf); 
            }

            System.out.println();

            if (count == f) {
                count = 0; 
            }
        }
         System.out.println("\nThe number of Page Faults using FIFO are " + pf);
        scanner.close();
    }
}








/*to run this program use 
ubuntu@Tanishka:~$ javac FIFOPageReplacement.java
ubuntu@Tanishka:~$ java FIFOPageReplacement  */


