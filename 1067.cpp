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
	int n; cin >> n;
	vector<ll> a(n*2), b(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
		a[i+n] = a[i];																																																																							
	}
	for(int i=n-1 ; i>=0 ; i--)
		cin >> b[i];
	vector<ll> res = multiply(a,b);
	cout << *max_element(all(res)) << "\n";
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}