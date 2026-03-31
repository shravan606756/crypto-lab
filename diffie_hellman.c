#include<stdio.h>
#include<string.h>

int power_mod(int base , int exp  , int mod)
{
    int res = 1;
    base = base%mod;
    while(exp>0)
    {
        if(exp%2==1)
        {
            res = (res*base)%mod;
        }
        exp=exp/2;
        base = (base*base)%mod;
    }
    return res;
}

int main()
{
    int a , b , p , g;
    printf("Enter a prime no. :");
    scanf("%d",&p);
    printf("\nEnter a generator bit : ");
    scanf("%d",&g);

    printf("Enter the secret key of alice : ");
    scanf("%d",&a);
    printf("Enter the secret key of bob : ");
    scanf("%d",&b);

    int A = power_mod(g,a,p);
    int B = power_mod(g,b,p);

    int KeyA = power_mod(B,a,p);
    int KeyB = power_mod(A,b,p);

    printf("public key of alice : ");
    printf("%d\n",A);
    printf("public key of bob : ");
    printf("%d\n",B);

    printf("shared key of alice : ");
    printf("%d\n",KeyA);
    printf("shared key of bob : ");
    printf("%d\n",KeyB);

    return 0;

}