#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
        return a>b;
    }
    
int main(){
//&string
    //基操
    string s="hello.cpp!";
    cout<<s.length()<<endl;
    cout<<s.size()<<endl;

    cout<<s[0]<<endl;
    cout<<s[s.length()-1]<<endl;

    string emptystr="";
    cout<<s.empty()<<endl;//false:0
    cout<<emptystr.empty()<<endl;//true:1
    
    string s0="victory";
    cout<<s0<<endl;
    string s1=s0;
    cout<<s1<<endl;
    string s2(5,'A');
    cout<<s2<<endl;
    string s3=s1+" "+s2;
    cout<<s3<<endl;
    cout<<s0[0]<<s0.at(0)<<endl;

    string s4="I'll master programming!";//查找元素
    size_t pos1=s4.find("master");
    if(pos1!=string::npos){
        cout<<pos1<<endl;
    }
    size_t pos2=s4.find("programming",4);
    if(pos2!=string::npos){
        cout<<pos2<<endl;
    }
    size_t pos3=s4.find_first_of("aeiou");
    size_t pos4=s4.find_last_of("aeiou");
    cout<<pos3<<pos4<<endl;
    string sub1=s4.substr(5);
    string sub2=s4.substr(0,4);
    cout<<sub1<<endl<<sub2<<endl;

    string s5="user@example.com";//切割字符串
    size_t pos=s5.find("@");
    string username=s5.substr(0,pos);
    string domain=s5.substr(pos+1);
    cout<<username<<endl;
    cout<<domain<<endl;

    string s6="hello";//修改操作
    s6.insert(5,"c++");
    cout<<s6<<endl;
    s6.erase(5,6);
    cout<<s6<<endl;
    s6.replace(0,5,"Hi");
    cout<<s6<<endl;

    string s7="programming";
    sort(s7.begin(),s7.end());//排序
    cout<<s7<<endl;
    reverse(s7.begin(),s7.end());//反转
    cout<<s7<<endl;


//&vector
    vector<int>vec1={1,3,5,7,9,2,4,6,8,10};
    //默认升序排序
    sort(vec1.begin(),vec1.end());
    for(auto it=vec1.begin();it!=vec1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    vector<int>vec2={1,3,5,7,9,2,4,6,8,10};
    //降序排序
    sort(vec2.begin(),vec2.end(),greater<int>());
    for(auto it=vec2.begin();it!=vec2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    vector<int>vec3={1,3,5,7,9,2,4,6,8,10};
    //使用lambda表达式
    sort(vec3.begin(),vec3.end(),[](int a,int b){
        return a>b;
    });
    for(auto it=vec3.begin();it!=vec3.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    vector<int>vec4={1,3,5,7,9,2,4,6,8,10};
    //自定义比较函数
    sort(vec4.begin(),vec4.end(),cmp);
    for(auto it=vec4.begin();it!=vec4.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    vector<int>vec5={1,2,3,4,5,6,7,8,9,10};
    //寻找第一个不小于目标值的值
    auto it1=lower_bound(vec5.begin(),vec5.end(),5);
    if(it1!=vec5.end()){
        int index=it1-vec5.begin();
        int value=*it1;
        cout<<index<<value<<endl;
    }
    vector<int>vec6={1,2,3,4,5,6,7,8,9,10};
    //寻找第一个大于目标值的值
    auto it2=upper_bound(vec6.begin(),vec6.end(),5);
    cout<<*it2<<endl;

    vector<int>vec7={1,2,3,4,5,6,7,8,9,10};
    //二分查找
    bool found=binary_search(vec7.begin(),vec7.end(),5);
    cout<<found<<endl; 


    return 0;
}