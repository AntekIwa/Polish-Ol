#include<bits/stdc++.h>

using namespace std;

void solve(){
    string n; cin >> n;
    cout << n << " ";
    if(n == "4" || n == "1"){
        cout << "\n";
        return;
    }
    int newn = 0;
    for(int i = 0; i < n.size(); i++)  newn += (n[i] - '0')*(n[i] - '0');
    while(newn != 4 && newn != 1){
        cout << newn << " ";
        int tmp = 0;
        while(newn > 0){
            tmp += (newn%10)*(newn%10);
            newn/=10;
        }
        newn = tmp;
    }
    cout << newn << "\n";
}
int main(){
    int q; cin >> q;
    while(q--) solve();
}
