#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100009;

int n, m, s, a[N] = {}, b[N] = {};

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + m);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int p = lower_bound(b, b + m, s - a[i]) - b;
        if (p == 0) {
            break;
        }
        ans = max(ans, a[i] + b[p - 1]);
    }

    cout << ans << endl;
    return 0;
}
