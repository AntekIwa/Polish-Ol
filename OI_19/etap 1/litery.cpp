#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()

const int base = 1<<20;
vector<int> tree(2*base);

void add(int x){
	x += base;
	while(x > 0){
		tree[x]++;
		x/=2;
	}
}

ll query(int x){
	x+=base;
	int end = 2*base-1;
	ll sum = 0;	
	while(x <= end && x != 0&& end != 0 ){
		if(x%2 == 1) sum += tree[x];
		if(end%2 == 0) sum += tree[end];
		x = (x+1)/2;
		end = (end-1)/2;
	}
	return sum;
}
int main(){
  ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n; cin >> n;
	string a,b; cin >> a >> b;
	queue<int> tab[26];
	for(int i = 0; i < n; i++) tab[a[i]-'A'].push(i);
	vector<int> ciag(n);
	for(int i = 0; i < n; i++){
		ciag[i] = tab[b[i]-'A'].front();
		tab[b[i]-'A'].pop();
	}
	ll res = 0;
	for(int i = 0; i < n; i++){
		res += query(ciag[i] + 1);
		add(ciag[i]);
	}
	cout << res;
	return 0;
}
