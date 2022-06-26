#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[128][128] ;
int white; //0
int blue; //1
int n;
bool is_ok(pair<int,int> start,int N){
    int ans=board[start.X][start.Y];
    for(int i=start.X;i<start.X+N;i++){
        for(int j=start.Y;j<start.Y+N;j++){
            if(board[i][j]!=ans){
                return false;}}}
    return true;
}
void recurse(pair<int,int> start, int N){
    if(is_ok(start,N)){
        if(board[start.X][start.Y]==0){white++;}
        else{blue++;}
    }
    else{
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){   
                recurse({start.X+(i*N/2),start.Y+(j*N/2)},N/2);
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    recurse({0,0},n);
    cout<<white<<'\n'<<blue;
}