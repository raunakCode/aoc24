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

struct UF {
	ll n;
	vector<ll> parent, mass;
	UF(ll N) {
		n = N;
		parent.resize(n);			
		mass.assign(n, 1);			
		rep(i, 0, n) parent[i] = i;
	}
	ll get(ll x) {
		if (parent[x] != x) parent[x] = get(parent[x]);		
		return parent[x];
	}
	void unite(ll a, ll b) {
		a = get(a);
		b = get(b);
		if (a != b) {
			if (mass[a] < mass[b]) swap(a, b);
			mass[a] += mass[b];
			parent[b] = a;
		}
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	vector<pair<ll, ll>> dirs = {{1, 0}, {-1, 0}};
	vector<pair<ll, ll>> dirs2 = {{0, 1}, {0, -1}};
	vector<pair<ll, ll>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	ll n = 4;
	vector<vector<char>> grid(n, vector<char>(n));
	rep(i, 0, n) rep(j, 0, n) {
		cin >> grid[i][j];
	}

	auto convert = [&](ll y, ll x) -> ll {
		return y * n + x;
	};

	auto inside = [&](ll y, ll x) -> bool {
		return (0 <= y && y < n && 0 <= x && x < n);
	};

	auto isEdge = [&](ll y, ll x) -> bool {
		ll c = grid[y][x];
		for(auto &d: directions) {
			ll Y = y + d.first, X = x + d.second;
			if (inside(Y, X)) {
				if (grid[Y][X] != c) return true;
			}
			else return true;
		}
		return false;
	};

	UF full(n * n);
	rep(i, 0, n) rep(j, 0, n) {
		ll cur = convert(i, j);
		for(auto &d: directions) {
			ll y = i + d.first, x = j + d.second;
			ll neighbour = convert(y, x);
			if (inside(y, x) && grid[i][j] == grid[y][x]) {
				full.unite(cur, neighbour);
			}
		}
	}

	UF vertical(n * n);
	UF horizontal(n * n);
	rep(k, 0, 2) {
		if (k == 1) {
			swap(vertical, horizontal);
			swap(dirs, dirs2);
		}
		rep(i, 0, n) rep(j, 0, n) {
			ll cur = convert(i, j);
			if (!isEdge(i, j)) continue;
			for(auto &d: dirs) {
				ll y = i + d.first, x = j + d.second;
				ll neighbour = convert(y, x);
				if (inside(y, x) && isEdge(y, x)) {
					vertical.unite(cur, neighbour);
				}
			}
		}
	}
	swap(vertical, horizontal);
	swap(dirs, dirs2);

	map<ll, pair<unordered_set<ll>, unordered_set<ll>>> info;
	rep(i, 0, n) rep(j, 0, n) {
		if (isEdge(i, j)) {
			ll comp = full.get(convert(i, j));
			pair<unordered_set<ll>, unordered_set<ll>> &sets = info[comp];
			sets.first.insert(vertical.get(convert(i, j)));
			sets.second.insert(horizontal.get(convert(i, j)));
		}
	}

	ll ans = 0;
	dbg(sz(info));
	for(auto &[comp, sets]: info) {
		ll area = full.mass[comp];
		ll perimeter = sz(sets.first) + sz(sets.second);
		ans += area * perimeter;
	}

	cout << ans;
}


