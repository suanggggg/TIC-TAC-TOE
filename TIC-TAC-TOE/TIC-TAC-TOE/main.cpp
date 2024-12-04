#include<graphics.h>
#include<iostream>

char matrix[3][3] =
{ '-','-', '-',
 '-', '-', '-',
 '-', '-', '-' };
char currentPiece = 'o';

bool checkWin(char c)
{
	if ((matrix[0][0] == c && matrix[0][1] == c && matrix[0][2] == c) ||
		(matrix[1][0] == c && matrix[1][1] == c && matrix[1][2] == c) ||
		(matrix[2][0] == c && matrix[2][1] == c && matrix[2][2] == c) ||
		(matrix[0][0] == c && matrix[1][0] == c && matrix[2][0] == c) ||
		(matrix[0][1] == c && matrix[1][1] == c && matrix[2][1] == c) ||
		(matrix[0][2] == c && matrix[1][2] == c && matrix[2][2] == c) ||
		(matrix[0][0] == c && matrix[1][1] == c && matrix[2][2] == c) ||
		(matrix[0][2] == c && matrix[1][1] == c && matrix[2][0] == c))
		return true;
	return false;
}
bool checkDraw()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (matrix[i][j] == '-')
				return false;
	return true;
}
void playChess(ExMessage msg)
{
	int index_x = msg.x / 300, index_y = msg.y / 300;
	matrix[index_x][index_y] = currentPiece;
	currentPiece = currentPiece == 'o' ? 'x' : 'o';
}
void drawMatrix()
{
	line(300, 0, 300, 900);
	line(600, 0, 600, 900);
	line(0, 300, 900, 300);
	line(0, 600, 900, 600);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] == 'x')
			{
				line(i * 300, j * 300, i * 300 + 300, j * 300 + 300);
				line(i * 300 + 300, j * 300, i * 300, j * 300 + 300);
			}
			else if (matrix[i][j] == 'o')
				circle(i * 300 + 150, j * 300 + 150, 100);
		}
	}
}

int main()
{
	initgraph(900, 900);


	BeginBatchDraw();
	bool running = true;
	while (running)
	{
		ExMessage msg;
		while (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN)
				playChess(msg);
		}
		cleardevice();
		drawMatrix();
		FlushBatchDraw();
		if (checkWin('x'))
		{
			MessageBox(GetHWnd(), _T("x펙綾價적"), _T("踏狗써監"), MB_OK);
			running = false;
		}
		else if (checkWin('o'))
		{
			MessageBox(GetHWnd(), _T("o펙綾價적"), _T("踏狗써監"), MB_OK);
			running = false;
		}
		else if (checkDraw())
		{
			MessageBox(GetHWnd(), _T("틱애"), _T("踏狗써監"), MB_OK);
			running = false;
		}
	}
	EndBatchDraw();
	return 0;

	// 123123

}