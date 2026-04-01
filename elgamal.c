#include<stdio.h>

int powerMod(int b,int e,int m)
{
    int r=1;
    b%=m;
    while(e>0)
    {
        if(e%2) r=(r*b)%m;
        e/=2;
        b=(b*b)%m;
    }
    return r;
}

int modInverse(int a,int m)
{
    for(int i=1;i<m;i++)
        if((a*i)%m==1) return i;
    return -1;
}

int main()
{
    int p,g,d,k,m;

    printf("Enter p and g: ");
    scanf("%d%d",&p,&g);

    printf("Enter private key d: ");
    scanf("%d",&d);

    int e = powerMod(g,d,p);

    printf("\nPublic Key (p,g,e): (%d,%d,%d)\n",p,g,e);

    printf("Enter plaintext: ");
    scanf("%d",&m);

    printf("Enter random k: ");
    scanf("%d",&k);

    // Encryption
    int y1 = powerMod(g,k,p);
    int y2 = (m * powerMod(e,k,p)) % p;

    printf("\nCipher Text (y1,y2): (%d,%d)",y1,y2);

    // Decryption
    int s = powerMod(y1,d,p);
    int s_inv = modInverse(s,p);

    int dec = (y2 * s_inv) % p;

    printf("\nDecrypted message: %d",dec);

    return 0;
}