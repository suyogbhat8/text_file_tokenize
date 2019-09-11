#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define max 500
int main()
{
    FILE * f;
    FILE * fout;
    FILE * fc;
    char * p;
    int local=0;
    char c;
    int count=0x1000;
    char str[max],str1[500]="";
    const char delim[]=" \n\r";
    f=fopen("SIC_in.txt","r");
    fout=fopen("SIC_out.txt","w+");
    fc=fopen("SIC_col.txt","a");
    printf("*file input*\n");
    while(fgets(str,max,f))
        {
            fprintf(fc,"%x ",count);
        fputs(str,fc);
        strcat(str1,str);
        count+=3;
        }
        printf("%s",str1);
     fclose(fc);
     fc=fopen("SIC_col.txt","r");
    while ((c = fgetc(fc))!= EOF)
    {
        fputc(c, fout);
    }
    rewind(fc);
    while(fgets(str,max,fc))
    {
        p=strtok(str," ");
        while(p!=NULL)
    {
        local++;
        p=strtok(NULL," ");
    }
    }
    p=strtok(str1,delim);
    printf("\n\n*After tokenizing*\n");
    while(p!=NULL)
    {
        printf("%s\n",p);
        p=strtok(NULL,delim);
    }
    rewind(fout);
    printf("\n*After adding a column in file*\n");
    while(fgets(str,max,fout))
         printf("%s",str);

      fclose(f);
      fclose(fc);
      fc=fopen("SIC_col.txt","w");
      fclose(fc);
      fclose(fout);
    return 0;
}
