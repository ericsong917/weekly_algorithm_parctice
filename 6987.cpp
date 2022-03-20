#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int d[6];
int arr[6][3];
int arr2[6][3];
int arr3[6][3];
int arr4[6][3];
bool answer1=false;
bool answer2=false;
bool answer3=false;
bool answer4=false;
int b_result[6][3];
int b_result2[6][3];
int b_result3[6][3];
int b_result4[6][3];

int a[15]={ 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
int b[15]={ 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };

void back_track(int depth,int arr[6][3], int result[6][3],bool * answer){
    if(*answer==true){
        return;
    }
    if(depth==15){
        bool flag=true;
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){   
                if(result[i][j]!=arr[i][j]){
                    flag=false;
                    break;
                }
            }
            if(flag==false) break;
        }

        if(flag){
            *answer=true;
        }
        return;
    }
    int x=a[depth];
    int y=b[depth];

    //x 승리 y 패배

    result[x][0]++; 
    result[y][2]++;
    back_track(depth+1, arr,result,answer);
    result[x][0]--;
    result[y][2]--;
    //무승부
    result[x][1]++; 
    result[y][1]++;
    back_track(depth+1,arr,result,answer);
    result[x][1]--; 
    result[y][1]--;
    //x 패배 y 승리
    result[x][2]++; 
    result[y][0]++;
    back_track(depth+1,arr,result,answer);
    result[x][2]--; 
    result[y][0]--;
}
void input(int ar[6][3]){
    for(int i=0;i<6;i++){
        for(int j=0;j<3;j++){
            cin>>ar[i][j];
}}
                }

void print_ans(bool answer){
    if(answer==true){
        cout<<"1 ";
    }
    else{
        cout<<"0 ";
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    input(arr);
    input(arr2);
    input(arr3);
    input(arr4);
    back_track(0,arr,b_result,&answer1);
    back_track(0,arr2,b_result2,&answer2);
    back_track(0,arr3,b_result3,&answer3);
    back_track(0,arr4,b_result4,&answer4);
    print_ans(answer1);
    print_ans(answer2);
    print_ans(answer3);
    print_ans(answer4);
    return 0;
}