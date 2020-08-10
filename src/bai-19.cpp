#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100009;

int n, x;
int a[2 * N] = {};

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
    }

    int l = 0, r = 0;
    long long sum = 0;
    int ans_l = 0, ans_r =  2 * n + 1;
    while (r < 2 * n) {
        sum += a[r];
        r += 1;

        while (l < r && sum >= x) {
            sum -= a[l];
            l += 1;
        }

        if (l > 0 && sum + a[l - 1] == x && r - (l - 1) < ans_r - ans_l) {
            ans_r = r;
            ans_l = l - 1;
        }
    }

    if (ans_r == 2 * n + 1) {
        cout << -1 << " " << -1 << endl;
    }
    else {
        cout << ans_l << " " << (ans_r - 1) % n << endl;
    }
    return 0;
}
