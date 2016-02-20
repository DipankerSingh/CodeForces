#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c)	for(auto &(i) : (c))
#define x     first
#define y     second
#define pb  push_back
#define PB  pop_back()
#define iOS  ios_base::sync_with_stdio
#define mp(a,b) make_pair(a,b)
#define sqr(a)  ((1LL * (a) * (a)))
#define all(a)  a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define double long double
typedef pair<int,int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>	os;
typedef long long ll;
const int maxn = 1e5 + 100, mod = 1e9 + 7;
#define int ll
int p[maxn], x[maxn], f[maxn],a,b,n,q;
main(int argc,char ** argv){
	iOS(false);
	cin >> n >> q;
	For(i,0,2)
		cin >> f[i];
	cin >> a >> b;
	For(i,2,maxn)
		f[i] = (1LL * a * f[i-2] + 1LL * b * f[i-1]) % mod;
	For(i,0,n)
		cin >> x[i];
	while(q--){
		int l,r;
		cin >> l >> r;
		-- l;
		-- r;
		if(l < r){
			p[l] = (p[l] + f[0]) % mod;
			p[l+1] = (p[l+1] + f[1])%mod;
			p[l+1] = (1LL * p[l+1] + mod - 1LL * ((1LL * b * f[0])%mod))%mod;
			p[r + 1] = (1LL * p[r+1] + mod - f[r - l + 1])%mod;
			p[r + 2] = (1LL * p[r+2] + mod - 1LL * ((1LL * a * f[r-l])%mod))%mod;
		}
		else{
			p[l] = (p[l] + f[0])%mod;
			p[r+1] = (1LL * p[r+1] + mod - ((1LL * b * f[0])%mod))%mod;
			p[r+2] = (1LL * p[r+2] + mod - 1LL * ((1LL * a * f[0])%mod))%mod;
		}
	}
	For(i,0,8)
	{
	    cout<<p[i]<<endl;
	}
	For(i,0,n){
		if(i > 1)
			p[i] = (1LL * p[i] + a * p[i-2])%mod;
		if(i)
			p[i] = (1LL * p[i] + b * p[i-1])%mod;
		x[i] = (p[i] + x[i])%mod;
		cout << x[i];
		if(i + 1 < n)
			cout << ' ';
	}
	cout << endl;
}
