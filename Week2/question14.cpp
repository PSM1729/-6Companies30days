// Burning tree

//CODE

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    Node *targetNode = NULL;
  
    void getParentMapping(Node *node, Node *par, map<Node *, Node *> &parents, int &target) {
        if(node == NULL) return;
        parents[node] = par;
        if(node -> data == target) targetNode = node;
        
        getParentMapping(node -> left, node, parents, target);
        getParentMapping(node -> right, node, parents, target);
    }
    
    int getMaxDistance(Node *node, map<Node *, Node *> &parents) {
        queue<Node *> q;
        map<Node *, bool> vis;
        
        q.push(node);
        vis[node] = true;
        int dis = 0;
        
        while(!q.empty()) {
            bool left = false;
            int sz = q.size();
            // cout << sz << "  ";
            for(int i = 0; i < sz; i++) {
                auto next = q.front();
                // cout << next -> data << " ";
                q.pop();
                if(next == NULL) continue;
                
                // cout << next -> data << " ";
                
                if(next -> left && !vis[next -> left]) {
                    vis[next -> left] = true;
                    q.push(next -> left);
                    left = true;
                }
                if(next -> right && !vis[next -> right]) {
                    vis[next -> right] = true;
                    q.push(next -> right);
                    left = true;
                }
                if(parents[next] != NULL && !vis[parents[next]]) {
                    vis[parents[next]] = true;
                    q.push(parents[next]);
                    left = true;
                }
            }
            // cout << "\n";
            if(left)
                dis++;
        }
        return dis;
    }
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node *, Node *> parents;
        getParentMapping(root, NULL, parents, target);
        // cout << targetNode -> data << "\n";
        // cout << parents.size() << "\n";
        // for(auto m : parents) {
        //     if(m.first == NULL || m.second == NULL) continue;
        //     cout << (m.first) -> data << " " << (m.second) -> data << "\n";
        // }
        int ans = getMaxDistance(targetNode, parents);
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends