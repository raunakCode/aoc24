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
	//cin.exceptions(cin.failbit);

	ll n = 130;
	vector<vector<char>> grid(n, vector<char>(n));
	vector<pll> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	ll x, y;
	rep(i, 0, n) rep(j, 0, n) {
		cin >> grid[i][j];
		if (grid[i][j] == '^') {
			y = i;
			x = j;
		}
	}
	ll d = 0;
	while(0 <= x && x < n && 0 <= y && y < n) {
		grid[y][x] = 'X';
		ll newY = y + dirs[d].first, newX = x + dirs[d].second;
		if (0 <= min(newY, newX) && max(newY, newX) < n) {
			if (grid[newY][newX] == '#') d = (d + 1) % 4;
			newY = y + dirs[d].first, newX = x + dirs[d].second;
		}
		swap(y, newY);
		swap(x, newX);
	}
	ll ans = 0;
	rep(i, 0, n) {
		ans += count(all(grid[i]), 'X');
	}
	cout << ans;
}

