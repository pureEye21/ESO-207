#include <iostream>
using namespace std;

void matrix_multiplication(long long** arr1, long long** arr2, long long k, long long mod){
    long long** mult = new long long*[k];
    for (int i = 0; i < k; ++i){
        mult[i] = new long long[k];
    }
    
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            mult[i][j] = 0;
            for(int l = 0; l < k; l++){
                mult[i][j] = (mult[i][j] + (arr1[i][l] * arr2[l][j]) % mod) % mod;
            }
        }
    }
    
    // Copying back the multiplied values to arr1
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            arr1[i][j] = mult[i][j];
        }
    }
    
    // Free up the space
    for(int i = 0; i < k; i++){
        delete[] mult[i];
    }
    delete[] mult;
}

// function to calculate arr^n
void matrix_exponentiation(long long** arr, long long k, long long n, long long mod){
    if(n == 1) return;
    
    // making temp arr for n % 2 == 1 case
    long long** temp = new long long*[k];
    for (int i = 0; i < k; ++i){
        temp[i] = new long long[k];
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            temp[i][j] = arr[i][j];
        }
    }
    
    // using arr^n = arr^n/2 * arr^n/2
    matrix_exponentiation(arr, k, n/2, mod);
    matrix_multiplication(arr, arr, k, mod);
    
    // If n is odd multiply arr again 
    if(n % 2 == 1){
        matrix_multiplication(arr, temp, k, mod);
    }
    
    // Free up the space
    for (int i = 0; i < k; ++i){
        delete[] temp[i];
    }
    delete[] temp;
    
    return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        if(n <= 1){
            cout << 1 << endl;
            continue;
        }
        long long** arr = new long long*[k];
        for (int i = 0; i < k; ++i){
            arr[i] = new long long[k];
        }
        
        /* Since sum[i] = sum[i-1] + sum[i-2] + sum[i-3] + ... Problem can be reformulated as nth term fibonnaci with 
        each term as sum of previous k terms. This can be solved using matrix exponentiation.
        */
        for(int i = 0; i < k; i++){
            arr[0][i] = 1;
        }
        for(int i = 1; i < k; i++){
            for(int j = 0; j < k; j++){
                if(j == (i-1)) arr[i][j] = 1;
                else arr[i][j] = 0;
            }
        }
        
        long long mod = 998244353;
        matrix_exponentiation(arr, k, n - 1, mod);
        cout<<(arr[0][0] + arr[0][1]) % mod<<endl;
    }
    return 0;
}
