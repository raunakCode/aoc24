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

	ll n = 130;
	vector<vector<char>> grid(n, vector<char>(n));
	vector<pll> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	ll Y, X;
	rep(i, 0, n) rep(j, 0, n) {
		cin >> grid[i][j];
		if (grid[i][j] == '^') {
			Y = i;
			X = j;
		}
	}
	ll ans = 0;
	rep(i, 0, n) rep(j, 0, n) {
		ll y = Y, x = X;
		if (grid[i][j] == '#') continue;
		vector<vector<char>> mat = grid;
		mat[i][j] = '#';

		bool found = 0;
		bool vis[n][n][4] = {};
		ll d = 0;
		auto good = [&](ll a, ll b) -> bool {
			return (0 <= min(a, b) && max(a, b) < n);
		};
		while(good(x, y)) {
			if (vis[y][x][d]) {
				found = 1;
				break;
			}
			vis[y][x][d] = 1;
			mat[y][x] = 'X';
			ll newY = y + dirs[d].first, newX = x + dirs[d].second;
			if (good(newY, newX)) {
				while (mat[newY][newX] == '#') {
					d = (d + 1) % 4;
					newY = y + dirs[d].first, newX = x + dirs[d].second;
				}
			}
			swap(y, newY);
			swap(x, newX);
		}
		if (found) {
			ans++;
		}
	}
	cout << ans;
}
