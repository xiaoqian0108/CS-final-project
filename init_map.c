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
		for(int32_t j = 0; j < 3; j++)
		{
			ArrayPlayer[i].building[j] = 0;
		}
		for(int32_t j = 0; j < 2; j++)
		{
			ArrayPlayer[i].special[j] = 0;
		}	
	}

	return;
}


//我有稍微改一下編號，跟line上傳的不太一樣，我把點、邊、板塊都從0開始編，這樣大家可能寫他們的陣列時比較值觀(第幾個陣列的元素就是地圖上的編號幾)
void init_map( Plate *ArrayPlate )
{
	//Line 1
	printf("            ");
	for(int32_t i = 0; i < 3; i++)
	{
		printf("\033[0;32m%02d\033[m      ", i);
	}
	printf("      \n");

	//Line 2
	printf("          ");
	for(int32_t i = 0; i < 6; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
	}
	printf("        \n");

	//Line 3
	printf("        ");
	for(int32_t i = 3; i < 7; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("  \n");
	
	//Line 4
	printf("        ");
	for(int32_t i = 6; i < 9; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
		printf("%02d", ArrayPlate[i - 6].res_num);
		printf("  ");
	}
	printf("\033[0;33m09\033[m");
	printf("        \n");

	//Line 5
	printf("        ");
	for(int32_t i = 7; i < 11; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("  \n");

	//Line 6
	printf("      ");
	for(int32_t i = 10; i < 18; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
	}
	printf("    \n");
	
	//Line 7
	printf("    ");
	for(int32_t i = 11; i < 15; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("\033[0;32m15\033[m    \n");
	
	//Line 8
	printf("    ");
	for(int32_t i = 18; i < 22; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
		printf("%02d", ArrayPlate[i - 15].res_num);
		printf("  ");
	}
	printf("\033[0;33m22\033[m    \n");

	//Line 9
	printf("    ");
	for(int32_t i = 16; i < 20; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("\033[0;32m20\033[m    \n");

	//Line 10
	printf("  ");
	for(int32_t i = 23; i < 33; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
	}
	printf("\n");

	//Line 11
	for(int32_t i = 21; i < 26; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("\033[0;32m26\033[m\n");

	//Line 12
	for(int32_t i = 33; i < 38; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
		printf("%02d", ArrayPlate[i - 26].res_num);
		printf("  ");
	}
	printf("\033[0;33m38\033[m\n");

	//Line 13
	for(int32_t i = 27; i < 32; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("\033[0;32m32\033[m\n");

	//Line 14
	printf("  ");
	for(int32_t i = 39; i < 49; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
	}
	printf("\n");

	//Line 15
	printf("    ");
	for(int32_t i = 33; i < 37; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("\033[0;32m37\033[m    \n");

	//Line 16
	printf("    ");
	for(int32_t i = 49; i < 53; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
		printf("%02d", ArrayPlate[i - 37].res_num);
		printf("  ");
	}
	printf("\033[0;33m53\033[m    \n");

	//Line 17
	printf("    ");
	for(int32_t i = 38; i < 42; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("\033[0;32m42\033[m    \n");

	//Line 18
	printf("      ");
	for(int32_t i = 54; i < 62; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
	}
	printf("    \n");

	//Line 19
	printf("        ");
	for(int32_t i = 43; i < 47; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("  \n");

	//Line 20
	printf("        ");
	for(int32_t i = 62; i < 65; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
		printf("%02d", ArrayPlate[i - 46].res_num);
		printf("  ");
	}
	printf("\033[0;33m65\033[m        \n");

	//Line 21
	printf("        ");
	for(int32_t i = 47; i < 50; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("  \n");

	//Line 22
	printf("          ");
	for(int32_t i = 66; i < 72; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
	}
	printf("        \n");

	//Line 23
	printf("            ");
	for(int32_t i = 51; i < 54; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("      \n");

	return;
}