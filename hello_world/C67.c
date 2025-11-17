#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
//玩转字符串！！！！！！
void replace_string_in_file(const char *filename, const char *old_str, const char *new_str) {
    FILE *input_file = fopen(filename, "r");
    FILE *output_file = fopen("out.txt", "w");
    
    /*if (input_file == NULL || output_file == NULL) {
        printf("Error opening files!\n");
        if (input_file) fclose(input_file);
        if (output_file) fclose(output_file);
        return;
    }*/
    
    char line[MAX_LINE_LENGTH];
    
    while (fgets(line, sizeof(line), input_file) != NULL) {
        char *pos = line;
        char *found;
        char temp[MAX_LINE_LENGTH];
        char result[MAX_LINE_LENGTH] = "";
        
        // 在每一行中查找并替换目标字符串
        while ((found = strstr(pos, old_str)) != NULL) {
            // 复制找到位置之前的部分
            strncpy(temp, pos, found - pos);
            temp[found - pos] = '\0';
            
            // 添加到结果中
            strcat(result, temp);
            strcat(result, new_str);
            
            // 移动到下一个搜索位置
            pos = found + strlen(old_str);
        }
        
        // 添加剩余部分
        strcat(result, pos);
        
        // 写入输出文件
        fputs(result, output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    // 检查命令行参数
    /*if (argc != 4) {
        printf("Usage: %s <filename> <old_string> <new_string>\n", argv[0]);
        return 1;
    }
    */
    
    char *filename = argv[1];
    char *old_str = argv[2];
    char *new_str = argv[3];
    
    replace_string_in_file(filename, old_str, new_str);
    
    return 0;
}