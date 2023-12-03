#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()

const int MAX_N = 1e6 + 7;
vector<ll> prime = {2,3,5,7,11,13,17,19,23,29};
vector<pair<ll,ll>> apCand;
vector<ll> antiprime;
int n;
void gen(ll primeIdx, ll maxPow, ll actNumb, ll divCnt){
	apCand.pb({actNumb, divCnt});
	for(int i = 1; i <= maxPow; i++){
		if(prime[primeIdx]>n/actNumb) return;
		actNumb*=prime[primeIdx];
		gen(primeIdx+1, i, actNumb, divCnt*(i+1));
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	gen(0,31,1,1);
	sort(all(apCand));
	int maxx = 0;
	for(int i = 0; i < apCand.size(); i++){
		if(apCand[i].nd > maxx){
			maxx = apCand[i].nd;
			antiprime.pb(apCand[i].st);
		}
	}
	cout << antiprime[antiprime.size()-1];
	return 0;
}
