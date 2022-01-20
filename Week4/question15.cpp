// Given two library versions of an executable: for example, “10.1.1.3” and “10.1.1.9” or “10” and “10.1”. Find out which one is more recent? Strings can be empty also.

//CODE

#include<bits/stdc++.h>
using namespace std;

void vcheck(string s, vector<string>& v) {
    int st = 0;
    int ed = s.find('.');
    while (ed != string::npos) 
    {
        v.push_back(s.substr(st, ed - st));
        st = ed + 1;
        ed = s.find('.', st);
    }
    v.push_back(s.substr(st));
}

int main() {
    string s, t;
    cout<<"1st one: ";
    cin >> s;
    cout<<"\n2nd library: ";
    cin>> t;
    if(s.empty() || t.empty())
        cout << max(s, t) << endl;
    else{
        vector<string> l1;
        vector<string> l2;
        vcheck(s, l1);
        vcheck(t, l2);

        bool flag = false;
        int i = 0, j = 0;
            int n = l1.size(), m = l2.size();
            while (i < n && j < m) {
                if (l1[i] == l2[j]) {
                    i++;
                    j++;
                } else {
                    flag = true;
                    cout<<"Latest one is : ";
                    if(l1[i] > l2[j])  
                        cout<<s<<endl ;
                    else 
                        cout<<t<<endl;
                    break;
                }
            }
            if (!flag){   
                cout <<"\nLatest one is : ";
                if(j == m)  
                    cout<<s<<endl ;
                else 
                    cout<<t<<endl;
            }
    }    
    return 0;
}