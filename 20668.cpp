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

const int MAX_N = 1e4 + 1;
const int MAX_M = 1e5 + 1;

vector<pair<int, pii>> G[MAX_M];
vector<vector<ll>> dis(MAX_N, vector<ll>(12, LLINF));

int main() {
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int A, B, L, K;
		cin >> A >> B >> L >> K;
		G[A].push_back({B, {L, K}});
		G[B].push_back({A, {L, K}});
	}
	
	priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;
	pq.push({0, {1, 1}});
	dis[1][1] = 0;
	
	while(!pq.empty()) {
		ll c = pq.top().ff;
		int x = pq.top().ss.ff;
		int s = pq.top().ss.ff;
		pq.pop();
		
		if(dis[x][s] < c) continue;

		for(auto nxt : G[x]) {
			ll y = nxt.ff;
			ll l = nxt.ss.ff;
			ll k = nxt.ss.ss;
			
			if(s + 1 <= k) {
				ll nc = dis[x][s] + (l * 2520 / (s + 1));
				if(dis[y][s + 1] > nc) {
					dis[y][s + 1] = nc;
					pq.push({nc, {y, s + 1}});
				}
			}
			
			if(s <= k) {
				ll nc = dis[x][s] + (l * 2520 / s);
				if(dis[y][s] > nc) {
					dis[y][s] = nc;
					pq.push({nc, {y, s}});
				}
			}
			
			if(s - 1 >= 1 && s - 1 <= k) {
				ll nc = dis[x][s] + (l * 2520 / (s - 1));
				if(dis[y][s - 1] > nc) {
					dis[y][s - 1] = nc;
					pq.push({nc, {y, s - 1}});
				}
			}
		}
	}
	
	ll ans = LLONG_MAX;
	for(int k = 1; k <= 10; k++) 
		ans = min(ans, dis[N][k]);
	ll mok = ans / 2520;
	ll nam = ans % 2520;
	vector<int> nams;
	for(int i=1 ; i<=10 ; i++) {
		nam *= 10;
		nams.push_back(nam / 2520);
		nam %= 2520;
	}
	bool lft = false;
	if(nams[9] >= 5) {
		for(int i=9 ; i>=0 ; i--) {
			if(nams[i] == 9) {
				nams[i] = 0;
				lft = true;
			}
			else {
				nams[i] += 1;
				lft = false;
				break;
			}
		}
		if(lft)
			mok += 1;
	}
	cout << mok << ".";
	for(int i=0 ; i<9 ; i++) 
		cout << nams[i];
	
	return 0;
}