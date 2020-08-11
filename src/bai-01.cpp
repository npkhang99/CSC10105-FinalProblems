#include <iostream>
#include <map>
using namespace std;

const int N = 100009;

int n, s, a[N] = {};
map<int, int> count;

int main() {
    cin >> n>> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        count[a[i]] += 1;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int need = s - a[i];
        ans += count[need] - (need == a[i]);
    }

    cout << ans << endl;
    return 0;
}
