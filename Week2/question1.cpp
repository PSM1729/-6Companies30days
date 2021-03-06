// Maximum Profit

//CODE: 

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int A[]) {
        vector<vector<int>> dp(k + 1, vector<int>(n , 0));
        for(int t = 1; t <= k; t++){
            int mx=INT_MIN;
            for(int d = 1; d < n; d++){
                if(dp[t - 1][d - 1] - A[d - 1]  > mx)
                    mx = dp[t - 1][d - 1] - A[d - 1];

                dp[t][d] = max (dp[t][d - 1], mx + A[d]);
            }
        }
        /*for(auto i:dp){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }*/
        return dp[k][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends