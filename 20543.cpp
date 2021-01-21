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
	int n, m; cin >> n >> m;
	vector<vector<ll>> a(n, vector<ll>(n));
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++) {
			cin >> a[i][j];
			a[i][j] = -a[i][j];
		}

	vector<vector<ll>> ans(n, vector<ll>(n));
	vector<vector<ll>> sum(n, vector<ll>(n));
	for(int i=m/2 ; i+m/2<n ; i++) {
		for(int j=m/2 ; j+m/2<n ; j++) {
			ans[i][j] = 
		}
	}
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<n ; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	} 
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}