#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* You can modify from here */
//for additional header files
/* You can modify to here */
#define MAX_LENGTH          10
#define MAX_CANDIDATES      10000
void backtrack(int a[],int k,int n);
int finished = 0;
char str_input[MAX_LENGTH+1];
char str_goal[MAX_LENGTH+1];
/* You can modify from here */
//for user-defined functions
int combineok=0;
int check[20]={0,};
int dap[20];
int answer_dap[20];
char string_arr[20][20];
char answer_string_arr[20][20];
char temp_string[20]="";
int answer_length=100;
int sum_of_arr(int a[],int n){
	int sum=0;
	for(int i=1;i<n;i++){
		sum+=a[i];
	}
    return sum;
}

void perm(int x,int n){
	if(x==n){
		strcpy(temp_string,"");
		combineok=0;
        for(int i=0;i<n;i++){
            strcat(temp_string,string_arr[dap[i]-1]);
        }
        if(strcmp(temp_string,str_goal)==0){
			combineok=1;
			return;
		}
        else{
			return ;
		}
	}
	for(int i=0;i<n;i++){
		if(check[i]==0){
			check[i]=1;
			dap[x]=i+1;
			perm(x+1,n);
			check[i]=0;
		}
	}
}

int combine_ok(int a[],int k){
    int start=0;
    for(int i=0;i<k;i++){
		dap[k]=i+1;
        strncpy(string_arr[i],&str_input[start],a[i+1]);
        start+=a[i+1];
        string_arr[i][a[i+1]]='\0';
        } //split 완료
		perm(0,k);
		if(combineok==1){

			return 1;
		}
		else{
			return 0;
		}
}
/* You can modify to here */


void construct_candidates(int a[],int k,int n,int c[],int *ncandidates) { 
  /* You can modify from here */
	*ncandidates=0;
	for(int i=1;i<=n+1;i++){
		if(sum_of_arr(a,k)+i>n+1){
			break;
		}
		else{
			c[*ncandidates]=i;
			*ncandidates=*ncandidates+1;
		}
	}
  /* You can modify to here */
}

void process_solution(int a[],int k) { 
  /* You can modify from here */
	if(k<answer_length){
		for(int i=0;i<k;i++){
			answer_dap[i]=dap[i];
			strcpy(answer_string_arr[i],string_arr[i]);
			answer_length=k;
			}
	}

  /* You can modify to here */
}

int is_a_solution(int a[],int k,int n) { 
  /* You can modify from here */
    if(sum_of_arr(a,k+1)==n+1 && combine_ok(a,k)==1){
		return 1;
	}
    else{
        return 0;
    }
  /* You can modify to here */
}

void print_solution(int a[], int n) {
  /* You can modify from here */
	for(int i=0;i<answer_length;i++){
		printf("%s ",answer_string_arr[i]);
	}
	printf("\n");
	for(int i=0;i<answer_length;i++){
		printf("%d ",answer_dap[i]);
	}
  /* you can modify to here */
}

int main()
{
	int a[MAX_LENGTH];
	scanf("%s",str_input);
	scanf("%s",str_goal);
	backtrack(a, 0,5);
	print_solution(a,(int)strlen(str_input) -1);
	return 0;
}

void backtrack(int a[],int k,int n) {
	int c[MAX_CANDIDATES];
	int ncandidates;
	int i;
	if(k==n+1){
        for(int i=1;i<=n;i++)   {
            printf("%d ",a[i]);
        }
        printf("\n");

    }
		// process_solution(a,k);
	else {
		k++;
		construct_candidates(a,k,n,c,&ncandidates);
		for(i=0; i<ncandidates; i++) {
			a[k] = c[i];
			backtrack(a,k,n);
			if(finished)
				return;
		}
	}
}
