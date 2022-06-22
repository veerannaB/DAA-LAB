#include <stdio.h>
#include<stdlib.h>
int d;
void sum(int,int,int[]);
int main()
{
    int n,w[100],i;
    scanf("%d%d",&n,&d);
    for(i=1;i<=n;i++)
    scanf("%d",&w[i]);
    sum(n,d,w);
}

void sum(int n,int d,int w[])
{
    int x[100],s,k,i;
    for(i=1;i<=n;i++)
    x[i]=0;
    s=0;
    k=1;
    x[k]=1;
    while(1)
	{
      if(k <= n && x[k]==1) {
      if(s+w[k] == d) {
	  for(i=1;i<=n;i++) {
       if(x[i]==1)
       printf("%d ",w[i]);
	   }
	    printf("\n");
        x[k]=0;
	}
	 else if(s+w[k] < d)
     s+=w[k];
     else {
        x[k]=0;
		} }
		 else{
               k--;
     while(k>0 && x[k]==0)
     k--;
     if(k<=0){
         break;
		 }
       x[k]=0;
       s=s-w[k];  }
       k=k+1;
       x[k]=1;
 } }
