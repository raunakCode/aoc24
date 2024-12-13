#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// editted the input by keeping only spaces and digits

	ll ax, ay, bx, by, X, Y;
	ll ans = 0;
	while(cin >> ax) {
		cin >> ay >> bx >> by >> X >> Y;
		ll cur = 1e12;
		bool found = 0;
		rep(i, 0, 101) rep(j, 0, 101) {
			if (X == ax * i + bx * j && Y == ay * i + by * j) {
				found = 1;
				cur = min(ll(i * 3 + j), cur);
			}
		}
		ans += (found ? cur : 0);
	}
	cout << ans;
}

