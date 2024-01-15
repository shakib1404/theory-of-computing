#include<stdio.h>
#include<stdbool.h>
#include<string.h>



#define states 10
#define alphabet 2


int main()
{

    int numstates,int numalphabet;

    char alphabet[states];
    int transition[numstates][numalphabet];
    int finalstates[maxstates]={false};

    printf("Enter the number of states:");
    scanf("%d",&numstates);

    printf("Enter the number of alphabet:");
    scanf("%d",&alphabet);


    printf("Enter the alphabet:");
    for(int i=0;i<numalphabet;i++)
    {

        scanf("%d",&alphabet);
    }

    printf("Enter the transitions for each alphabet:");

    for(int i=0;i<numstates;i++)
        for(int j=0;j<numalphabet;j++)
    {

        int nextstates;

        printf("transition from %d with %c",i,alphabet[j]);

        scanf("%d",&nextstates);

        transition[i][j]=nextstates;

        int finalstates;

        printf("Enter the num final states:");
        scanf("%d",&finalstates);


        printf("Enter the finalstates:");
        for(int i=0;i<finalstates)


    }


}

