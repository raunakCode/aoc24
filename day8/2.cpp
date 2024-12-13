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
	ll N = 50;
	vector<vector<char>> grid(N, vector<char>(N));
	map<char, vector<pll>> pos;
	rep(i, 0, N) rep(j, 0, N) {
		cin >> grid[i][j];
		if (grid[i][j] != '.') {
			pos[grid[i][j]].push_back({i, j});
		}
	}
	set<pll> antinodes;
	for(auto &x: pos) {
		vector<pll> v = x.second;
		rep(i, 0, sz(v)) {
			rep(j, 0, sz(v)) {
				if (i == j) continue;
				ll dy = v[i].first - v[j].first;
				ll dx = v[i].second - v[j].second;
				ll Y = v[j].first;
				ll X = v[j].second;
				while(0 <= Y+dy && Y+dy < N && 0 <= X+dx && X+dx < N) {
					Y += dy;
					X += dx;
					antinodes.insert({Y, X});
				}
			}
		}
	}
	cout << sz(antinodes);
}

