#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100009;

int n, m, a[N] = {}, b[N] = {};

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + m);

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        // nếu trùng với giá trị cũ => bỏ
        if (i > 0 && a[i - 1] == a[i]) {
            continue;
        }

        // tìm kiếm nhị phân
        int p = lower_bound(b, b + m, a[i]) - b;
        // nếu nằm ngoài [0; m) thì bỏ vì vô nghĩa
        if (p < 0 || m <= p) {
            continue;
        }

        // cần điều kiện này vì lower_bound trả về giá trị đầu tiên >= nên có khả năng tìm được giá trị > giá trị đang cần
        if (a[i] == b[p]) {
            ans.push_back(a[i]);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " \n"[i == (int) ans.size() - 1];
    }
    return 0;
}
