#include<stdio.h>
#include<string.h>

int main()
{
    char txt[100] , enc[100];

    printf("Enter the text : ");
    scanf("%s",txt);
    
    int key;
    printf("Enter the key : ");
    scanf("%d",&key);
    key = key%26;

    //encryption
    int i;  
    for(i=0 ; txt[i]!='\0' ; i++)
    {
        enc[i] = (txt[i]-'a'+key)%26 +'a';
    }
    enc[i] = '\0';
    printf("\nEncrypted text : %s",enc);
    
    //decryption
    for(i=0 ; enc[i]!='\0' ; i++)
    {
        txt[i] = (enc[i]-'a'-key+26)%26 +'a';
    }
    txt[i] ='\0';
    printf("\nDecrypted text : %s",txt);

    return 0;
}