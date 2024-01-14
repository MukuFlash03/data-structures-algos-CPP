/*

Type: Patterns
https://www.youtube.com/watch?v=tNm_NNSB3_w&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=4

Four Rules
- Rows represented by outer loop
- Columns represented by inner loop; connect inner loop to outer loop
- Print character + space in inner loop; \n in outer loop
- Observe symmetry

Pattern 1

* * * * 
* * * * 
* * * * 
* * * * 


Pattern 2

*
* *
* * *
* * * *
* * * * *

Pattern 3

1
1 2
1 2 3
1 2 3 4
1 2 3 4 5


Pattern 4

1
2 2
3 3 3
4 4 4 4
5 5 5 5 5

Pattern 5

* * * * *
* * * *
* * *
* *
*

Pattern 6

1 2 3 4 5
1 2 3 4
1 2 3
1 2
1

Pattern 7

        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *


Pattern 8

* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *


Pattern 9

        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *
* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *


Pattern 10

*
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*


Pattern 11

1
0 1
1 0 1
0 1 0 1
1 0 1 0 1


Pattern 12

1         1
1 2     2 1
1 2 3 3 2 1


Pattern 12_1

1         1
2 2     2 2
3 3 3 3 3 3


*/

/*

A. Optimal Approach

i = j = 0 to n
print *

*/


#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

int i, j, k;

void printPattern1_2(int n) {
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) { // P1
        // for (j = 0; j <= i; j++) { // P2
            cout << "* ";
        }
        cout << "\n";
    }
}

void printPattern3_4(int n) {
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            cout << j << " "; // P3
            // cout << i << " "; // P4
        }
        cout << "\n";
    }
}

void printPattern5_6(int n) {
    // for (i = n - 1; i >= 0; i--) { // M1
        // for (j = 0; j <= i; j++) { // M1
    for (i = 0; i < n; i++) { // M2
        for (j = 0; j < n - i; j++) { // M2
            cout << "* "; // P5
            // cout << j+1 << " "; // P6
        }
        cout << "\n";
    }
}

void printPattern7(int n) {
    int ind;

    for (i = 0; i < n; i++) {
        int ind = 2 * (n - i - 1);
        
        // Spaces
        for (k = 0; k < ind / 2; k++) {
            cout << "  ";
        }

        // Stars
        for (j = 0; j < 2 * i + 1; j++) {
            cout << "* ";
        }

        // Spaces
        // for (k = ind / 2 + 2 * i + 1; k < n; k++) {
        for (k = 0; k < ind / 2; k++) {
            cout << " ";
        }
        cout << "\n";
    }
}

void printPattern8(int n) {
    int ind;

    for (i = 0; i < n; i++) {
        int ind = 2 * (n - i) - 1;
        
        // Spaces
        for (k = 0; k < i; k++) {
            cout << "  ";
        }

        // Stars
        for (j = 0; j < ind; j++) {
            cout << "* ";
        }

        // Spaces
        for (k = 0; k < i; k++) {
            cout << " ";
        }
        cout << "\n";
    }
}

void printPattern9(int n) {
    printPattern7(n);
    printPattern8(n);
}

void printPattern10(int n) {
    int ind;

    // for (i = 1; i <= 2 * n - 1; i++) {
    for (i = 1; i <= 2 * n - 1; i++) {
        ind = i;
        if (i > n)
            ind = 2 * n - i;
        for (j = 0; j < ind; j++) {
            cout << "* ";
        }
        cout << "\n";   
    }
}

void printPattern11(int n) {
    int start = 1;

    for (i = 0; i < n; i++) {
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;

        for (j = 0; j <= i; j++) {
            cout << start << " ";
            start = 1 - start;
        }
        cout << "\n";
    }
}

void printPattern12_1(int n) {
    int ind1, ind2;

    for (i = 0; i < n; i++) {
        ind1 = 2 * (n - i - 1);
        ind2 = 2 * n - ind1;

        for (j = 0; j < ind2 / 2; j++) {
            cout << i+1 << " ";
        }

        for (k = 0; k < ind1; k++) {
            cout << "  ";
        }

        for (j = 0; j < ind2 / 2; j++) {
            cout << i+1 << " ";
        }

        cout << "\n";
    }
}

void printPattern12(int n) {
    int ind;

    for (i = 0; i < n; i++) {
        ind = 2 * (n - i - 1);

        // Chars
        for (j = 0; j <= i; j++) {
            cout << j+1 << " ";
        }

        // Spaces
        for (k = 0; k < ind; k++) {
            cout << "  ";
        }

        // Chars
        for (j = i; j >= 0; j--) {
            cout << j+1 << " ";
        }

        cout << "\n";
    }
}



int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        printPattern9(n);
        cout << "\n";
    }
    return 0;
}