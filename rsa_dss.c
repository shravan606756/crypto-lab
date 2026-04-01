#include<stdio.h>
#include<string.h>

int gcd(int a , int b)
{
    while(b)
    {
        int t = b;
        b = a%b;
        a=t;
    }
    return a;
}

int modInverse(int e,  int phi)
{
    for(int i = 0 ; i<phi ; i++)
    {
        if((e*i)==1)
        {
            return i;
        }
    }
    return -1;
}

int powerMod(int base , int exp , int mod)
{
    int r=1;
    base = base%mod;

    while(exp>0)
    {
        if(exp%2==1)
        {
            r = (r*base)%mod;
        }
        exp=exp/2;
        base = (base*base)%mod;
    }
    return r;
}

int h(int m)
{
    return m%100;
}

int main()
{
    int p,q;
    printf("Enter the value of p and q : ");
    scanf("%d%d",&p,&q);

    int n = p*q;
    int phi = (p-1)*(q-1);

    int e;
    printf("\nEnter the value of e : ");
    scanf("%d",&e);

    while(gcd(e,phi)!=1)
    {
        printf("\nInvalid input of e");
        printf("\nEnter the value of e : ");
        scanf("%d",&e);
    }

    int d = modInverse(e,phi);

    int m;
    printf("\nEnter the message : ");
    scanf("%d",&m);

    int hash = h(m);
    int sign = powerMod(hash , d , n);
    int verify = powerMod(sign , e , n);

    printf("\nHash: %d",hash);
    printf("\nSignature: %d",sign);
    printf("\nVerification: %d",verify);
}
