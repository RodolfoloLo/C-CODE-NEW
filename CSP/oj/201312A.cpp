 #include<iostream>
 #include<unordered_map>
 #include<vector>
 int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    unordered_map<int,int> count;
    int maxcount=0;
    int result=arr[0];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        countarr[i]++;
        if(count[arr[i]]>maxcount){
            maxcount=count[arr[i]];
            result=arr[i];
        }
    }
    cout<<result<<endl;
    return 0;
 }