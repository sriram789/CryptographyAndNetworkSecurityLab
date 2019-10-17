#include<stdio.h>
#include<math.h>
#include<string.h>

int gcd(int a,int b)
{
    int min=(a<b)?a:b;
    while(1)
    {
        if(a%min==0 && b%min==0)
        {
            return min;
        }
        min--;
    }
    return 1;
}
int main()
{
    int p,q,n,phi,e,d,M,C;
    printf("Enter the p and q value\n");
    scanf("%d %d",&p,&q);

    n=p*q;
    phi=(p-1)*(q-1);
    e=2;
    while(1)
    {
        if(gcd(e,phi)==1)
            break;
        else
            e++;
    }
    
    // for(int i=1;i<=10;i++)
    // {
    //     int x= 1+ i*phi;
    //     if(x%e ==1){
    //         d= (int)x/e;
    //         break;
    //     }
    // }

    d = (int)(1 + (2*phi))/e; 

    printf("e=%d   d=%d\n",e,d);

    printf("Enter the message");
    scanf("%d",&M);
    C = (int)pow(M,e) % n;
    printf("%d is the encrypted msg of %d",C,(int)pow(C,d)%n);
    return 0;
}