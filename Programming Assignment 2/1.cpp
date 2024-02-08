#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
long long ans = 0; // Count number of Inversions 
void Sort(vector<long long int> &arr, int i, int j){
    if(i>=j) return; // Base case 
    
    //Divide the array in two sorted array using recursive calls
    int mid = (i + j) / 2;
     Sort(arr, i, mid);
     Sort(arr, mid + 1, j);
    
    //Merge two sorted parts of the array 
    vector<long long int> temp;
    int idx1 = i, idx2 = mid + 1;
    while(idx1 <= mid && idx2 <= j){
        if(arr[idx1] <= arr[idx2]){
            temp.push_back(arr[idx1]);
            idx1++;
        }
        else{
            ans += mid - idx1 + 1; // Count of inversions with arr[idx2] as the smaller element 
            temp.push_back(arr[idx2]);
            idx2++;
        }
    }
    while(idx1 <= mid){
        temp.push_back(arr[idx1]);
        idx1++;
    }
    while(idx2 <= j){
        temp.push_back(arr[idx2]);
        idx2++;
    }
    
    // Copy the sorted value to arr
    for(int k = i; k <= j; k++) arr[k] = temp[k - i];
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<long long int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        Sort(arr, 0, n-1);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}