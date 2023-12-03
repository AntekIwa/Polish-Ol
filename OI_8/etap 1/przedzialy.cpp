#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n,a,b,ile= 0;
    cin >> n;
    vector<pair<int,int>> przed;
    for(int i = 0; i < n; i ++){
        cin >> a >> b;
        przed.push_back(make_pair(a,b));
    }
    sort(przed.begin(), przed.end());
    int akt = 0;
    for(int i = 1; i < n;i++){
        if(przed[akt].second>= przed[i].first && przed[akt].second < przed[i].second) przed[akt].second = przed[i].second;
        else{
            cout << przed[akt].first << " " << przed[akt].second << endl;
            ile++;
            akt = i;
        }
    }
    cout << przed[akt].first << " " << przed[akt].second << endl;
    return 0;

}
