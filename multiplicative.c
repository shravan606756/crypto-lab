#include<stdio.h>
#include<string.h>

int modInverse(int k)
{
    for(int i=0 ; i<26 ; i++)
    {
        if((k*i)%26==1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char txt[100] , enc[100];

    printf("Enter the text : ");
    scanf("%s",txt);    
    int key;
    printf("Enter the key : ");
    scanf("%d",&key);
    key = key%26;
    int inv = modInverse(key);

    //encryption
    int i;  
    for(i=0 ; txt[i]!='\0' ; i++)
    {
        enc[i] = (((txt[i]-'a')*key)+26 %26)%26 +'a';
    }
    enc[i] = '\0';
    printf("\nEncrypted text : %s",enc);

    //decrypt
    for(int i=0 ; enc[i]!='\0' ; i++)
    {
        txt[i] = (((enc[i]-'a') * inv)+26 %26)%26 + 'a';
    }
    txt[i]='\0';
    printf("\nDecrypted text : %s",txt);

    return 0;
}