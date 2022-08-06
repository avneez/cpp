// #include<bits/stdc++.h>
// using namespace std;

// struct TIME
// {
//   int hours;
//   int minutes;
// };

// void computeTimeDifference(struct TIME t1, struct TIME t2, struct TIME *diff){

//     if(t2.minutes > t1.minutes)
//     {
//         --t1.hours;
//         t1.minutes += 60;
//     }
//     diff->minutes = t1.minutes-t2.minutes;
//     diff->hours = t1.hours-t2.hours;
// }


// int main(){
//     int t; cin>>t;
//     while(t--){
//         struct TIME t1, t2, diff;
//         vector<pair<int,int>> ans;
//         // int n,h,m, hi,mi;
//         int n;
//         cin>> n >> t1.hours >> t1.minutes;
//         vector<pair<int,int>> v;
//         while(n--){
//             cin>>t2.hours>>t2.minutes;
//             v.push_back({t2.hours,t2.minutes});
//         }
//         for(int i=0; i<v.size();i++){
//             computeTimeDifference(t1,t2, &diff);
//             if(diff.hours==0 and diff.minutes==0){
//                 cout<<0<<" "<<0;
//                 return 0;
//             }
//             pair<int,int> mini= {INT_MAX,INT_MAX};
//             pair<int,int> curr={diff.hours,diff.minutes};
//             // min(curr,mini);
//             // if(curr<mini){
//             //     mini = curr;
//             //     ans.push_back(mini);
//             // }
//             // else v.pop_back();
//             ans.push_back(curr);
//         }
//         sort(ans.begin(),ans.end());
//         cout<<ans[0].first<<" "<<ans[0].second;
//         cout<<endl;
//     }

// return 0;
// }

#include<bits/stdc++.h>
using namespace std;

pair<int,int> diff(pair<int,int> t1, pair<int,int> t2)
{
    int hourDiff = t2.first / 100 - t1.first / 100 - 1;

    int minDiff = t2.second % 100 + (60 - t1.second % 100);

    if (minDiff >= 60) {
        hourDiff++;
        minDiff = minDiff - 60;
    }

    pair<int,int> res = {hourDiff,minDiff};
    return res;
}

int main(){
    int t; cin>>t;
    while(t--){
        vector<pair<int,int>> ans;
        int n,h,m, hi,mi;
        cin>> n >> h >> m;
        pair<int,int> t1={h,m};
        pair<int,int> t2;
        vector<pair<int,int>> v;
        while(n--){
            cin>>hi>>mi;
            pair<int,int> t2={hi,mi};
            v.push_back(t2);
        }
        for(int i=0; i<v.size();i++){
            pair<int,int> temp=diff(t1,t2);
            if(temp.first==0 and temp.second==0){
                cout<<0<<" "<<0;
                return 0;
            }
            // pair<int,int> mini= {INT_MAX,INT_MAX};

            // min(curr,mini);
            // if(curr<mini){
            //     mini = curr;
            //     ans.push_back(mini);
            // }
            // else v.pop_back();
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        cout<<ans[0].first<<" "<<ans[0].second;
        cout<<endl;
    }
return 0;
}