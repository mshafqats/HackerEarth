/*
=====================
|  ID:   mshafqats  |
|  LANG: C          |
=====================
Mohammad Shafqat Siddiqui
*/

#include <stdio.h>
#include <stdlib.h>
 
int compfunc(const void* a, const void* b)
{
    return *(long*)a - *(long*)b;
}
 
int main()
{
    long t, i, n, m, q, x[100002], y[100002], minEW, minNS;
 
    scanf("%d", &t);
 
    while (t--)
    {
        long maxEW = -1, maxNS = -1, minNS = -1, minEW = -1, ewCount = 0, 
		nsCount = 0;
 
        scanf("%ld %ld %ld", &n, &m, &q);
 
        for (i = 1; i <= q; i++)
        {
            scanf("%ld %ld", &x[i], &y[i]);
        }
 
        qsort(x + 1, q, sizeof(long), compfunc);
        qsort(y + 1, q, sizeof(long), compfunc);
 
        x[0] = y[0] = 1;
        x[q + 1] = n;
        y[q + 1] = m;
 
        for (i = 1; i <= q + 1; i++)
        {
            long ew = x[i] - x[i-1];
 
            if (ew > 0)
            {
                ewCount++;
                if (minEW < 0 || ew < minEW) minEW = ew;
                if (maxEW < 0 || ew > maxEW) maxEW = ew;
            }
 
            long ns = y[i] - y[i - 1];
 
            if (ns > 0)
            {
                nsCount++;
                if (minNS < 0 || ns < minNS) minNS = ns;
                if (maxNS < 0 || ns > maxNS) maxNS = ns;
            }
        }
 
        printf("%ld %ld %ld\n", ewCount * nsCount, minEW * minNS, maxEW * maxNS);
    }
 
    return 0;
}
