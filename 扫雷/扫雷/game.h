#ifndef _GAME_H__
#define _GAME_H__
#define ROW 11
#define COL 11
#define COUNT 10
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void muen();//�˵�����
void inint_mine(char arr[ROW][COL],char arr2[ROW][COL], int row, int col);//��ʼ������
void print_player(char arr[ROW][COL],int row,int col);//��ӡ�������
void print_mine(char arr[ROW][COL], int row, int col);//��ӡ�� 
void set_mine(char arr[ROW][COL], int row, int col);
void check_mine(char arr[ROW][COL],char arr2[ROW][COL],int row, int col);//�����λ����Χ����
void safe_mine(char arr[ROW][COL],char arr2[ROW][COL], int row, int col);//�����һ�α�ը��
int ISwin(char arr[ROW][COL], int row, int col);//�Ƿ�ʤ��

#endif
 

//#ifndef __GAME_H__
//#define __GAME__H__
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<time.h>
//
//#define row 12
//#define col 12
//#define COUNT 10//�������׵�����
//extern char show_mine[row][col];//չʾ����
//extern char real_mine[row][col];//��������
//
//void muen();//�˵�����
//void init_mine();//��ʼ�����麯��
//void set_mine();//���׺���
//int count_mine();//ͳ����Χ�׵ĸ���
//void print_player();//��ӡ�������
//void print_mine();//��ӡ��������� 
//int  sweep_mine();//ɨ�׺���
//void safe_mine();//�����һ�α���ը���ĺ���
//void open_mine(int x, int y);//չ������
//int count_show_mine(); ///�ж��������ʣ��δ֪����ĸ���
//
//#endif  //__GAME_H__
