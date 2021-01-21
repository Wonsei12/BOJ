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
	int A, B; cin >> A >> B;
	int C, D; cin >> C >> D;
	vector<int> visAfull(B+1), visBfull(A+1), visAempty(B+1), visBempty(A+1);
	visAempty[0]=visBempty[0]=1;
	queue<pair<int, pii>> q;
	q.push({0,{0,0}});
	while(!q.empty()) {
		int prev = q.front().ff, curA = q.front().ss.ff, curB = q.front().ss.ss; q.pop();
		assert(curA<=A&&curB<=B);
		if(C==curA&&D==curB) {
			cout << prev << "\n";
			return;
		}
		// case 1 : empty A
		if(visAempty[curB]==0) {
			visAempty[curB] = prev+1;
			q.push({prev+1,{0,curB}});
		}
		// case 2 : empty B
		if(visBempty[curA]==0) {
			visBempty[curA] = prev+1;
			q.push({prev+1,{curA,0}});
		}
		// case 3 : fill A
		if(visAfull[curB]==0) {
			visAfull[curB] = prev+1;
			q.push({prev+1,{A,curB}});
		}
		// case 4 : fill B
		if(visBfull[curA]==0) {
			visBfull[curA] = prev+1;
			q.push({prev+1,{curA,B}});
		}
		// case 5 : pour A to B
		if(curA + curB >= B) {
			// -> B is full
			// -> poured B - curB
			// -> curA - B + curB left in A
			assert(curA-B+curB <= A);
			if(visBfull[curA-B+curB]==0) {
				visBfull[curA-B+curB] = prev+1;
				q.push({prev+1,{curA-B+curB,B}});
			}
			if(curA+curB==B) {
				visAempty[B] = prev+1;
			}
		} else if(curA + curB < B) {
			// -> A is empty
			if(visAempty[curA+curB]==0) {
				visAempty[curA+curB] = prev+1;
				q.push({prev+1,{0,curA+curB}});
			}
		} 
		// case 6 : pour B to A
		if(curA + curB >= A) {
			// -> A is full
			// -> poured A - curA
			// -> curB - A + curA left in B
			assert(curA-A+curB <= B);
			if(visAfull[curA-A+curB]==0) {
				visAfull[curA-A+curB] = prev+1;
				q.push({prev+1,{A,curA-A+curB}});
			}
			if(curA+curB==A) {
				visBempty[A] = prev+1;
			}
		} else if(curA + curB < A) {
			if(visBempty[curA+curB]==0) {
				visBempty[curA+curB] = prev+1;
				q.push({prev+1,{curA+curB,0}});
			}
		} 
	}
	cout << -1 << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}