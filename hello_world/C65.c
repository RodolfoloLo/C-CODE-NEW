/*实验教材P207 程序设计 第（9）题
本关任务：
利用值栈对逆波兰表达式进行求值。逆波兰表达式从键盘输入，其中的运算符仅包含加、减、乘、除4种运算，表达式中的数都是十进制数，用换行符结束输入。
由于逆波兰表达式的长度不限，所以值栈要用后进先出链表实现。/尾插

编程要求
根据题目要求，在右侧编辑器中完成程序设计。

测试说明
平台会对你编写的代码进行测试：

测试输入：
2  1  +  3  *
预期输出：
9
解释:
该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9

测试输入：
4  13  5  /  +
预期输出：
6
解释: 该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6

计算规则：遇到数字就压入栈，遇到运算符就从栈中弹出两个数进行计算，然后把结果压回栈中
*/
//栈！！！他来了
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct stack_node{
    int data;
    struct stack_node *next;
}Stack_node;
Stack_node *top=NULL;//栈顶指针
//压栈
void push(int value){
    Stack_node *new_node=(Stack_node*)malloc(sizeof(Stack_node));
    new_node->data=value;
    new_node->next=top;
    top=new_node;
}
//example:  first time:top->23->NULL(push 23) second time:top->77->23->NULL(push 77)~类似头插法
//出栈
int pop(){
    if(top==NULL){
        return 0;
    }
    Stack_node *temp=top;
    int value=top->data;
    top=top->next;
    free(temp);
    return value;
}
int is_operator(const char *token){
    return strcmp(token,"+")==0||strcmp(token,"-")==0||strcmp(token,"*")==0||strcmp(token,"/")==0;
}
int calculate(int a,int b,char op){
    if(op=='+')return a+b;
    else if(op=='-')return a-b;
    else if(op=='*')return a*b;
    else if(op=='/')return a/b;
    else return 0;
}

int main(){
    char line[1000];
    
    // 读取整行输入
    if(fgets(line, sizeof(line), stdin) != NULL){
        char *token = strtok(line, " \n");  // 按空格和换行符分割
        
        while(token != NULL){
            if(isdigit(token[0])||(token[0]=='-'&&isdigit(token[1]))){
                push(atoi(token));
            }else if(is_operator(token)){
                int b=pop();
                int a=pop();
                int result=calculate(a,b,token[0]);
                push(result);
            }
            token = strtok(NULL, " \n");
        }
    }
    
    printf("%d\n",pop());
    return 0;
}