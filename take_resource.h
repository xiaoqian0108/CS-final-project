#pragma once
#include <stdint.h>

typedef struct _Plate
{
	int32_t res_num;  // 資源數字指示
	int32_t scene;  // 六種場地
	int32_t bandit;  // 盜賊
}sPlate;

typedef struct _Vertex
{
	int32_t type;  // 節點種類(3種)
	int32_t village;  // 村莊
	int32_t city;  // 城市
	int32_t port;  // 港口類型
    	int32_t res_num[3];  //:{0,5,8}  // 鄰近的資源數字指示
	int32_t res_type[3];  //:{0,2,1}  // 鄰近的資源種類
}sVertex;

typedef struct _Line
{
	int32_t type;  // 道路種類
	int32_t road;  // 道路的擁有權
}sLine;

typedef struct _Player
{
	int32_t resource[5];  // 五種資源
    int32_t building[3];  // 三種建築
	int32_t develop[5];  // 五種發展卡
   	int32_t new_deve[5];  // 剛拿到的卡
	int32_t special[2];  // 特殊計分卡
}sPlayer;

void init_plate( sPlate *pPlate );

void init_vertex( sVertex *pVertex );

void init_line();

void init_player( sPlayer *pPlayer );

int32_t drop_dice();

int32_t take_resource( int32_t dice , sPlate *pPlate, sVertex *pVertex, sPlayer *pPlayer );

void bandit_function();

void isVillage( sVertex *pVertex, sPlayer *pPlayer, int32_t i, int32_t number[] );
