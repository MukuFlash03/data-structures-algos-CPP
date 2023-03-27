#include <iostream>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

int main() {
    std::string str;
    getline(std::cin,str);

    int i;
    for(i = 0; str[i]; i++);
    std::cout << i;

}