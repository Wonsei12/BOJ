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
	int n; cin >> n;
	vector<pair<pair<int, string>,int>> a(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i].ff.ff >> a[i].ff.ss; 
		a[i].ss=i;
	}
	auto cmp = [](pair<pair<int, string>, int> a, pair<pair<int, string>, int> b) -> bool {
		if(a.ff.ff==b.ff.ff)
			return a.ss < b.ss;
		return a.ff.ff < b.ff.ff;
	};
	sort(a.begin(),a.end(),cmp);
	for(auto x : a) {
		cout << x.ff.ff << " " << x.ff.ss << "\n";
	}
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}