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
	vector<pair<ll, ll>> startpos(200001); // startpos[id] = {pos, len}
	rep(i, 0, sz(s)) {
		ll num = s[i] - '0';
		string c = (i&1 ? "." : to_string(cur));
		if (i % 2 == 0) startpos[cur] = {sz(b), num};
		rep(j, 0, num) {
			b.push_back(c);
		}
		if (i % 2 == 0) cur++;
	}
	cur--;

	for(int i = cur; i >= 0; i--) {
		ll st, len;
		tie(st, len) = startpos[i];
		ll currentLen = 0;
		ll pos = -1;
		rep(j, 0, st) {
			if (b[j] == ".") {
				currentLen++;
				if (currentLen == len) {
					pos = j - len + 1;
					break;
				}
			}
			else currentLen = 0;
		}
		if (pos != -1) {
			rep(j, st, st + len) b[j] = ".";
			rep(j, pos, pos + len) b[j] = to_string(i);
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

