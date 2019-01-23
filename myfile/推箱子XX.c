/*
名称：推箱子
927371525@qq.com
描述：以前做51单片机课程设计的推箱子
游戏，现在移植到了C4droid上
*/
#include<stdio.h>
#include<conio.h>
//#include"map.h"
//由于C4droid的编译环境问题，要写完整的路径
#include"/storage/emulated/0/C_test/myfile/map.h"


int playMap(char m[8][8]);

int main()
{
	char c_map[8][8];
	int c_level = 0;
	
	printf("\n     第%d关\n", c_level+1);
	loadmap(0, c_map);
	playMap(map[c_level]);
	while (1)
	{
		gameOperate(keyOperate(), &c_level, c_map);
		clrscr();
		//printf("\ntest_lv:%d\n", c_level);
		printf("\n     第%d关\n", c_level+1);
		playMap(c_map);
	}
	return 0;
}

int playMap(char m[8][8])
{
	char i, j;
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			//printf("%2d", m[i][j]);
			if (m[i][j] == 0)//空白
			{
				printf("%2c", ' ');
			}
			if (m[i][j] == 1)//人物
			{
				printf("人");
			}
			if (m[i][j] == 2)//墙壁
			{
				printf("围");
			}
			if (m[i][j] == 3)//箱子
			{
				printf("囗");
			}
			if (m[i][j] == 4)//终点
			{
				printf("叵");
			}
			if (m[i][j] == 5)//终点+箱子
			{
				printf("回");
			}
			if (m[i][j] == 6)//终点+人物
			{
				printf("区");
			}
			
		}
		printf("\n");
	}
	printf("\n操作说明：\n2：上移\n4：左移\n6：右移\n8：下移\n+：下一个关卡\n-：上一个关卡\n");
	return 0;
}

int keyOperate()
{
	char keyNum = 0;
	//scanf("%c", &keyNum);
	keyNum = getch();
	//printf("\ntest_key:%c\n", keyNum);
	switch (keyNum)
	{
		case '2': return 1;
		case '8': return 2;
		case '4': return 3;
		case '6': return 4;
		case '+': return 5;
		case '-': return 6;
		default : return 0;
	}
}

int loadmap(int lv, char m[8][8])
{
	int i,j;
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			m[i][j] = map[lv][i][j];
		}
	}
}

int gameOperate(int key, int* p_lv, char map_lv[8][8])
{
	int p_x, p_y;//记录当前人物的位置
	//extern map[][8][8];
	int lvlup;
	
	lvlup = 1;
	for (int x=0; x<8; x++)
	{
		for (int y=0; y<8; y++)
		{
			if (map_lv[x][y] == 1 || map_lv[x][y] == 6)
			{
				p_x = x;
				p_y = y;
			}
			if (map_lv[x][y] == 3)//判断本关卡有没有没归位的箱子
			{
				lvlup = 0;
			}
		}
	}
	if (lvlup == 1)
	{
		key = 5;
	}
	
	if (key == 0)//无效按键
	{
		return 1;
	}
	else if (key == 1)//上
	{
		//如果上面是空位0
		if (map_lv[p_x - 1][p_y] == 0)
		{
			//人物上移
			map_lv[p_x - 1][p_y] = 1;
			//人原来的位置
			if (map_lv[p_x][p_y] == 1)
			{
				map_lv[p_x][p_y] = 0;
			}
			else if (map_lv[p_x][p_y] == 6)
			{
				map_lv[p_x][p_y] = 4;
			}
		}
		//上面是人1，无效
		//上面是墙2，无操作
		//上面是箱子3
		else if (map_lv[p_x - 1][p_y] == 3)
		{
			if (map_lv[p_x - 2][p_y] == 0)//箱子上面是空白
			{
				map_lv[p_x - 2][p_y] = 3;//空白处放箱子
				map_lv[p_x - 1][p_y] = 1;//人往上移
				//人原来的位置处理
				if (map_lv[p_x][p_y] == 1)
				{
					map_lv[p_x][p_y] = 0;
				}
				else if (map_lv[p_x][p_y] == 6)
				{
					map_lv[p_x][p_y] = 4;
				}
			}
			else if (map_lv[p_x - 2][p_y] == 4)//箱子上面是终点
			{
				map_lv[p_x - 2][p_y] = 5;//箱子进入终点
				map_lv[p_x - 1][p_y] = 1;//人往上移
				//人原来的位置处理
				if (map_lv[p_x][p_y] == 1)
				{
					map_lv[p_x][p_y] = 0;
				}
				else if (map_lv[p_x][p_y] == 6)
				{
					map_lv[p_x][p_y] = 4;
				}
			}
		}
		//上面是终点4
		else if (map_lv[p_x - 1][p_y] == 4)
		{
			map_lv[p_x - 1][p_y] = 6;
			//人原来的位置处理
			if (map_lv[p_x][p_y] == 1)
			{
				map_lv[p_x][p_y] = 0;
			}
			else if (map_lv[p_x][p_y] == 6)
			{
				map_lv[p_x][p_y] = 4;
			}
		}
		//上面是终点+箱子5
		else if (map_lv[p_x - 1][p_y] == 5)
		{
			if (map_lv[p_x - 2][p_y] == 0)
			{
				map_lv[p_x - 2][p_y] = 3;
				map_lv[p_x - 1][p_y] = 6;
				//人原来的位置处理
				if (map_lv[p_x][p_y] == 1)
				{
					map_lv[p_x][p_y] = 0;
				}
				else if (map_lv[p_x][p_y] == 6)
				{
					map_lv[p_x][p_y] = 4;
				}
			}
			else if (map_lv[p_x - 2][p_y] == 4)
			{
				map_lv[p_x - 2][p_y] = 5;
				map_lv[p_x - 1][p_y] = 6;
				//人原来的位置处理
				if (map_lv[p_x][p_y] == 1)
				{
					map_lv[p_x][p_y] = 0;
				}
				else if (map_lv[p_x][p_y] == 6)
				{
					map_lv[p_x][p_y] = 4;
				}
			}
		}
		//上面是人物+箱子6，无效
	}
	else if (key == 2)//下
	{
		//如果下面是空位0
		if (map_lv[p_x + 1][p_y] == 0)
		{
			//人物下移
			map_lv[p_x + 1][p_y] = 1;
			//人原来的位置
			if (map_lv[p_x][p_y] == 1)
			{
				map_lv[p_x][p_y] = 0;
			}
			else if (map_lv[p_x][p_y] == 6)
			{
				map_lv[p_x][p_y] = 4;
			}
		}
		//下面是人1，无效
		//下面是墙2，无操作
		//下面是箱子3
		else if (map_lv[p_x + 1][p_y] == 3)
		{
			if (map_lv[p_x + 2][p_y] == 0)//箱子下面是空白
			{
				map_lv[p_x + 2][p_y] = 3;//空白处放箱子
				map_lv[p_x + 1][p_y] = 1;//人往下移
				//人原来的位置处理
				if (map_lv[p_x][p_y] == 1)
				{
					map_lv[p_x][p_y] = 0;
				}
				else if (map_lv[p_x][p_y] == 6)
				{
					map_lv[p_x][p_y] = 4;
				}
			}
			else if (map_lv[p_x + 2][p_y] == 4)//箱子下面是终点
			{
				map_lv[p_x + 2][p_y] = 5;//箱子进入终点
				map_lv[p_x + 1][p_y] = 1;//人往下移
				//人原来的位置处理
				if (map_lv[p_x][p_y] == 1)
				{
					map_lv[p_x][p_y] = 0;
				}
				else if (map_lv[p_x][p_y] == 6)
				{
					map_lv[p_x][p_y] = 4;
				}
			}
		}
		//下面是终点4
		else if (map_lv[p_x + 1][p_y] == 4)
		{
			map_lv[p_x + 1][p_y] = 6;
			//人原来的位置处理
			if (map_lv[p_x][p_y] == 1)
			{
				map_lv[p_x][p_y] = 0;
			}
			else if (map_lv[p_x][p_y] == 6)
			{
				map_lv[p_x][p_y] = 4;
			}
		}
		//下面是终点+箱子5
		else if (map_lv[p_x + 1][p_y] == 5)
		{
			if (map_lv[p_x + 2][p_y] == 0)
			{
				map_lv[p_x + 2][p_y] = 3;
				map_lv[p_x + 1][p_y] = 6;
				//人原来的位置处理
				if (map_lv[p_x][p_y] == 1)
				{
					map_lv[p_x][p_y] = 0;
				}
				else if (map_lv[p_x][p_y] == 6)
				{
					map_lv[p_x][p_y] = 4;
				}
			}
			else if (map_lv[p_x + 2][p_y] == 4)
			{
				map_lv[p_x + 2][p_y] = 5;
				map_lv[p_x + 1][p_y] = 6;
				//人原来的位置处理
				if (map_lv[p_x][p_y] == 1)
				{
					map_lv[p_x][p_y] = 0;
				}
				else if (map_lv[p_x][p_y] == 6)
				{
					map_lv[p_x][p_y] = 4;
				}
			}
		}
		//上面是人物+箱子6，无效
	}
	else if (key == 3)//左
	{
		//如果左边是空位0
		if (map_lv[p_x][p_y - 1] == 0)
		{
			//人物左移
			map_lv[p_x][p_y - 1] = 1;
			//人原来的位置
			if (map_lv[p_x][p_y] == 1)
			{
				map_lv[p_x][p_y] = 0;
			}
			else if (map_lv[p_x][p_y] == 6)
			{
				map_lv[p_x][p_y] = 4;
			}
		}
		//左边是人1，无效
		//左边是墙2，无操作
		//左边是箱子3
		else if (map_lv[p_x][p_y - 1] == 3)
		{
			if (map_lv[p_x][p_y - 2] == 0)//箱子左边是空白
			{
				map_lv[p_x][p_y - 2] = 3;//空白处放箱子
				map_lv[p_x][p_y - 1] = 1;//人往左移
				//人原来的位置处理
				if (map_lv[p_x][p_y] == 1)
				{
					map_lv[p_x][p_y] = 0;
				}
				else if (map_lv[p_x][p_y] == 6)
				{
					map_lv[p_x][p_y] = 4;
				}
			}
			else if (map_lv[p_x][p_y - 2] == 4)//箱子左边是终点
			{
				map_lv[p_x][p_y - 2] = 5;//箱子进入终点
				map_lv[p_x][p_y - 1] = 1;//人往左移
				//人原来的位置处理
				if (map_lv[p_x][p_y] == 1)
				{
					map_lv[p_x][p_y] = 0;
				}
				else if (map_lv[p_x][p_y] == 6)
				{
					map_lv[p_x][p_y] = 4;
				}
			}
		}
		//左边是终点4
		else if (map_lv[p_x][p_y - 1] == 4)
		{
			map_lv[p_x][p_y - 1] = 6;
			//人原来的位置处理
			if (map_lv[p_x][p_y] == 1)
			{
				map_lv[p_x][p_y] = 0;
			}
			else if (map_lv[p_x][p_y] == 6)
			{
				map_lv[p_x][p_y] = 4;
			}
		}
		//左边是终点+箱子5
		else if (map_lv[p_x][p_y - 1] == 5)
		{
			if (map_lv[p_x][p_y - 2] == 0)
			{
				map_lv[p_x][p_y - 2] = 3;
				map_lv[p_x][p_y - 1] = 6;
				//人原来的位置处理
				if (map_lv[p_x][p_y] == 1)
				{
					map_lv[p_x][p_y] = 0;
				}
				else if (map_lv[p_x][p_y] == 6)
				{
					map_lv[p_x][p_y] = 4;
				}
			}
			else if (map_lv[p_x][p_y - 2] == 4)
			{
				map_lv[p_x][p_y - 2] = 5;
				map_lv[p_x][p_y - 1] = 6;
				//人原来的位置处理
				if (map_lv[p_x][p_y] == 1)
				{
					map_lv[p_x][p_y] = 0;
				}
				else if (map_lv[p_x][p_y] == 6)
				{
					map_lv[p_x][p_y] = 4;
				}
			}
		}
		//上边是人物+箱子6，无效
	}
	else if (key == 4)//右
	{
		//如果右边是空位0
		if (map_lv[p_x][p_y + 1] == 0)
		{
			//人物右移
			map_lv[p_x][p_y + 1] = 1;
			//人原来的位置
			if (map_lv[p_x][p_y] == 1)
			{
				map_lv[p_x][p_y] = 0;
			}
			else if (map_lv[p_x][p_y] == 6)
			{
				map_lv[p_x][p_y] = 4;
			}
		}
		//右边是人1，无效
		//右边是墙2，无操作
		//右边是箱子3
		else if (map_lv[p_x][p_y + 1] == 3)
		{
			if (map_lv[p_x][p_y + 2] == 0)//箱子右边是空白
			{
				map_lv[p_x][p_y + 2] = 3;//空白处放箱子
				map_lv[p_x][p_y + 1] = 1;//人往右移
				//人原来的位置处理
				if (map_lv[p_x][p_y] == 1)
				{
					map_lv[p_x][p_y] = 0;
				}
				else if (map_lv[p_x][p_y] == 6)
				{
					map_lv[p_x][p_y] = 4;
				}
			}
			else if (map_lv[p_x][p_y + 2] == 4)//箱子右边是终点
			{
				map_lv[p_x][p_y + 2] = 5;//箱子进入终点
				map_lv[p_x][p_y + 1] = 1;//人往右移
				//人原来的位置处理
				if (map_lv[p_x][p_y] == 1)
				{
					map_lv[p_x][p_y] = 0;
				}
				else if (map_lv[p_x][p_y] == 6)
				{
					map_lv[p_x][p_y] = 4;
				}
			}
		}
		//右边是终点4
		else if (map_lv[p_x][p_y + 1] == 4)
		{
			map_lv[p_x][p_y + 1] = 6;
			//人原来的位置处理
			if (map_lv[p_x][p_y] == 1)
			{
				map_lv[p_x][p_y] = 0;
			}
			else if (map_lv[p_x][p_y] == 6)
			{
				map_lv[p_x][p_y] = 4;
			}
		}
		//右边是终点+箱子5
		else if (map_lv[p_x][p_y + 1] == 5)
		{
			if (map_lv[p_x][p_y + 2] == 0)
			{
				map_lv[p_x][p_y + 2] = 3;
				map_lv[p_x][p_y + 1] = 6;
				//人原来的位置处理
				if (map_lv[p_x][p_y] == 1)
				{
					map_lv[p_x][p_y] = 0;
				}
				else if (map_lv[p_x][p_y] == 6)
				{
					map_lv[p_x][p_y] = 4;
				}
			}
			else if (map_lv[p_x][p_y + 2] == 4)
			{
				map_lv[p_x][p_y + 2] = 5;
				map_lv[p_x][p_y + 1] = 6;
				//人原来的位置处理
				if (map_lv[p_x][p_y] == 1)
				{
					map_lv[p_x][p_y] = 0;
				}
				else if (map_lv[p_x][p_y] == 6)
				{
					map_lv[p_x][p_y] = 4;
				}
			}
		}
		//上边是人物+箱子6，无效
	}
	else if (key == 5)//下一关
	{
		(*p_lv)++;
		//map.h里面只有21个地图(0≤level≤20)
		(*p_lv)%=21;
		loadmap(*p_lv, map_lv);
	}
	else if (key == 6)  //上一关
	{
		(*p_lv)--;
		if ((*p_lv) < 0)
		    *p_lv = 20;
		loadmap(*p_lv, map_lv);
	}
}
