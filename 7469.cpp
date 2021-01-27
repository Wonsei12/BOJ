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

class SegmentTree {
public:
	vector<vector<int>> seg;
	int n, mn, mx;
	vector<int> v;
	SegmentTree(vector<int> v) {
		this->v = v;
		n = sz(v);
		mn = *min_element(v.begin(),v.end());
		mx = *max_element(v.begin(),v.end());
		seg.resize(n*4+5);
		build(1,0,n-1);
	}
	void build(int idx, int s, int e) {
		for(int i=s ; i<=e ; i++) {
			seg[idx].push_back(v[i]);
		}
		sort(seg[idx].begin(),seg[idx].end());
		int mid = (s+e) / 2;
		if(s!=e) {
			build(idx*2, s, mid);
			build(idx*2+1, mid+1, e);
		}
	}
	int query(int idx, int s, int e, int l, int r, int z) {
		if(l > r) 
			return 0;
		if(l == s && r == e) {
			int cnt = lower_bound(seg[idx].begin(),seg[idx].end(),z) - seg[idx].begin();
			return cnt;
		}
		int mid = (s + e) / 2;
		return query(idx*2, s, mid, l, min(r, mid), z)
			 + query(idx*2+1, mid+1, e, max(mid+1, l), r, z);
	}
	int query2(int l, int r, int k) {
		int ans = -1;
		int L = mn, R = mx;
		while(L <= R) {
			int mid = (L+R) / 2;
			int z = query(1,0,n-1,l,r,mid);
			if(z <= k-1) {
				L = mid + 1;
				ans = mid;
			} else {
				R = mid - 1;
			}
		}	
		return ans;
	}
};

void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
	}
	SegmentTree st(a);
	while(q--) {
		int l, r, z; cin >> l >> r >> z;
		cout << st.query2(l-1,r-1,z) << "\n";
	}
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}