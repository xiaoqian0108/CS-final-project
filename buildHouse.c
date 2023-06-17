#include <stdio.h>
#include <stdint.h>
#include "map.h"
#include "build.h"
#include "time.h"

void build_house( int32_t player, int32_t house, Plate *ArrayPlate, Vertex *ArrayVertex, Line *ArrayLine, Player *ArrayPlayer ) //1:village, 2:city
{
	int32_t vertex_neighbor[54][3] = { 
	{0, 1, 0},
	{2, 3, 0},
	{4, 5, 0},
	{0, 6, 0},
	{1, 2, 7},
	{3, 4, 8},
	{5, 9, 0},
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

	int32_t line_neighbor[72][2] = {0};

	for( int32_t i = 0; i < 6; i++ )
	{
		line_neighbor[i][0] = i / 2;
		line_neighbor[i][1] = (i + 1) / 2 + 3;
	}
	for( int32_t i = 6; i < 10; i++ )
	{
		line_neighbor[i][0] = i - 3;
		line_neighbor[i][1] = i + 1;
	}
	for( int32_t i = 10; i < 18; i++ )
	{
		line_neighbor[i][0] = i / 2 + 2;
		line_neighbor[i][1] = (i + 1) / 2 + 6;
	}
	for( int32_t i = 18; i < 23; i++ )
	{
		line_neighbor[i][0] = i - 7;
		line_neighbor[i][1] = i - 2;
	}
	for( int32_t i = 23; i < 33; i++ )
	{
		line_neighbor[i][0] = (i + 1) / 2 + 4;
		line_neighbor[i][1] = i / 2 + 10;
	}
	for( int32_t i = 33; i < 39; i++ )
	{
		line_neighbor[i][0] = i - 12;
		line_neighbor[i][1] = i - 6;
	}
	for( int32_t i = 39; i < 49; i++ )
	{
		line_neighbor[i][0] = i / 2 + 8;
		line_neighbor[i][1] = (i + 1) / 2 + 13;
	}
	for( int32_t i = 49; i < 54; i++ )
	{
		line_neighbor[i][0] = i - 16;
		line_neighbor[i][1] = i - 11;
	}
	for( int32_t i = 54; i < 62; i++ )
	{
		line_neighbor[i][0] = (i + 1) / 2 + 11;
		line_neighbor[i][1] = i / 2 + 16;
	}
	for( int32_t i = 62; i < 66; i++ )
	{
		line_neighbor[i][0] = i - 19;
		line_neighbor[i][1] = i - 15;
	}
	for( int32_t i = 66; i < 72; i++ )
	{
		line_neighbor[i][0] = (i + 1) / 2 + 14;
		line_neighbor[i][1] = i / 2 + 18;
	}

	if( house == 1 )
	{
		if( ArrayPlayer[player - 1].resource[4] == 0 || ArrayPlayer[player - 1].resource[1] == 0 || ArrayPlayer[player - 1].resource[0] == 0 || ArrayPlayer[player - 1].resource[2] == 0 )
		{
			printf("Your resources are insufficient! \n");
			return;
		}
	}

	if( house == 1 )
	{
		int32_t buildvillage_num = 0;

		init_map( ArrayPlate );
		map( ArrayPlate, ArrayVertex, ArrayLine );
		
		int32_t test = 0;
		int32_t NotBulid = 0;

		while( NotBulid == 0 )
		{
			printf("Which one do you want to build village ? \n");
			printf("Please enter: ");
			scanf("%d", &buildvillage_num);

			if( vertex_neighbor[buildvillage_num][2] == 0 )
			{	
				if( ArrayLine[ vertex_neighbor[buildvillage_num][0] ].road != player && ArrayLine[ vertex_neighbor[buildvillage_num][1] ].road != player )
				{
					printf("This point cannot be covered !\n");
					continue;
				}
			}
			else
			{
				if( ArrayLine[ vertex_neighbor[buildvillage_num][0] ].road != player && ArrayLine[ vertex_neighbor[buildvillage_num][1] ].road != player 
					&& ArrayLine[ vertex_neighbor[buildvillage_num][2] ].road != player )
				{
					printf("This point cannot be covered !\n");
					continue;
				}
			}
			

			for(int32_t i = 0; i < 3; i++)
			{
				if( i == 2 && vertex_neighbor[buildvillage_num][i] == 0)
				{
					continue;
				}
				else
				{
					int32_t adjacentline = vertex_neighbor[buildvillage_num][i];
					test = (line_neighbor[adjacentline][0] != buildvillage_num) ? line_neighbor[adjacentline][0] : buildvillage_num;
					if( ArrayVertex[test].village != 0 || ArrayVertex[test].city != 0 )
					{
						NotBulid = 1;
					}
				}
			}
			if( NotBulid == 1)
			{
				NotBulid = 0;
				printf("This point cannot be covered !\n");
			}
			else
			NotBulid = 2;
		}

		ArrayVertex[ buildvillage_num ].village == player;
		ArrayPlayer[player - 1].resource[4]--;
		ArrayPlayer[player - 1].resource[1]--;
		ArrayPlayer[player - 1].resource[0]--;
		ArrayPlayer[player - 1].resource[2]--;
		ArrayPlayer[player - 1].building[1]++;
	}


	if( house == 2 )
	{
		if( ArrayPlayer[player - 1].resource[3] < 3 || ArrayPlayer[player - 1].resource[0] < 2 )
		{
			printf("Your resources are insufficient! \n");
			return;
		}
	}
	if( house == 2 )
	{
		int32_t buildcity_num = 0;

		init_map( ArrayPlate );
		map( ArrayPlate, ArrayVertex, ArrayLine );
		printf("Which one do you want to build city ? \n");
		printf("Please enter: ");
		scanf("%d", &buildcity_num);

		ArrayVertex[buildcity_num].village = 0;
		ArrayVertex[buildcity_num].city = player;

		ArrayPlayer[player - 1].resource[3] = ArrayPlayer[player - 1].resource[3] - 3;
		ArrayPlayer[player - 1].resource[0] = ArrayPlayer[player - 1].resource[0] - 2;
		ArrayPlayer[player - 1].building[2]++;
	}


	return;
}