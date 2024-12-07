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
		vector<ll> temp;
		rep(i, 1, sz(a)) temp.push_back(a[i]);
		swap(a, temp);
	
		auto rec = [&](auto &self, ll curVal, ll i, ll mode) -> bool {
			ll newVal = curVal;
			if (mode == 0) newVal += a[i];
			else if (mode == 1) newVal *= a[i];
			else {
				string one = to_string(newVal);
				string two = to_string(a[i]);
				string num = one + two;
				newVal = stoll(num);
			}
			if (i == sz(a) - 1) {
				return (newVal == n);	
			}
			bool q = 0;
			rep(j, 0, 3) {
				q = q || self(self, newVal, i + 1, j);
			}
			return q;
		};
		bool win = 0;
		rep(i, 0, 3) {
			win = win || rec(rec, a[0], 1, i);
		}
		if (win) ans += n;
	}
	cout << ans;
}


