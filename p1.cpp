#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int>& a,vector<int>& b){
    return (((double)a[0]/(double)a[1])<((double)b[0]/(double)b[1]));
}

int main(){

    int t;
    cin>>t;
    vector<vector<int>> ar(t,vector<int> (3));
    for(int i=0;i<t;i++){
        cin>>ar[i][0]>>ar[i][1]>>ar[i][2];
    }

    sort(ar.begin(),ar.end(),cmp);

    for(int i=0;i<t;i++){
        cout<<" "<<ar[i][0]<<" "<<ar[i][1]<<" "<<ar[i][2]<<endl;
    }

    return 0;
}