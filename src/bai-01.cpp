#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100009;

int n, s, a[N] = {};

// hàm chỉ để debug với test có n <= 10^4
int naive() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] <= s) {
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

    sort(a, a + n);

    long long count = 0;
    for (int i = 0; i < n; i++) {
        int need = s - a[i];
        // tìm phần trong mảng a mà với mọi phần tử từ đó trở về trước (không tính nó) cộng với a[i] sẽ không vượt quá s đề cho
        int p = upper_bound(a, a + n, need) - a;
        
        // cứ cộng vào trước, tính sau
        count += p;

        /**
         * nếu phần mình tìm lớn hơn hoặc bằng vị trí mình đang xét thì phải trừ 1 khỏi count
         * vì nếu p > i thì sẽ bị tính a[i] + a[i] => đếm dư => phải trừ đi trường hợp này
         * NOTE: vì mình tìm upper_bound nên sẽ không thể xảy ra trường hợp p == i nên cũng không cần xét >= chi cả
         * nếu không có thì fail tại test:
         * n = 3
         * s = 6
         * a = 3 3 3
         */
        if (p > i) {
            count -= 1;
        }
    }

    // vì mình sẽ đếm 2 lần trường hợp (i, j) và (j, i) nên phải cắt một nửa đi
    count /= 2;

    // nếu n <= 10000 thì so sánh với thuật ngây thơ O(n^2)
    // nếu kết quả không đúng thì sẽ throw => Runtime error
    if (n <= 10000) {
        assert(count == naive());
    }

    cout << count << endl;
    return 0;
}
