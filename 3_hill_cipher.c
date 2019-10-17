#include<stdio.h>
#include<string.h>
//ONLY ENCRYPTION
int main()
{
    char plain_text[100];
    int cipher_text[100];
    char key[100][100];
    int size;
    printf("Enter the plain text(n):");
    scanf("%s",plain_text);

    size= strlen(plain_text);

    printf("Enter the key(n*n):\n");
    for(int i=0;i<size;i++)
        scanf("%s",key[i]);
    


//ENCRYPTION code
    for(int j=0;j<size;j++)
    {cipher_text[j]=0;
        for(int k=0;k<size;k++)
        {
            cipher_text[j]=cipher_text[j]+(key[j][k]-'A')*(plain_text[k]-'A');
        }
    }




    printf("Encryption:::cipher text =");
    for(int i=0;i<size;i++)
        printf("%c",(cipher_text[i]%26)+'A');

    return 0;
}