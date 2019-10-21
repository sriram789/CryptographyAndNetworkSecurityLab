#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<openssl/des.h>

char *Encrypt(char * key,char * msg,int size){
	static char * res;
	int n=0;
	DES_cblock key2;
	DES_key_schedule schedule;

	res =(char *) malloc(size);

	memcpy(key2,key,8);
	DES_set_odd_parity(&key2);
	DES_set_key_checked(&key2,&schedule);

	DES_cfb64_encrypt((unsigned char *)msg,(unsigned char*)res,size,&schedule,&key,&n,DES_ENCRYPT);
	return (res);
}

char *Decrypt(char * key,char * msg,int size){
	static char * res;
	int n=0;
	DES_cblock key2;
	DES_key_schedule schedule;

	res =(char *) malloc(size);

	memcpy(key2,key,8);
	DES_set_odd_parity(&key2);
	DES_set_key_checked(&key2,&schedule);

	DES_cfb64_encrypt((unsigned char *)msg,(unsigned char*)res,size,&schedule,&key,&n,DES_DECRYPT);
	return (res);
}

int main()
{
	char key[]="SRIRAM";
	char plain_text[]="HIHELLOGUYS";
	char * encrypted=malloc(sizeof(plain_text));
	char * decrypted=malloc(sizeof(plain_text));

	printf("%X",Encrypt(key,plain_text,sizeof(plain_text)));
	printf("%s",Decrypt(key,Encrypt(key,plain_text,sizeof(plain_text)),sizeof(plain_text)));
	return 0;
}	
