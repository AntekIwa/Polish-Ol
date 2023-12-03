#include<bits/stdc++.h>

using namespace std;

const int maxn = 1007;
int edges[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int res = 0;
    int n,m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        edges[a]++;
        edges[b]++;
    }
    int sumDif = 0;
    for(int i = 1; i <= n; i++) sumDif+= (edges[i]*(n-1-edges[i]));
    sumDif /= 2;
    cout << ((n*(n-1)*(n-2))/6) - sumDif;
}
