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

class SegmentTree {
public:
	vector<ll> seg;
	int n;
	SegmentTree(int n) {
		seg.resize(4 * n + 5);
		this->n = n;
	}
	ll upd_(int idx, int l, int r, int pos, ll val) {
		if (pos < l || pos > r) return seg[idx];
		if (pos == l && pos == r) return seg[idx] += val;
		int mid = (l + r) / 2;
		return seg[idx] = upd_(idx * 2, l, mid, pos, val) +
				upd_(idx * 2 + 1, mid + 1, r, pos, val);
	}
	ll calc_(int idx, int l, int r, int tl, int tr) {
		if (tl > tr) return 0;
		if (tl == l && tr == r) return seg[idx];
		int mid = (l + r) / 2;
		return calc_(idx * 2, l, mid, tl, min(tr, mid)) +
			calc_(idx * 2 + 1, mid + 1, r, max(mid + 1, tl), tr);
	}
	ll find_(int idx, int l, int r, ll rank) {
		if(l==r) return l;
		int mid = (l+r)/2;
		if(seg[idx*2]>=rank) return find_(idx*2,l,mid,rank);
		else return find_(idx*2+1,mid+1,r,rank-seg[idx*2]); 
	}
	void upd(int pos, ll val) {
		upd_(1, 0, n - 1, pos, val);
	}
	ll calc(int l, int r) {
		return calc_(1, 0, n - 1, l, r);
	} 
	ll find(ll rank) {
		return find_(1, 0, n-1, rank);
	}
};

bool cmp(pair<int, pii> a, pair<int, pii> b) {
	return a.ss.ff < b.ss.ff;
}

bool cmp2(pii a, pii b) {
	return a.ss < b.ss;
}

int main() {
	IOS;
	int n; cin >> n;
	int qq; cin >> qq;
	vector<vector<int>> G(n);
	vector<ll> a(n);
	for(int i=0 ; i<n ; i++) 
		cin >> a[i];
	vector<pii> p(n); 
	p[0] = {0,-1};
	for(int i=1 ; i<n ; i++) {
		int x; cin >> x; x--;
		p[i] = {i,x};
		G[x].push_back(i);
	}
	sort(p.begin(),p.end(),cmp2);
	vector<ll> v(n);
	function<ll(int)> val = [&](int x) {
		ll ret = 0;
		for(int nxt : G[x])
			ret += val(nxt);
		return v[x] = ret + a[x];
	};
	val(0);
	vector<pair<int, pii>> q(qq);
	for(int i=0 ; i<qq ; i++) {
		q[i].ff = i;
		cin >> q[i].ss.ff >> q[i].ss.ss;
		q[i].ss.ff --, q[i].ss.ss --;
	}
	sort(q.begin(),q.end(),cmp);
	SegmentTree st(n);

	int idx = 0;
	vector<ll> ans(qq);
	for(int i=0 ; i<qq ; i++) {
		while(idx < n && p[idx].ss < q[i].ss.ff) {
			int z = p[idx].ff;
			st.upd(z, v[z]);
			idx += 1;
		}
		ans[q[i].ff] = st.calc(q[i].ss.ff, q[i].ss.ss);
	}
	for(auto x : ans) {
		cout << x << "\n";
	}
}