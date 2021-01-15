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

void solve() {
	int n, k; cin >> n >> k;
	vector<ll> a(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
	}
	ll l=1,r=1e10;
	auto solve = [&](ll cur) -> bool {
		ll ans = 0;
		for(int i=0 ; i<n ; i++) {
			ans += a[i] / cur;
		}
		return ans >= k;
	};
	ll ans;
	while(l<=r) {
		ll mid = (l+r)/2;
		if(solve(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}