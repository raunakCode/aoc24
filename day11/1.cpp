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
	vector<ll> a;
	ll x;
	while(stream >> x) a.push_back(x);

	rep(_, 0, 25) {
		vector<ll> nxt;
		rep(i, 0, sz(a)) {
			if (a[i] == 0) {
				nxt.push_back(1);
			}
			else {
				string num = to_string(a[i]);
				if (sz(num) % 2 == 0) {
					string one = "";
					string two = "";
					rep(j, 0, sz(num)/2) one += num[j];
					rep(j, sz(num)/2, sz(num)) two += num[j];
					nxt.push_back(stoll(one));
					nxt.push_back(stoll(two));
				}
				else {
					nxt.push_back(a[i] * 2024);
				}
			}
		}
		swap(a, nxt);
	}
	cout << sz(a);
}




