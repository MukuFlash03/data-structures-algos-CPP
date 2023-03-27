#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

vector <long long> sieveErato(long long int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    
    for (int i = 2; i*i <= n; i++)
    {
        if (prime[i] == true)
            for (int j = i*i; j <= n; j+=i)
                prime[j] = false;
    }
    
    long long int sum = 0, prod = 1;
    for (int i = 2; i <= n; i++)
        if (prime[i])
        {
            sum += i;
            prod *= i;
        }
    vector <long long> res;
    res.push_back(sum);
    res.push_back(prod);
    
    return res;
}


int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        long long int n;
        cin >> n;
        vector <long long> res =  sieveErato(n);
        cout << res[0] << "\t" << res[1] << endl;
        t--;
    }
    return 0;
}