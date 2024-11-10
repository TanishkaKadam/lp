/*Experiment no :5
Write a program to  simulate page replacement Algorithm: FIFO
Write a program to  simulate page replacement Algorithm:  LRU
 Write a program to  simulate page replacement Algorithm: LFU */
 
 
 
 //2. lru
 
 

#include <stdio.h>

int main() {
    int i, j, n, f, pf = 0, next = 1, min, rs[25], m[10], count[10], flag[25];

    // Input the length of reference string
    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    // Input the reference string
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
        flag[i] = 0;  // Initialize flag to 0 for all reference string entries
    }

    // Input the number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &f);

    // Initialize the frames and the counters
    for (i = 0; i < f; i++) {
        m[i] = -1;  // Frames initially empty
        count[i] = 0;  // No pages in the frames yet
    }

    printf("\nThe Page Replacement Process is:\n");

    // Simulate the LRU (Least Recently Used) page replacement
    for (i = 0; i < n; i++) {
        int pageFound = 0;

        // Check if the page is already in one of the frames
        for (j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                pageFound = 1;  // Page found in the frame
                count[j] = next; // Update the time of the page's usage
                next++;
                break;
            }
        }

        // If the page is not found in the frames, we need to replace one
        if (pageFound == 0) {
            // Find the least recently used page (minimum count)
            min = 0;
            for (j = 1; j < f; j++) {
                if (count[j] < count[min]) {
                    min = j;
                }
            }

            // Replace the least recently used page with the new page
            m[min] = rs[i];
            count[min] = next;
            next++;
            pf++;  // Increment page fault count
        }

        // Print the current frame contents
        for (j = 0; j < f; j++) {
            printf("%d\t", m[j]);
        }

        // If a page fault occurred, print the page fault number
        if (pageFound == 0) {
            printf("PF No. -- %d", pf);
        }
        printf("\n");
    }

    // Output the total number of page faults
    printf("\nThe number of page faults using LRU are: %d\n", pf);

    return 0;
}




/* to run the program use
ubuntu@Tanishka:~$ gcc lru2.c
ubuntu@Tanishka:~$ ./a.out
 */
