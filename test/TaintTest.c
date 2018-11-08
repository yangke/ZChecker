#include <stdio.h>
#include <stdlib.h>
void HelpMassage()  
{  
    FILE *fp;  
    int size = 0;  
    char *ar ;  
  
    //二进制方式打开文件  
    fp = fopen("lining.txt","rb");  
    if(NULL == fp)  
    {  
        printf("Error:Open input.c file fail!\n");  
        return;  
    }  
  
    //求得文件的大小  
    fseek(fp, 0, SEEK_END);  
    size = ftell(fp);  
    rewind(fp);  
  
    //申请一块能装下整个文件的空间  
    ar = (char*)malloc(sizeof(char)*size);  
  
    //读文件  
    fread(ar,1,size,fp);//每次读一个，共读size次  
  
    printf("%s",ar);
    printf(ar,"%");
    fclose(fp);  
    free(ar);  
  
    printf("按任意键继续");  
    getchar();  
    getchar();  
}  
int main2()
{
	HelpMassage();
        return 0;	
}
