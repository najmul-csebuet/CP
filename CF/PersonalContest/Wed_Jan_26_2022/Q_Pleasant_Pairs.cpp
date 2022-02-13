#include <bits/stdc++.h>
using namespace std;

#define HIDE_TEMPLATE true

#ifdef HIDE_TEMPLATE

#define ACTIVATE_FASTIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define dist(x1, y1, x2, y2) sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2))

#define ll long long
#define V vector
#define P pair

#define si set<int>

#define vc vector<char>
#define vs vector<string>
#define vb vector<bool>
#define vi vector<int>
#define vd vector<double>
#define vll vector<ll>


#define pii pair<int, int>
#define vii vector<pair<int, int>>

#define vvi vector<vector<int>>

#define mii map<int, int>
#define msi map<string, int>

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define repr(i, a, b) for (auto i = (a); i > (b); --i)

#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define var auto

#define tr(container, it) for (var it = container.begin(); it != container.end(); it++)
#define trr(container, it) for (var it = container.rbegin(); it != container.rend(); it++)

// https://codeforces.com/blog/entry/62393
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define umii unordered_map<int, int, custom_hash>
#define ghtii gp_hash_table<int, int, custom_hash>
#define boost(a) a.max_load_factor(0.25); a.reserve(1<<20);

#define eqd(a,b) (abs(a-b)<1e-9)

#endif

struct IO {

    string readLine() {
        string str;
        getline(cin, str);
        return str;
    }

    vi readInts() {
        int n;
        cin >> n;
        return readInts(n);
    }

    vi readInts(int n) {
        vi a(n);
        rep(i, 0, n) cin >> a[i];
        return a;
    }

    void print(vi n) {
        print(n, " ");
    }

    void print(vi n, string separator) {
        if (n.size() == 0) return;
        rep(i, 0, n.size() - 1) cout << n[i] << separator;
        cout << n[n.size() - 1] << "\n";
    }

    void reversePrint(vi n) {
        reversePrint(n, " ");
    }

    void reversePrint(vi n, string separator) {
        if (n.size() == 0) return;
        repr(i, n.size() - 1, 0) cout << n[i] << separator;
        cout << n[0] << "\n";
    }
} io;

void solve() {
    var A = io.readInts();
    ll ans = 0;
    umii map;
    boost(map);
    int n = sz(A);
    rep(i, 0, n) map[A[i]]++;

    // j = 1, 2, 3, ..., n
    rep(j, 2, n + 1) {
        int aj = A[j - 1];
        if(2*j - 1 < aj) continue;
        int high = 2*j - 1 - mod(2*j - 1, aj);
        // i = j - 1, j - 2, ..., 1
        for(int i = high; i >= aj && i >= j + 1; i -= aj) {
            ans += map[i / aj];
        }
    }
    cout << ans << "\n";
}

int main() {
    ACTIVATE_FASTIO()
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
