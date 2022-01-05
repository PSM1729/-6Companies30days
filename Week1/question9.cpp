//Given a pattern containing only I's and D's. I for increasing and Dfor decreasing.Devise an algorithm to print the minimum number following that pattern.

// CODE:

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        int n=S.length()+1;
        string ans;
        stack<string> st; 	
        for(int i=0;i<n;i++){
	    	st.push(to_string(i+1)); 
			if(S.length()==i || S[i]=='I' ){ 
				while(!st.empty()){ 
    				ans+=st.top();
    				st.pop();
			    }
		    }
	    }
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends