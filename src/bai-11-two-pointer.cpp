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

    // sắp xếp tăng a bà b tăng dần để dễ dàng xử lý hơn
    sort(a, a + n);
    sort(b, b + m);

    int i = 0; // duyệt a
    int j = 0; // duyệt b

    vector<int> ans;

    // khi còn trong mảng (chưa lố)
    while (i < n && j < m) {
        // nếu a[i] == b[j]
        if (a[i] == b[j]) {
            ans.push_back(a[i]); // gặp giá trị xuất hiện ở cả 2 dãy => bỏ vào vector kết quả
            
            // nếu phần tử kề sau phần tử thứ i của a thì bỏ qua nó (khỏi đếm trùng)
            while (i < n - 1 && a[i + 1] == a[i]) {
                i += 1;
            }
            
            // nếu phần tử kề sau phần tử thứ j của b thì bỏ qua nó (khỏi đếm trùng)
            while (j < m - 1 && b[j + 1] == b[j]) {
                j += 1;
            }
            
            // tịnh tiến i và j
            i += 1;
            j += 1;
        }
        // nếu b[j] vẫn còn đang nhỏ hơn a[i]
        else if (b[j] < a[i]) {
            // thì mình chỉ cần tịnh tiến j với mong muốn thu gọn khoảng cách đó (tăng b giữ a)
            j += 1;
        }
        // trường hợp còn lại là a[i] < b[j], hay b[j] đã lớn hơn a[i]
        else {
            // thì mình chỉ cần tịnh tiến i (tăng a giữ b)
            i += 1;
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " \n"[i == (int) ans.size() - 1];
    }
    return 0;
}
