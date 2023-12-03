#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,suma=0;
    cin >> n;
    int izo[n];
    for(int i = 0; i < n; i++){
        cin >> izo[i];
        suma+=izo[i];
    }
    sort(izo,izo+n);
    int i = 0, j = n-1;
    while(i<=j){
        suma+=izo[j]-izo[i];
        i++;
        j--;
    }
    cout << suma;
    return 0;
}
