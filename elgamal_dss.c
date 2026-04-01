#include<stdio.h>

int powerMod(int base,int exp,int mod)
{
    int res=1;
    base%=mod;

    while(exp>0)
    {
        if(exp%2) res=(res*base)%mod;
        exp/=2;
        base=(base*base)%mod;
    }
    return res;
}

int gcd(int a,int b)
{
    while(b)
    {
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int modInverse(int a,int m)
{
    for(int i=1;i<m;i++)
        if((a*i)%m==1) return i;
    return -1;
}

int main()
{
    int p,g;

    printf("Enter p and g: ");
    scanf("%d%d",&p,&g);

    int x;
    printf("Enter secret key x: ");
    scanf("%d",&x);

    int y = powerMod(g,x,p);

    printf("\nPublic key (p,g,y): (%d,%d,%d)",p,g,y);

    int k;
    printf("\nEnter k: ");
    scanf("%d",&k);

    while(gcd(k,p-1)!=1)
    {
        printf("Invalid k, re-enter: ");
        scanf("%d",&k);
    }

    int hm;
    printf("Enter hash message: ");
    scanf("%d",&hm);

    // SIGN
    int r = powerMod(g,k,p);
    int k_inv = modInverse(k,p-1);
    int s = ((hm - x*r) * k_inv) % (p-1);
    
    printf("\nSignature (r,s): (%d,%d)",r,s);

    // VERIFY
    int v1 = powerMod(g,hm,p);
    int v2 = (powerMod(y,r,p) * powerMod(r,s,p)) % p;

    if(v1==v2)
    {
        printf("\nValid Signature");
    }

    else
    {
        printf("\nInvalid Signature");
    }

    return 0;
}