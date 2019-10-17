#include<stdio.h>
#include<string.h>

char value_table[10][100];
//ONLY ENCRYPTION
int main()
{
    char plain_text[100];
    char cipher_text[100];
    int depth;
    int i,j,count,flag,k;




    printf("Enter the plain text:");
    scanf("%s",plain_text);
    printf("Enter the depth:");
    scanf("%d",&depth);



//ASSIGNING CIPHER TEXT
    i=0;
    j=0;
    k=0;
    count=0;
    flag=0;
    while(1)
    { 
        
        value_table[i][j]=plain_text[k++];
        printf("value table of %d %d is %c\n", i, j, value_table[i][j]);
        count++;
        if(i == 0)
        {
            flag=0;
        }
        if(i == depth -1)
        {
            flag=1;
        
        }
        if(flag==0)
        {
            i=i+1;
            j=j+1;
        }
        if(flag==1)
        {
            i=i-1;
            j=j+1;
        }
        if(count==strlen(plain_text))
        {
            break;
        }
    }


//PRINTING CIPHER TEXT
    k=0;
    for(int i=0;i<depth;i++,printf("\n"))
    {
        for(int j=0;j<100;j++)
        {
             if(value_table[i][j]<='z' && value_table[i][j]>='a')
             {
                cipher_text[k++]=value_table[i][j];
             }
        }
    }
     cipher_text[k]='\0';

     printf("The cipher text of %s is %s\n",plain_text,cipher_text);
    return 0;
}