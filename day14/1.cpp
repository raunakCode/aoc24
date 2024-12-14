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

	// editted the input by removing all everything that isn't a space or a number.
	// also made all commas into spaces

	ll width = 101, height = 103;
	vector<pair<ll, ll>> pos;
	vector<pair<ll, ll>> delta;

	ll px, py, dx, dy;
	while(cin >> px) {
		cin >> py >> dx >> dy;
		pos.push_back({px, py});
		delta.push_back({dx, dy});
	}

	// everything is {x, y}
	assert(sz(pos) == sz(delta));
	rep(_, 0, 100) {
		rep(i, 0, sz(pos)) {
			pos[i].first += delta[i].first;
			pos[i].second += delta[i].second;
			pos[i].first = (pos[i].first % width + 2 * width) % width;
			pos[i].second = (pos[i].second % height + 2 * height) % height;
		}
	}

	vector<ll> quad(4);	
	rep(i, 0, sz(pos)) {
		if (pos[i].first < width / 2 && pos[i].second < height / 2) quad[0]++;
		else if (pos[i].first < width / 2 && pos[i].second > height / 2) quad[1]++;
		else if (pos[i].first > width / 2 && pos[i].second < height / 2) quad[2]++;
		else if (pos[i].first > width / 2 && pos[i].second > height / 2) quad[3]++;
	}
	ll ans = 1;
	rep(i, 0, 4) ans *= quad[i];
	cout << ans;

}

