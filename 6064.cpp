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
	int m,n,x,y; cin >> m >> n >> x >> y;
	int tot = m*n;
	int cur=1;
	int a=0,b=0;
	a+=x-1;b+=x-1;b%=n;cur+=x-1;tot-=x-1;
	while(tot>=0) {
		if(a==x-1&&b==y-1) {
			cout << cur << "\n";
			return;
		}
		b+=m; b%=n; cur+=m; tot-=m;
	}
	cout << -1 << "\n";
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}