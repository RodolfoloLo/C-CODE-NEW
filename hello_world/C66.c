/*任务描述
本关任务：修改2.(1)的程序，在显示文本的过程中对每一行加一个行号，同时，设计一个显示控制参数/p，
使得每显示5行（一屏）就暂停，当用户按下任何一个键，例如"q"就继续显示下一屏。

编程要求
根据提示，在右侧编辑器修改代码。

测试说明
平台会对你编写的代码进行测试：

测试输入：
cat test1.txt /p      （控制台命令）
q                     （运行时输入）
预期输出：
1 1234567
2 abcdefg
3 !@#$%^&
4 1234567
5 abcdefg
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	FILE * fp;
    //检查命令行参数个数
	if(argc!=3){
		printf("Arguments error!\n");
		exit(-1);
	}
    //检查文件是否正常打开
	if((fp=fopen(argv[1],"r"))==NULL){      /* fp指向filename */
		printf("Can't open %s file!\n", argv[1]);
		exit(-1);
	}
    char line[256];
    int line_number=1;
    int line_count=0;
    if(strcmp(argv[2],"/p")==0){
        while(fgets(line,sizeof(line),fp)!=NULL){//这里是NULL!!!
            //fgets函数就是用来给你一行一行读取文件的！
            printf("%d:%s",line_number,line);
            line_number++;
            line_count++;
            if(line_count==5){
                line_count=0;
                char input[10];
                fgets(input,sizeof(input),stdin);
            }
        }
    }
	fclose(fp);                        /* 关闭filename */ 
	return 0;
}
