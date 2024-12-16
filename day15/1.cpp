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

	ll n = 50;
	vector<vector<char>> grid(n, vector<char>(n));
	array<ll, 2> pos;
	rep(i, 0, n) rep(j, 0, n) {
		cin >> grid[i][j];
		if (grid[i][j] == '@') pos = {i, j};
	}
	
	char C;
	while(cin >> C) {
		array<ll, 2> dir;
		if (C == 'v') dir = {1, 0};
		else if (C == '<') dir = {0, -1};
		else if (C == '^') dir = {-1, 0};
		else {
			assert(C == '>');
			dir = {0, 1};
		}
			
		bool willMove = false;
		ll y = pos[0], x = pos[1];
		while(0 <= min(y + dir[0], x + dir[1]) && max(y + dir[0], x + dir[1]) < n) {
			y += dir[0];
			x += dir[1];
			if (grid[y][x] != 'O') {
				willMove = (grid[y][x] == '.');
				break;
			}
		}
		if (willMove) {
			grid[pos[0]][pos[1]] = '.';
			pos[0] += dir[0];
			pos[1] += dir[1];
			grid[pos[0]][pos[1]] = '@';
			bool reached = (pos[0] == y && pos[1] == x);
			for(int Y = pos[0] + dir[0], X = pos[1] + dir[1]; !reached; Y += dir[0], X += dir[1]) {
				grid[Y][X] = 'O';
				reached = (Y == y && X == x);
			}
		}
	}

	ll sum = 0;
	rep(i, 0, n) rep(j, 0, n) {
		if (grid[i][j] == 'O') sum += i * 100 + j;
	}

	cout << sum;
}

