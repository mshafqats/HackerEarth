/*
=====================
|  ID:   mshafqats  |
|  LANG: C          |
=====================
Mohammad Shafqat Siddiqui
*/

#include <stdio.h> 
int partition(int[], int, int);  
void quick_sort(int[], int, int);
int main() 
{  
int t, n, s, h; 
scanf("%d", &t); 
while (t--) 
{ 
h = 0;  
scanf("%d", &n); 
int value[n], comb[n]; 
for (int j = 0; j < n; j++)  
scanf("%d%d", &value[j], &comb[j]);
qSort(value, 0, n - 1); 
qSort(comb, 0, n - 1); 
s = n - 1;  
for (int j = n - 1; j >= 0; j--)
{  
if (comb[s] >= value[j]) 
 { 
h++;  
s--;
}  
}  
printf("%d\n", n - h); 
} 
}  
void qSort(int a[], int l, int u) {  
int j; 
 if (l < u) 
{ 
 j = partition(a, l, u); 
        qSort(a, l, j - 1); 
        qSort(a, j + 1, u); 
	}
}  
int partition(int a[], int l, int u) {  
	int v, i, j, temp;
	v = a[l]; 
	i = l; 
	j = u + 1;  
 
	do  
	{  
		do  
			i++;  
        while (a[i] < v && i <= u); 
		do
			j--;  
		while (v < a[j]); 
		if (i < j) {  
        	temp = a[i]; 
        	a[i] = a[j]; 
        	a[j] = temp; 
    	} 
	} 
	while (i < j); 
	a[l] = a[j]; 
	a[j] = v; 
	return (j);  
}
