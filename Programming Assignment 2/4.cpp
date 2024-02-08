#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        
        // Input 
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        vector<pair<int, int>> intervals(s);
        for(int i = 0; i < s; i++){
            int l , r;
            cin >> l >> r;
            l--;
            r--;
            intervals[i].first = l;
            intervals[i].second = r;
        }
        
        int q, k;
        cin >> q >> k;
        
        vector<int> appear(n, 1e9); // First time arr[i] is updated 
        for(int i = 0; i < q; i++){
            int idx; cin >> idx;
            idx--;
            
            if(arr[idx] != 1) appear[idx] = min(appear[idx], i + 1);
        }
        
        int lo = 0, hi = q, mid; 
        bool flag = false;
        // Binary search over number of queries completed
        while(hi >= lo){
            mid = (hi + lo) / 2;
            
            vector<int> sum(n + 1);
            for(int i = 0; i < n; i++){
                if(appear[i] != 1e9 && appear[i] <= mid){     // Condition for arr[i] = 1
                    arr[i] = 1;
                } else if(appear[i] != 1e9 && appear[i] > mid){ // Condition for arr[i] = -1
                    arr[i] = -1;
                }
                
                sum[i + 1] = sum[i] + arr[i]; // Prefix sum array 
            }
            
            // Count of intervals with sum > 0
            int cnt = 0;
            for(int i = 0; i < s; i++){
                int l = intervals[i].first;
                int r = intervals[i].second;
                
                if(sum[r+1] - sum[l] > 0) cnt++;
            }
            
            if(cnt >= k){
                hi = mid;
                flag = true;
                if(hi == lo) break;
            }
            else lo = mid + 1; 
        }
        
        if(flag) cout << hi << endl;
        else cout << -1 << endl;
    }
    return 0;
}