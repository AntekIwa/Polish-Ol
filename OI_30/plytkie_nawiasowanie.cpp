#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()

string naw = "";
int res = 0;
int aktualna_gleb = 0;
int n = 0;
int szuk_h = 0;

void check(int idx){
    if(naw[idx] == ')' && aktualna_gleb>0) aktualna_gleb--;
    else if(naw[idx] == ')' && aktualna_gleb == 0){
        aktualna_gleb++;
        res++;
    }
    else if(naw[idx] == '(' && aktualna_gleb < szuk_h) aktualna_gleb++;
    else{
        aktualna_gleb--;
        res++;
    }
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //input
    cin >> n >> szuk_h;
    cin >> naw;
    
    rep(i,n) check(i);
    cout << res << "\n";
    return 0;
}
