#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    long long n;
    cin >> n;
    vector <long long> a(n);
    vector <long long> prefixSum(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];   
    }
    long long sum_max = a[0];
    long long start = 0, end = 0;
    
//______________O(N^3)_________________//

    // for (long long i = 0; i < n; i++) {
    //     for (long long j = i; j < n; j++) {
    //         long long sum = 0;
    //         for (long long k = i; k <=j ;k++){
    //             sum += a[k];
    //             if (sum > sum_max){
    //                 start = i;
    //                 end = k;
    //                 sum_max = sum;
    //             }
    //         }
    //     }
    //}

//______________O(N^2)_________________//
    // prefixSum[0] = a[0];
    // for (long long i = 1; i < n; i++){
    //     prefixSum[i] = a[i] + prefixSum[i-1];
    // } 
    // sum_max = 0;
    // for (long long i = 0; i < n; i++){
    //     for (long long j = i + 1; j < n; j++) {
    //         long long sum = prefixSum[j] - prefixSum[i];
    //         if (sum > sum_max){
    //             start = i + 1 ;
    //             end = j;
    //            sum_max = sum;
    //         }
    //     }
    // }
//______________O(N)_________________//
    long long checkStart = 0;
    long long minPr = 0;
    prefixSum[0] = a[0];
    for (long long i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i-1] + a[i];
        if (sum_max < prefixSum[i] -minPr){
            sum_max = prefixSum[i] - minPr;
            start = checkStart + 1;
            end =i;
        }
        if (prefixSum[i] < minPr){
            minPr = prefixSum[i];
            checkStart = i;
        }
    }
    cout << sum_max <<endl;
    cout << start << " " << end << endl;
    return 0;
}