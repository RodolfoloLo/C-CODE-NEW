//上一个dfs有三个测试点TLE了，这一次用状态压缩DP（状压dp）
/*
&关于状压dp
状压dp=状态压缩+动态规划
就是用一个二进制数来表示一个状态，用位运算来进行状态转移
example：
有五个任务，每个任务可以做或不做
传统表示方法：bool task【5】；
状态压缩表示法：int state=0；
state=21；
10101：表示做任务0,2,4（注意从右往左数！！！！！）
*/
#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<double,double>>points;
double dp[1<<15][15];//dp【mask】【last】mask表示已经吃掉的奶酪集合，dp【mask】【i】表示的是在状态mask下，最后吃的是地i块奶酪的最短距离
//最终答案既是mask全为1的状态中的最小值
double distance(double x1,double x2,double y1,double y2){
    return (sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}
int main(){
    cin>>n;
    points.resize(n);
    for(int i=0;i<n;i++){
        cin>>points[i].first>>points[i].second;
    }
    //初始化dp为无穷大
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            dp[mask][i]=1e18;
        }
    }
    //初始化：从起点到每个点的距离
    for(int i=0;i<n;i++){
        dp[1<<i][i]=distance(0,points[i].first,0,points[i].second);
    }
    for(int mask=1;mask<(1<<n);mask++){
        for(int last=0;last<n;last++){
            if(((mask>>last)&1)==0){
                continue;
            }//last不在mask中
            if(dp[mask][last]>1e18){
                continue;
            }
            //尝试下一个未访问的点
            for(int next=0;next<n;next++){
                if(((mask>>next)&1)==1){
                    continue;
                }//已访问
                int new_mask=mask|(1<<next);
                double new_distance=dp[mask][last]+distance(points[last].first,points[next].first,points[last].second,points[next].second);
                if(new_distance<dp[new_mask][next]){
                    dp[new_mask][next]=new_distance;
                }
            }
        }
    }
    double answer=1e18;
    int full_mask=(1<<n)-1;
    for(int i=0;i<n;i++){
        answer=min(answer,dp[full_mask][i]);
    }
    cout<<fixed<<setprecision(2)<<answer<<endl;
    return 0;
}