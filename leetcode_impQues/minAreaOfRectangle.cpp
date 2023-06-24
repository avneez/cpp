#include<bits/stdc++.h>
using namespace std;

    int minAreaRect(vector<vector<int>>& points) {
    //for every x -> a set of y coords (y1,y2...yn) or keep a record of all points(x,y)
    //unordered_map<int,set<int>> mp;

        set<pair<int,int>> mp;
        for(auto p:points){
            mp.insert({p[0],p[1]});
        }

// diagonal method- checking two points of a diagonal to find next two points since it's a rectangle
        int area=INT_MAX;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                // if(i!=j){
                    if(points[i][0]!=points[j][0] && points[i][1]!=points[j][1]){
                        pair<int,int> op1={points[i][0],points[j][1]}; //x of d2
                        pair<int,int> op2={points[j][0],points[i][1]}; //y of d2

                        if(mp.count(op1) && mp.count(op2)){
                            int l=abs(points[i][0]-points[j][0]),w=abs(points[i][1]-points[j][1]);
                            area=min(area,l*w);
                        }
                    }
                // }
            }
        }
        return area==INT_MAX ? 0 : area;
    }

int main(){
    vector<vector<int>> points = {{1,1},{1,3},{3,1},{3,3},{2,2}}; //op-2  //{{1,1},{1,3},{3,1},{3,3},{4,1},{4,3}}; //op-4
    int ans = minAreaRect(points);
    return ans;
}
