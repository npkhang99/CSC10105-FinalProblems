/*
Điều kiện tiên quyết giải bài này là giới hạn số số nguyên của tọa độ điểm nằm trong đoạn [-10e6, 10e6]
Để các slope được độ chính xác khi a/b != c/d (không bị giới hạn do máy tính lưu trữ số thực) thì phải sử dụng kiểu Double để đảm bảo
*/

#include <bits/stdc++.h>
using namespace std;

class Point_2D
{
private:
    int m_x, m_y, m_idx;

public:
    static Point_2D O;
    Point_2D(int x, int y, int idx) : m_x{ x }, m_y{ y }, m_idx{ idx } {}
    Point_2D(const Point_2D& another) : m_x{ another.m_x }, m_y{ another.m_y }, m_idx{ another.m_idx } {}

    int getIdx()
    {
        return m_idx;
    }

    static bool compareSlope(Point_2D A, Point_2D B)
    {
        double slope_a, slope_b;
        if (A.m_x == Point_2D::O.m_x)
        {
            if (A.m_y - Point_2D::O.m_y > 0)
                slope_a = DBL_MAX;
            else
                slope_a = -DBL_MAX;
        }
        else
            slope_a = (A.m_y - Point_2D::O.m_y) * 1.0 / (A.m_x - Point_2D::O.m_x);

        if (B.m_x == Point_2D::O.m_x)
        {
            if (B.m_y - Point_2D::O.m_y > 0)
                slope_b = DBL_MAX;
            else
                slope_b = -DBL_MAX;
        }
        else
            slope_b = (B.m_y - Point_2D::O.m_y) * 1.0 / (B.m_x - Point_2D::O.m_x);

        return slope_a > slope_b;
    }
};

Point_2D Point_2D::O = Point_2D(0, 0, -1);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n, x, y, min_x = INT_MAX, pos_O;
    vector <Point_2D> map;

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> y;
        map.push_back(Point_2D(x, y, i));

        // tim O co hoanh do x nho nhat
        if (x < min_x)
        {
            min_x = x;
            pos_O = i - 1;
        }
    }

    // loai diem tree_O ra khoi mang, va tree_O tro thanh goc
    Point_2D tree_O = map[pos_O];
    if (pos_O != n - 1)
    {
        map[pos_O] = map[n - 1];
    }
    map.pop_back();
    Point_2D::O = tree_O;

    // sap xep mang theo do doc cua tree_O
    sort(map.begin(), map.end(), Point_2D::compareSlope);

    // diem trung vi tree_O2
    Point_2D tree_O2 = map[map.size() / 2];

    cout << tree_O.getIdx() << ' ' << tree_O2.getIdx() << endl;

    return 0;
}
