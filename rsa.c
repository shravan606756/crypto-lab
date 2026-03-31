#include<stdio.h>
#include<string.h>

int gcd(int a ,int b)
{
    while(b)
    {
        int t = b;
        b = a%b;
        a=t;
    }
    return a;    
}

int modInverse(int e , int phi)
{
    for(int d = 1 ; d<phi ; d++)
    {
        if((e*d)%phi==1)
        {
            return d;
        }
    }

    return -1;
}

int powerMod(int base , int exp , int mod)
{
    int res= 1; 
    base = base%mod;
    while(exp>0)
    {
        if(exp%2==1)
        {
            res = (res*base) % mod;
        }
        exp = exp/2;
        base = (base * base) %mod;
    }
    return res;
}

int main()
{
    int p , q ;

    printf("Enter the value of p and q : ");
    scanf("%d%d",&p,&q);

    int n = p*q;
    int phi = (p-1)*(q-1);

    int e;
    printf("\nEnter the value of e : ");
    scanf("%d",&e);

    while(gcd(e , phi)!=1)
    {
        printf("\nInvalid input of e");
        printf("\nEnter the value of e : ");
        scanf("%d",&e);
    }

    int d = modInverse(e , phi);
    
    int m;
    printf("\nEnter the message : ");
    scanf("%d",&m);

    int c = powerMod(m , e , n);
    int plain = powerMod(c , d , n);

    printf("\nEncrypted message : %d",c);
    printf("\nDecrypted message : %d",plain);

    return 0;
}
