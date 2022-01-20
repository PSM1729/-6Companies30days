//Find the length of the Longest Arithmetic Progression (LLAP) in it

//CODE

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        if (n <= 2)  
            return n;

        int L[n][n];
        int llap = 2;  
        for (int i = 0; i < n; i++)
            L[i][n-1] = 2;
    
        for (int j=n-2; j>=1; j--)
        {
            int i = j-1, k = j+1;
            while (i >= 0 && k <= n-1)
            {
               if (A[i] + A[k] < 2*A[j])
                   k++;
               else if (A[i] + A[k] > 2*A[j])
               {   L[i][j] = 2, i--;   }
    
               else
               {
                   L[i][j] = L[j][k] + 1;
                   llap = max(llap, L[i][j]);
                   i--; k++;
               }
            }
    
            while (i >= 0)
            {
                L[i][j] = 2;
                i--;
            }
        }
        return llap;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends