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
	vector<pii> a(n);
	pii s, e;
	cin >> s.ff >> s.ss;
	for(int i=0 ; i<n ; i++) 
		cin >> a[i].ff >> a[i].ss;
	cin >> e.ff >> e.ss;
	queue<pii> q;
	q.push(s);
	vector<bool> vis(n);
	while(!q.empty()) {
		int cX=q.front().ff, cY=q.front().ss; q.pop();
		if(abs(cX-e.ff)+abs(cY-e.ss)<=1000) {
			cout << "happy\n";
			return;
		}
		for(int i=0 ; i<n ; i++) {
			if(!vis[i]&&abs(cX-a[i].ff)+abs(cY-a[i].ss)<=1000) {
				vis[i]=1;
				q.push(a[i]);
			}
		}
	}
	cout << "sad\n";
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}