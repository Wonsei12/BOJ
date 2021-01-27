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

int D=0,R=1,U=2,L=3;
vector<int> dx = {1,0,-1,0}, dy= {0,1,0,-1};
int par[500500];
int cost[1000100];

int find(int x) {
	if(x==par[x]) return x;
	return par[x] = find(par[x]);
}

void merge(int u, int v) {
	u = find(u); v = find(v);
	if(u > v) swap(u,v);
	par[v] = u;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<string> s(n);
	for(int i=0 ; i<n ; i++) {
		cin >> s[i];
	}	
	int idx = 1;
	vector<vector<int>> id(n, vector<int>(m));
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<m ; j++) {
			if(s[i][j] == 'V' || s[i][j] == 'H') {
				cost[idx*2-1]=(s[i][j]=='V');
				cost[idx*2]=(s[i][j]=='H');
				id[i][j] = idx;
				idx += 1;
			}
		}
	}

	for(int i=0 ; i<500020 ; i++) 
		par[i] = i;

	function<int(int,int,int)> simulate = [&](int x, int y, int dir) {
		while(1) {
			x += dx[dir]; y += dy[dir];
			if(x < 0) {
				x = 0; dir = D;
			} else if(x >= n) {
				x = n-1; dir = U;
			} else if(y < 0) {
				y = 0; dir = R;
			} else if(y >= m) {
				y = m-1; dir = L;
			}
			if(id[x][y]) {
				if(dir==L||dir==R) 
					return id[x][y] * 2 - 1;
				else
					return id[x][y] * 2;
			}
			if(s[x][y]=='#') return -1;
			if(s[x][y]=='/') {
				if(dir == U) dir = R;
				else if(dir == R) dir = U;
				else if(dir == L) dir = D;
				else if(dir == D) dir = L;
			}
			if(s[x][y]=='\\') {
				if(dir==U) dir = L;
				else if(dir==L) dir = U;
				else if(dir==D) dir = R;
				else if(dir==R) dir = D;
			}
		}
		return -1;
	};

	// horizontal : 1, 3, 5, ...
	// vertical : 2, 4, 6, ...

	auto rvs = [](int x) {
		if(x % 2) 
			return x + 1;
		else
			return x - 1;
	};

	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<m ; j++) { if(id[i][j]) 
			for(int dir=0 ; dir<4 ; dir++) {
				int cur = id[i][j] * 2 - (dir==L||dir==R);
				int nxt = simulate(i,j,dir);
				
				if(nxt == -1) cost[cur] = INF;
				else {
					merge(cur,nxt);
					merge(rvs(cur),rvs(nxt));
				}
			}		
		}
	}

	idx-=1;
	for(int i=1 ; i<=idx*2 ; i+=2) {
		if(find(i)==find(i+1)) {
			cout << -1 << "\n";
			return;
		}
	}

	vector<vector<int>> z(idx*2+100);
	for(int i=1 ; i<=idx*2 ; i++) {
		int par = find(i);
		z[par].push_back(i);
	}

	ll ans = 0;

	for(int i=1 ; i<=idx*2 ; i++) {
		ll ans1 = 0, ans2 = 0;
		for(auto x : z[i]) {
			ans1 += cost[x];
			ans2 += cost[rvs(x)];
		}
		if(ans1>=INF&&ans2>=INF) {
			cout << -1 << "\n";
			return;
		}
		ans += min(ans1, ans2);
	}
	cout << ans / 2 << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}