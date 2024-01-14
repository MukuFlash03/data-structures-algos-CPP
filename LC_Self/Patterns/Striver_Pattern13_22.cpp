/*

Type: Patterns
https://www.youtube.com/watch?v=tNm_NNSB3_w&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=4

Four Rules
- Rows represented by outer loop
- Columns represented by inner loop; connect inner loop to outer loop
- Print character + space in inner loop; \n in outer loop
- Observe symmetry

Pattern 13

1
2 3
4 5 6
7 8 9 10
11 12 13 14 15


Pattern 14

A
A B
A B C
A B C D
A B C D E

Pattern 15

A B C D E
A B C D
A B C
A B
A


Pattern 15_1

A 
B A 
C B A 
D C B A 
E D C B A 

Pattern 16

A
B B
C C C
D D D D
E E E E E

Pattern 17

    A
  A B A
A B C B A


Pattern 18

E
D E
C D E
B C D E
A B C D E


Pattern 19

* * * * * * * * * *
* * * *     * * * *
* * *         * * *
* *             * *
*                 *
*                 *
* *             * *
* * *         * * *
* * * *     * * * *
* * * * * * * * * *


Pattern 20

*                 *
* *             * *
* * *         * * *
* * * *     * * * *
* * * * * * * * * *
* * * *     * * * *
* * *         * * *
* *             * *
*                 *


Pattern 21

* * * * *
*       *
*       *
*       *
* * * * *


Pattern 22

4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4



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

void printPattern13(int n) {
    int num = 1;

    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            cout << num++ << " ";
        }
        cout << "\n";
    }
}

void printPattern14(int n) {
    for (i = 0; i < n; i++) {
        for (j = 'A'; j <= 'A' + i; j++) {
            cout << char(j) << " ";
        }
        cout << "\n";
    }
}

void printPattern15_1(int n) {
    for (i = 0; i < n; i++) {
        for (j = 'A' + i; j >= 'A'; j--) {
            cout << char(j) << " ";
        }
        cout << "\n";
    }
}

void printPattern15(int n) {
    for (i = 0; i < n; i++) {
        for (j = 'A'; j <= 'A' + (n - i - 1); j++) {
            cout << char(j) << " ";
        }
        cout << "\n";
    }
}

void printPattern16(int n) {
    for (i = 0; i < n; i++) {
        for (j = 'A'; j <= 'A' + i; j++) {
            cout << char('A' + i) << " ";
        }
        cout << "\n";
    }
}

void printPattern17(int n) {
    int ind, mid;
    char ch = ' ';

    for (i = 0; i < n; i++) {
        int ind = 2 * (n - i - 1);
        
        // Spaces
        for (k = 0; k < ind / 2; k++) {
            cout << "  ";
        }

        // Chars
        ch = 'A';
        mid = 2 * i + 1;
        for (j = 0; j < 2 * i + 1; j++) {
            cout << ch << " ";
            if (j <= mid / 2 - 1)
                ch++;
            else
                ch--;
        }

        // Spaces
        for (k = 0; k < ind / 2; k++) {
            cout << " ";
        }
        cout << "\n";
    }
}

void pattern18(int n) {
    for (i = 0; i < n; i++) {
        for (j = 'E' - i; j <= 'E'; j++) {
            cout << char(j) << " ";
        }
        cout << "\n";
    }
}

void printPattern19_A(int n) {
    for (i = 0; i < n; i++) {
        // Chars
        for (j = 0; j < n - i; j++) {
            cout << "* ";
        }

        // Spaces 
        for (k = 0; k < 2 * i; k++) {
            cout << "  ";
        }

        // Chars
        for (j = 0; j < n - i; j++) {
            cout << "* ";
        }
        cout << "\n";
    }
}

void printPattern19_B(int n) {
    for (i = 0; i < n; i++) {
        // Chars
        for (j = 0; j <= i; j++) {
            cout << "* ";
        }

        // Spaces 
        for (k = 0; k < 2 * (n - i - 1); k++) {
            cout << "  ";
        }

        // Chars
        for (j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << "\n";
    }
}

void printPattern19(int n) {
    printPattern19_A(n);
    printPattern19_B(n);
}

void printPattern20(int n) {
    int ind1, ind2;

    for (i = 1; i <= 2 * n - 1; i++) {
        ind1 = i;
        ind2 = 2 * (n - i);
        if (i > n) {
            ind1 = 2 * n - i;
            ind2 = 2 * (i - n);
        }

        // Chars
        for (j = 0; j < ind1; j++) {
            cout << "* ";
        }

        for (k = 0; k < ind2; k++) {
            cout << "  ";
        }

        // Chars
        for (j = 0; j < ind1; j++) {
            cout << "* ";
        }
            cout << "\n";
    }
}

void printPattern21(int n) {
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "\n";
    }
}

void printPattern22(int n) {
    int top, bottom, left, right;
    for (i = 0; i < 2 * n - 1; i++) {
        for (j = 0; j < 2 * n - 1; j++) {
            top = i;
            left = j;
            bottom = (2 * n - 1) - 1 - i;
            right = (2 * n - 1) - 1 - j;
            cout << (n - min(min(top, bottom), min(left, right))) << " ";
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
        printPattern19(n);
        cout << "\n";
    }
    return 0;
}