// Possible Words From Phone Digits

//CODE

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> mob = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void bt(int a[], int N, int i, string com){
        if(com.length() == N){
            ans.push_back(com);
            return;
        }
        for(auto ch: mob[a[i]]){
            com.push_back(ch);
            bt(a,N,i+1,com);
            com.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        string com;
        bt(a,N,0,com);
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends