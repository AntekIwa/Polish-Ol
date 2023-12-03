#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t,a,n;
  cin >> t >> a >> n;
  int tl[n], az[n], w[n];
  for(int i = 0; i < n; i++) cin >> tl[i] >> az[i] >> w[i];
  
  // knapsack problem - dynamic programming
  int Ta[t+1][a+1];
  // set all values to infinity
  for(int i = 0; i<= t; i++){
    for(int j = 0; j <= a; j++){
      Ta[i][j] = 1000000;
    }
  }
  Ta[0][0] = 0;
  int ti, ai,td,ad,k;
  for(k = 0; k < n; k++){
    for(ti = t; ti >= 0; ti--){
      for(ai = a; ai >=0; ai--){
         // computing new solve from prevoius solutions
          td = min(t,ti+tl[k]);
          ad = min(a,ai+az[k]);
          Ta[td][ad] = min(Ta[td][ad], Ta[ti][ai] + w[k]);
      }
    }
  }
  cout << Ta[t][a];
  return 0;
}
