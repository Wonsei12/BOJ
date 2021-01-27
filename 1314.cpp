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
	int n; cin >> n;
	vector<int> w(n), t(n);
	for(int i=0 ; i<n ; i++)
		cin >> w[i] >> t[i];
	vector<string> trust(n);
	for(int i=0 ; i<n ; i++)
		cin >> trust[i];
	int limit; cin >> limit;

	auto check = [&](int x) {
		vector<int> mask;
		int weight = 0;
		int idx = 0;
		while(x > 0) {
			if(x & 1) {
				mask.push_back(idx);
				weight += w[idx];
			}
			idx += 1;
			x /= 2;
		}
		if(weight > limit)
			return false;
		if(sz(mask) == 1)
			return true;
		for(int i=0 ; i<sz(mask) ; i++) {
			bool suc = false;
			for(int j=0 ; j<sz(mask) ; j++) {
				if(i == j) continue;
				if(trust[mask[i]][mask[j]] == 'Y') {
					suc = true;
					break;
				}
			}
			if(!suc) 
				return false;
		}
		return true;
	};

	vector<int> dp(pw(n), INF);
	dp[0] = 0;

	auto pop_count = [](int x) {
		int cnt = 0;
		while(x > 0) {
			if(x & 1)
				cnt += 1;
			x /= 2;
		}
		return cnt;
	};

	auto cmp = [&](int x, int y) {
		return pop_count(x) < pop_count(y);
	};

	vector<int> dx;
	for(int i=0 ; i<pw(n) ; i++) {
		dx.push_back(i);
	}
	sort(dx.begin(),dx.end(),cmp);

	queue<int> q;
	q.push(0);

	while(!q.empty()) {
		int mask = q.front(); q.pop(); //debug(mask);
		for(int newMask = 1 ; newMask < pw(n) ; newMask++) {
			if(newMask & mask) continue;
			if(!check(newMask)) continue;
			int tmp = newMask;
			int elapsed = 0;
			int idx = 0;
			while(tmp > 0) {
				if(tmp & 1) {
					elapsed = max(elapsed, t[idx]);
				}
				idx += 1;
				tmp /= 2;
			}
			if((newMask | mask) == pw(n) - 1) {
				dp[pw(n)-1] = min(dp[pw(n)-1], dp[mask] + elapsed);
			} else {
				int tot = (mask | newMask);
				for(int p = tot ; p ; p=(p-1)&tot) {
					if(!check(p)) continue;
					int tmp = p;
					int elapsed2 = 0;
					int idx = 0;
					while(tmp > 0) {
						if(tmp&1) {
							elapsed2 = max(elapsed2, t[idx]);
						}
						idx += 1;
						tmp /= 2;
					}
					if(dp[tot ^ p] > dp[mask] + elapsed + elapsed2)
						q.push(tot^p);
					dp[tot ^ p] = min(dp[tot ^ p], dp[mask] + elapsed + elapsed2);
				}
			}
		}
	}
	if(dp[pw(n)-1] == INF)
		cout << -1 << "\n";
	else
		cout << dp[pw(n)-1] << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}