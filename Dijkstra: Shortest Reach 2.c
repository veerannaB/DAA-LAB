#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
       int t,n,e,i,j;
       scanf("%d",&t);
       for(i=0;i<t;i++)
       {
              scanf("%d%d",&n,&e);
              int s,k,mat[n+1][n+1],d[n+1],x,y,r,v[n+1];
              for(j=1;j<=n;j++)
              {
                     d[j] = 999999;
                     v[j] = 0;
                     for(k=1;k<=n;k++)
                     {
                           mat[j][k] = 999999;
                     }
              }
              for(j=0;j<e;j++)
              {
                     scanf("%d%d%d",&x,&y,&r);
                     if(mat[x][y] > r)
                     {
                           mat[x][y] = r;
                           mat[y][x] = r;      
                     }
              }
              scanf("%d",&s);
              d[s] = 0;
              int p,min,mind=s;
              v[mind] = 1;
              for(j=1;j<=n;j++)
              {
                     for(k=1;k<=n;k++)
                     {
                           if(mat[mind][k] != 999999)
                           {
                                  p = d[mind] + mat[mind][k];
                                  if(d[k] > p)
                                  {
                                         d[k]= p;
                                  }
                           }
                     }
                     min = 9999999;
                     for(k=1;k<=n;k++)
                     {
                           if(d[k] < min && v[k]==0)
                           {
                                  min = d[k];
                                  mind = k;
                           }
                     }
                     v[mind] = 1;
              }
              for(j=1;j<=n;j++)
              {
                     if(d[j]!= 0)
                     {
                           if(d[j] == 999999)
                           {
                                  printf("-1 ");
                           }
                           else
                           {
                                  printf("%d ",d[j]); 
                           }
                          
                     }
              }
              printf("\n");
       }
    return 0;
}

