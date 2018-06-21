#include<stdio.h>
#include<stdlib.h>
#define row 5
#define col 5

struct subset
{
    int parent;
    int rank;
};

int count_island(int a[][col])
{
    int i,j;

    struct subset *s=(struct subset*)malloc(sizeof(struct subset)*(row*col));

    for(i=0;i<(row*col);i++)
    {
        s[i].parent=-1;
        s[i].rank=0;
    }

      for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(a[i][j]==0)
               continue;

                int l,m;
    if(i==0)
        l=i;
        else
          l=i-1;

    if(j==0)
        m=0;
    else
       m=j-1;


    while(l<=i+1&&l<row)
    { //outer while starts

        while(m<=j+1&& m<col)
        { //inner while starts

          if(l==i&&m==j)
            continue;

          if(a[l][m]==1)
            unionn(s,i*row+j,l*row+m);
              m++;

        }//inner while ends
        l++;

         }//outer while ends
     } //inner for ends
  }//outer for ends

  int c[row*col]={0};
int count=0;
  for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {

            if(a[i][j]==0)
                continue;

            int x=find(s,i*row+j);

              if(c[x]==0)
              {
                  count++;
                  c[x]++;
              }
            else
                c[x]++;
        }
    }
    return count;
}

int find(struct subset *s,int i)
{
    if(s[i].parent==-1)
        return i;
    return(s,s[i].parent);
}

int unionn(struct subset *s,int x,int y)
{
    int x_set=find(s,x);
    int y_set=find(s,y);

    if(s[x_set].rank<s[y_set].rank)
        s[x_set].parent=y_set;
    else
    if(s[y_set].rank<s[x_set].rank)
        s[y_set].parent=x_set;
else
{
    s[y_set].parent=x_set;
    s[x_set].rank=s[x_set].rank+1;
}}

int main()
{
    int m[][col]={{1,1,0,0,0},
                   {0,1,0,0,1},
                   {1,0,0,1,1},
                   {0,0,0,0,0},
                   {1,0,1,0,1},
                 };
        int n=count_island(m);
        printf("no. of islands:%d",n);
}
