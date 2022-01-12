#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL

#define ll long long
#define ull unsigned long long
#define vll vector<ll>
#define pii pair<ll, ll>
#define vii vector<pii>
#define vs vector<string>
#define vb vector<bool>
#define vi vector<int>
#define vd vector<double>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define ld long double
#define mapii map<int, int>
#define mapsi map<string, int>
#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

#endif

class Util {
public:
    vi readArray() {
        int n;
        cin >> n;
        return readArray(n);
    }

    vi readArray(int n) {
        vi a(n);
        rep(i, 0, n) cin >> a[i];
        return a;
    }
};

Util util;

int main() {
    int t;
    cin >> t;
    while(t-- > 0) {
        vi a = util.readArray();
        //sort(all(a));
        /* int ans = 0, n = sz(a);
        rep(i, 0, n - 1) {
            ans += (a[i + 1] - a[i]);
        } */
        //cout << ans << endl;
        cout << max(all(a)) - min(all(a)) << endl;
    }
    return 0;
}
