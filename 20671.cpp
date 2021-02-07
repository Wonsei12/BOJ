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

int n;
vector<vector<pair<pii, int>>> pos;
vector<int> p;

int find(int x) {
	if(x == p[x]) return x;
	return p[x] = find(p[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	p[x] = y;
}

bool cmp(pair<pii, int> a, pair<pii, int> b) {
	return a.ff.ff < b.ff.ff;
}

int main() {
	IOS;
	cin >> n;
	p = vector<int>(n + 1);
	for(int i=0 ; i<=n ; i++) 
		p[i] = i;
	vector<int> par(n, -1);
	pos = vector<vector<pair<pii, int>>> (n+1);
	for(int i=0 ; i<n ; i++) {
		int h, l, r; cin >> h >> l >> r;
		pos[h].push_back({{l,r},i});
	}
	for(int i=1 ; i<=n ; i++) {
		sort(pos[i].begin(),pos[i].end(),cmp);
	}
	for(int i=2 ; i<=n ; i++) {
		for(auto x : pos[i]) {
			int l = 0, r = sz(pos[i-1]) - 1;
			int ans = -1;
			while(l <= r) {
				int mid = (l + r) / 2;
				if(pos[i-1][mid].ff.ff <= x.ff.ff) {
					ans = mid;
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			par[x.ss] = pos[i-1][ans].ss; 
		}
	}
	int q; cin >> q;
	auto solve = [&](int h, int x) -> int {
		if(sz(pos[h]) == 0) return -1;
		int l = 0, r = sz(pos[h]) - 1;
		while(l <= r) {
			int mid = (l+r) / 2;
			if(x >= pos[h][mid].ff.ff && x <= pos[h][mid].ff.ss) {
				return pos[h][mid].ss;
			} else if(x < pos[h][mid].ff.ff) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return -1;
	};

	while(q--) {
		int x, p; cin >> x >> p;
		int l = 1, r = n, ans = -1;
		while(l <= r) {
			int mid = (l+r) / 2;
			int s = solve(mid, x);
			if(s != -1) {
				l = mid + 1;
				ans = s;
			} else {
				r = mid - 1;
			}
		}
		if(ans == -1) {
			cout << 0 << " ";
		} else {
			int cnt = 0;
			while(p--) {
				ans = find(ans);
				if(ans == n) break;
				if(par[ans] == -1) unite(ans, n);
				else unite(ans, par[ans]);
				cnt ++;
			}
			cout << cnt << " ";
		}
	}
}