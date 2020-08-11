#include <bits/stdc++.h>
using namespace std;

struct point {
    int id;
    long long x;
    long long y;

    bool operator<(const point& rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }

    point() {}
    point(int id, long long x, long long y) : id(id), x(x), y(y) {}
};

const int N = 1000009;

int n;
vector<point> a;

long long ccw(point a, point b, point c) {
    return (b.x - a.x) * (b.y + a.y) + (c.x - b.x) * (c.y + b.y) + (a.x - c.x) * (a.y + c.y);
}

// O(n^2)
pair<int, int> better_but_not_best() {
    sort(a.begin(), a.end());
    int i = n / 2 - 1;
    for (int j = i + 1; j < n; j++) {
        int left_side = 0;
        int right_side = 0;
        for (int k = 0; k < n; k ++) {
            if (k == i || k == j) {
                continue;
            }
            if (ccw(a[k], a[i], a[j]) > 0) {
                left_side += 1;
            }
            else {
                right_side += 1;
            }
        }

        if (left_side == right_side) {
            return make_pair(a[i].id + 1, a[j].id + 1);
        }
    }
    return make_pair(-1, -1);
}

int main() {
    while (cin >> n) {
        a.clear();
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            a.push_back(point(i, x, y));
        }

        pair<int, int> ans = better_but_not_best();

        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}
