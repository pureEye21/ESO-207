#include <iostream>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        // arr[i] stores the maximum sum subarray starting at index i
        // if(arr[i+1] >= 0) we and take arr[i+1] and add arr[i];
        // if(arr[i+1] < 0) we take arr[i]; for max sum subarray 
        for(int i = n-2; i >= 0; i--){
            arr[i] = max(arr[i], arr[i+1] + arr[i]);
        }
        for(int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
