#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"

void init_struct( Plate *ArrayPlate, Vertex *ArrayVertex, Line *ArrayLine, Player *ArrayPlayer )
{
	//init Plate
	for(int32_t i = 0; i < 19; i++)
	{
		ArrayPlate[i].bandit = 0;
	}
	ArrayPlate[15].bandit = 1;

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
			ArrayPlate[i].scene = 0;
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

	for(int32_t i = 0; i < 54; i++)
	{
		ArrayVertex[i].village = 0;
		ArrayVertex[i].city = 0;
		ArrayVertex[i].port = 0;
		for(int32_t j = 0; j < 3; j++)
		{
			ArrayVertex[i].res_type[j] = 0;
		}
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
	ArrayVertex[5].res_type[1] = ArrayPlate[1].scene;	ArrayVertex[5].res_type[2] = ArrayPlate[2].scene;
	ArrayVertex[6].res_type[2] = ArrayPlate[2].scene;
	ArrayVertex[7].res_type[1] = ArrayPlate[0].scene;	ArrayVertex[7].res_type[2] = ArrayPlate[3].scene;
	ArrayVertex[8].res_type[0] = ArrayPlate[0].scene;	ArrayVertex[8].res_type[1] = ArrayPlate[1].scene;	ArrayVertex[8].res_type[2] = ArrayPlate[4].scene;
	ArrayVertex[9].res_type[0] = ArrayPlate[1].scene;	ArrayVertex[9].res_type[1] = ArrayPlate[2].scene;	ArrayVertex[9].res_type[2] = ArrayPlate[5].scene;
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
	for(int32_t i = 0; i < 72; i++)
	{
		ArrayLine[i].type = 0;
		ArrayLine[i].road = 0;
	}

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
	

	//init Player
	for(int32_t i = 0; i < 4; i++)
	{
		for(int32_t j = 0; j < 5; j++)
		{
			ArrayPlayer[i].resource[j] = 0;
			ArrayPlayer[i].develop[j] = 0;
			ArrayPlayer[i].new_deve[j] = 0;
		}
		ArrayPlayer[i].building[0] = 15;
		ArrayPlayer[i].building[1] = 5;
		ArrayPlayer[i].building[2] = 4;
		for(int32_t j = 0; j < 2; j++)
		{
			ArrayPlayer[i].special[j] = 0;
		}	
	}

	ArrayVertex[0].village = 4;
	//ArrayVertex[1].village = 4;
	ArrayVertex[4].village = 1;
	ArrayLine[2].road = 1;
	ArrayLine[7].road = 1;
	//ArrayLine[28].road = 1;
	//ArrayLine[35].road = 1;
	return;
}

void init_plate ( Plate *pPlate )
{
    pPlate[0].res_num = 4;
    pPlate[0].scene = 1;
    pPlate[0].bandit = 0;
    pPlate[1].res_num = 11;
    pPlate[1].scene = 2;
    pPlate[1].bandit = 0;
    pPlate[2].res_num = 12;
    pPlate[2].scene = 3;
    pPlate[2].bandit = 0;
    pPlate[3].res_num = 8;
    pPlate[3].scene = 4;
    pPlate[3].bandit = 0;
    pPlate[4].res_num = 3;
    pPlate[4].scene = 5;
    pPlate[4].bandit = 0;
    pPlate[5].res_num = 6;
    pPlate[5].scene = 1;
    pPlate[5].bandit = 0;
    pPlate[6].res_num = 9;
    pPlate[6].scene = 2;
    pPlate[6].bandit = 0;
    pPlate[7].res_num = 5;
    pPlate[7].scene = 3;
    pPlate[7].bandit = 0;
    pPlate[8].res_num = 10;
    pPlate[8].scene = 4;
    pPlate[8].bandit = 0;
    pPlate[9].res_num = 11;
    pPlate[9].scene = 5;
    pPlate[9].bandit = 0;
    pPlate[10].res_num = 5;
    pPlate[10].scene = 1;
    pPlate[10].bandit = 0;
    pPlate[11].res_num = 10;
    pPlate[11].scene = 2;
    pPlate[11].bandit = 0;
    pPlate[12].res_num = 2;
    pPlate[12].scene = 3;
    pPlate[12].bandit = 0;
    pPlate[13].res_num = 9;
    pPlate[13].scene = 4;
    pPlate[13].bandit = 0;
    pPlate[14].res_num = 4;
    pPlate[14].scene = 5;
    pPlate[14].bandit = 0;
    pPlate[15].res_num = 0;
    pPlate[15].scene = 6;
    pPlate[15].bandit = 1;
    pPlate[16].res_num = 6;
    pPlate[16].scene = 1;
    pPlate[16].bandit = 0;
    pPlate[17].res_num = 3;
    pPlate[17].scene = 2;
    pPlate[17].bandit = 0;
    pPlate[18].res_num = 8;
    pPlate[18].scene = 3;
    pPlate[18].bandit = 0;

    /*
    // print
    for( int32_t i = 0; i < 19; i++ )
    {
        printf( "Plate %d:  ", i+1 );
        printf( "Resource Number: %d  ", pPlate[i].res_num );
        printf( "Scene: %d  ", pPlate[i].scene );
        printf( "Bandit: %d  ", pPlate[i].bandit );
        printf( "\n" );
    }
    */
}

void init_player( Player *pPlayer )
{
    // Player 1
    pPlayer[0].resource[0] = 0;
    pPlayer[0].resource[1] = 1;
    pPlayer[0].resource[2] = 2;
    pPlayer[0].resource[3] = 3;
    pPlayer[0].resource[4] = 4;
    pPlayer[0].building[0] = 0;
    pPlayer[0].building[1] = 0;
    pPlayer[0].building[2] = 0;
    pPlayer[0].develop[0] = 2;
    pPlayer[0].develop[1] = 1;
    pPlayer[0].develop[2] = 1;
    pPlayer[0].develop[3] = 1;
    pPlayer[0].develop[4] = 2;
    pPlayer[0].new_deve[0] = 0;
    pPlayer[0].new_deve[1] = 0;
    pPlayer[0].new_deve[2] = 0;
    pPlayer[0].new_deve[3] = 0;
    pPlayer[0].new_deve[4] = 0;
    pPlayer[0].special[0] = 0;
    pPlayer[0].special[1] = 0;

    // Player 2
    pPlayer[1].resource[0] = 3;
    pPlayer[1].resource[1] = 2;
    pPlayer[1].resource[2] = 1;
    pPlayer[1].resource[3] = 2;
    pPlayer[1].resource[4] = 3;
    pPlayer[1].building[0] = 0;
    pPlayer[1].building[1] = 0;
    pPlayer[1].building[2] = 0;
    pPlayer[1].develop[0] = 3;
    pPlayer[1].develop[1] = 1;
    pPlayer[1].develop[2] = 1;
    pPlayer[1].develop[3] = 0;
    pPlayer[1].develop[4] = 1;
    pPlayer[1].new_deve[0] = 0;
    pPlayer[1].new_deve[1] = 0;
    pPlayer[1].new_deve[2] = 0;
    pPlayer[0].new_deve[3] = 0;
    pPlayer[0].new_deve[4] = 0;
    pPlayer[1].special[0] = 0;
    pPlayer[1].special[1] = 0;

    // Player 3
    pPlayer[2].resource[0] = 2;
    pPlayer[2].resource[1] = 1;
    pPlayer[2].resource[2] = 1;
    pPlayer[2].resource[3] = 1;
    pPlayer[2].resource[4] = 2;
    pPlayer[2].building[0] = 0;
    pPlayer[2].building[1] = 0;
    pPlayer[2].building[2] = 0;
    pPlayer[2].develop[0] = 2;
    pPlayer[2].develop[1] = 0;
    pPlayer[2].develop[2] = 0;
    pPlayer[2].develop[3] = 1;
    pPlayer[2].develop[4] = 1;
    pPlayer[2].new_deve[0] = 0;
    pPlayer[2].new_deve[1] = 0;
    pPlayer[2].new_deve[2] = 0;
    pPlayer[0].new_deve[3] = 0;
    pPlayer[0].new_deve[4] = 0;
    pPlayer[2].special[0] = 0;
    pPlayer[2].special[1] = 0;

    // Player 4
    pPlayer[3].resource[0] = 0;
    pPlayer[3].resource[1] = 3;
    pPlayer[3].resource[2] = 2;
    pPlayer[3].resource[3] = 1;
    pPlayer[3].resource[4] = 0;
    pPlayer[3].building[0] = 0;
    pPlayer[3].building[1] = 0;
    pPlayer[3].building[2] = 0;
    pPlayer[2].develop[0] = 1;
    pPlayer[2].develop[1] = 0;
    pPlayer[2].develop[2] = 1;
    pPlayer[2].develop[3] = 0;
    pPlayer[2].develop[4] = 2;
    pPlayer[3].new_deve[0] = 0;
    pPlayer[3].new_deve[1] = 0;
    pPlayer[3].new_deve[2] = 0;
    pPlayer[0].new_deve[3] = 0;
    pPlayer[0].new_deve[4] = 0;
    pPlayer[3].special[0] = 0;
    pPlayer[3].special[1] = 0;
}


int determine_road( Line *pLine, Vertex *pVertex, Player *pPlayer, int32_t turn, int32_t bank_rec[])
{
	int32_t i, j;
    int32_t line_and_line_neighbor[72][4] = {
		{1, 6, -1, -1},    	
		{0, 2, 7, -1}, 
    	{1, 7, 3, -1},
    	{2, 4, 8, -1}, 
    	{3, 5, 8, -1},
    	{4, 9, -1, -1},
    	{0, 10, 11, -1},
    	{1, 2, 12, 13},
    	{3, 4, 14, 15},
    	{5, 16, 17, -1},
    	{6, 11, 18, -1},
    	{6, 10, 12, 19},
    	{7, 11, 13, 19},
    	{7, 12, 14, 20},
    	{8, 13, 15, 20},
    	{8, 14, 16, 21},
    	{9, 17, 21, -1},
    	{9, 16, 22, -1},
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

    int32_t line_neighbor[72][2] = {0};
	for( i = 0; i < 6; i++ )
	{
		line_neighbor[i][0] = i / 2;
		line_neighbor[i][1] = (i + 1) / 2 + 3;
	}
	for( i = 6; i < 10; i++ )
	{
		line_neighbor[i][0] = i - 3;
		line_neighbor[i][1] = i + 1;
	}
	for( i = 10; i < 18; i++ )
	{
		line_neighbor[i][0] = i / 2 + 2;
		line_neighbor[i][1] = (i + 1) / 2 + 6;
	}
	for( i = 18; i < 23; i++ )
	{
		line_neighbor[i][0] = i - 7;
		line_neighbor[i][1] = i - 2;
	}
	for( i = 23; i < 33; i++ )
	{
		line_neighbor[i][0] = (i + 1) / 2 + 4;
		line_neighbor[i][1] = i / 2 + 10;
	}
	for( i = 33; i < 39; i++ )
	{
		line_neighbor[i][0] = i - 12;
		line_neighbor[i][1] = i - 6;
	}
	for( i = 39; i < 49; i++ )
	{
		line_neighbor[i][0] = i / 2 + 8;
		line_neighbor[i][1] = (i + 1) / 2 + 13;
	}
	for( i = 49; i < 54; i++ )
	{
		line_neighbor[i][0] = i - 16;
		line_neighbor[i][1] = i - 11;
	}
	for( i = 54; i < 62; i++ )
	{
		line_neighbor[i][0] = (i + 1) / 2 + 11;
		line_neighbor[i][1] = i / 2 + 16;
	}
	for( i = 62; i < 66; i++ )
	{
		line_neighbor[i][0] = i - 19;
		line_neighbor[i][1] = i - 15;
	}
	for( i = 66; i < 72; i++ )
	{
		line_neighbor[i][0] = (i + 1) / 2 + 14;
		line_neighbor[i][1] = i / 2 + 18;
	}

	int32_t village[10] = {-1}, villages = 0, own_roads[15], roads = 0, available = 0, available_road[72] = {-1};
	for(i = 0; i <= 71; i++)
	{
		if( i <= 53 && (pVertex[i].village == turn + 1 || pVertex[i].city == turn + 1) )
		{
			village[villages] = i;
			villages++;
		}
		
		if( pLine[i].road == turn + 1 )
		{
			own_roads[roads] = i;
			roads++;
		}
	}
	for(i = 0; i < villages; i++)
	{
		for(j = 0; j < 72; j++)
		{
			if( pLine[j].road == 0 && (line_neighbor[j][0] == village[i] || line_neighbor[j][1] == village[i]) )
			{
				available_road[j] = 1;
				available++;
			}
		}
	}
	int32_t n, m, common_vertex = -1;
	for( i = 0; i < roads; i++ )
	{
		for( j = 0; j < 4; j++ )
		{
			n = own_roads[i], m = line_and_line_neighbor[n][j];
			if( m != -1 && pLine[m].road == 0 )
			{
				if(line_neighbor[n][0] == line_neighbor[m][0])
				{
					common_vertex = line_neighbor[n][0];
				}
				else if(line_neighbor[n][0] == line_neighbor[m][1])
				{
					common_vertex = line_neighbor[n][0];
				}
				else if(line_neighbor[n][1] == line_neighbor[m][0])
				{
					common_vertex = line_neighbor[n][1];
				}
				else if(line_neighbor[n][1] == line_neighbor[m][1])
				{
					common_vertex = line_neighbor[n][1];
				}
				if(common_vertex != -1 && pVertex[common_vertex].village == 0 && pVertex[common_vertex].city == 0)
				{
					available_road[m] = 1;
					available++;
				}
			}
		}
	}
	if(available == 0)
	{
		printf("There is no place you can build a road!\n");
		return 0;
	}
	else {
		printf("The place where you can build the road:");
		for(i = 0; i < 72; i++)
		{
			if(available_road[i] == 1)
			{
				printf(" \x1b[31m%d\x1b[0m", i);
			}
		}
		printf("\n");
	}
	int32_t build_this_place = 99;
	while(1)
	{
		printf("Where would you like to build your road (If cancel: -1)?\n");
		scanf("%d", &build_this_place);
		if(build_this_place == -1)
		{
			return 0;
		}
		else if(available_road[build_this_place] == 1)
		{
			break;
		}
		else {
			printf("This place is not available!!!\n");
		}
	}
	int32_t road_no = build_this_place;
	pLine[build_this_place].road = turn + 1;
	pPlayer[turn].resource[1]--;
    pPlayer[turn].resource[4]--;
    bank_rec[1]++;
    bank_rec[4]++;
    printf("Success to build the road on %d\n", build_this_place);
	printf("\nPlayer %d's resources:" , 1);
	printf("wheat: \x1b[31m%d\x1b[0m", pPlayer[turn].resource[0]);
	printf(", wood: \x1b[31m%d\x1b[0m", pPlayer[turn].resource[1]);
	printf(", wool: \x1b[31m%d\x1b[0m", pPlayer[turn].resource[2]);
	printf(", ore: \x1b[31m%d\x1b[0m", pPlayer[turn].resource[3]);
	printf(", brick: \x1b[31m%d\x1b[0m", pPlayer[turn].resource[4]);
	printf("\n");
    printf("\n");
    

	return 0;
}

void build_road(Line *pLine, Plate *pPlate, Vertex *pVertex, Player *pPlayer, int32_t turn, int32_t bank_rec[] )
{
    int32_t road_NO = 0;
    printf("pLine[3].road = %d\n", pLine[3].road);

    if( pPlayer[0].resource[1] < 1 || pPlayer[0].resource[4] < 1 )
    {
        printf( "You don't have enough resources.\n" );
        return;
    }

    determine_road(pLine, pVertex, pPlayer, turn, bank_rec);
    while(1){
    	printf( "Would you continue to build?(Y/N)\n" );
    }
    
}

int main()
{
	Player ArrayPlayer[4];
	Plate ArrayPlate[19];
	Vertex ArrayVertex[53];
	Line ArrayLine[72];
	int32_t bank_rec[5] = {19};
	int32_t turn = 0;
	//init_plate( ArrayPlate );
	init_struct( ArrayPlate, ArrayVertex, ArrayLine, ArrayPlayer );
	init_player( ArrayPlayer );
	build_road(ArrayLine, ArrayPlate, ArrayVertex, ArrayPlayer, turn, bank_rec );
	printf("Bank resources:");
	printf("wheat: \x1b[31m%d\x1b[0m", bank_rec[0]);
	printf(", wood: \x1b[31m%d\x1b[0m", bank_rec[1]);
	printf(", wool: \x1b[31m%d\x1b[0m", bank_rec[2]);
	printf(", ore: \x1b[31m%d\x1b[0m", bank_rec[3]);
	printf(", brick: \x1b[31m%d\x1b[0m", bank_rec[4]);
	printf("\n");
    printf("\n");
}


