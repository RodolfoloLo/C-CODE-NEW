
/*任务描述
实验教材P207 程序设计 第（2）题
本关任务：
用单向链表建立一张班级成绩单，包括每个学生的学号、姓名、英语、高等数学、普通物理、C语言程序设计4门课程的成绩。实现以下功能，并提供菜单选项：
0.退出
1.输入每个学生的各项信息
2.输出每个学生的各项信息
3.修改指定学生的指定数据项的内容：
    1.修改英语成绩
    2.修改高等数学成绩
    3.修改普通物理成绩
    4.修改C语言成绩
4.统计每个学生的平均成绩（保留2位小数）
5.输出各位学生的学号、姓名、4门课程的总成绩和平均成绩

(注意：每项功能可多次选择，例如，先选功能1，输入3个学生，后面又选功能1，输入2个学生，则此时共有5个学生，再选择功能5时，应该输出5个学生的信息。)

相关知识
为了完成本关任务，你需要掌握：1.结构体，2.链表。

编程要求
根据题目要求，在右侧编辑器完成程序设计。

测试说明
平台会对你编写的代码进行测试，输入为功能编号，：

测试输入：
依次输入功能编号1，学生数量n，每个学生的学号、姓名和成绩；功能编号2；功能编号3，指定学生的学号，修改的数据项，数据；功能编号4；功能编号5：
1    （功能编号）
4    （学生人数）
U202012345 Jack 99 100 80 96    （学号 姓名 英语 数学 物理 C语言成绩）
U202054321 Rose 89 94 85 100
U202056789 Tom 12 34 56 78
U202098765 Jerry 98 76 54 32
2    （功能编号）
3    （功能编号）
U202054321 1 66    （将学号为U202054321的同学的英语成绩修改为66）
4    （功能编号）
5    （功能编号）

预期输出：

U202012345 Jack 99 100 80 96
U202054321 Rose 89 94 85 100
U202056789 Tom 12 34 56 78
U202098765 Jerry 98 76 54 32
U202012345 Jack 93.75
U202054321 Rose 86.25
U202056789 Tom 45.00
U202098765 Jerry 65.00
U202012345 Jack 375 93.75
U202054321 Rose 345 86.25
U202056789 Tom 180 45.00
U202098765 Jerry 260 65.00

开始你的任务吧，祝你成功！*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student {
    char ID[23];
    char Name[10];
    int English;
    int Math;
    int Physics;
    int C;
    double average;
    struct student *next;
} Student;

Student *head = NULL;

// 交换两个节点的数据!
void swap_data(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
    // 特别处理next指针，保持链表连接
    Student *temp_next = a->next;
    a->next = b->next;
    b->next = temp_next;
}

// 冒泡排序
void sort_by_average() {
    if (head == NULL || head->next == NULL) return;
    
    int swapped;
    Student *ptr;
    Student *last = NULL;
    
    do {
        swapped = 0;
        ptr = head;
        
        while (ptr->next != last) {
            if (ptr->average > ptr->next->average) {
                swap_data(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
}

// 1. 输入学生信息
void create_list(int n) {
    for (int i = 0; i < n; i++) {
        Student *new_node = (Student*)malloc(sizeof(Student));
        
        scanf("%s %s %d %d %d %d", 
              new_node->ID, new_node->Name,
              &new_node->English, &new_node->Math,
              &new_node->Physics, &new_node->C);
        
        new_node->average = (new_node->English + new_node->Math + 
                           new_node->Physics + new_node->C) / 4.0;
        new_node->next = NULL;
        
        // 头插法
        new_node->next = head;
        head = new_node;
    }
}

// 2. 输出学生信息
void print_students() {
    sort_by_average();
    Student *p = head;
    while (p != NULL) {
        printf("%s %s %d %d %d %d\n", 
               p->ID, p->Name, p->English, p->Math, p->Physics, p->C);
        p = p->next;
    }
}

// 3. 修改成绩
void modify_score() {
    char id[23];
    int subject, score;
    scanf("%s %d %d", id, &subject, &score);
    
    Student *p = head;
    while (p != NULL) {
        if (strcmp(p->ID, id) == 0) {
            switch(subject) {
                case 1: p->English = score; break;
                case 2: p->Math = score; break;
                case 3: p->Physics = score; break;
                case 4: p->C = score; break;
            }
            p->average = (p->English + p->Math + p->Physics + p->C) / 4.0;
            break;
        }
        p = p->next;
    }
}

// 4. 输出平均分
void print_average() {
    sort_by_average();
    Student *p = head;
    while (p != NULL) {
        printf("%s %s %.2f\n", p->ID, p->Name, p->average);
        p = p->next;
    }
}

// 5. 输出总分和平均分
void print_total_avg() {
    sort_by_average();
    Student *p = head;
    while (p != NULL) {
        int total = p->English + p->Math + p->Physics + p->C;
        printf("%s %s %d %.2f\n", p->ID, p->Name, total, p->average);
        p = p->next;
    }
}

int main() {
    int choice;
    
    while (1) {
        scanf("%d", &choice);
        if (choice == 0) break;
        
        switch(choice) {
            case 1: {
                int n;
                scanf("%d", &n);
                create_list(n);
                break;
            }
            case 2:
                print_students();
                break;
            case 3:
                modify_score();
                break;
            case 4:
                print_average();
                break;
            case 5:
                print_total_avg();
                break;
        }
    }
    
    // 释放内存
    Student *p = head;
    while (p != NULL) {
        Student *temp = p;
        p = p->next;
        free(temp);
    }
    
    return 0;
}
/*任务描述
实验教材P207 程序设计 第（3）题
本关任务：
对程序设计的第二题增加按照平均成绩进行升序排序的函数，写出用交换结点数据域的方法升序排序的函数，排序可用选择法或冒泡法。菜单选项：

0退出
1输入每个学生的各项信息
2输出每个学生的各项信息，结果按平均成绩升序排序
3修改指定学生的指定数据项的内容：
修改英语成绩
修改高等数学成绩
修改普通物理成绩
修改C语言成绩
4统计每个学生的平均成绩，结果按平均成绩升序排序（保留2位小数）
5输出各位学生的学号、姓名、4门课程的总成绩和平均成绩，结果平均成绩升序排序
相关知识
为了完成本关任务，你需要掌握：1.排序，2.链表。

编程要求
根据题目要求，在右侧编辑器完成程序设计。

测试说明
测试输入：
依次输入功能编号1，学生数量n，每个学生的学号、姓名和成绩；功能编号2；功能编号3，指定学生的学号，修改的数据项，数据；功能编号4；功能编号5：
1    （功能编号）
4    （学生人数）
U202012345 Jack 99 100 80 96    （学号 姓名 英语 数学 物理 C语言成绩）
U202054321 Rose 89 94 85 100
U202056789 Tom 12 34 56 78
U202098765 Jerry 98 76 54 32
2    （功能编号）
3    （功能编号）
U202054321 1 66    （将学号为U202054321的同学的英语成绩修改为66）
4    （功能编号）
5    （功能编号）

预期输出：

U202012345 Jack 99 100 80 96
U202054321 Rose 89 94 85 100
U202098765 Jerry 98 76 54 32
U202056789 Tom 12 34 56 78
U202012345 Jack 93.75
U202054321 Rose 86.25
U202098765 Jerry 65.00
U202056789 Tom 45.00
U202012345 Jack 375 93.75
U202054321 Rose 345 86.25
U202098765 Jerry 260 65.00
U202056789 Tom 180 45.00

开始你的任务吧，祝你成功！*/