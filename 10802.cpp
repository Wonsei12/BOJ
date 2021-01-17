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
const ll MOD = 20150523;
const long double PI = acos(-1.0);

ll solve1(string s) { // 1~s까지 3의 배수가 몇개 있는지
	vector<vector<vector<ll>>> dp(sz(s)+1, vector<vector<ll>>(3, vector<ll>(2,-1)));
	function<ll(int,int,int)> dfs = [&](int idx, int num, int ok) -> ll {
		if(idx == sz(s)) 
			return (int)(num == 0);

		ll& ret = dp[idx][num][ok];
		if(ret != -1)
			return ret;
		ret = 0;
		
		if(ok) {
			for(int i=0 ; i<=9 ; i++) {
				ret += dfs(idx+1, (num+i)%3, ok);
				ret %= MOD;
			}
		} else {
			int cur = s[idx] - '0';
			for(int i=0 ; i<cur ; i++) {
				ret += dfs(idx+1, (num+i)%3, true);
				ret %= MOD;
			}
			ret += dfs(idx+1, (num+cur)%3, false);
			ret %= MOD;
		}
		return ret;
	};	
	ll ans = 0;
	for(int i=0 ; i<(int)(s[0]-'0') ; i++) {
		ans += dfs(1, i%3, true);
		ans %= MOD;
	}
	ans += dfs(1, (int)(s[0]-'0')%3, false);
	ans -= 1;
	ans %= MOD;
	ans += MOD;
	ans %= MOD;
	return ans;
}

ll solve2(string s) { // 1~s까지 3, 6, 9을 사용하는 숫자가 몇개 있는지
	// 3, 6, 9를 쓰지 않아보자
	vector<vector<ll>> dp(sz(s)+1, vector<ll>(2, -1));
	function<ll(int,int)> dfs = [&](int idx, int ok) -> ll {
		if(idx == sz(s)) 
			return 1;

		ll& ret = dp[idx][ok];
		if(ret != -1)
			return ret;
		ret = 0;
		if(ok) {
			for(int i=0 ; i<=9 ; i++) {
				if(i==3||i==6||i==9)
					continue;
				ret += dfs(idx+1, ok);
				ret %= MOD;
			}
		} else {
			int cur = s[idx] - '0';
			for(int i=0 ; i<cur ; i++) {
				if(i==3||i==6||i==9)
					continue;
				ret += dfs(idx+1, true);
				ret %= MOD;
			}
			if(cur!=3&&cur!=6&&cur!=9) 
				ret += dfs(idx+1, false);
			ret %= MOD;
		}
		return ret;
	};
	ll ans = 0;
	int cur = (int)(s[0]-'0');
	for(int i=0 ; i<cur ; i++) {
		if(i==3||i==6||i==9)
				continue;
		ans += dfs(1, true);
	}
	if(cur!=3&&cur!=6&&cur!=9)
		ans += dfs(1, false);
	ans -= 1;
	ll m = 0;
	for(char c : s) {
		m *= 10;
		m += c-'0';
		m %= MOD;
	}
	ans = ((m - ans) % MOD + MOD) % MOD;
	return ans;
}

ll solve3(string s) { // 3의 배수이나, 3, 6, 9를 쓰지 않는 애들 갯수
	vector<vector<vector<ll>>> dp(sz(s)+1, vector<vector<ll>>(3, vector<ll>(2,-1)));
	function<ll(int,int,int)> dfs = [&](int idx, int num, int ok) -> ll {
		if(idx == sz(s)) 
			return (int)(num == 0);

		ll& ret = dp[idx][num][ok];
		if(ret != -1)
			return ret;
		ret = 0;
		if(ok) {
			for(int i=0 ; i<=9 ; i++) {
				if(i==3||i==6||i==9)
					continue;
				ret += dfs(idx+1, (num+i)%3, ok);
				ret %= MOD;
			}
		} else {
			int cur = s[idx] - '0';
			for(int i=0 ; i<cur ; i++) {
				if(i==3||i==6||i==9)
					continue;
				ret += dfs(idx+1, (num+i)%3, true);
				ret %= MOD;
			}
			if(cur!=3&&cur!=6&&cur!=9)
				ret += dfs(idx+1, (num+cur)%3, false);
			ret %= MOD;
		}
		return ret;
	};	
	ll ans = 0;
	int cur = (int)(s[0]-'0');
	for(int i=0 ; i<cur ; i++) {
		if(i==3||i==6||i==9)
			continue;
		ans += dfs(1, i%3, true);
		ans %= MOD;
	}
	if(cur!=3&&cur!=6&&cur!=9)
		ans += dfs(1, cur%3, false);
	ans -= 1;
	ans += MOD;
	ans %= MOD;
	return ans;
}

ll solve(string s) {
	ll a1 = solve1(s); // 3의 배수의 갯수 
	ll a2 = solve2(s); // 3, 6, 9를 사용하는 애들의 갯수
	ll a3 = solve3(s); // 3의 배수이면서 3, 6, 9를 사용하지 않는 애들

	ll gyo = a1 - a3;
	ll ans = a1 + a2 - gyo;
	ans %= MOD; ans += MOD; ans %= MOD;
	return ans;
}

int clap(string s) {
	int sum = 0;
	for(auto c : s) {
		if((c-'0')==3||(c-'0')==6||(c-'0')==9) 
			return 1;
		sum += c-'0';
	}
	if(sum%3==0)
		return 1;
	else
		return 0;
}

void solve() {
	string a, b; cin >> a >> b;
	cout << ((solve(b) - solve(a) + clap(a)) % MOD + MOD) % MOD << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}