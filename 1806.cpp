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

int main() {
	IOS;
	int n; ll s; cin >> n >> s;
	vector<ll> a(n+1);
	for(int i=1 ; i<=n ; i++)
		cin >> a[i];
	int p1=1,p2=1; ll cur = a[1];
	int ans = INF;
	while(p1<=n&&p2<=n&&p1<=p2) {
		if(cur >= s) {
			ans=min(ans,p2-p1+1);
			p1 += 1;
			cur -= a[p1-1];
		} else {
			p2 += 1;
			cur += a[p2];
		}
	}
	if(ans==INF)ans=0;
	cout << ans << "\n";
}