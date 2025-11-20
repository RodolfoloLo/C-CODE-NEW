#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>rand;//不要初始化大小，动态数组这时派上用场！
    for(int i=0;i<n;i++){
        int num; cin>>num; rand.push_back(num);
    }
    sort(rand.begin(),rand.end());
    auto last=unique(rand.begin(),rand.end());
    rand.erase(last,rand.end());
    /*
    对于一个有序的数组，我们可以使用 unique 函数对它去重。
    unique 函数的调用方式为 unique(begin_place,end_place)，
    如果数组里有 k 个不同的值，那么调用后数组的前 k 个位置将会是这些不同的值有序排列，
    重复的值会被移动到数组后面。
    现在有个问题：我们怎么知道 k 是多少呢？不用担心，unique 函数是有返回值的！它的返回值是指向这 k 个数的下一个位置的指针，
    所以用这个指针减去 begin_place 得出来的数字就是 k 了。*/
    cout<<rand.size()<<endl;
    for(int num:rand){
        cout<<num<<" ";//学会这样更加便利的for循环！！！
    }
    cout<<endl;
    //再用set解决一遍
    set<int>s;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        s.insert(num);//set自动去重和排序
    }
    cout<<s.size()<<endl;
    for(auto it=s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}