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

	string s; 
	getline(cin, s);
	istringstream stream(s);

	map<ll, ll> freq;
	ll x;
	while(stream >> x) {
		freq[x]++;
	}

	rep(_, 0, 75) {
		map<ll, ll> nxt;
		for(auto &[num, cnt]: freq) {
			if (num == 0) {
				nxt[1] += cnt;
			}
			else {
				string val = to_string(num);
				if (sz(val) % 2 == 0) {
					string one = "";
					string two = "";
					rep(j, 0, sz(val)/2) one += val[j];
					rep(j, sz(val)/2, sz(val)) two += val[j];
					nxt[stoll(one)] += cnt;
					nxt[stoll(two)] += cnt;
				}
				else {
					nxt[num * 2024] += cnt;
				}
			}
		}
		swap(freq, nxt);
	}

	ll ans = 0;
	for(auto &x: freq) {
		ans += x.second;
	}
	cout << ans;
}


