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
    
    /*
    HDSD hai hàm lower_bound và upper_bound để thực hiện việc tìm kiếm nhị phân trên một mảng đã được sắp xếp tăng một cách nhanh hơn

    n = 7
    a = 1 2 3 3 3 4 5

    - Cấu trúc hai hàm
        #include <algorithm>

        std::lower_bound(start_iterator, end_iterator, value);
        std::upper_bound(start_iterator, end_iterator, value);

        khoảng giá trị thực hiện việc tìm kiếm là [start_iterator; end_iterator)
        để lấy iterator cho mảng bình thường, ta sẽ dùng toán tử cộng
        ví dụ ta có mảng a:
        - đoạn [3, 8) thì start và end iterator sẽ là [a + 3, a + 8)
        - đoạn [0, 10) thì start và end iterator sẽ là  [a + 0, a + 10), vì + 0 có thể lược bớt nên cũng có thể viết lại thành [a, a + 10)
        
        với std::vector, ta cũng có thể cộng như thế, nhưng phải truy vấn vào iterator begin() trước khi cộng
        ví dụ ta có std::vector v:
        - đoạn [3, 8) thì start và end iterator sẽ là [v.begin() + 3, v.begin() + 8)
        - đoạn [0, 10) thì start và end iterator sẽ là  [v.begin() + 0, v.begin() + 10), vì + 0 có thể lược bớt nên cũng có thể viết lại thành [v.begin(), v.begin() + 10)
        - giả sử ta cần tìm cả vector thì start và end iterator của ta sẽ là [v.begin(), v.begin() + v.size()), tuy nhiên std::vector có cung cấp cho mình hàm để lấy
            iterator cuối vector là vector.end() nên thay vì phải gọi vector.begin() + vector.size() thì ta chỉ cần gọi vector.end() nên có thể viết lại thành
            [v.begin(), v.end())
    
    - Cụ thể
    
    p = std::lower_bound(a, a + n, x)
        => tìm kiếm nhị phân phần tử đầu tiên sao cho giá trị phần tử đó lớn hơn hoặc bằng x và trả về con trỏ trỏ vào phần tử đó
            nói cách khác, nếu ta cho x = 3 thì sẽ có thể hình dung như sau
        
        a = 1 2 3 3 3 4 5
        p = lower_bound(a, a + n, 3)

        a = 1   2   3   3   3   4   5
                    ^
                    p
        
        để lấy được index, ta trừ địa chỉ của con p cho địa chỉ của mảng => index = p - a (p - a.begin() nếu a là vector)
    
    p = std::upper_bound(a, a + n, x)
        => tìm kiếm nhị phân phần tử đầu tiên sao cho giá trị phần tử đó lớn hơn x và trả về con trỏ trỏ vào phần tử đó
            nói cách khác, nếu ta cho x = 3 thì sẽ có thể hình dung như sau
        
        a = 1 2 3 3 3 4 5
        p = upper_bound(a, a + n, 3)

        a = 1   2   3   3   3   4   5
                                ^
                                p
        
        để lấy được index, ta trừ địa chỉ của con p cho địa chỉ của mảng => index = p - a (p - a.begin() nếu a là vector)
    */

    long long count = 0;
    for (int i = 0; i < n; i++) {
        int p = lower_bound(b, b + m, s - a[i]) - b;
        count += p;
    }

    cout << count << endl;
    return 0;
}
