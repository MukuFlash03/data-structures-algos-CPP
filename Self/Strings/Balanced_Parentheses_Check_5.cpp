/*
https://www.tutorialcup.com/interview/string/expression-contains-redundant-bracket-or-not.htm
*/

#include <bits/stdc++.h> 
using namespace std; 
  
bool checkRedundancy(string& s){ 
    stack<char> st; 
  
    for(auto& ch : s){ 
        if(ch == ')'){ 
            char top = st.top(); 
            st.pop(); 
  
            bool flag = true; 
  
            while(top != '('){ 
                if(top == '+' || top == '-' || top == '*' || top == '/'){ 
                    flag = false; 
                }
  
                top = st.top(); 
                st.pop(); 
            } 
  
            if(flag == true){ 
                return true; 
            }
        } 
        else{
            st.push(ch); 
        }
    } 
    return false; 
} 
  
void findRedundant(string& s){ 
    bool ans = checkRedundancy(s); 
    if(ans == true){ 
        cout << "Yes\n";
    }
    else{
        cout << "No\n"; 
    }
} 
  
int main(){
    
    string s = "((a+b))"; 
    findRedundant(s); 
  
    return 0; 
}