#include <bits/stdc++.h>
using namespace std;

#define HIDE_TEMPLATE true

#ifdef HIDE_TEMPLATE

#define ACTIVATE_FASTIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define dist(x1, y1, x2, y2) sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2))

#define ll long long
#define ull unsigned long long
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

bool isPalin(int n, string &s) {
    rep(i, 0, n / 2) {
        if (s[i] != s[n - i - 1]) return false;
    }
    return true;
}

bool isAll1(int n, string &s) {
    rep(i, 0, n) {
        if (s[i] != '1') return false;
    }
    return true;
}

vi calcPlaPos(string &s) {
    vi a;
    int n = s.size();
    rep(i, 0, n) {
        if (s[i] == '0') a.eb(i);
    }
    return a;
    /* rep(i, 0, n / 2) {
        //if (s[i] == '1') a.eb(i);
        if (s[i] != s[n - i - 1]) {
            if(s[i] == '0') a.eb(i);
            else a.eb(n - i - 1);
        }
    }
    return a; */
}

void solve(int n, string &s) {
    ull alice = 0, bob = 0;
    bool lastMoveIsReverse = false;
    //var plaPos = calcPlaPos(s);

    var alicesTurn = true;

    while(!isAll1(n, s)) {
        // first turn Alice
        if (isPalin(n, s)) {
            // must set a 0 bit to 1, try to make a plalindrome
            int mid = n / 2;
            if(n%2 == 1 && s[mid] == '0') {
                s[mid] = '1';
            } else {
                rep(i, 0, n) {
                    if (s[i] == '0') {
                        s[i] = '1';
                        break;
                    }
                }
            }

            if (alicesTurn) alice++;
            else bob++;
        } else {
            if(!lastMoveIsReverse) {
                // can reverse it
                lastMoveIsReverse = true;
                reverse(all(s));
            }
            else {
                // must set a 0 bit to 1, try to make a plalindrome
                // find 01 or 10
                rep(i, 0, n / 2) {
                    if (s[i] != s[n - i - 1]) {
                        if(s[i] == '0') s[i] = '1';
                        else s[n - i - 1] = '1';
                        break;
                    }
                }

                if (alicesTurn) alice++;
                else bob++;
            }
        }

        alicesTurn = !alicesTurn;
    }

    if(alice < bob) cout << "ALICE\n";
    else if(bob < alice) cout << "BOB\n";
    else cout << "DRAW\n";
}

int main() {
    ACTIVATE_FASTIO()
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        solve(n, s);
    }
}
