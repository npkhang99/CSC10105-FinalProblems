#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

struct heap_element {
    int i, j;
};

const int N = 100009;

int n, k, a[N] = {};

// cần thiết để dùng min-heap
bool operator<(const heap_element& lhs, const heap_element& rhs) {
    return a[lhs.i] + a[lhs.j] > a[rhs.i] + a[rhs.j];
}

bool check_and_insert(heap_element e, set<heap_element> &used, priority_queue<heap_element> &heap) {
    // cặp (i, j) phải nằm trong mảng, mà i luôn nhỏ hơn j nên không cần phải check i < n => điều kiện 1
    // vì i phải khác j => điều kiện thứ hai
    // vì cặp (i, j) phải chưa được dùng => không có trong set nên set.find phải trả về iterator end của set đó => điều kiện thứ ba
    if (e.j < n && e.i != e.j && used.find(e) == used.end()) {
        used.insert(e);
        heap.push(e);
        return true;
    }
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // sắp xếp lại mảng theo thứ tự tăng dần
    sort(a, a + n);

    // min-heap để lưu các phần tử theo thứ tự tăng dần của tổng => truy vấn phần tử đầu của heap là tổng nhỏ nhất hiện tại trong heap
    priority_queue<heap_element> heap;
    // một tập hợp chứa các cặp tổng đã dùng rồi, chủ yếu dùng để tránh tính lại những tổng đã được tính
    set<heap_element> used;

    // phần tử đầu tiên (hay là tổng nhỏ nhất mình có đầu tiên) đó là tổng 2 số nhỏ nhất của mảng (là a[0] + a[1])
    // nhét cặp số (0, 1) vào heap và vào tập hợp các giá trị đã dùng
    heap.push({0, 1});
    used.insert({0, 1});

    // vì mình cần tổng thứ k => cần phải pop k lần => for k - 1 lần để phần tử đầu heap là tổng lớn thứ k
    for (int i = 0; i < k - 1; i++) {
        // lấy phần tử đầu heap
        heap_element top = heap.top();
        // pop nó ra
        heap.pop();

        /**
         * với một cặp giá trị (i, j) thì mình có 2 cách đi:
         * 1. tăng i và giữ j, hay nói cách khác là (i + 1, j)
         * 2. giữ u và tăng j, hay nói cách khác là (i, j + 1)
         * => vì không biết chọn cái nào nên cứ test thử cả 2 trường hợp và thêm nó vào một cách mù quáng, để heap và set xử lý vụ tổng
         * 
         * tại sao lại +1:
         * vì nếu mình cộng hơn 1 thì chỉ làm tổng của mình lớn hơn nữa thôi vì mảng của mình đã được sắp xếp tăng dần rồi
         */

        check_and_insert({top.i + 1, top.j}, used, heap);
        check_and_insert({top.i, top.j + 1}, used, heap);
    }

    cout << a[heap.top().i] + a[heap.top().j] << endl;
    cout << heap.top().i << " " << heap.top().j << endl;
    return 0;
}
