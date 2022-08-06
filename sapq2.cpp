#include<bits/stdc++.h>
using namespace std;

int Prod(vector<int>& order, int dis){
    int answer=0;
    for(int i=0; i<order.size(); i++){
        if(dis%order[i]==0 and order[i]>0){
            answer++;
        }
    }
    return answer;
}

int main(){
    int os;
    cin>>os;

    vector<int> order;
    for(int i=0; i<os; i++){
        int temp;
        cin>>temp;
        order.push_back(temp);
    }

    int dis;
    cin>>dis;

    int result=Prod(order,dis);
    cout<<result;
return 0;
}