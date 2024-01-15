#include<stdio.h>
#include<math.h>

void converter(int n,int k)
{
    int i;
    int arr[10]={0};





    for( i=0;n>0;i++)
    {
        arr[i]=n%2;
        n=n/2;

    }
    for(i=k-1;i>=0;i--)
    {

        printf("%d",arr[i]);

    }
    printf("\n");
}

int main()
{
    int k;
    printf("take input k:");
    scanf("%d",&k);

    for(int i=0;i<pow(2,k);i++)
    {

        converter(i,k);
    }
}
