#include<stdio.h>
#include<string.h>

char m[5][5];

//Matrix generation

void gen(char *k)
{
    int f[26]={0};
    int i,j=0;
    for(i=0 ; k[i] ; i++)
    {
        if(k[i]=='j')
        {
            k[i]='i';
        }

        if(!f[k[i]-'a'])
        {
            m[j/5][j%5]=k[i];
            f[k[i]-'a']=1;
            j++;
        }
    }

    for(i=0 ; i<26 ; i++)
    {
        if(i+'a'=='j')
        {
            continue;
        }

        if(!f[i])
        {
            m[j/5][j%5]=i+'a';
            j++;
        }
    }
}

//To find respective rows and cols

void find(char c , int *r , int *c2)
{
    if(c=='j')
    {
        c='i';
    }

    for(int i=0 ; i<5 ; i++)
    {
        for(int j=0 ; j<5 ; j++)
        {
            if(m[i][j]==c)
            {
                *r=i;
                *c2=j;
                return;
            }
        }
    }
}


int main()
{
    char k[50] , t[100];
    printf("Enter the key : ");
    scanf("%s",k);
    gen(k);

    printf("Enter the text : ");
    scanf("%s",t);

    char p[100]; int i, j =0 ;

    //generating pairs
    for(int i=0 ; t[i] ; i++)
    {
        if(t[i]==t[i+1])
        {
            p[j++] = t[i];
            p[j++] = 'x';

        }
        else{
            p[j++] = t[i];
            if(t[i+1])
            {
                p[j++] = t[++i];
            }
        }
    }
    if(j%2!=0)
    {
        p[j++]='x';
    }
    p[j] = '\0';   

    char enc[100] , dec[100];

    //encryption
    int k1=0;
    for(i=0 ; p[i] ; i+=2)
    {
        int r1,r2,c1,c2;
        find(p[i],&r1,&c1);
        find(p[i+1],&r2,&c2);

        if(r1==r2)
        {
            enc[k1++] = m[r1][(c1+1)%5];
            enc[k1++] = m[r2][(c2+1)%5];
        }
        else if(c1==c2)
        {
            enc[k1++] = m[(r1+1)%5][c1];
            enc[k1++] = m[(r2+1)%5][c2];
        }
        else{
            enc[k1++] = m[r1][c2];
            enc[k1++] = m[r2][c1];
        }
    }

    enc[k1] = '\0';
    printf("\nEncrypted text : %s",enc);


    //decryption
    int k2=0;
    for(i=0 ; enc[i] ; i+=2)
    {
        int r1,r2,c1,c2;
        find(enc[i],&r1,&c1);
        find(enc[i+1],&r2,&c2);

        if(r1==r2)
        {
            dec[k2++] = m[r1][(c1+4)%5];
            dec[k2++] = m[r2][(c2+4)%5];
        }
        else if(c1==c2)
        {
            dec[k2++] = m[(r1+4)%5][c1];
            dec[k2++] = m[(r2+4)%5][c2];
        }
        else{
            dec[k2++] = m[r1][c2];
            dec[k2++] = m[r2][c1];
        }
    }
    dec[k2] = '\0';
    printf("\nDecrypted text : %s",dec);
}