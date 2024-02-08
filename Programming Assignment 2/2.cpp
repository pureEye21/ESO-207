#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


vector<int> depth(1001); //Stores depth of each element 

//Tree nodes 
struct TreeNode{
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): key(val), left(nullptr), right(nullptr) {}
};

//Recursive Tree construction using given rule
TreeNode* makeTree(vector<int> &arr, int i, int j, int currDepth){
    if(i > j) return nullptr;
    
    //Find Maximum in range arr[i, j]
    int idx = i;
    int mx = arr[i];
    for(int k = i; k <= j; k++){
        if(arr[k] > mx){
            mx = arr[k];
            idx = k;
        }
    }
    
    depth[idx] = currDepth;
    
    TreeNode* node = new TreeNode(arr[idx]); //Make current node 
    node->left = makeTree(arr, i, idx - 1, currDepth + 1);
    node->right = makeTree(arr, idx + 1, j, currDepth + 1);
    
    return node;
}
int main()
{
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        vector<int> arr(n+1);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        TreeNode* root = makeTree(arr, 0, n - 1, 0);
        
        for(int i = 0; i < n; i++) cout << depth[i] << " ";
        cout << endl;
    }

    return 0;
}