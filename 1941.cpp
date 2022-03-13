#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#define X first
#define Y second
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char arr[5][5];
vector<int> group(7);
bool check_connected_arr[7]={true,true,true,true,true,true,true}; //연결선이 하나 이상인지 체크해서 저장하는 배열
int ans=0;
string temp;
bool check_connected(vector<int> check_arr){
    bool vis[5][5]={false,};
    int connected=1;
    queue<pair<int,int>> q;
    int x=check_arr[0]/5;
    int y=check_arr[0]%5;
    vis[x][y]=1;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> cur=q.front();
        int I=cur.X;
        int J=cur.Y;
        q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=I+dx[dir];
            int ny=J+dy[dir];
            if(nx<0||nx>=5||ny<0||ny>=5) {continue;}
            auto it=find(check_arr.begin(),check_arr.end(),(nx*5+ny));
            if(vis[nx][ny]) { continue;}
            if(it==check_arr.end()){
                continue;
            }
            vis[nx][ny]=1;
            connected++;
            q.push({nx,ny});
        }
    }

    if(connected==7){
        return true;
    }
    else{
        return false;
    }

}
bool check_previlege(vector<int> check_arr){
    int S_num=0; //이다솜파가 더 많아야함
    int Y_num=0;
    for(int k=0;k<7;k++){
        int i=check_arr[k]/5;
        int j=check_arr[k]%5; //숫자로부터 좌표 획득
        if(arr[i][j]=='S'){
            S_num++;
        }
        else{
            Y_num++;
        }
    }
    if(S_num>Y_num){
        return true;
    }
    else{
        return false;
    }
}
void com(int depth,int next){ //0~24 중에 7개를 뽑는 조합
    if(depth==7){ //arr 찾음
        if(check_connected(group)){
            if(check_previlege(group)){

                ans++;
            }
        }
        return;
    }
    for(int i=next;i<=24;i++){
        group[depth]=i;
        com(depth+1,i+1);
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    for(int i=0;i<5;i++){
        cin>>temp;
        for(int j=0;j<5;j++){
            arr[i][j]=temp[j];
        }
    }
    com(0,0);
    cout<<ans;





    
}