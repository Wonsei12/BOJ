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
	int m; cin >> m;
	queue<int> q;
	while(m--) {
		string s; cin >> s;
		if(s=="size") {
			cout << sz(q) << "\n";
		} else if(s=="push") {
			int x; cin >> x;
			q.push(x);
		} else if(s=="front") {
			if(sz(q)) 
				cout << q.front() << "\n";
			else
				cout << -1 << "\n";
		} else if(s=="empty") {
			if(sz(q))
				cout << 0 << "\n";
			else
				cout << 1 << "\n";
		} else if(s=="back") {
			if(sz(q)) 
				cout << q.back() << "\n";
			else
				cout << -1 << "\n";
		}
		else {
			if(sz(q)) {
				cout << q.front() << "\n";
				q.pop();
			} else
				cout << -1 << "\n";
		}
	}
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}