#include <iostream>
using namespace std;

const int N = 1009;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int n, m, a[N][N] = {};
long long prefix_sum[N][N] = {};

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix_sum[i][j] = prefix_sum[i][j - 1] + a[i][j];
        }
    }

    long long ans = -INF;
    for (int l = 1; l <= m; l++) {
        for (int r = l; r <= m; r++) {
            long long tmp = 0;
            for (int i = 1; i <= n; i++) {
                tmp += prefix_sum[i][r] - prefix_sum[i][l - 1];
                ans = max(ans, tmp);
                tmp = max(tmp, 0ll);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
