//�������ݴ���һ�������壨��һЩ���ݣ���һ���㷨��
//initgraph(
//	width,  ��
//	height,  ��
//	flag   ������ʽ
//);

#include<graphics.h>
#include<iostream>
//int i,j;
char board_data[3][3] =
{
	{ '-', '-', '-' },
	{ '-', '-', '-' },
	{ '-', '-', '-' },
};
//char board_data[3][3];
// void initialize_board(){
//	for (i = 0; i < 3; i++) {
//		for (j = 0; j < 3; j++) {
//			board_data[i][j] = '-';
//		}
//	}
//}
 char current_piece = 'O';//
//����ʤ
bool CheckWin(char c) {

	if (board_data[0][0] == c && board_data[0][1] == c && board_data[0][2] == c)
		return true;
	if (board_data[1][0] == c && board_data[1][1] == c && board_data[1][2] == c)
		return true;
	if (board_data[2][0] == c && board_data[2][1] == c && board_data[2][2] == c)
		return true;
	if (board_data[0][0] == c && board_data[1][0] == c && board_data[2][0] == c)
		return true;
	if (board_data[0][1] == c && board_data[1][1] == c && board_data[2][1] == c)
		return true;
	if (board_data[0][2] == c && board_data[1][2] == c && board_data[2][2] == c)
		return true;
	if (board_data[0][0] == c && board_data[1][1] == c && board_data[2][2] == c)
		return true;
	if (board_data[0][2] == c && board_data[1][1] == c && board_data[2][0] == c)
		return true;

	return false;
	/*for (i = 0; i < 3; i++) {
		 j = 0;
		 if (board_data[i][j] == c && board_data[i][j + 1] == c && board_data[i][j + 2] == c)
			 return true;
	}
	for (j = 0; j < 3; j++) {
		i = 0;
		if (board_data[i][j] == c && board_data[i+1][j] == c && board_data[i+2][j] == c)
			return true;
	}
	i = 0; j = 0;
	if (board_data[i][j] == c && board_data[i + 1][j + 1] == c && board_data[i + 2][j + 2] == c)
		return true;
		i = 0; j = 2;
		if (board_data[i][j] == c && board_data[i + 1][j - 1] == c && board_data[i + 2][j -2] == c)
			return true;
	return false;*/
}
//���ƽ��
bool CheckDraw()
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++) {
			if (board_data[i][j] == '-')
			{
				return false;
			}

		}

	}
	return true;

}
//������������
void DrawBoard()
{
	line(0, 200, 600, 200);
	line(0, 400, 600, 400);
	line(200, 0, 200, 600);
	line(400, 0, 400, 600);
}
//��������
void DrawPiece()
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			switch (board_data[i][j])
			{
			case 'O':
				circle(200 * j + 100, 200 * i + 100, 100);
				break;
			case'X':
				line(200 * j, 200 * i, 200 * (j + 1), 200 * (i + 1));
				line(200 * (j+1), 200 * i, 200 * j , 200 * (i + 1));
				break;
			case'-':
				break;
			default:
				break;
			}

		}

	}
}
//������ʾ��Ϣ
void DrawTipText()
{
	static TCHAR str[64];//����TCHAR�����ַ�������Ϊ��ʽ���Ļ�����
	_stprintf_s(str, _T("��ǰ�������ͣ�%c"), current_piece);//�ַ�����ʽ������
	settextcolor(RGB(225, 175, 45));//�Ȼ�ɫ
	outtextxy(0, 0, str);//��x��y�����ַ�����ʽ��ʾ�ı�
}
int main()
{
	initgraph(600, 600);//���ƴ��ڣ��ú����while��ס���ô�����ʧ
	/*initialize_board();*/
	bool running = true;

	const int fps = 60;

	ExMessage msg;

	BeginBatchDraw();

	/*
	��ʼ��������

	while (true)
	{
		��ȡ�������();
		�������ݣ�����
		���»��ƻ���();

	}
	�ͷ���Դ������

	*/

	//solidcircle(x,y,r)


	while (running)
	{
		DWORD start_time = GetTickCount();//��ȡϵͳ���������������ĺ�����   //��CPU
		while (peekmessage(&msg))
		{
			//������ִ����Ϣ�����߼�
		
			if (msg.message == WM_LBUTTONDOWN) //���£���message�Ǹ������
			{//������λ��
				int x = msg.x;
				int y = msg.y;
				int index_x = x / 200;
				int index_y = y / 200;
				//��������
				if (board_data[index_y][index_x] == '-') 
				{
					board_data[index_y][index_x] = current_piece;//�������˸���=������˺þ�

					if (current_piece == 'O')
						current_piece = 'X';
					else
						current_piece = 'O';
				}

			//Sleep(15);
			}

		}
		

		

		/*MessageBox(
			hWnd,  �����ھ�� //GetHWnd() ��ȡ���ھ��
			text,    ��ʾ����
			caption,   ��������
			type        ������ʽ  //MB_OK  ʹ��������ʾ������ֻ��OKһ��ȷ�ϰ���
			);*/
		cleardevice();//���õ�ǰ����ɫ�����Ļ��������ǰ������ (0, 0)//ע���˺���ҲûӰ�죿��

		DrawBoard();
		DrawPiece();
		DrawTipText();

		FlushBatchDraw();


		if (CheckWin('X'))
		{

			MessageBox(GetHWnd(), _T("X���Ӯ"), _T("��Ϸ����"), MB_OK);
			running = false;
		}
		else if (CheckWin('O')) 
		{

			MessageBox(GetHWnd(), _T("O���Ӯ"), _T("��Ϸ����"), MB_OK);
			running = false;
		}
		else if (CheckDraw()) 
		{

			MessageBox(GetHWnd(), _T("ƽ��"), _T("��Ϸ����"), MB_OK);
			running = false;
		}
		DWORD end_time = GetTickCount();//
		DWORD delta_time = end_time - start_time;
		if (delta_time < 1000 / fps) 
		{
			Sleep(1000 / fps - delta_time);//��sleep��ʱ��CPUռ����

		}
		

	

		
	}
	EndBatchDraw();


	return 0;
}