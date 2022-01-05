//DECODE STRING

//CODE

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        stack<string> chars;
        stack<int> nums;
        string res;
        int num = 0;
        for(char c : s) {
            if(isdigit(c)) {
                num = num*10 + (c-'0');                              
            }
            else if(isalpha(c)) {
                res.push_back(c);                
            }
            else if(c == '[') {
                chars.push(res);
                nums.push(num);
                res = "";
                num = 0;
            }
            else if(c == ']') {
                string tmp = res;
                for(int i = 0; i < nums.top()-1; ++i) {
                    res += tmp;
                }
                res = chars.top() + res;
                chars.pop(); nums.pop();
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends