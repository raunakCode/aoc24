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

	ll extra = 10000000000000;

	ll ax, ay, bx, by, X, Y;
	ll ans = 0;
	while(cin >> ax) {
		cin >> ay >> bx >> by >> X >> Y;
		X += extra, Y += extra;
		ll det = ax * by - bx * ay;	
		if (det == 0) continue;
		ll one = X * by - Y * bx;
		ll two = Y * ax - X * ay;
		if (one % det != 0 || two % det != 0) continue;
		one /= det, two /= det;
		ans += 3 * one + two;
	}
	cout << ans;
}

