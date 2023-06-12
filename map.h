#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#pragma once

typedef struct _Plate
{
		int res_num;//資源數字指示
		int scene;//六種場地
		int bandit;//盜賊
}Plate;

typedef struct _Vertex
{
	int type;//節點種類(3種)
	int village;//村莊
	int city;//城市
	int port;//港口類型
    int res_num[3];//鄰近的資源數字指示
	int res_type[3];//鄰近的資源種類
}Vertex;


typedef struct _Line
{
	int type;//道路種類(2)
	int road;//道路的擁有權
}Line;


typedef struct _Player
{
	int resource[5];//五種資源
    int building[3];//三種建築
	int develop[5];//五種發展卡
    int new_deve[5];//剛拿到的卡
	int special[2];//特殊計分卡
}Player;

void init_struct( Plate *ArrayPlate, Vertex *ArrayVertex, Line *ArrayLine, Player *ArrayPlayer );

//這邊因為我目前還沒有找到更好的辦法，所以只好把這個爆開的每個點對應的數字指示物放在主函式
//所以主函式需要放入
/*
    struct _Plate ArrayPlate[19];
	struct _Vertex ArrayVertex[54] = {
	{ .res_num = {0, 0, 4} },
	{ .res_num = {0, 0, 11} },		
	{ .res_num = {0, 0, 12} },
	{ .res_num = {0, 0, 4} },
	{ .res_num = {0, 4, 11} },
	{ .res_num = {0, 11, 12} },
	{ .res_num = {0, 0, 12} },
	{ .res_num = {0, 4, 8} },
	{ .res_num = {4, 11, 3} },
	{ .res_num = {11, 12, 6} },
	{ .res_num = {0, 12, 9} },
	{ .res_num = {0, 0, 8} },
	{ .res_num = {4, 8, 3} },
	{ .res_num = {11, 3, 6} },
	{ .res_num = {12, 6, 9} },
	{ .res_num = {0, 0, 9} },
	{ .res_num = {0, 8, 5} },
	{ .res_num = {8, 3, 10} },
	{ .res_num = {3, 6, 11} },
	{ .res_num = {6, 9, 5} },
	{ .res_num = {0, 9, 10} },
	{ .res_num = {0, 0, 5} },
	{ .res_num = {8, 5, 10} },
	{ .res_num = {3, 10, 11} },
	{ .res_num = {6, 11, 5} },
	{ .res_num = {9, 5, 10} },
	{ .res_num = {0, 0, 10} },
	{ .res_num = {0, 0, 5} },
	{ .res_num = {5, 10, 2} },
	{ .res_num = {10, 11, 9} },
	{ .res_num = {11, 5, 4} },
	{ .res_num = {5, 10, 7} },
	{ .res_num = {0, 0, 10} },
	{ .res_num = {0, 5, 2} },
	{ .res_num = {10, 2, 9} },
	{ .res_num = {11, 9, 4} },
	{ .res_num = {5, 4, 7} },
	{ .res_num = {0, 10, 7} },
	{ .res_num = {0, 0, 2} },
	{ .res_num = {2, 9, 6} },
	{ .res_num = {9, 4, 3} },
	{ .res_num = {4, 7, 8} },
	{ .res_num = {0, 0, 7} },
	{ .res_num = {0, 2, 6} },
	{ .res_num = {9, 6, 3} },
	{ .res_num = {4, 3, 8} },
	{ .res_num = {0, 7, 8} },
	{ .res_num = {0, 0, 6} },
	{ .res_num = {0, 6, 3} },
	{ .res_num = {0, 3, 8} },
	{ .res_num = {0, 0, 8} },
	{ .res_num = {0, 0, 6} },
	{ .res_num = {0, 0, 3} },
	{ .res_num = {0, 0, 8} },
	};
	struct _Line ArrayLine[72];
	struct _Player ArrayPlayer[4];
*/