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

#define rep(i, a, b) for (auto i = (a); i <= (b); ++i)
#define repr(i, a, b) for (auto i = (a); i >= (b); --i)

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

void solve(int n, int k, vi &A) {
    sort(all(A));
    if(k == 0) {
        if(A[0] == 1) {
            // x can't be < 1
            cout << -1 << endl;
        } else {
            cout << A[0] - 1 << endl;
        }
        return;
    }

    if(k == n) {
        cout << A[n - 1] << endl;
        return;
    }

    // k > 0 && k < n
    if(A[k - 1] == A[k]) {
        cout << -1 << endl;
    } else {
        cout << A[k - 1] << endl;
    }
}

int main() {
    ACTIVATE_FASTIO()
    int n, k;
    cin >> n >> k;
    var A = io.readInts(n);
    solve(n, k, A);
}
