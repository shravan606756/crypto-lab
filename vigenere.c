#include<stdio.h>
#include<string.h>

void encrypt(char plain[], char key[], char cipher[]);
void decrypt(char cipher[], char key[], char plain[]);

int main()
{
    char plain[100] , cipher[100] , key[50];
    printf("Enter the plain text : ");
    scanf("%s",plain);
    printf("Enter the key : ");
    scanf("%s",key);

    encrypt(plain,key,cipher);
    printf("\n Encrypted message : %s",cipher);

    decrypt(cipher,key,plain);
    printf("\n Decrypted message : %s",plain);

    return 0;
}

void encrypt(char plain[] , char key[] , char cipher[] )
{
    int n = strlen(key);
    int i,j=0;

    for(i=0 ; plain[i]!='\0' ; i++)
    {
        cipher[i] = ((plain[i]-'a') + (key[j]-'a'))%26 +'a';
        j=(j+1)%n;
    }
    cipher[i] = '\0';
}

void decrypt(char cipher[] , char key[] , char plain[])
{
    int n=strlen(key);
    int i,j=0;

    for(i=0 ; cipher[i]!='\0' ; i++)
    {
        plain[i] = (((cipher[i]-'a') - (key[j]-'a')) +26)%26 +'a';
        j=(j+1)%n;
    }
    plain[i] = '\0';    
}