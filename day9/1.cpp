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

	string s; cin >> s;
	string temp = "";
	ll cur = 0;
	vector<string> b;
	rep(i, 0, sz(s)) {
		ll num = s[i] - '0';
		string c = (i&1 ? "." : to_string(cur));
		rep(j, 0, num) {
			b.push_back(c);
		}
		if (i % 2 == 0) cur++;
	}
	ll l = 0, r = sz(b) - 1;
	while(l < r) {
		if (b[r] == ".") r--;
		else if (b[l] != ".") l++;
		else {
			b[l] = b[r];
			b[r] = ".";
			l++;
		}
	}
	ll ans = 0;
	rep(i, 0, sz(b)) {
		if (b[i] == ".") continue;
		ll val = stoll(b[i]);
		ans += i * val;
	}
	cout << ans;
}

