#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<queue>
#include<unordered_map>

#define int long long
#define pb push_back
using std::string;
#define all(a) (a).begin(), (a).end()
#define read(v) {for (auto& el : (v)) std::cin >> el;}
#define print(v) {for (auto el : (v)) std::cout << el << ' ';}
#define npt nuintptr

using ull = uint64_t;
using ld = double;
using std::endl;
using vll = std::vector<int>;
using pll = std::pair<int, int>;
using mll = std::vector<vll>;
const int inf = 1e17;

vll mul(vll a, vll b) {
    if (a.size() < 128 && b.size() < 128) {
        vll ans(std::max(a.size(), b.size()) * 2);
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                ans[i + j] += a[i] * b[j];
            }
        }
        return ans;
    }
    int l = std::max(a.size(), b.size());
    if (l % 2) ++l;
    while (a.size() < l) a.pb(0);
    while (b.size() < l) b.pb(0);
    vll af = {a.begin() + l / 2, a.end()},
        ae = {a.begin(), a.begin() + l / 2},
        bf = {b.begin() + l / 2, b.end()},
        be = {b.begin(), b.begin() + l / 2};
    vll afbf = mul(af, bf), aebe = mul(ae, be);
    vll afae(l / 2);
    for (int i = 0; i < l / 2; ++i) {
        afae[i] = af[i] + ae[i];
    }
    vll bfbe(l / 2);
    for (int i = 0; i < l / 2; ++i) {
        bfbe[i] = bf[i] + be[i];
    }
    vll ans = mul(afae, bfbe);
    for (int i = 0; i < l; ++i) {
        ans[i] -= afbf[i] + aebe[i];
    }
    vll ret(2 * l);
    for (int i = 0; i < l; ++i) {
        ret[i] = aebe[i];
    }
    for (int i = l; i < 2 * l; ++i) {
        ret[i] = afbf[i - l];
    }
    for (int i = l / 2; i < l + l / 2; ++i) {
        ret[i] += ans[i - l / 2];
    }
    return ret;
}

signed main() {
#ifndef LOCAL
    std::freopen("multiply.in", "r", stdin);
    std::freopen("multiply.out", "w", stdout);
#endif
    std::string a, b;
    std::cin >> a >> b;
    if (a == "0" || b == "0") {
        std::cout << 0;
        return 0;
    }
    int sign = 1;
    if (a[0] == '-') sign *= -1;
    if (b[0] == '-') sign *= -1;
    vll va, vb;
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] >= '0' && a[i] <= '9') va.pb(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; --i) {
        if (b[i] >= '0' && b[i] <= '9') vb.pb(b[i] - '0');
    }
    vll ans = mul(va, vb);
    while (ans.back() == 0) ans.pop_back();
    int i = 0;
    while (true) {
        if (i >= ans.size()) break;
        if (ans[i] > 9) {
            if (i + 1 < ans.size()) {
                ans[i + 1] += ans[i] / 10;
            } else {
                ans.pb(ans[i] / 10);
            }
        }
        ans[i] %= 10;
        ++i;
    }
    if (sign == -1) std::cout << '-';
    for (int i = ans.size() - 1; i >= 0; --i) std::cout << ans[i];
}