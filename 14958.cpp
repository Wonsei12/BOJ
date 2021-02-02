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

typedef complex<double> cpx;

void fft(vector<cpx> &a, bool inv){
    int n = sz(a), j = 0;
    vector<cpx> roots(n/2);
    for(int i=1; i<n; i++){
        int bit = (n >> 1);
        while(j >= bit) j -= bit, bit >>= 1;
        j += bit;
        if(i < j) swap(a[i], a[j]);
    }
    double ang = 2 * PI / n * (inv ? -1 : 1);
    for(int i=0; i<n/2; i++) roots[i] = cpx(cos(ang * i), sin(ang * i));
    for(int i=2; i<=n; i<<=1){
        int step = n / i;
        for(int j=0; j<n; j+=i) for(int k=0; k<i/2; k++){
            cpx u = a[j+k], v = a[j+k+i/2] * roots[step * k];
            a[j+k] = u+v; a[j+k+i/2] = u-v;
        }
    }
    if(inv) for(int i=0; i<n; i++) a[i] /= n;
}
vector<ll> multiply(vector<ll> &v, vector<ll> &w){
    vector<cpx> fv(v.begin(), v.end());
    vector<cpx> fw(w.begin(), w.end());
    int n = 2; 
    while(n < sz(v) + sz(w)) 
    	n <<= 1;
    fv.resize(n); fw.resize(n);
    fft(fv, 0); fft(fw, 0);
    for(int i=0; i<n; i++) fv[i] *= fw[i];
    fft(fv, 1);
    vector<ll> ret(n);
    for(int i=0; i<n; i++) ret[i] = (ll)round(fv[i].real());
    return ret;
}

void solve() {
	int n, m; cin >> n >> m;
	string s1, s2; cin >> s1 >> s2;
	vector<ll> s1R(n), s1P(n), s1S(n);
	vector<ll> s2R(m), s2P(m), s2S(m);
	for(int i=0 ; i<n ; i++) {
		s1R[i] += s1[i] == 'R';
		s1P[i] += s1[i] == 'P'; 
		s1S[i] += s1[i] == 'S';
	}
	for(int i=0 ; i<m ; i++) {
		s2R[i] += s2[i] == 'R';
		s2P[i] += s2[i] == 'P';
		s2S[i] += s2[i] == 'S';
	}
	reverse(all(s2R));
	reverse(all(s2P));
	reverse(all(s2S));
	vector<ll> res1 = multiply(s1R, s2P);
	vector<ll> res2 = multiply(s1P, s2S);
	vector<ll> res3 = multiply(s1S, s2R);
	for(int i=0 ; i<sz(res1) ; i++) {
		res1[i] += res2[i] + res3[i];
	}
	ll mx = 0;
	for(int i=m-1 ; i<m+n-1 ; i++) {
		mx = max(mx, res1[i]);
	}
	cout << mx << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}