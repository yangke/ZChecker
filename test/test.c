#include<stdio.h>
void writeCharToLog(char * Data)
{
    FILE *F=fopen("mylog.txt","w");
    if(F!=NULL)
    {
       if (!Data)
          return;
       fputc(*Data,F);
       fclose(F);
    }
    fclose(F);
    return;
}
int main()
{
    writeCharToLog("whoami"); 
    return 0;
}
