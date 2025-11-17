/*题目描述
将 1,2,…,9 共 9 个数分成三组，分别组成三个三位数，且使这三个三位数的比例是 A:B:C，试求出所有满足条件的三个三位数，若无解，输出 No!!!。

输入格式
三个数，A,B,C。

输出格式
若干行，每行 3 个数字。按照每行第一个数字升序排列。
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    vector<int>digits={1,2,3,4,5,6,7,8,9};
    bool found=false;
    
    do{
        int num1=digits[0]*100+digits[1]*10+digits[2]*1;
        int num2=digits[3]*100+digits[4]*10+digits[5]*1;
        int num3=digits[6]*100+digits[7]*10+digits[8]*1;
        if(num1*b==num2*a&&num2*c==num3*b){
            cout<<num1<<" "<<num2<<" "<<num3<<endl;
            found=true;
        }
    }while(next_permutation(digits.begin(),digits.end()));//next_permutation函数：按字典序生成序列的下一个排列
    //注意，初始状态必须有序 当没有下一个排列时，返回false，循环结束
    if(!found){
        cout<<"No!!!"<<endl;//&关于endl和\n：endl每次都会刷新缓冲区，较慢需要大量输出时，使用endl可能会导致超时
    }
    return 0;
}
/*关于vector，
其实就是一个动态数组，可以自动扩容
两种初始化的方式，（）和{}，
一些基本操作：
vector<int>vec;
///添加元素
//尾部添加
vec.push_back(1);->{1}
vec.push_back(2);->{1,2}
vec.push_back(3);->{1,2,3}
//指定位置插入
vec.insert(vec.begin()+1,5);->{1,5,2,3}
///删除元素
//尾部删除
vec.pop_back();->{1,5,2}
//指定位置删除
vec.erase(vec.begin()+1);->{1,2}
//清除所有
vec.clear();

///访问元素
vector<int>vec={10,20,30};
//下标访问，不检查边界，速度快
cout<<vec[0];
//赋值
vec[1]=25;
//检查边界，安全
cout<<vec.at(0);->10
/vec.at(5)->std::out_of_range
//首尾
cout<<vec.front();->10
cout<<vec.back();->30

容量相关
vec.size();
vec.empty();/是否为空->false（0）
.resize(5)->{10,25,30,0,0}

//bagin()&end()
“智能指针”
begin()指向第一个元素
end()指向最后一个元素的*下一个位置*
取值需要解引用
example
for(auto it=vec.begin();it!=vec.end();it++){
   cout<*it<<" ";
}/正向遍历
for(auto it=vec.rbegin();it!=vec.rend();it++){
   cout<*it<<endl;
}