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

	ll N = 55;
	vector<vector<ll>> grid(N, vector<ll>(N));
	rep(i, 0, N) rep(j, 0, N) {
		char c; cin >> c;
		grid[i][j] = c - '0';
	}

	vector<pair<ll,ll>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

	auto dfs = [&](auto &self, ll y, ll x, ll &cnt) -> void {
		if (grid[y][x] == 9) cnt++;
		for (auto &d: dirs) {
			ll Y = y + d.first, X = x + d.second;
			if (0 <= Y && Y < N && 0 <= X && X < N && grid[Y][X] == grid[y][x] + 1) {
				self(self, Y, X, cnt);
			}
		}
	};

	ll ans = 0;
	rep(i, 0, N) rep(j, 0, N) {
		if (grid[i][j] == 0) {
			ll cnt = 0;
			dfs(dfs, i, j, cnt);
			ans += cnt;
		}
	}
	cout << ans;
}

