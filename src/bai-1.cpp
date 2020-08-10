#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    long long n, x;
    cin >> n >> x;
    vector <long long> a(n);
    for (long long i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long start = 0, end = 0;
    for (long long i = 0; i < n; i++){
        if (a[i] == x || (a[i] < x && a[i+1] > x)) {
            end = i;
        }
    }
    long long count = 0;
    while (start != end){
        if (a[start]+ a[end] <= x){
            start++;
            count++;
        }
        else {
            end--;
            start = 0;
        }
    }
    cout << count << endl;
    return 0;
}