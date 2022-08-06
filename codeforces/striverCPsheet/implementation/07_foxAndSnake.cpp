#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> arr(n, vector<char>(m));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2==0){
                arr[i][j] = '#';   //putting # in every even ith row
            }

            else if(i%4==1){       //when i%4 == 1 we are in that row where # will be placed at last i.e. at m-1
                if(j==(m-1)){
                   arr[i][j] = '#';
                }
                else{
                    arr[i][j] = '.';
                }
            }

            else if(i%4==3){     ////when i%4 == 3 we are in that row where # will be placed at front i.e. at 0
                if(j==0){
                   arr[i][j] = '#';
                }
                else{
                    arr[i][j] = '.';
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }

return 0;
}
