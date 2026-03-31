#include<stdio.h>
#include<string.h>

int modInverse(int a)
{
    a=a%26;
    if(a<0)
    {
        a=a+26;
    }

    for(int i=1 ; i<26 ; i++)
    {
        if((a*i)%26==1)
        {
            return i;
        }
    }
    return -1;
}

void encrypt(char p[] , int k[2][2] , char c[])
{
    int i;
    for(i=0 ; p[i]!='\0';i++)
    {
        int x = p[i]-'a';
        int y = p[i+1]-'a';

        c[i] = (k[0][0]*x + k[0][1]*y)%26 +'a';
        c[i+1] = (k[1][0]*x + k[1][1]*y)%26 +'a';
    }
    c[i]='\0';

}

void decryption(char p[] , int k[2][2] , char c[])
{
    int det = (k[0][0]*k[1][1] - k[0][1]*k[1][0])%26;
    if(det<0)
    {
        det=det+26;
    }

    int iv = modInverse(det);
    
    if(iv<0)
    {
        printf("Invalid key matrix\n");
        return;
    }

    int inv[2][2];
    inv[0][0]=(k[1][1]*iv)%26;
    inv[0][1]=(-k[0][1]*iv)%26;
    inv[1][0]=(-k[1][0]*iv)%26;
    inv[1][1]=(k[0][0]*iv)%26;

    for(int i=0 ; i<2 ; i++)
    {
        for(int j=0 ; j<2 ; j++)
        {
            if(inv[i][j]<0)
            {
                inv[i][j]=inv[i][j]+26;
            }
        }
    }

    int i;
    for(i=0 ; c[i]!='\0';i++)
    {
        int x = p[i]-'a';
        int y = p[i+1]-'a';

        p[i] = (inv[0][0]*x + inv[0][1]*y)%26;
        p[i+1] = (inv[1][0]*x + inv[1][1]*y)%26;
    }
    p[i]='\0';
}

int main()
{
    char p[100] , c[100] , key[5];
    int k[2][2];

    printf("Enter the plain text : ");
    scanf("%s",p);

    printf("Enter the key matrix : ");
    scanf("%s" , key);

    k[0][0] =key[0]-'a';
    k[0][1] =key[1]-'a';
    k[1][0] =key[2]-'a';
    k[1][1] =key[3]-'a';

    encrypt(p,k,c);
    printf("\nEncrypted text : %s",c); 

    decryption(c,k,p);
    printf("\nDecrypted text : %s",p);

    return 0;
}