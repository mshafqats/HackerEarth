/*
=====================
|  ID:   mshafqats  |
|  LANG: C          |
=====================
Mohammad Shafqat Siddiqui
*/

#include<stdio.h>
#include<string.h>
    
typedef struct node
{
    int x;
    int y;
}node;
    
int cmp(void *a, void *b)
{
    node l=*(node *)a;
    node r=*(node *)b;
    if(l.x > r.x)
        return 1;
    else if(l.x == r.x)
    {
        if(l.y > r.y)
            return 1;
        else
            return(0);
    }
    return(0);
}
    
int main(void)
{
    char arr[100005];
    node ans[100005];
    scanf("%s", arr);
    int n=strlen(arr),i;
    ans[0].x=0;
    ans[0].y=0;
    int x=0, y=0, k=1;
    for(i=0;i<n;i++)
    {
        if(arr[i]=='L')
        {
            y--;
        }
        else if(arr[i]=='R')
        {
            y++;
        }
        else if(arr[i]=='U')
        {
            x--;
        }
        else if(arr[i]=='D')
        {
            x++;
        }
        ans[k].x=x;
        ans[k].y=y;
        k++;
    }
    
    qsort(ans, k, sizeof(node), cmp);
    int c=0;
    
    for(i=0;i<k-1;i++)
    {
        if(ans[i].x==ans[i+1].x && ans[i].y==ans[i+1].y)
        {
            c++;
        }
    }
    printf("%d\n", c);
}
