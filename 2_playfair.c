#include<stdio.h>
#include<string.h>

char table[5][5];
int main()
{
    char string[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int present[26]={0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char key[100];
    char plain_text[100];
    char cipher_text[100];
    int k,start,val,itr,first_x,first_y,second_x,second_y;
    printf("Enter the key");
    scanf("%s",key);
    printf("Enter the plain text");
    scanf("%s",plain_text);

    for(int i=0;i<strlen(key);i++)
        present[key[i]-'A']=1;

    k=0;
    start=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(k<strlen(key))
                table[i][j]=key[k++];
            else
            {
                for(int x=start;x<26;x++)
                {
                    if(present[x]==0)
                        {
                            table[i][j]=string[x];
                            start=x;
                            present[x]=1;
                            break;
                        }
                }
            }
        }
    }

    for(int i=0;i<5;i++,printf("\n"))
    {
        for(int j=0;j<5;j++)
        {
            printf("%c ",table[i][j]);
        }
    }

    if(strlen(plain_text)%2!=0)
    {
        plain_text[strlen(plain_text)]='Z';
        val=strlen(plain_text)+1;
        plain_text[val]='\0';
    }

    itr=0;
    for(int i=0;i<strlen(plain_text);i=i+2)
    {
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(table[j][k]==plain_text[i])
                {
                    first_x=j;
                    first_y=k;
                }
                if(table[j][k]==plain_text[i+1])
                {
                    second_x=j;
                    second_y=k;
                }
            }
        }

        if(first_x == second_x)
        {
            cipher_text[itr++]=table[first_x][(first_y+1)%5];
            cipher_text[itr++]=table[second_x][(second_y+1)%5];
        }
        else
        {
            if(first_y == second_y)
            {
                cipher_text[itr++]=table[(first_x+1)%5][first_y];
                cipher_text[itr++]=table[(second_x+1)%5][second_y];
            }
            else
            {
                cipher_text[itr++]=table[second_x][first_y];
                cipher_text[itr++]=table[first_x][second_y];
            }
        }
    }
    cipher_text[itr]='\0';
    printf("The cipher text is %s",cipher_text);
    return 0;

}