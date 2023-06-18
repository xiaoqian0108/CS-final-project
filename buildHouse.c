#include <stdio.h>
#include <stdint.h>
#include "map.h"
#include "build.h"
#include "time.h"

void build_house( int32_t player, int32_t init, int32_t house, Plate *ArrayPlate, Vertex *ArrayVertex, Line *ArrayLine, Player *ArrayPlayer ) //1:village, 2:city
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




	if( init == 1 )
	{
		if( player == 0)
		{
			int32_t buildvillage_num = 0;
			int32_t buildroad_num = 0;
			int32_t NotBulid_init = 0;

			while( NotBulid_init == 0 )
			{
				init_map( ArrayPlate );
				map( ArrayPlate, ArrayVertex, ArrayLine );
				printf("Which one do you want to build village ? \n");
				printf("Please enter: ");
				scanf("%d", &buildvillage_num);

				for(int32_t i = 0; i < 3; i++)
				{
					if( i == 2 && vertex_neighbor[buildvillage_num][i] == 0)
					{
						continue;
					}
					else
					{
						int32_t adjacentline = vertex_neighbor[buildvillage_num][i];
						int32_t test = (line_neighbor[adjacentline][0] != buildvillage_num) ? line_neighbor[adjacentline][0] : buildvillage_num;
						if( ArrayVertex[test].village != 0 || ArrayVertex[test].city != 0 )
						{
							NotBulid_init = 1;
						}
					}
				}
				if( NotBulid_init == 1 || ArrayVertex[buildvillage_num].village != 0 || ArrayVertex[buildvillage_num].city != 0 )
				{
					NotBulid_init = 0;
					printf("This point cannot be covered !!!\n");
				}
				else
				NotBulid_init = 2;
			}
	
			ArrayVertex[buildvillage_num].village = 1;
			ArrayPlayer[player].building[1]--;

			printf("Which one do you want to build road ? \n");
			printf("You can only choose ");
			for(int32_t i = 0; i < 3; i++)
			{
				if(i == 2 && vertex_neighbor[buildvillage_num][2] == 0)
				{
					continue;
				}
				else
				{
					printf("%d ", vertex_neighbor[buildvillage_num][i]);
				}
			}
			printf("\n");
			printf("Please enter: ");
			scanf("%d", &buildroad_num);
			ArrayLine[buildroad_num].road = 1;
			ArrayPlayer[player].building[0]--;
		}
		else if( player == 1 || player == 2 || player == 3 )
		{
			srand( time(0) );
			int32_t site = 0;

			do 
			{
		    	site = rand() % 54;
			} 
			while (ArrayVertex[site].village != 0);

			ArrayVertex[site].village = player + 1;
			ArrayPlayer[player].building[1]--;

			int32_t siteRoad = 0;
			if( vertex_neighbor[site][2] == 0 )
			{
				siteRoad = rand() % 2;
			}
			else
			{
				siteRoad = rand() % 3;
			}
			int32_t road = vertex_neighbor[site][siteRoad];
			ArrayLine[road].road = player + 1;
			ArrayPlayer[player].building[0]--;
		}
	}
	else
	{
		if( player == 0 )
		{
			if( house == 1 )
			{
				if( ArrayPlayer[player].resource[4] == 0 || ArrayPlayer[player].resource[1] == 0 || ArrayPlayer[player].resource[0] == 0 || ArrayPlayer[player].resource[2] == 0 )
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
						if( ArrayLine[ vertex_neighbor[buildvillage_num][0] ].road != player + 1 && ArrayLine[ vertex_neighbor[buildvillage_num][1] ].road != player + 1 )
						{
							printf("This point cannot be covered ?!\n");
							continue;
						}
					}
					else
					{
						if( ArrayLine[ vertex_neighbor[buildvillage_num][0] ].road != player + 1 && ArrayLine[ vertex_neighbor[buildvillage_num][1] ].road != player + 1
							&& ArrayLine[ vertex_neighbor[buildvillage_num][2] ].road != player + 1 )
						{
							printf("This point cannot be covered !!\n");
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
						printf("This point cannot be covered !!!\n");
					}
					else
					NotBulid = 2;
				}

				ArrayVertex[ buildvillage_num ].village == player + 1;
				ArrayPlayer[player].resource[4]--;
				ArrayPlayer[player].resource[1]--;
				ArrayPlayer[player].resource[0]--;
				ArrayPlayer[player].resource[2]--;
				ArrayPlayer[player].building[1]--;
			}


			if( house == 2 )
			{
				if( ArrayPlayer[player].resource[3] < 3 || ArrayPlayer[player].resource[0] < 2 )
				{
					printf("Your resources are insufficient! \n");
					return;
				}
			}
			if( house == 2 )
			{
				int32_t buildcity_num = 0;
				int32_t OK = 0;

				while( OK == 0 )
				{
					init_map( ArrayPlate );
					map( ArrayPlate, ArrayVertex, ArrayLine );
					printf("Which one do you want to build city ? \n");
					printf("Please enter: ");
					scanf("%d", &buildcity_num);

					if( ArrayVertex[buildcity_num].village == player + 1 )
					{
						ArrayVertex[buildcity_num].village = 0;
						ArrayVertex[buildcity_num].city = player + 1;
						ArrayPlayer[player].building[1]++;
						ArrayPlayer[player].building[2]--;

						ArrayPlayer[player].resource[3] = ArrayPlayer[player].resource[3] - 3;
						ArrayPlayer[player].resource[0] = ArrayPlayer[player].resource[0] - 2;
						OK = 1;
					}
					else
					{
						printf("This point cannot be covered !\n");
					}
				}
			}
		}

		if( player == 1 || player == 2 || player == 3 )
		{
			if( house == 1 )
			{
				srand( time(0) );
				int32_t site = 0;
				int32_t choose_ver1 = 0;
				int32_t choose_ver2 = 0;
				int32_t ver = 0;

				while( choose_ver1 == 0 && choose_ver2 == 0 )
				{
					do 
					{
						site = rand() % 72;
					} 
					while (ArrayLine[site].road != player + 1);

					
					for(int32_t i = 0; i < 2; i++)
					{
						if( vertex_neighbor[ line_neighbor[site][i] ][2] == 0 )
						{
							for(int32_t j = 0; j < 2; j++)
							{
								int32_t line = vertex_neighbor[ line_neighbor[site][i] ][j];
								int32_t vertex = ( line_neighbor[line][0] != line_neighbor[site][i] ) ? line_neighbor[line][0] : line_neighbor[line][1];
								
								if( ArrayVertex[vertex].village == 0 && ArrayVertex[vertex].city == 0 )
								{
									if( i == 0 )
									{
										choose_ver1++; // 2代表這個點沒有東西
									}
									else if( i == 1 )
									{
										choose_ver2++;
									}
								}
							}

							if( choose_ver1 == 2 )
							{
								ver = line_neighbor[site][0];
							}
							else if( choose_ver2 == 2 )
							{
								ver = line_neighbor[site][1];
							}
						}
						else
						{
							for(int32_t j = 0; j < 3; j++)
							{
								int32_t line = vertex_neighbor[ line_neighbor[site][i] ][j];
								int32_t vertex = ( line_neighbor[line][0] != line_neighbor[site][i] ) ? line_neighbor[line][0] : line_neighbor[line][1];
								
								if( ArrayVertex[vertex].village == 0 && ArrayVertex[vertex].city == 0 )
								{
									if( i == 0 )
									{
										choose_ver1++; // 3代表這個點沒有東西
									}
									else if( i == 1 )
									{
										choose_ver2++;
									}
								}
							}
							if( choose_ver1 == 3 )
							{
								ver = line_neighbor[site][0];
							}
							else if( choose_ver2 == 3 )
							{
								ver = line_neighbor[site][1];
							}
							
						}
					}
				}

				ArrayVertex[ver].village = player + 1;
				ArrayPlayer[player].building[1]--;
			}

			int32_t citysite = 0;
			if( house == 2 )
			{
				do 
				{
					citysite = rand() % 54;
				} 
				while (ArrayVertex[citysite].village != player + 1);

				ArrayVertex[citysite].city = player + 1;
				ArrayVertex[citysite].village = 0;
				ArrayPlayer[player].building[1]++;
				ArrayPlayer[player].building[2]--;

				ArrayPlayer[player].resource[3] = ArrayPlayer[player].resource[3] - 3;
				ArrayPlayer[player].resource[0] = ArrayPlayer[player].resource[0] - 2;
			}
		}
	}

	return;
}


/*
    主函式要寫的大家剛開始蓋兩棟村莊，兩條路
    build_house( 0, 1, 0, ArrayPlate, ArrayVertex, ArrayLine, ArrayPlayer );
	build_house( 1, 1, 0, ArrayPlate, ArrayVertex, ArrayLine, ArrayPlayer );
	build_house( 2, 1, 0, ArrayPlate, ArrayVertex, ArrayLine, ArrayPlayer );
	build_house( 3, 1, 0, ArrayPlate, ArrayVertex, ArrayLine, ArrayPlayer );
	
	build_house( 3, 1, 0, ArrayPlate, ArrayVertex, ArrayLine, ArrayPlayer );
	build_house( 2, 1, 0, ArrayPlate, ArrayVertex, ArrayLine, ArrayPlayer );
	build_house( 1, 1, 0, ArrayPlate, ArrayVertex, ArrayLine, ArrayPlayer );
	build_house( 0, 1, 0, ArrayPlate, ArrayVertex, ArrayLine, ArrayPlayer );
*/