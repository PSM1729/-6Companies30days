// String Amendment

//CODE

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        string ans="";
        for(int i=0; i<s.length(); i++)
        {
            if(isupper(s[i]))
            {
                if(i!=0)
                 ans+= " ";
                
                ans+=(s[i]+32);
            }
            else
            {
                ans+= s[i];
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends