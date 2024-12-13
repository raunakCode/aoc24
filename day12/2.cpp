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

	vector<pair<ll, ll>> up = {{-1, 0}};
	vector<pair<ll, ll>> down = {{1, 0}};
	vector<pair<ll, ll>> lt = {{0, -1}};
	vector<pair<ll, ll>> rt = {{0, 1}};

	vector<pair<ll, ll>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	ll n = 140;
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

	auto isEdge = [&](ll y, ll x, ll mode) -> bool {
		ll c = grid[y][x];
		bool ret = 0;
		vector<pair<ll, ll>> curDirections;
		if (mode == 0) curDirections = directions;
		if (mode == 1) curDirections = lt;
		if (mode == 2) curDirections = rt;
		if (mode == 3) curDirections = up;
		if (mode == 4) curDirections = down;
		for(auto &d: curDirections) {
			ll Y = y + d.first, X = x + d.second;
			if (inside(Y, X)) {
				if (grid[Y][X] != c) ret = true;
			}
			else ret = true;
		}
		return ret;
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

	UF UP(n * n);
	UF DOWN(n * n);
	UF LEFT(n * n);
	UF RIGHT(n * n);
	UF uf(n * n);

	rep(k, 1, 5) {
		if (k >= 3) swap(dirs, dirs2);	
		if (k == 1) swap(uf, LEFT);
		if (k == 2) swap(uf, RIGHT);
		if (k == 3) swap(uf, UP);
		if (k == 4) swap(uf, DOWN);
		rep(i, 0, n) rep(j, 0, n) {
			ll cur = convert(i, j);
			if (!isEdge(i, j, k)) continue;
			for(auto &d: dirs) {
				ll y = i + d.first, x = j + d.second;
				ll neighbour = convert(y, x);
				if (inside(y, x) && grid[y][x] == grid[i][j] && isEdge(y, x, k)) {
					uf.unite(cur, neighbour);
				}
			}
		}
		if (k >= 3) swap(dirs, dirs2);	
		if (k == 1) swap(uf, LEFT);
		if (k == 2) swap(uf, RIGHT);
		if (k == 3) swap(uf, UP);
		if (k == 4) swap(uf, DOWN);
	}
	swap(dirs, dirs2);

	map<ll, array<unordered_set<ll>, 4>> info;
	rep(i, 0, n) rep(j, 0, n) {
		ll comp = full.get(convert(i, j));
		array<unordered_set<ll>, 4> &sets = info[comp];
		if (isEdge(i, j, 1)) sets[0].insert(LEFT.get(convert(i, j)));
		if (isEdge(i, j, 2)) sets[1].insert(RIGHT.get(convert(i, j)));
		if (isEdge(i, j, 3)) sets[2].insert(UP.get(convert(i, j)));
		if (isEdge(i, j, 4)) sets[3].insert(DOWN.get(convert(i, j)));
	}

	ll ans = 0;
	for(auto &[comp, sets]: info) {
		ll area = full.mass[comp];
		ll perimeter = 0;
		rep(i, 0, 4) perimeter += sz(sets[i]);
		ans += area * perimeter;
	}

	cout << ans;
}
