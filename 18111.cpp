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
	int n, m; ll b; cin >> n >> m >> b;
	vector<vector<ll>> a(n, vector<ll>(m));
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<m ; j++) {
			cin >> a[i][j];
		}	
	}
	ll mn = LLINF, mnIdx;
	for(int h=0 ; h<=256 ; h++) {
		ll need=0, time=0, have=0;
		for(int i=0 ; i<n ; i++) {
			for(int j=0 ; j<m ; j++) {
				if(a[i][j] < h) {
					need += h - a[i][j];
					time += h - a[i][j];
				}
				else {
					have += a[i][j] - h;
					time += 2 * (a[i][j] - h);
				}
			}
		}
		if(need > b + have)
			continue;
		if(mn >= time) {
			mn = time;
			mnIdx = h;
		}
	}
	cout << mn << " " << mnIdx << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}