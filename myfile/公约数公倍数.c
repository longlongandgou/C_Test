/* 求两个整数的最大公约数和最小公倍数 */
#include<stdio.h>
int main()
{
	int maxgy(int x, int y);	// 声明一个函数
	int m, n, j, k;
	printf("求两个数的最大公约数和最小公倍数\n请输入两个整数:\n");
	scanf("%d%d", &m, &n);
	j = maxgy(m, n);
	// 最大公约数
	k = (m / j) * (n / j) * j;
	// 最小公倍数
	printf("\n%d和%d的最大公约数是:%d，最小公倍数是:%d\n", m, n, j, k);
	return 0;
}

// int maxgy(int x,int y)
// {
// int i,j;
// for (i = 1;i <= x && i <= y;i++)
// {
// if (x % i == 0 && y % i == 0)
//	j = i;
//}

//return j;
//}

//int maxgy(int x, int y)
//{
//	int i;
//	for (i = (x<y)?x:y; i > 0; i--)
//	{
////		printf("test i:%d\n", i);
//		if (x % i == 0 && y % i == 0)
//		    break;
//	}
//	return i;
//}

int maxgy(int x, int y)
{
	int i;
	for (i = (x<y)?x:y; i > 0; i--)
	{
//		printf("test i: %d\n", i);
		if (x % i == 0 && y % i == 0)
		    return i;
	}
}