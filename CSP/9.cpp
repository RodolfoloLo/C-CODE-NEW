//广度优先搜索
//“子节点”点点相连，开枝散叶~同时走多条路
//队列是BFS的核心数据结构
/*&队列
先进先出的特性
~从后面放入新元素，从前面取出旧元素！！！
~先访问的节点先拓展
~保证按照“层次”遍历
~离起点近的节点先被处理
*/
#include<bits/stdc++.h>
using namespace std;
struct elevatorstate{
    int floor;
    int steps;
};
int bfs(int n,int start,int target,vector<int>& buttons){//注意vector传参时的写法
    if(start==target){
        return 0;
    }//特殊情况：开始即结束

    vector<bool> visited(n+1,false);//标记访问过的楼层,这是bfs算法的关键！

    queue<elevatorstate> q;
    q.push({start,0});//初始状态入队，在起始楼层，没按过按钮
    visited[start]=true;

    while(!q.empty()){//一直排查，直到queue为空！
        elevatorstate current=q.front();
        q.pop();
        //“配套操作”
        int currentfloor=current.floor;
        int currentsteps=current.steps;
        int movedistance=buttons[currentfloor];//向上/向下移动楼层

        //尝试两个方向
        int nextfloors[2]={
            currentfloor+movedistance,
            currentfloor-movedistance
        };
        for(int i=0;i<2;i++){
            int nextfloor=nextfloors[i];
            //检查新楼层是否有效
            if(nextfloor>=1&&nextfloor<=n){
                if(nextfloor==target){
                    return (currentsteps+1);
                }
                if(!visited[nextfloor]){
                    visited[nextfloor]=true;
                    q.push({nextfloor,currentsteps+1});
                }
            }
        }
    }
    return -1;
}

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>buttons(n+1);//楼层可以从1楼开始访问
    for(int i=1;i<=n;i++){
        cin>>buttons[i];
    }
    int result=bfs(n,a,b,buttons);
    cout<<result<<endl;
    return 0;
}