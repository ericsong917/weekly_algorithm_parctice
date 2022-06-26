#include<bits/stdc++.h>
using namespace std;
int arr[20];
int m;
bool is_used[20];
int print_arr[20];
void back(int k){
    if(k==6){
        for(int i=0;i<6;i++){
            cout<<print_arr[i]<<' ';
        }
        cout<<"\n";
        return;
    }
    for(int i=0;i<=m-1;i++){
        if(!is_used[i]){
            print_arr[k]=arr[i];
            is_used[i]=1;
            back(k+1);
            is_used[i]=0;
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    while(1)
{       cin>>m;
        if(m==0){break;}
        for(int i=0;i<m;i++){
            cin>>arr[i];}
        back(0);
}
    return 0;
}