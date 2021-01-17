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
	int s, e; cin >> s >> e;
	vector<string> ans(10001,"-");
	queue<int> q;
	q.push(s);
	ans[s]="";
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		if(cur==e) {
			cout << ans[cur] << "\n";
			return;
		}
		int nxt = cur - 1;
		if(nxt<0) nxt = 9999;
		if(ans[nxt]=="-") {
			ans[nxt]=ans[cur]+"S";
			q.push(nxt);
		}
		nxt = (cur*2)%10000;
		if(ans[nxt]=="-") {
			ans[nxt]=ans[cur]+"D";
			q.push(nxt);
		}
		nxt = (cur-1000*(cur/1000))*10+(cur/1000);
		if(ans[nxt]=="-") {
			ans[nxt]=ans[cur]+"L";
			q.push(nxt);
		}
		nxt = cur/10 + (cur%10)*1000;
		if(ans[nxt]=="-") {
			ans[nxt]=ans[cur]+"R";
			q.push(nxt);
		}
	}
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}