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

int n;
vector<int> par;

int find_par(int a) {
	if(par[a]==a) 
		return a;
	return par[a] = find_par(par[a]);
}

void union_par(int a, int b) {
	a=find_par(a);
	b=find_par(b);
	if(a==b)
		return;
	if(a>b)
		swap(a,b);
	par[b]=a;
}

void solve() {
	cin >> n;
	par = vector<int>(n);
	for(int i=0 ; i<n ; i++)
		par[i]=i;
	int m; cin >> m;
	while(m--) {
		int u, v; cin >> u >> v; u--, v--;
		union_par(u,v);
	}
	int cnt = 0;
	for(int i=0 ; i<n ; i++) {
		if(find_par(i)==i) 
			cnt+=1;
	}
	cout << cnt << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}