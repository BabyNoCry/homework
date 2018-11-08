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
void muen();//菜单函数
void inint_mine(char arr[ROW][COL],char arr2[ROW][COL], int row, int col);//初始化棋盘
void print_player(char arr[ROW][COL],int row,int col);//打印玩家棋盘
void print_mine(char arr[ROW][COL], int row, int col);//打印答案 
void set_mine(char arr[ROW][COL], int row, int col);
void check_mine(char arr[ROW][COL],char arr2[ROW][COL],int row, int col);//计算该位置周围雷数
void safe_mine(char arr[ROW][COL],char arr2[ROW][COL], int row, int col);//避免第一次被炸死
int ISwin(char arr[ROW][COL], int row, int col);//是否胜利

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
//#define COUNT 10//棋盘中雷的总数
//extern char show_mine[row][col];//展示数组
//extern char real_mine[row][col];//布雷数组
//
//void muen();//菜单函数
//void init_mine();//初始化数组函数
//void set_mine();//布雷函数
//int count_mine();//统计周围雷的个数
//void print_player();//打印玩家棋盘
//void print_mine();//打印设计者棋盘 
//int  sweep_mine();//扫雷函数
//void safe_mine();//避免第一次被雷炸死的函数
//void open_mine(int x, int y);//展开函数
//int count_show_mine(); ///判断玩家棋盘剩余未知区域的个数
//
//#endif  //__GAME_H__
