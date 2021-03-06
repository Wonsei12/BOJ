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
	int cursor = 0;
	vector<int> a(n);
	for(int i=0 ; i<n ; i++)
		cin >> a[i];
	int cnt = 1;
	vector<int> ans(n);
	int prev = 0;
	for(int i=9 ; i>=0 ; i--) {
		for(int j=prev ; j<n ; j++) {
			if(a[j]==i) {
				cursor = j;
				ans[j] = cnt++;
			}
		}
		for(int j=0 ; j<prev ; j++) {
			if(a[j]==i) {
				cursor = j;
				ans[j] = cnt++;
			}
		}
		prev = cursor;
	}
	cout << ans[m] << "\n";
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}