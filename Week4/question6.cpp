// Generate Parentheses 

//CODE

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void generateParentheses(int n, int open, int close, string s, vector<string>&ans)
    {
        if(open==n && close==n){
            ans.push_back(s);
            return;
        }
        if(open<n)
            generateParentheses(n, open+1, close, s+"(", ans);
            
        if(close<open)
            generateParentheses(n, open, close+1, s+")", ans);
    
    }
    
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        string s= "";
        generateParentheses(n, 0, 0, s, ans);
        return ans;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends