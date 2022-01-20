// Total number of ways n can be expressed as sum of xth power of unique natural numbers

//CODE

// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    long long int mod = 1e9+7;
    int numOfWays(int n, int x)
    {
        vector<int> dp(n+1,0);   
        dp[0]=1;
        dp[1]=1;
        int maxi= pow(n, 1.0/x);
        for(int i=2; i<=maxi; i++)
        {
            int p= pow(i,x);
            for(int j=n; j>=p; j--)
                dp[j]= (dp[j]+dp[j-p])%mod;
        }
        
        return dp[n]%mod;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends