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

	ll biggest = 0;
	ll ans = 0;
	rep(sec, 0, 11000) {
		vector<pair<ll, ll>> POS = pos;
		rep(i, 0, sz(POS)) {
			POS[i].first += delta[i].first * sec;
			POS[i].second += delta[i].second * sec;
			POS[i].first = (POS[i].first % width + 2 * width) % width;
			POS[i].second = (POS[i].second % height + 2 * height) % height;
		}
		vector<vector<bool>> grid(height, vector<bool>(width));
		rep(i, 0, sz(POS)) {
			grid[POS[i].first][POS[i].second] = 1;
		}

		vector<pair<ll, ll>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
		vector<vector<bool>> vis(height, vector<bool>(width));

		auto dfs = [&](auto &self, ll y, ll x) -> ll {
			vis[y][x] = 1;
			ll mx = 0;
			for(auto &d: dirs) {
				ll Y = y + d.first, X = x + d.second;
				if (0 <= Y && Y < height && 0 <= X && X < width && !vis[Y][X] && grid[Y][X]) {
					mx = max(self(self, Y, X), mx);
				}
			}
			return mx + 1;
		};
		ll cur = 0;
		rep(i, 0, height) rep(j, 0, width) {
			if (!grid[i][j] || vis[i][j]) continue;
			cur = max(dfs(dfs, i, j), cur);
		}
		if (cur > biggest) {
			biggest = cur;
			ans = sec;
		}
	}

	cout << ans;
}

