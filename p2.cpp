#include <bits/stdc++.h>
using namespace std;

int main(){

    int t,n,totalBed,r,s,h,walls=0;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        walls=0;
        char x;
        for(int j=0;j<n;j++){
            cin>>totalBed>>x>>r>>x>>s>>x>>h;
            walls=walls + (r*3) + (s*4) + (6*h);
        }

        double oneThirdWalls=(double)walls/3;
        double accentQty=oneThirdWalls*1.5;
        double regularQty=oneThirdWalls*2*2.25; //two third of walls
        double totalHours=(oneThirdWalls*2.5)+(oneThirdWalls*2*3.25);

        printf("%.2f %.2f %.2f\n",totalHours,accentQty,regularQty);

    }

    return 0;

}