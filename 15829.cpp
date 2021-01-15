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
const ll MOD = 1234567891;
const long double PI = acos(-1.0);

void solve() {
	int n; string s; cin >> n >> s;
	ll pow = 1;
	ll ans = 0;
	for(char c : s) {
		ans += (c-'a'+1) * pow;
		pow *= 31;
		pow %= MOD;
		ans %= MOD;
	}
	cout << ans << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}