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

struct cmp {
	bool operator() (int a, int b) {
		return a > b;
	}
};

void solve() {
	int n; cin >> n;
	priority_queue<int, vector<int>, cmp> pq;
	while(n--) {
		int a; cin >> a;
		if(a==0) {
			if(sz(pq)) {
				cout << pq.top() << "\n";
				pq.pop();
			} else {
				cout << 0 << "\n";
			}
		}
		else {
			pq.push(a);
		}
	}
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}