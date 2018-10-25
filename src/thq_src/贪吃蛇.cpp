#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define BEG_X	2
#define BEG_Y	1
#define WID		20
#define HEI		20
HANDLE hout;
typedef enum {UP, DOWN, LEFT, RIGHT} DIR;
typedef struct Snake_body
{
	COORD pos;//蛇身的位置
	struct Snake_body *next;//下一个蛇身
	struct Snake_body *prev;//前一个蛇身
}SNAKE, *PSNAKE;
PSNAKE head = NULL;//蛇头
PSNAKE tail = NULL;//蛇尾
//画游戏边框的函数
void DrawBorder()
{
	int i, j;
	COORD pos = {BEG_X, BEG_Y};
	for(i = 0; i < HEI; ++i)
	{
		SetConsoleCursorPosition(hout, pos);
		for(j = 0; j < WID; ++j)
		{
			if(i == 0)//第一行
			{
				if(j == 0)
					printf("┏");
				else if(j == WID - 1)
					printf("┓");
				else
					printf("━");
			}
			else if(i == HEI - 1)//最后一行
			{
				if(j == 0)
					printf("┗");
				else if(j == WID - 1)
					printf("┛");
				else
					printf("━");
			}
			else if(j == 0 || j == WID - 1)//第一列或最后一列
				printf("┃");
			else
				printf("  ");
		}
		++pos.Y;
	}	
}
//添加蛇身的函数
void AddBody(COORD pos)
{
	PSNAKE pnew = (PSNAKE)calloc(1, sizeof(SNAKE));
	pnew->pos = pos;
	if(!head)
	{
		head = tail = pnew;
	}
	else
	{
		pnew->next = head;//新创建蛇身的next指向原先的蛇头
		head->prev = pnew;//原先的蛇头的prev指向新创建的蛇身
		head = pnew;//把新创建的蛇身作为新的蛇头
	}
	SetConsoleCursorPosition(hout, head->pos);
	printf("◎");
}
//蛇身移动的函数
void MoveBody(DIR dir)
{
	PSNAKE ptmp;
	COORD pos = head->pos;
	switch(dir)
	{
		case UP:
			if(head->pos.Y > BEG_Y + 1)
				--pos.Y;
			else
				return;
		break;		
		case DOWN:
			if(head->pos.Y < BEG_Y + HEI - 2)
				++pos.Y;
			else
				return;
		break;
		case LEFT:
			if(head->pos.X > BEG_X + 2)
				pos.X -= 2;
			else
				return;
		break;
		case RIGHT:
			if(head->pos.X < BEG_X + (WID - 2) * 2)
				pos.X += 2;
			else 
				return;
		break;
	}
	AddBody(pos);//添加了一个新的蛇头
	ptmp = tail;//保存当前的蛇尾
	tail = tail->prev;
	if(tail)
		tail->next = NULL;
	SetConsoleCursorPosition(hout, ptmp->pos);
	printf("  ");
	free(ptmp);
}
int main()
{
	int ctrl;
	DIR dir = RIGHT;//初始蛇的方向是向右的
	COORD pos = {BEG_X + 2, BEG_Y + HEI / 2};
	system("color 0E");
	system("mode con cols=90 lines=30");
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("    ------------贪吃蛇的移动------------");
	DrawBorder();
	//自定义几个蛇的身体
	AddBody(pos);
	pos.X += 2;
	AddBody(pos);
	pos.X += 2;
	AddBody(pos);
	pos.X += 2;
	AddBody(pos);
	pos.X += 2;
	AddBody(pos);
	pos.X += 2;
	AddBody(pos);
	pos.X += 2;
	AddBody(pos);
	//控制蛇的移动
	while(ctrl = getch())
	{
		switch(ctrl)
		{
			case 'w':
				if(dir == DOWN)
					continue;
				dir = UP;
				break;
			case 's':
				if(dir == UP)
					continue;
				dir = DOWN;
				break;
			case 'a':
				if(dir == RIGHT)
					continue;
				dir = LEFT;
				break;
			case 'd':
				if(dir == LEFT)
					continue;
				dir = RIGHT;
				break;
			case 'q':
				return 0;
		}
		MoveBody(dir);
	}
	
	return 0;
}