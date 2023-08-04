//{ Driver Code Starts
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

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  void buildGraph(Node* root,unordered_map<int,vector<int>>& graph){
        
        if(root->left!=NULL){
            graph[root->data].push_back(root->left->data);
            graph[root->left->data].push_back(root->data);
            buildGraph(root->left,graph);
        }
        if(root->right!=NULL){            
            graph[root->data].push_back(root->right->data);
            graph[root->right->data].push_back(root->data);
            buildGraph(root->right,graph);            
        }
    }
    int minTime(Node* root, int target) {
        
        unordered_map<int,vector<int>> graph;
        unordered_map<int,bool> visited;
        queue<pair<int,int>> q;
        
        //build the graph
        buildGraph(root,graph);
        q.push({target,0});
        
        //bfs
        int ans=0;
        while(!q.empty()){
            auto t= q.front();q.pop();
            int curr=t.first;
            int vl=t.second;
            visited[curr]=true;
            ans=max(ans,vl);
            
            for(int x : graph[curr])
                if(!visited[x]) q.push({x,vl+1});
                
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

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