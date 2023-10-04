#include<stdio.h>

int
getWine(int n){
    if(n == 1) return 1;
    if(n == 2) return 3;
    
    if(n > 2){
        return n + getWine(n - 2);
    }
    
    //else
    return 0;
}

int main()
{
    int a,b;
    /*while(~scanf("%d%d", &a, &b))printf("%d\n",a+b);*/
    int i;
    for(i= 1; i < 4; i++){
        a = getWine(i);
	printf("%d\t", a);
    }
    
    return 0;
}
