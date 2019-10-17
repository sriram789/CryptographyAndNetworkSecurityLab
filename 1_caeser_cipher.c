#include<stdio.h>
#include<string.h>

int main()
{
    char plain_text[100];
    char cipher_text[100];
    int key;
    printf("Enter the plain text:");
    scanf("%s",plain_text);
    printf("Enter the key:");
    scanf("%d",&key);
    printf("ENCRYPTION:::\n");


    for(int i=0;i<strlen(plain_text);i++)
    {
        cipher_text[i] = ( (plain_text[i] - 'A' + key) % 26) + 'A';
    }
    cipher_text[strlen(plain_text)]='\0';
    printf("The cipher text of %s is %s\n",plain_text,cipher_text);



    /*printf("DECRYPTION:::\n");
    for(int i=0;i<strlen(cipher_text);i++)
    {
        plain_text[i] = ( (cipher_text[i] - 'A' - key) + 26)%26 + 'A';
    }
    plain_text[strlen(cipher_text)]='\0';
    printf("The plain text of %s is %s\n",cipher_text,plain_text);*/
    return 0;
}