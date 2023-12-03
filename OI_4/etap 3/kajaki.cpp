#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
int kaj[maxn];

int main(){
	int n,k; cin >> k >> n;
	for(int i = 0; i < n; i++) cin >> kaj[i];
	sort(kaj, kaj+n);
	int i = 0;
	int j = n-1;
	int res = 0;
	while(i<=j){
		res++;
		if(kaj[i]+kaj[j]>k) j--;
		else{
			i++;
			j--;
		}
	}
	cout << res;
}
