#include <stdio.h>
#include <stdint.h>
#include "map.h"
#include "longestroad.h"
#include "computer_road.h"


int32_t vertex_neighbor[54][3] = {
	//0代表只有兩個鄰近邊
	{0, 1, 0}, //0
	{2, 3, 0}, //1
	{4, 5, 0}, //2
	{0, 6, 0}, //3
	{1, 2, 7}, //4
	{3, 4, 8}, //5
	{5, 9, 0}, //6
	{6, 10, 11},
	{7, 12, 13},
	{8, 14, 15},
	{9, 16, 17},
	{10, 18, 0},
	{11, 12, 19},
	{13, 14, 20},
	{15, 16, 21},
	{17, 22, 0},
	{18, 23, 24},
	{19, 25, 26},	
	{20, 27, 28},
	{21, 29, 30},
	{22, 31, 32},
	{22, 33, 0},
	{24, 25, 34},
	{26, 27, 35},
	{28, 29, 36},
	{30, 31, 37},
	{32, 38, 0},
	{33, 39, 0},
	{34, 40, 41},
	{35, 42, 43},
	{36, 44, 45},
	{37, 46, 47},
	{38, 48, 0},
	{39, 40, 49},
	{41, 42, 50},
	{43, 44, 51},
	{45, 46, 52},
	{47, 48, 53},
	{49, 54, 0},
	{50, 55, 56},
	{51, 57, 58},
	{52, 59, 60},
	{53, 61, 0},
	{54, 55, 62},
	{56, 57, 63},
	{58, 59, 64},
	{60, 61, 65},
	{62, 66, 0},
	{63, 67, 68},
	{64, 69, 70},
	{65, 71, 0},
	{66, 67, 0},
	{68, 69, 0},
	{70, 71, 0},
};



int32_t line_and_line_neighbor[72][4] = {
	{ 1,  6, -1, -1},
	{ 0,  2,  7, -1}, 
    { 1,  7,  5, -1},
    { 2,  4,  8, -1}, 
    { 3,  5,  8, -1},
    { 4,  9, -1, -1},
    { 0, 10, 11, -1},
    { 1,  2, 12, 13},
    { 3,  4, 14, 15},
    { 5, 16, 17, -1},
    { 6, 11, 18, -1},
    { 6, 10, 12, 19},
    { 7, 11, 13, 19},
    { 7, 12, 14, 20},
    { 8, 13, 15, 20},
    { 8, 14, 16, 21},
    { 9, 17, 21, -1},
    { 9, 16, 22, -1},
    {10, 23, 24, -1},
    {11, 12, 25, 26},
    {13, 14, 27, 28},
    {15, 16, 29, 30},
    {17, 31, 32, -1},
    {18, 24, 33, -1},
    {18, 23, 25, 34},
    {19, 24, 26, 34},
    {19, 25, 27, 35},
    {20, 26, 28, 35},
    {20, 27, 29, 36},
    {21, 28, 30, 36},
    {21, 29, 31, 37},
    {22, 30, 32, 37},
    {22, 31, 38, -1},
    {23, 39, -1, -1},
    {24, 25, 40, 41},
    {26, 27, 42, 43},
    {28, 29, 44, 45},
    {30, 31, 46, 47},
    {32, 48, -1, -1},
    {33, 40, 49, -1},
    {34, 39, 41, 49},
    {34, 40, 42, 50},
    {35, 41, 43, 50},
    {35, 42, 44, 51},
    {36, 43, 45, 51},
    {36, 44, 46, 52},
    {37, 45, 47, 52},
    {37, 46, 48, 53},
    {38, 47, 53, -1},
    {39, 40, 54, -1},
    {41 ,42, 55, 56},
    {43, 44, 57, 58},
    {45, 46, 59, 60},
    {47, 48, 61, -1},
    {49, 55, 62, -1},
    {50, 54, 56, 62},
    {50, 55, 57, 63},
    {51, 56, 58, 63},
    {51, 57, 59, 64},
    {52, 58, 60, 64},
    {52, 59, 61, 65},
    {53, 60, 65, -1},
    {54, 55, 66, -1},
    {56, 57, 67, 68},
    {58, 59, 69, 70},
    {60, 61, 71, -1},
    {62, 67, -1, -1},
    {63, 66, 68, -1},
    {63, 67, 69, -1},
    {64, 68, 70, -1},
    {64, 69, 71, -1},
    {65, 70, -1, -1},
};

int32_t isAvailable( int32_t m, int32_t n, int32_t vertex_neighbor[][3], sVertex *pVertex, int32_t player_NO )
{
	int32_t middle_vertex = 0;
	for( size_t i = 0; i < 3; i++ )
	{
        for( size_t j = 0; j < 3; j++ )
		{
            if( vertex_neighbor[m][i] == vertex_neighbor[m][j] )
			{
				middle_vertex = vertex_neighbor[m][i];
                //printf( "%d ", vertex_neighbor[m][i] );
                break;
            }
        }
    }

	if( pVertex[middle_vertex].village == player_NO + 1 || pVertex[middle_vertex].village == 0 )
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void computer_build_road( Player *pPlayer, Vertex *pVertex, Line *pLine, int32_t bank_res[], int32_t vertex_neighbor[][3], int32_t line_and_line_neighbor[][4], int32_t player_NO, sList* pList, int32_t player_longroad[] )
{
    if( pPlayer[player_NO].resource[1] < 1 || pPlayer[player_NO].resource[4] < 1 )
    {
        printf( "Player %d doesn't have enough resources to build a road.\n", player_NO+1 );
    }

	if( pPlayer[player_NO].building[1] == 15 )
	{
		printf( "Sorry. You can not build a road.\n" );
		return;
	}

	int32_t line_NO = 0;
	int32_t isVertexVillage = 0;
	for( int32_t i = 0; i < 54; i++ )
	{	
		if( pVertex[i].village == player_NO )
		{
			for( int32_t j = 0; j < 3; j++ )
			{
				if( vertex_neighbor[i][j] == 0 )
				{
					pLine[vertex_neighbor[i][j]].road = player_NO;
					line_NO = vertex_neighbor[i][j];
					isVertexVillage = 1;
					break;
				}
			}
		}
	}

	if( isVertexVillage == 1 )
	{
		pPlayer[player_NO].resource[1]--;
		pPlayer[player_NO].resource[4]--;
		pPlayer[player_NO].building[1]++;
		return;
	}

	int32_t available = 0;
	for( int32_t i = 0; i < 72; i++ )
	{
		if( pLine[i].road == player_NO )
		{
			for( int32_t j = 0; j < 4; j++ )
			{
				available = isAvailable( pLine[i].road, pLine[line_and_line_neighbor[i][j]].road, vertex_neighbor, pVertex, player_NO );
				if( pLine[line_and_line_neighbor[i][j]].road == 0 && available == 0 )
				{
					pLine[line_and_line_neighbor[i][j]].road = player_NO;
					line_NO = line_neighbor[i][j];
					break;
				}
			}
		}
	}

    pPlayer[player_NO].resource[1]--;
    pPlayer[player_NO].resource[4]--;
    pPlayer[player_NO].building[1]++;


	addNode( pList[1], line_NO );

	sListNode *pNewNode = calloc( 1, sizeof( sListNode ) );
	pNewNode = pList[1].pHead;

	int32_t longestRoad = 0;
	
	for(int32_t i = 0; i < (list_player1.size); i++)
	{
    	int32_t temp_longestRoad = LongestRoad(player_NO + 1, pNewNode -> data, ArrayVertex, ArrayLine);
		longestRoad = (temp_longestRoad > longestRoad) ? temp_longestRoad : longestRoad;
		pNewNode = pNewNode -> pNext;
	}

	player_longroad[ player_NO ] = longestRoad;

	return;

}