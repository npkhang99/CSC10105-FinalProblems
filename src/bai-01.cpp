#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 100009;

int n, s, a[N] = {};

int naive() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] <= n) {
                count += 1;
            }
        }
    }
    return count;
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int expected = naive();
    cerr << expected << endl;

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        cerr << setw(2) << i << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        cerr << setw(2) << a[i] << " \n"[i == n - 1];
    }

    long long count = 0;
    for (int i = 0; i < n; i++) {
        int need = s - a[i];
        int p = upper_bound(a, a + n, need) - a;
        cerr << setw(2) << i << " " << setw(2) << a[i] << " " << setw(2) << need << " " << p << endl;
        count += p;
        if (p >= i) {
            count -= 1;
        }
    }

    cout << count << endl;
    return 0;
}
