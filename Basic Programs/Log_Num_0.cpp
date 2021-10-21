#include <iostream>
using namespace std;

int log_a_base_b(int a, int b)
{
    return (a > b -1)? 1 + log_a_base_b(a/b, b): 0;
}

int main()
{
    int a;
    int b;
    cout<<"Enter the value of 'a': "<<endl;
    cin>>a;
    cout<<"Enter the value of 'b': "<<endl;
    cin>>b;
    //printf("%d\n",log_a_base_b(a,b));
    cout<<log_a_base_b(a,b)<<endl;
    return 0;
}