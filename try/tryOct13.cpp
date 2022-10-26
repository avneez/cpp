#include<bits/stdc++.h>
using namespace std;

//     bool isVowel(char c) {
//         return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
//     }

//     int countVowelSubstrings(string s) {
//         int result = 0, N = s.size();
//         for (int i = 0; i < N; ++i) {
//                 if(isVowel(s[i]) && isVowel(s[i+1]) && isVowel(s[i+2])){
//                             result++;
//                 }
//         }
//         return result;
//     }

// int main(){
//     string s;
//     cin>>s;
//     cout<<countVowelSubstrings(s);
// return 0;
// }

int main(){
int N=3, M=3;
int A[N][M] = {{10,20,30},
               {40,50,60},
               {70,80,90}};
int i=0;
int j=0;
        for(;j<M;j++){
            int ans=0;
            int x=j;
            i=0;
            while(x>=0 && x<M && i>=0 && i<N){
                ans+=A[i][x];
                i++;
                x--;
            }
            cout<<ans<<endl;
        }
        i=1;
        j=M-1;
        for(;i<N;i++){
            int x=i;
            int ans=0;
            j=M-1;
            while(j>=0 &&j<M && x>=0 && x<N){
                ans+=A[x][j];
                x++;
                j--;
            }
            cout<<ans<<endl;
        }
    return 0;
}