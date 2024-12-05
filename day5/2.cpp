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
         
#define umap unordered_map
#define uset unordered_set

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

const ll inf = 1e11;


void solve() {
	// used python to reformat the input a bit
	ll n; cin >> n;
	map<ll, set<ll>> before;
	rep(_, 0, n) {
		ll a, b;
		cin >> a >> b;
		before[a].insert(b);
	}
	ll ans = 0;
	ll updates; cin >> updates;
	cin.ignore();
	rep(_, 0, updates) {
		string s;
		getline(cin, s);
		istringstream stream(s);
		vector<ll> a;
		ll x; 
		while(stream >> x) {
			a.push_back(x);
		}
		bool good = 1;
		rep(i, 0, sz(a)) {
			rep(j, 0, sz(a)) {
				if (i == j) continue;
				if (i < j && (before[a[j]].count(a[i]))) good = 0;
			}
		}
		if (!good) {
			vpll b;	
			rep(i, 0, sz(a)) {
				ll cnt = 0;
				rep(j, 0, sz(a)) {
					if (i == j) continue;
					if (before[a[i]].count(a[j])) cnt++;
				}
				b.pb(mp(cnt, a[i]));
			}
			sort(all(b));
			ans += b[sz(b)/2].S;
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
 
