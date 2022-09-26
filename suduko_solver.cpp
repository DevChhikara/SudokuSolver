#include<iostream>
#include<cmath>

using namespace std;

   bool isSafe(int arr[][9],int i,int j,int no){
        //method for checking row and column 
        for(int k=0;k<9;k++){
            if(arr[k][j]==no||arr[i][k]==no){
                return false;
            }
        }
        //check for subgrid
        int sx=(i/3)*3;
        int sy=(j/3)*3;
        for(int x=sx;x<sx+3;x++){
            for(int y=sy;y<sy+3;y++){
                if(arr[x][y]==no){
                    return false;
                }
            }
        }
        return true;
   }
 
   bool sudokoSolver(int arr[][9],int i,int j,int n)
   {
    //base case 
    if(i==n){
    //print value

    for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<arr[i][j]<<",";
            }
            cout<<endl;
    }

    return true;
    }
    //rec case
    if(j==n){
        return sudokoSolver(arr,i+1,0,n);
    }
    if(arr[i][j]!=0){
        return sudokoSolver(arr,i,j+1,n);
    }
     int no;
    for(int no=1;no<=n;no++){
        if(isSafe(arr,i,j,no)){
        arr[i][j]=no;
        bool solveSubproblem=sudokoSolver(arr,i,j+1,n);
        if(solveSubproblem==true){
            return true;
        }
        }
    }
    //bactrack if result is not possible 
    arr[i][j]=0;
    return false;
   } 


int main(){
    int n=9;
    int arr[][9]=
    {{5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}};

    if(!sudokoSolver(arr,0,0,n)){
      cout<<"cant be solved for given inputs";
    }

   // sudokoSolver(arr,0,0,9);
    return 0;
}