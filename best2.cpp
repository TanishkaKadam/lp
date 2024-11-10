/*Experiment No.: 4
Problem Statement : Write a Java/C++ program to simulate memory placement strategies
1. First Fit
2. Best Fit
3. Worst Fit */



//2. Best fit


#include <iostream>
#include <vector>
#include <limits> 

#define MAX 25

int main() {
    std::vector<int> frag(MAX, 0), b(MAX, 0), f(MAX, 0);
    std::vector<int> bf(MAX, 0), ff(MAX, 0);
   

    int nb, nf, temp, lowest = std::numeric_limits<int>::max();

  
    std::cout << "\nEnter the number of blocks: ";
    std::cin >> nb;
    std::cout << "Enter the number of files: ";
    std::cin >> nf;

   
    std::cout << "\nEnter the size of the blocks:-\n";
    for (int i = 1; i <= nb; ++i) {
        std::cout << "Block " << i << ": ";
        std::cin >> b[i];
    }

   
    std::cout << "Enter the size of the files :-\n";
    for (int i = 1; i <= nf; ++i) {
        std::cout << "File " << i << ": ";
        std::cin >> f[i];
          }

   
    for (int i = 1; i <= nf; ++i) {
        lowest = std::numeric_limits<int>::max();
        for (int j = 1; j <= nb; ++j) {
            if (bf[j] != 1) {
                temp = b[j] - f[i];
                if (temp >= 0 && lowest > temp) {
                    ff[i] = j;
                    lowest = temp;
                }
            }
        }
        frag[i] = lowest;
        bf[ff[i]] = 1;
    }

   
    std::cout << "\nFile No\tFile Size \tBlock No\tBlock Size\tFragment";
    for (int i = 1; i <= nf && ff[i] != 0; ++i) {
        std::cout << "\n" << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i];
    }

    return 0;
}
