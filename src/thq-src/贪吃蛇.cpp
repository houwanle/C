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
	COORD pos;//�����λ��
	struct Snake_body *next;//��һ������
	struct Snake_body *prev;//ǰһ������
}SNAKE, *PSNAKE;
PSNAKE head = NULL;//��ͷ
PSNAKE tail = NULL;//��β
//����Ϸ�߿�ĺ���
void DrawBorder()
{
	int i, j;
	COORD pos = {BEG_X, BEG_Y};
	for(i = 0; i < HEI; ++i)
	{
		SetConsoleCursorPosition(hout, pos);
		for(j = 0; j < WID; ++j)
		{
			if(i == 0)//��һ��
			{
				if(j == 0)
					printf("��");
				else if(j == WID - 1)
					printf("��");
				else
					printf("��");
			}
			else if(i == HEI - 1)//���һ��
			{
				if(j == 0)
					printf("��");
				else if(j == WID - 1)
					printf("��");
				else
					printf("��");
			}
			else if(j == 0 || j == WID - 1)//��һ�л����һ��
				printf("��");
			else
				printf("  ");
		}
		++pos.Y;
	}	
}
//�������ĺ���
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
		pnew->next = head;//�´��������nextָ��ԭ�ȵ���ͷ
		head->prev = pnew;//ԭ�ȵ���ͷ��prevָ���´���������
		head = pnew;//���´�����������Ϊ�µ���ͷ
	}
	SetConsoleCursorPosition(hout, head->pos);
	printf("��");
}
//�����ƶ��ĺ���
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
	AddBody(pos);//�����һ���µ���ͷ
	ptmp = tail;//���浱ǰ����β
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
	DIR dir = RIGHT;//��ʼ�ߵķ��������ҵ�
	COORD pos = {BEG_X + 2, BEG_Y + HEI / 2};
	system("color 0E");
	system("mode con cols=90 lines=30");
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("    ------------̰���ߵ��ƶ�------------");
	DrawBorder();
	//�Զ��弸���ߵ�����
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
	//�����ߵ��ƶ�
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