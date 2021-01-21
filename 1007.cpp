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
const ll MOD = 1e4 + 7;
const long double PI = acos(-1.0);

void solve() {
	int n; cin >> n;
	vector<pair<double, double>> a(n);
	for(int i=0 ; i<n ; i++)
		cin >> a[i].ff >> a[i].ss;
	vector<bool> vis(n);
	double ans=LLINF;
	vector<int> c;
	for(int i=0 ; i<n/2 ; i++)
		c.push_back(-1);
	for(int i=0 ; i<n/2 ; i++)
		c.push_back(1);
	do {
		double sX=0,sY=0;
		for(int i=0 ; i<n ; i++) {
			sX+=c[i]*a[i].ff;
			sY+=c[i]*a[i].ss;
		}
		ans=min(ans,sX*sX+sY*sY);
	} while(next_permutation(c.begin(),c.end()));
	cout << fixed << setprecision(15);
	cout << sqrt(ans) << "\n";
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}