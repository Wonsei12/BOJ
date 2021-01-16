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
	int n, m; cin >> n >> m;
	map<string, int> mp;
	vector<string> ss;
	for(int i=1 ; i<=n; i++) {
		string s; cin >> s;
		mp[s]=i; ss.push_back(s);
	}
	while(m--) {
		string s; cin >> s;
		if('0'<=s[0]&&s[0]<='9') {
			int cur = 0;
			for(int i=0 ; i<sz(s) ; i++) {
				cur *= 10;
				cur += s[i]-'0';
			}
			cout << ss[cur-1] << "\n";
		} else {
			cout << mp[s] << "\n";
		}
	}
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}