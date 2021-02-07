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
		if (pos == l && pos == r) return seg[idx] = val;
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
	void upd(int pos, ll val) {
		upd_(1, 0, n - 1, pos, val);
	}
	ll calc(int l, int r) {
		return calc_(1, 0, n - 1, l, r);
	} 
};

void solve() {
	int n; cin >> n;
	SegmentTree st(n);
	for(int i=0 ; i<n ; i++) {
		int x; cin >> x;
		st.upd(i,x%2);
	}
	int q; cin >> q;
	while(q--) {
		int qu; cin >> qu;
		if(qu == 1) {
			int i, x; cin >> i >> x; i--;
			st.upd(i,x%2);
		} else if(qu == 2) {
			int l, r; cin >> l >> r; l--, r--;
			cout << r-l+1-st.calc(l,r) << "\n";
		} else {
			int l, r; cin >> l >> r; l--, r--;
			cout << st.calc(l,r) << "\n";
		}
	}
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}