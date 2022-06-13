#include<stdio.h>
#include<stdlib.h>

int set[50],sol[50],d;

void SumOfSubsets(int s,int k,int r)
{
    sol[k]=1; //Select the element to Solution

    if(s+set[k]==d)
    {
        printf("Selected Subset Elements\n");
        for(int i=1;i<=k;i++)
        {
            if(sol[i])
                printf("%d ",set[i]);
        }
        exit(0);
    }
    else if(s+set[k]+set[k+1]<=d)
    {
        SumOfSubsets(s+set[k],k+1,r-set[k]);
    }

    //backtracking
    if((s+r-set[k]>=d) && (s+set[k+1]<=d))
    {
        sol[k]=0;
        SumOfSubsets(s,k+1,r-set[k+1]);
    }

}

int main()
{
    int n,totalsum=0;
    printf("Enter No.of Elements : ");
    scanf("%d",&n);

    printf("Enter the Elements : ");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&set[i]);
        totalsum+=set[i];
    }

    printf("Enter the Max Sum : ");
    scanf("%d",&d);

    if(totalsum<d || set[1]>d)
    {
        printf("No Solution\n");
        exit(0);
    }

    SumOfSubsets(0,1,totalsum);
}
