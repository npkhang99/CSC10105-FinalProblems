#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main (){
    long long n, k;
    cin >> n >> k;
    vector <long long> a(n);
    // vector <long long> sum(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];   
    }
    set <long long> s;
    long long res = 0, sum = 0;
    for (long long i = 0; i < n; i++){
        sum = (sum + a[i]) %k;
        if (sum < 0) {
            sum += k;
        }
        res = max(res, sum);
        auto j =  s.lower_bound(sum + 1);
        if (j != s.end()){
            res = max(res, sum - *j + k);
        }
        s.insert (sum);
    }
    cout << res << endl;
    return 0;
}