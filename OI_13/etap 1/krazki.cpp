#include <bits/stdc++.h>
//minimum on prefix
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n,m,tmp,a;
    cin >> n >> m;
    int mini[n],k[n];
    cin >> mini[0];
    for(int i = 1; i < n; i++){
        cin >> tmp;
        mini[i] = min(tmp,mini[i-1]);
    }
    int d = n;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        while (d>0 && mini[d-1]<x) d--;
        d--;
    }
    cout << max(0,d+1);
    return 0;
}
