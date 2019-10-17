#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int q,alpha,Xa,Xb,Ya,Yb,Ka,Kb;
    printf("Enter the q value");
    scanf("%d",&q);
    printf("Enter the alpha  value");
    scanf("%d",&alpha);
    printf("Enter the  Xa value");
    scanf("%d",&Xa);
    printf("Enter the  Xb value");
    scanf("%d",&Xb);
//CALCULATING PUBLIC KEY
    Ya=(int)pow(alpha,Xa)%q;
    Yb=(int)pow(alpha,Xb)%q;
//CALCULATING SHARED KEY
    Ka=(int)pow(Yb,Xa)%q;
    Kb=(int)pow(Ya,Xb)%q;

    if(Ka==Kb)
        printf("The key exchanged are same ka,kb = %d",Ka);
    else
        printf("The key are not same ka=%d kb=%d",Ka,Kb);
    
    return 0;
}