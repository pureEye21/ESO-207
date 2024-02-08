#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
 
const int MAX_N = 1e5 + 5;
vector<int> graph[MAX_N];
int par[MAX_N];
int dfn[MAX_N];
int back_edges[MAX_N];
int cycle[MAX_N];
int cnt;

void dfs(int vertex) {
  dfn[vertex] = cnt++;
  for (auto &child : graph[vertex]) {
      if(dfn[child] == 0){
          par[child] = vertex;
          dfs(child);
          back_edges[vertex] += back_edges[child];
      }
      else if(dfn[child] > dfn[vertex]){
          back_edges[vertex]--;
      }
      else{
          back_edges[vertex]++;
      }
  }
  back_edges[vertex]--;
}
 
int main () {
    
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    for(int i= 0; i< m; i++){
        cin >> b[i];
        graph[a[i]].push_back(b[i]);
        graph[b[i]].push_back(a[i]);
    }
    
    for(int i = 1; i <= n; i++){
        if(dfn[i] == 0){
            cnt = 1;
            dfs(i);
            back_edges[i] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        if(back_edges[i]){
            cycle[i] = 1;
            cycle[par[i]] = 1;
        }
    }
    
    for(int i = 1; i <= n; i++){
        cout << cycle[i] << " ";
    }
    
}
