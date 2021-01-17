#define LOCAL

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define LLINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define uniq(x) sort(all(x)); x.resize(unique(all(x))-x.begin());
#define sz(x) (int)x.size()
#define pw(x) (1LL<<x)

using pii = pair<int, int>;
using ll = long long;
const ll MOD = 1e9 + 7;
const long double PI = acos(-1.0);

ll euclid(ll x, ll y, ll &k, ll &l) {
	if (y == 0) {
		k = 1;
		l = 0;
		return x;
	}
	ll g = euclid(y, x % y, l, k);
	l -= k * (x / y);
	return g;
}

ll ceil(ll a, ll b) {
	if(a >= 0) 
		return (a+b-1) / a;
	else
		return a/b;
}

void solve() {
	ll k, c; cin >> k >> c;
	ll x, a;
	ll g = euclid(-k,c,x,a);
	if(g!=1&&g!=-1) {
		cout << "IMPOSSIBLE\n";
	} else {
		// x, a
		// x + z * c, a + z * k
		// z > (-x/c), z > (-k/a)
		ll zLimB = max(ceil(x,c),ceil(k,a));
		ll zLimT = (1e9-a)/k;
		cout << zLimB << " " << zLimT << "\n";
		if(zLimB > zLimT) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << zLimB << "\n";
		}
	}
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}