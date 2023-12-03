#include <iostream>

using namespace std;

int main(){
    int n,obw=0;
    cin >> n;
    int wyspa[n];
    for(int i = 0; i < n; i ++){
        cin >> wyspa[i];
        obw+=wyspa[i];
    }
    int maks = obw;
    int sred = obw/2 ;
    int y = 0;
    int x = 0;
    int s = 0;
    while(x< n){
        if(s<sred){
            s+= wyspa[x];
            x++;
        }
        else{
            s-=wyspa[y];
            y++;
        }
        if(abs(sred-s)<maks) maks = abs(sred-s);
    }
    cout << sred- maks;
    return 0;
}
