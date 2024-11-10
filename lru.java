/*Experiment no :5
Write a program to  simulate page replacement Algorithm: FIFO
Write a program to  simulate page replacement Algorithm:  LRU
 Write a program to  simulate page replacement Algorithm: LFU */
 
 
 
 //2. lru
 
 
 import java.util.Scanner;

public class LRUPageReplacement {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
       
        System.out.print("Enter the length of reference string: ");
        int n = scanner.nextInt();
        int[] rs = new int[n];
        System.out.print("Enter the reference string: ");
        for (int i = 0; i < n; i++) {
            rs[i] = scanner.nextInt();
        }
        System.out.print("Enter the number of frames: ");
        int f = scanner.nextInt();

        int[] m = new int[f]; 
        int[] count = new int[f]; 
        int[] flag = new int[n];
        for (int i = 0; i < f; i++) {
            count[i] = 0;
            m[i] = -1; 
        }

        int pf = 0; 
        int next = 1; 

        System.out.println("\nThe Page Replacement process is:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < f; j++) {
                if (m[j] == rs[i]) {
                    flag[i] = 1; 
                    count[j] = next; 
                    next++;
                }
            }
            if (flag[i] == 0) {
                if (i < f) { 
                    m[i] = rs[i]; 
                    count[i] = next; 
                    next++;
                } else {
                    int min = 0;
                    for (int j = 1; j < f; j++) {
                        if (count[min] > count[j]) {
                            min = j;
                        }
                           }
                    m[min] = rs[i]; 
                    count[min] = next; 
                    next++;
                }
                pf++; 
            }
            for (int j = 0; j < f; j++) {
                System.out.print(m[j] + "\t");
            }
            if (flag[i] == 0) {
                System.out.print("PF No. -- " + pf); 
            }
            System.out.println();
        }
        
        System.out.println("\nThe number of page faults using LRU are " + pf);
        scanner.close();
    }
}






/* to run this program use 
 ubuntu@Tanishka:~$ javac LRUPageReplacement.java
ubuntu@Tanishka:~$ java LRUPageReplacement
*/
