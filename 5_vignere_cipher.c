#include<stdio.h>
#include<string.h>
char encryption_table[26][26];
int main()
{
    char plain_text[100];
    char cipher_text[100];
    char key[100];
    printf("Enter the plain text:");
    scanf("%s",plain_text);
    printf("Enter the key text:");
    scanf("%s",key);

    //CREATING ENCRYPTION TABLE
    for(int i=0;i<=25;i++,printf("\n"))
    {
        for(int j=0;j<=25;j++)
        {
            encryption_table[i][j]= ((i+j)%26)+'A';
        }
    }


    //ENCRYPTION
    printf("ENCRYPTION:::\n");
    for(int i=0;i<strlen(plain_text);i++)
    {
        cipher_text[i]=encryption_table[plain_text[i]-'A'][key[i]-'A'];
    }
    cipher_text[strlen(plain_text)]='\0';



    printf("The cipher text of %s is %s\n",plain_text,cipher_text);
return 0;
}