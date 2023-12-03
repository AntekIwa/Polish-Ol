#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    vector<int> arr;
    cin >> n;
    while(n!=0){
        if(n == 0) break;
        arr.push_back(n);
        cin >> n;
    }
    sort(arr.begin(), arr.end());
    n = arr.size();
    for(int i = 0; i < n - 2; i++){
        if(arr[i] + arr[i+1] > arr[i+2]){
            cout << arr[i] << " " << arr[i+1] << " " << arr[i+2] << "\n";
            return 0;
        }
    }
    cout << "NIE\n";
}
