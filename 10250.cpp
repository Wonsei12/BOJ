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
	int h, w, n; cin >> h >> w >> n;
	int cnt = 0;
	for(int i=0 ; i<w ; i++) {
		for(int j=0 ; j<h ; j++) {
			cnt++;
			if(cnt==n) {
				cout << (i+1) + (j+1) * 100 << "\n";
			}
		}
	}
	return;
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}