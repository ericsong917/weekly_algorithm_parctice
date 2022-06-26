#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n;
int board[64][64];
bool is_ok(pair<int,int> start,int N){
    int ans=board[start.X][start.Y];
    for(int i=start.X;i<start.X+N;i++){
        for(int j=start.Y;j<start.Y+N;j++){
            if(board[i][j]!=ans){
                return false;}}}
    return true;
}
void recurse(pair<int,int> start,int N){
    if(is_ok(start,N)){
        cout<<board[start.X][start.Y];
    }
    else{
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                if(i==0&&j==0) {cout<<'(';}
                recurse({start.X+(i*N/2),start.Y+(j*N/2)},N/2);
                if(i==1 && j==1){cout<<')';}
            }
        }
    } 
}
int main(){
    cin>>n;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<n;j++){
            board[i][j]=str[j]-48;
        }
    }
    recurse({0,0},n);
}