#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
         
using namespace std;
using namespace __gnu_pbds;
 
/* typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set; */
         
#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define sq(x) (x)*(x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
         
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
         
#define all(x) (x).begin(), (x).end()

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b-1); i >= (a); --i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define trav(a, x) for (auto &a : x)
         
struct chash { // large odd number for C
      const uint64_t C = ll(4e18 * acos(0)) | 71;
      ll operator()(ll x) const { return __builtin_bswap64(x * C); }
};
 
template<typename T> using fast_set = __gnu_pbds::gp_hash_table<T, null_type, chash>;
template<typename T, typename H> using fast_set_h = __gnu_pbds::gp_hash_table<T, null_type, H>;
template<typename T, typename U> using fast_map = __gnu_pbds::gp_hash_table<T, U, chash>;
 
#ifdef DEBUG
#include "/home/redkar/kod/cp/lib/debug.cpp"
#else
#define dbg(...)
#define dbgArr(...)
#endif

const ll inf = 1e12;

void solve() {
	vpll dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
	ll n = 140;
	char grid[n][n];
	rep(i, 0, n) rep(j, 0, n) {
		cin >> grid[i][j];
	}
	ll ans = 0;
	trav(d, dirs) {
		rep(i, 0, n) rep(j, 0, n) {
			string s = "";
			s += grid[i][j];
			ll curY = i, curX = j;
			ll cnt = 0;
			while(0 <= curY + d.F && curY + d.F < n && 0 <= curX + d.S && curX + d.S < n && cnt < 3) {
				curY += d.F;
				curX += d.S;
				s += grid[curY][curX];
				cnt++;
			}
			if (s == "XMAS") ans++;
		}
	}
	cout << ans;


}

int main() { 
	faster
        int test = 1; // cin >> test;
	REP(tc, 1, test) {
		solve();
	}
}

