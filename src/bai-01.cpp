#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100009;

int n, s, a[N] = {};

int main() {
    cin >> n>> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    long long count = 0;
    for (int i = 0; i < n; i++) {
        int need = s - a[i];
        int p = upper_bound(a, a + n, need) - a;
        count += p - (need == a[i]);
    }

    cout << count << endl;
    return 0;
}
