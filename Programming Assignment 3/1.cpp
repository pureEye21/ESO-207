#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>> &g, vector<int> &color, int vertex, bool &flag){
    int curr_color = color[vertex]; 
    for(auto &child : g[vertex]){
        if(color[child] == curr_color){
            flag = false;
        }
        if(color[child]) continue; 
        if(curr_color == 1) color[child] = 2;
        else color[child] = 1;
        dfs(g, color, child, flag);
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> color(n + 1);
    bool flag = true;
    for(int i = 1; i <= n; i++){
        if(!color[i]){
            color[i] = 1;
            dfs(g,  color, i, flag);
        }
    }
    if(flag){
        cout << "YES" << endl;
        for(int i = 1; i <= n; i++) cout << color[i] << " ";
        cout << endl;
    }
    else cout << "NO" << endl;
    return 0;
}
