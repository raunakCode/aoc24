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
	// edited input to make easier to parse
	cin.tie(0)->sync_with_stdio(0);

	ll N = 850;
	ll ans = 0;
	rep(_, 0, N) {
		string s;
		getline(cin, s);

		istringstream stream(s);

		vector<ll> a;

		ll x;
		while(stream >> x) a.push_back(x);
		ll n = a[0];
		bool found = 0;
		rep(b, 0, (1<<(sz(a) - 2))) {
			ll cur = a[1];
			rep(i, 0, sz(a) - 2) {
				if (b & (1<<i)) {
					cur *= a[i + 2];
				}
				else cur += a[i + 2];
			}
			if (cur == n) {
				found = 1;
			}
		}
		if (found) ans += n;
	}
	cout << ans;
}


