#include <bits/stdc++.h>
using namespace std;
int n=-1;
int arr[15];
bool is_used[15];
int ans[15];
int index=0;
int c=0;
int combination(int n, int r)
{
    if(n == r || r == 0) 
        return 1; 
    else 
        return combination(n - 1, r - 1) + combination(n - 1, r);
}
void func(int start,int k){
    if(k==6){
        for(int i=0;i<6;i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=start;i<n;i++){
        ans[k]=arr[i];
        func(i+1,k+1);
        }
    }

int main(){
    while(1){
        cin>>n;
        if(n==0) { return 0;}
        for(int i=0;i<n;i++){
        cin>>arr[i];
        }
        func(0,0);
        cout<<"\n";
        }

}