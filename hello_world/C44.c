#include<stdio.h>
#include<string.h>
typedef struct{
    char name[77];
    int score;
}student;//注意typedef的使用
student students[100];
int count=0;
void input_students(){
    scanf("%d",&count);
    for(int i=0;i<count;i++){
        scanf("%s %d",students[i].name,&students[i].score);
    }
}
void sort_students(){//掌握好冒泡排序！！！
    for(int i=0;i<count-1;i++){
        for(int j=0;j<count-i-1;j++){
            if(students[j].score<students[j+1].score){
                student temp=students[j];
                students[j]=students[j+1];
                students[j+1]=temp;
            }
            if(students[j].score==students[j+1].score){
                if(strcmp(students[j].name,students[j+1].name)>0){
                    student temp=students[j];
                students[j]=students[j+1];
                students[j+1]=temp;
                }
            }
        }
    }
}
void output_students(){
    for(int i=0;i<count;i++){
        printf("%s %d\n",students[i].name,students[i].score);
    }
}
void find_students(int target_score){
    int left=0;
    int right=count-1;
    int flag=0;
    int target_index=-1;//小技巧
    sort_students();
    while(left<=right){
        int mid=left+(right-left)/2;
        if(students[mid].score==target_score){
            flag=1;
            target_index=mid;
            break;
        }else if(students[mid].score<target_score){
            left=mid+1;
        }else if(students[mid].score>target_score){
            right=mid-1;
        }
    }
    if(!flag){
        printf("not found");
    }
    int true_target_index=target_index;
    while(true_target_index>0&&students[true_target_index-1].score==target_score){
        true_target_index--;
    }
    while(students[true_target_index].score==target_score){
        printf("%s %d\n",students[true_target_index].name,students[true_target_index].score);
        true_target_index++;
    }
}
int main(){
    char choice;
    int target_score;
    while(1){
        scanf(" %c",&choice);//注意空格，跳过空白字符
        switch(choice){
            case '0':
                return 0;
            case '1':
                input_students();
                break;
            case '2':
                sort_students();
                break;
            case '3':
                output_students();
                break;
            case '4':
                scanf("%d",&target_score);
                find_students(target_score);
                break;
        }
    }
    return 0;
}