//孩子第一次挑战洛谷绿题！吃奶酪~“旅行商问题”
//dfs+剪枝
//&pair:
//将两个值组合成一个单元，这两个值可以是相同类型或者不同类型，注意是两个！
#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<double,double>>points;
vector<bool>visited;
double ans=1e9;
double distance(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void dfs(double current_x,double current_y,int cnt,double current_distance){
    if(current_distance>=ans){
        return;
    }//这，就是剪枝！
    if(cnt==n){
        ans=min(ans,current_distance);
        return;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            double d=distance(current_x,current_y,points[i].first,points[i].second);
            dfs(points[i].first,points[i].second,cnt+1,current_distance+d);
            visited[i]=false;//无论如何，记住回溯！！！！！
        }
    }
}
int main(){
    cin>>n;
    points.resize(n);
    visited.resize(n,false);//全局变量在这里要重新定义大小！
    for(int i=0;i<n;i++){
        cin>>points[i].first>>points[i].second;
    }
    dfs(0,0,0,0.0);
    cout<<fixed<<setprecision(2)<<ans<<endl;//小数输出格式
    return 0;
}