#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    long long n, k;
    cin >> n, k;
    vector <long long> a(n);
    vector <long long> maxSum(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];   
    }
    maxSum[0] = a[0];
    long long cur_max  = a[0];
    for (long long i  = 1; i < n; i++){
        maxSum[i] = max(maxSum[i-1] + a[i], a[i]);
    }
    long long sum = 0;
    for (long long i  = 0; i < k; i++){
        sum += a[i];
    }
    long long result = sum;
    for (long long i  = k; i < n; i++){
        sum = sum + a[i] - a[i - k];
        result = max(result, sum);
        result = max (result, sum + maxSum[i -k]);
    }
    cout << result << endl;
    return 0;
}
