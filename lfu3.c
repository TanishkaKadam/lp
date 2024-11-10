/*Experiment no :5
Write a program to  simulate page replacement Algorithm: FIFO
Write a program to  simulate page replacement Algorithm:  LRU
 Write a program to  simulate page replacement Algorithm: LFU */
 
 
 
 //3. lfu optimal 
 
 
 

#include <stdio.h>

int n;  

int findmin(int freq[], int n) {
    int i, min = freq[0], min_index = 0;
    for (i = 1; i < n; i++) {
        if (freq[i] < min) {
            min = freq[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int seq[30], fr[5], freq[5], i, j, max, count = 0, pf = 0, flag = 0;

    printf("Enter maximum limit of the sequence: ");
    scanf("%d", &max);

   
    printf("\nEnter the sequence: ");
    for (i = 0; i < max; i++) {
        scanf("%d", &seq[i]);
    }

   
    printf("\nEnter the number of frames: ");
    scanf("%d", &n);

  
    for (i = 0; i < n; i++) {
        fr[i] = -1; 
        freq[i] = 0; 
    }

    printf("\nThe Page Replacement Process is:\n");

    for (i = 0; i < max; i++) {
        flag = 0;

       
        for (j = 0; j < n; j++) {
            if (fr[j] == seq[i]) {
                freq[j]++;  
                flag = 1;
                break;
            }
        }

        
        if (flag == 0) {
            int min_index = findmin(freq, n);  

            
            fr[min_index] = seq[i];
            freq[min_index] = 1;  
            pf++;  
        }

       
        for (j = 0; j < n; j++) {
            printf("%d\t", fr[j]);
        }

       
        if (flag == 0) {
            printf("PF No. -- %d", pf);
        }
        printf("\n");
    }

    
    float pfr = (float)pf / max;
    printf("\nThe number of page faults using LFU are: %d", pf);
    printf("\nPage fault rate: %f", pfr);

    return 0;
}


/* to run this program 
ubuntu@Tanishka:~$ gcc lfu3.c
ubuntu@Tanishka:~$ ./a.out */
