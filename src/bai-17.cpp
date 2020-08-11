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
    prefixSum[0] = a[0];
    for (long long i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1] + a[i]; 
        if (prefixSum[i] == 0){ 
            count++;
        }
    }
    long long count = 0;
    //______O(N^3)_________//
    // for (long long i  = 0; i < n; i++){
    //     for (long long j = i; j < n; j++){
    //         long long sum =0;
    //         for (long long k = i; k <= j; k++)
    //             sum += a[k];
    //         if (sum == 0)
    //             count++;
    //     }
    // }

    //___________O(N^2)___________//
    // for (long long i = 1; i < n; i++) {
    //      for (long long j = 1; j < n; j++) {
    //          if (sum[j] - sum[i - 1] == 0){
    //             count ++;
    //          }
    //     }
    // }

//___________O(NlogN)___________//
//     sort(prefixSum.begin(), prefixSum.end());
//     long long tmp = 1;
//     for (long long i  = 0; i < n; i++){
//         if (prefixSum[i] == prefixSum[i-1]){
//             tmp++;
//         }
//         else {
//             count += tmp * (tmp - 1)/2;
//             tmp = 1;
//         }
//     }
//     count += tmp * (tmp - 1)/ 2;

//___________O(N)___________//
    long long minPr = prefixSum[0], maxPr = prefixSum[0];
    for (long long i = 0; i < n; i++){
        if (prefixSum[i] < minPr){
            minPr = prefixSum[i];
        }
        if (prefixSum[i] > maxPr){
            maxPr = prefixSum[i]
        }
    }
    long long tmp  = 1;
    vector <long long > tmpSum(n);
    while (tmp <= maxPr){
        for (long long i = 0; i < n; i++){
            tmpSum[i] = prefixSum[i];
        }
        vector <long long> vec(10,0);
        for (long long i = 0; i < n; i++){
            vec[(tmpSum[i]/tmp) % 10]++;
        }
        for (long long i = 1; i < 10; i++){
            vec[i] = vec[i] + b[i-1];
        }
        for (long long i = tmpSum.size()-1; i >= n; i--){
            prefixSum[vec[tmpSum[i]/tmp%10] -1] = tmpSum[i];
            vec[tmpSum[i]/tmp%10]--;
        }
        tmp *= 10;
    }
    tmp = 1;
    for (long long i  = 0; i < n; i++){
        if (prefixSum[i] == prefixSum[i-1]){
            tmp++;
        }
        else {
            count += tmp * (tmp - 1)/2;
            d = 1;
        }
    }
    count += d * (d - 1)/ 2;

    cout << count << edl;
    return 0;
}
