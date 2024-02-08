#include <iostream>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        long long arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        //mid represents maximum height and cost stores total cost to make mid as maximum height
        long long lo = 0, hi = 1e6 + 1, mid, cost;
        while((hi - lo) > 1){
            mid = (hi + lo) / 2;
            cost = 0;
            for(int i = 0; i < n; i++){
                if(arr[i] > mid){
                    // cost = (mid+1) + (mid+2) + (mid+3) .... + arr[i] = sum of first (arr[i]) natural numbers - sum of fist (mid) natural numbers
                    cost += (arr[i] * (arr[i] + 1) / 2) - (mid * (mid + 1) / 2); 
                }
            }
            if(cost >= k){
                lo = mid;
            }
            else hi = mid;
        }
        cost = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] > lo){
                cost += (arr[i] * (arr[i] + 1) / 2) - (lo * (lo + 1) / 2); 
            }
        }
        if(cost <= k) cout << lo << endl;
        else cout << hi << endl;
    }
    return 0;
}
