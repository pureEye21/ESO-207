#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 2e5 + 5;
const int MAX_LOG = 20;
int mat[MAX_N][MAX_LOG];
vector<int> adj[MAX_N];
int depth[MAX_N];
vector<int> a(MAX_N), b(MAX_N), c(MAX_N), d(MAX_N);
int dp [MAX_N];

void dfs(int node, int par = -1){
    for(auto &child : adj[node]){
        if(child == par) continue;
        mat[child][0] = node;
        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}

void sparseTable(int n){
    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= n; j++){
            if(mat[j][i - 1] != -1) mat[j][i] = mat[mat[j][i - 1]][i - 1];
        }
    }
}

int lca(int x, int y){
    if(depth[x] < depth[y]) swap(x, y);
    int dis = depth[x] - depth[y];
    while(dis){
        int temp = log2(dis);
        dis -= 1 << temp;
        x = mat[x][temp];
    }
    
    if(x == y) return x;
    for (int i = 19; i>=0; i--){
        if (mat[x][i] != mat[y][i]) 
        { 
            x = mat[x][i]; 
            y = mat[y][i]; 
        }
    }
 
    return mat[x][0];
}

void dfs2(int node, int par = -1){
    for(auto &child : adj[node]){
        if(child == par) continue;
        dfs2(child, node);
        dp[node] += dp[child];
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k; cin >> n >> k;
    for(int i = 0; i < (n - 1); i++){
        cin >> a[i];
    }
    for(int i = 0; i < (n - 1); i++){
        cin >> b[i];
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 20; j++) mat[i][j] = -1;
    }
    mat[1][0] = 0;
    dfs(1);
    sparseTable(n);
    for(int i = 0; i < k; i++){
        cin >> c[i] >> d[i];
        dp[c[i]]++;
        dp[d[i]]++;
        dp[lca(c[i], d[i])]--;
        dp[mat[lca(c[i], d[i])][0]]--;
    }
    
    dfs2(1);
    
    for(int i = 1; i <= n; i++) cout << dp[i] << " ";
    
    
    
    return 0;
}
