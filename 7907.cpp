#include <bits/stdc++.h>
using namespace std;

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

struct point {
	int x,y; 
	point() {}
	point(int x, int y):x(x),y(y) {}
};

bool cmp(pii a, pii b) {
	return a.ss < b.ss;
}

int main() {
	IOS;
	int n, m, k; cin >> n >> m >> k;
	vector<point> a(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i].x >> a[i].y;
	}
	vector<vector<pii>> G(n);
	vector<int> deg(n),deg2;
	for(int i=0 ; i<m ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		if(a[u].x == a[v].x) {
			if(a[u].y < a[v].y) swap(u,v);
			G[u].push_back({v,0});
			deg[v]+=1;
		} else if(a[u].y == a[v].y) {
			if(a[u].x > a[v].x) swap(u,v);
			G[u].push_back({v,1});
			deg[v]+=1;
		} else assert(false);
	}
	deg2=deg;
	for(int i=0 ; i<n ; i++) {
		if(sz(G[i])<2) continue;
		if(G[i][0].ss==1) swap(G[i][0],G[i][1]);
	}
	vector<int> rank1(n),rank2(n);
	rank1[0] = 1;
	rank2[0] = 1;
	int rank = 1;
	function<void(int)> dfs1 = [&](int v) {
		for(int i=0 ; i<sz(G[v]) ; i++) {
			int nxtNode = G[v][i].ff;
			deg[nxtNode] -= 1;
			if(deg[nxtNode] == 0) {
				rank1[nxtNode] = ++rank;
				dfs1(nxtNode);
			}
		}
	};
	function<void(int)> dfs2 = [&](int v) {
		for(int i=sz(G[v]) - 1 ; i>=0 ; i--) {
			int nxtNode = G[v][i].ff;
			deg2[nxtNode] -= 1;
			if(deg2[nxtNode] == 0) {
				rank2[nxtNode] = ++rank;
				dfs2(nxtNode);
			}
		}
	};
	dfs1(0); rank = 1; dfs2(0);
	while(k--) {
		int x, y; cin >> x >> y; x--, y--;
		bool b1=(rank1[x]<rank1[y]); 
		bool b2=(rank2[x]<rank2[y]);
		if(b1==b2) cout << "TAK\n";
		else cout << "NIE\n";
	}
}