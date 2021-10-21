/*
https://www.tutorialcup.com/interview/string/integer-to-roman.htm
*/

/*C++ Implementation of Integer to Roman conversion Problem*/ 
#include<bits/stdc++.h>
using namespace std;
/*function to add the precalcuated values in vector.*/
void set_precalculated(vector<pair<int,string>>&v)
{
    v.push_back({1,"I"});
    v.push_back({4,"IV"});
    v.push_back({5,"V"});
    v.push_back({9,"IX"});
    v.push_back({10,"X"});
    v.push_back({40,"XL"});
    v.push_back({50,"L"});
    v.push_back({90,"XC"});
    v.push_back({100,"C"});
    v.push_back({400,"CD"});
    v.push_back({500,"D"});
    v.push_back({900,"CM"});
    v.push_back({1000,"M"});
}
int main() 
{ 
    int n;
    /*take N as input*/
    cin>>n;
    /*create a vector to store the precalculated roman values for some numbers(base numbers).*/
    vector<pair<int,string>> v;
    /*store the values*/
    set_precalculated(v);
    /*string which containg the final answer.*/
    string ans="";
    /*size of the vector*/
    int sz=v.size();
    /*repeat while N greter than 0.*/
    while(n>0&&sz>=0)
    {
        /*turn store the value which means we need to add v[sz-1].second turn number of times.*/
        int turn=n/(v[sz-1].first);
        /*update the value of N.*/
        n=n%(v[sz-1].first);
        /*add to the answer.*/
        for(int k=0;k<turn;k++)
        {
            ans+=(v[sz-1].second);
        }
        /*move to the next lowest precalculated number in vector*/
        sz--;
    }
    cout<<ans<<endl;
    return 0; 
}