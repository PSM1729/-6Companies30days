// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> arr, int k) {
        unordered_map<int, int> map;
        for (int e : arr) {
            int rem = e % k;
            int complementOne = -rem;
            int complementTwo = rem < 0 ? - k - rem : k - rem;

            if (map[complementOne]) {
                map[complementOne] -= 1;
            } else if (map[complementTwo]) {
                map[complementTwo] -= 1;
            } else {
                map[rem] += 1;
            }
        }

        for (auto e : map) {
            if (e.second) return false;
        }

        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends