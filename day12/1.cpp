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

	ll n = 140;
	vector<vector<char>> grid(n, vector<char>(n));
	rep(i, 0, n) rep(j, 0, n) {
		cin >> grid[i][j];
	}

	vector<vector<bool>> vis(n, vector<bool>(n));

	vector<pair<ll, ll>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

	auto dfs = [&](auto &self, ll y, ll x, ll &a, ll &p, char c) -> void {
		a++;
		for(auto &d: dirs) {
			ll Y = y + d.first, X = x + d.second;
			if (0 <= Y && Y < n && 0 <= X && X < n) {
				if (grid[Y][X] != c) p++;
				else if (!vis[Y][X]) {
					vis[Y][X] = 1;
					self(self, Y, X, a, p, c);
				}
			}
			else p++;
		}
	};

	ll ans = 0;
	rep(i, 0, n) rep(j, 0, n) {
		if (!vis[i][j]) {
			ll area = 0, perimeter = 0;
			vis[i][j] = 1;
			dfs(dfs, i, j, area, perimeter, grid[i][j]);
			ans += area * perimeter;
		}
	}

	cout << ans;
}


