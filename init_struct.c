#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"

void init_struct( Plate *ArrayPlate, Vertex *ArrayVertex, Line *ArrayLine, Player *ArrayPlayer )
{
	//init Plate
	ArrayPlate[15].bandit = 0;

	ArrayPlate[0].res_num = 4;
	ArrayPlate[1].res_num = 11;
	ArrayPlate[2].res_num = 12;
	ArrayPlate[3].res_num = 8;
	ArrayPlate[4].res_num = 3;
	ArrayPlate[5].res_num = 6;
	ArrayPlate[6].res_num = 9;
	ArrayPlate[7].res_num = 5;
	ArrayPlate[8].res_num = 10;
	ArrayPlate[9].res_num = 11;
	ArrayPlate[10].res_num = 5;
	ArrayPlate[11].res_num = 10;
	ArrayPlate[12].res_num = 2;
	ArrayPlate[13].res_num = 9;
	ArrayPlate[14].res_num = 4;
	ArrayPlate[15].res_num = 7;
	ArrayPlate[16].res_num = 6;
	ArrayPlate[17].res_num = 3;
	ArrayPlate[18].res_num = 8;

	srand( time(0) );
	int32_t resource_num[18] = { 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 5 };
	int32_t site = 0;

	for(int32_t i = 17; i >= 0 ; i--)
	{
		site = rand() % (i + 1);
		
		int32_t temp = resource_num[i];
		resource_num[i] = resource_num[site];
		resource_num[site] = temp;
	}

	for(int32_t i = 0; i < 19; i++)
	{
		if( i == 15 )
		{
			continue;
		}
		else if( i < 15 )
		{
			ArrayPlate[i].scene = resource_num[i];
		}
		else if( i > 15 )
		{
			ArrayPlate[i].scene = resource_num[i - 1];
		}
	}

	//init Vertex
	int32_t vertex_type0[] = {1, 2, 3, 4, 7, 12, 16, 22, 27, 28, 33, 39, 43, 48, 51, 52, 53, 54};
	int32_t vertex_type1[] = {5, 6, 8, 11, 17, 21, 34, 38, 44, 47, 49, 50};
	int32_t vertex_type2[] = {9, 10, 13, 14, 15, 18, 19, 20, 23, 24, 25, 26, 29, 30, 31, 32, 35, 36, 37, 40 , 41, 42, 45, 46}; 

	for(int32_t i = 0; i < sizeof( vertex_type0 ) / sizeof( vertex_type0[0] ); i++)
	{
		ArrayVertex[ vertex_type0[i] - 1 ].type = 0;
	}
	for(int32_t i = 0; i < sizeof( vertex_type1 ) / sizeof( vertex_type1[0] ); i++)
	{
		ArrayVertex[ vertex_type1[i] - 1 ].type = 1;
	}
	for(int32_t i = 0; i < sizeof( vertex_type2 ) / sizeof( vertex_type2[0] ); i++)
	{
		ArrayVertex[ vertex_type2[i] - 1 ].type = 2;
	}

	ArrayVertex[15].port = 1;
	ArrayVertex[20].port = 1;
	ArrayVertex[1].port = 2;
	ArrayVertex[4].port = 2;
	ArrayVertex[48].port = 3;
	ArrayVertex[52].port = 3;
	ArrayVertex[37].port = 4;
	ArrayVertex[42].port = 4;
	ArrayVertex[7].port = 5;
	ArrayVertex[11].port = 5;

	int32_t vertex_port6[] = {3, 7, 22, 28, 39, 44, 51, 54};
	for(int32_t i = 0; i < sizeof( vertex_port6 ) / sizeof( vertex_port6[0] ); i++)
	{
		ArrayVertex[ vertex_port6[i] - 1 ].port = 6;
	}

	ArrayVertex[0].res_type[2] = ArrayPlate[0].scene;
	ArrayVertex[1].res_type[2] = ArrayPlate[1].scene;
	ArrayVertex[2].res_type[2] = ArrayPlate[2].scene;
	ArrayVertex[3].res_type[2] = ArrayPlate[0].scene;
	ArrayVertex[4].res_type[1] = ArrayPlate[0].scene;	ArrayVertex[4].res_type[2] = ArrayPlate[1].scene;
	ArrayVertex[5].res_type[1] = ArrayPlate[1].scene;	ArrayVertex[4].res_type[2] = ArrayPlate[2].scene;
	ArrayVertex[6].res_type[2] = ArrayPlate[2].scene;
	ArrayVertex[7].res_type[1] = ArrayPlate[0].scene;	ArrayVertex[7].res_type[2] = ArrayPlate[3].scene;
	ArrayVertex[8].res_type[0] = ArrayPlate[0].scene;	ArrayVertex[8].res_type[1] = ArrayPlate[1].scene;	ArrayVertex[8].res_type[2] = ArrayPlate[4].scene;
	ArrayVertex[9].res_type[0] = ArrayPlate[1].scene;	ArrayVertex[8].res_type[1] = ArrayPlate[2].scene;	ArrayVertex[8].res_type[2] = ArrayPlate[5].scene;
	ArrayVertex[10].res_type[1] = ArrayPlate[2].scene;	ArrayVertex[10].res_type[2] = ArrayPlate[6].scene;
	ArrayVertex[11].res_type[2] = ArrayPlate[3].scene;
	ArrayVertex[12].res_type[0] = ArrayPlate[0].scene;	ArrayVertex[12].res_type[1] = ArrayPlate[3].scene;	ArrayVertex[12].res_type[2] = ArrayPlate[4].scene;
	ArrayVertex[13].res_type[0] = ArrayPlate[1].scene;	ArrayVertex[13].res_type[1] = ArrayPlate[4].scene;	ArrayVertex[13].res_type[2] = ArrayPlate[5].scene;
	ArrayVertex[14].res_type[0] = ArrayPlate[2].scene;	ArrayVertex[14].res_type[1] = ArrayPlate[5].scene;	ArrayVertex[14].res_type[2] = ArrayPlate[6].scene;
	ArrayVertex[15].res_type[2] = ArrayPlate[6].scene;
	ArrayVertex[16].res_type[1] = ArrayPlate[3].scene;	ArrayVertex[16].res_type[2] = ArrayPlate[7].scene;
	ArrayVertex[17].res_type[0] = ArrayPlate[3].scene;	ArrayVertex[17].res_type[1] = ArrayPlate[4].scene;	ArrayVertex[17].res_type[2] = ArrayPlate[8].scene;
	ArrayVertex[18].res_type[0] = ArrayPlate[4].scene;	ArrayVertex[18].res_type[1] = ArrayPlate[5].scene;	ArrayVertex[18].res_type[2] = ArrayPlate[9].scene;
	ArrayVertex[19].res_type[0] = ArrayPlate[5].scene;	ArrayVertex[19].res_type[1] = ArrayPlate[6].scene;	ArrayVertex[19].res_type[2] = ArrayPlate[10].scene;
	ArrayVertex[20].res_type[1] = ArrayPlate[6].scene;	ArrayVertex[20].res_type[2] = ArrayPlate[11].scene;
	ArrayVertex[21].res_type[2] = ArrayPlate[7].scene;
	ArrayVertex[22].res_type[0] = ArrayPlate[3].scene;	ArrayVertex[22].res_type[1] = ArrayPlate[7].scene;	ArrayVertex[22].res_type[2] = ArrayPlate[8].scene;
	ArrayVertex[23].res_type[0] = ArrayPlate[4].scene;	ArrayVertex[23].res_type[1] = ArrayPlate[8].scene;	ArrayVertex[23].res_type[2] = ArrayPlate[9].scene;
	ArrayVertex[24].res_type[0] = ArrayPlate[5].scene;	ArrayVertex[24].res_type[1] = ArrayPlate[9].scene;	ArrayVertex[24].res_type[2] = ArrayPlate[10].scene;
	ArrayVertex[25].res_type[0] = ArrayPlate[6].scene;	ArrayVertex[25].res_type[1] = ArrayPlate[10].scene;	ArrayVertex[25].res_type[2] = ArrayPlate[11].scene;
	ArrayVertex[26].res_type[2] = ArrayPlate[11].scene;
	ArrayVertex[27].res_type[2] = ArrayPlate[7].scene;
	ArrayVertex[28].res_type[0] = ArrayPlate[7].scene;	ArrayVertex[28].res_type[1] = ArrayPlate[8].scene;	ArrayVertex[28].res_type[2] = ArrayPlate[12].scene;
	ArrayVertex[29].res_type[0] = ArrayPlate[8].scene;	ArrayVertex[29].res_type[1] = ArrayPlate[9].scene;	ArrayVertex[29].res_type[2] = ArrayPlate[13].scene;
	ArrayVertex[30].res_type[0] = ArrayPlate[9].scene;	ArrayVertex[30].res_type[1] = ArrayPlate[10].scene;	ArrayVertex[30].res_type[2] = ArrayPlate[14].scene;
	ArrayVertex[31].res_type[0] = ArrayPlate[10].scene;	ArrayVertex[31].res_type[1] = ArrayPlate[11].scene;	ArrayVertex[31].res_type[2] = ArrayPlate[15].scene;
	ArrayVertex[32].res_type[2] = ArrayPlate[11].scene;
	ArrayVertex[33].res_type[1] = ArrayPlate[7].scene;	ArrayVertex[33].res_type[2] = ArrayPlate[12].scene;
	ArrayVertex[34].res_type[0] = ArrayPlate[8].scene;	ArrayVertex[34].res_type[1] = ArrayPlate[12].scene;	ArrayVertex[34].res_type[2] = ArrayPlate[13].scene;
	ArrayVertex[35].res_type[0] = ArrayPlate[9].scene;	ArrayVertex[35].res_type[1] = ArrayPlate[13].scene;	ArrayVertex[35].res_type[2] = ArrayPlate[14].scene;
	ArrayVertex[36].res_type[0] = ArrayPlate[10].scene;	ArrayVertex[36].res_type[1] = ArrayPlate[14].scene;	ArrayVertex[36].res_type[2] = ArrayPlate[15].scene;
	ArrayVertex[37].res_type[1] = ArrayPlate[11].scene;	ArrayVertex[37].res_type[2] = ArrayPlate[15].scene;
	ArrayVertex[38].res_type[2] = ArrayPlate[12].scene;
	ArrayVertex[39].res_type[0] = ArrayPlate[12].scene;	ArrayVertex[39].res_type[1] = ArrayPlate[13].scene;	ArrayVertex[39].res_type[2] = ArrayPlate[16].scene;
	ArrayVertex[40].res_type[0] = ArrayPlate[13].scene;	ArrayVertex[40].res_type[1] = ArrayPlate[14].scene;	ArrayVertex[40].res_type[2] = ArrayPlate[17].scene;
	ArrayVertex[41].res_type[0] = ArrayPlate[14].scene;	ArrayVertex[41].res_type[1] = ArrayPlate[15].scene;	ArrayVertex[41].res_type[2] = ArrayPlate[18].scene;
	ArrayVertex[42].res_type[2] = ArrayPlate[15].scene;
	ArrayVertex[43].res_type[1] = ArrayPlate[12].scene;	ArrayVertex[43].res_type[2] = ArrayPlate[16].scene;
	ArrayVertex[44].res_type[0] = ArrayPlate[13].scene;	ArrayVertex[44].res_type[1] = ArrayPlate[16].scene;	ArrayVertex[44].res_type[2] = ArrayPlate[17].scene;
	ArrayVertex[45].res_type[0] = ArrayPlate[14].scene;	ArrayVertex[45].res_type[1] = ArrayPlate[17].scene;	ArrayVertex[45].res_type[2] = ArrayPlate[18].scene;
	ArrayVertex[46].res_type[1] = ArrayPlate[15].scene;	ArrayVertex[46].res_type[2] = ArrayPlate[18].scene;
	ArrayVertex[47].res_type[2] = ArrayPlate[16].scene;
	ArrayVertex[48].res_type[1] = ArrayPlate[16].scene;	ArrayVertex[48].res_type[2] = ArrayPlate[17].scene;
	ArrayVertex[49].res_type[1] = ArrayPlate[17].scene;	ArrayVertex[49].res_type[2] = ArrayPlate[18].scene;
	ArrayVertex[50].res_type[2] = ArrayPlate[18].scene;
	ArrayVertex[51].res_type[2] = ArrayPlate[16].scene;
	ArrayVertex[52].res_type[2] = ArrayPlate[17].scene;
	ArrayVertex[53].res_type[2] = ArrayPlate[18].scene;
    
	//init Line
	int32_t line_type0[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 18, 19, 23, 24, 33, 34, 39, 40, 49, 50, 54, 55, 62, 63, 66, 67, 68, 69, 70, 71, 72};
	int32_t line_type1[] = {8, 9, 12, 13, 14, 15, 16, 17, 20, 21, 22, 25, 26, 27, 28, 29, 30, 31, 32, 35, 36, 37, 38, 41, 42, 43, 44, 45, 46, 47, 48, 51, 52, 53, 56, 57, 58, 59, 60, 61, 64, 65};
	for(int32_t i = 0; i < sizeof( line_type0 ) / sizeof( line_type0[0] ); i++)
	{
		ArrayLine[ line_type0[i] - 1 ].type = 0;
	}
	for(int32_t i = 0; i < sizeof( line_type1 ) / sizeof( line_type1[0] ); i++)
	{
		ArrayLine[ line_type1[i] - 1 ].type = 1;
	}

	return;
}