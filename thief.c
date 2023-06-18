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
	ArrayVertex[0].village = 4;
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

int isthief( Vertex *pVertex, Player *pPlayer, int32_t ary[], int32_t resource_NO, int32_t number[], int32_t turn )
{   
	int32_t i, j;
	
    int32_t p[4] = {0}, amount = 0, oneplayer, resource;
    for(i = 0; i < 6; i++)
    { 
    	if( pVertex[ary[i]].village != turn && pVertex[ary[i]].village > 0)
	    {
	        amount = 1;
	        break;
	    }
    }
    if(amount == 0)
    {
    	printf("There is no player!!!\n");
    	return -1;
    } 
    amount = 0;
    for(i = 0; i < 6; i++)
    { 
    	if( pVertex[ary[i]].village != turn && pVertex[ary[i]].village > 0)
	    {
	    	j = pVertex[ary[i]].village;
	    	printf("%d", j);
	        if(pPlayer[j - 1].resource[0] > 0 || pPlayer[j - 1].resource[1] > 0 || pPlayer[j - 1].resource[2] > 0 || pPlayer[j - 1].resource[3] > 0 || pPlayer[j - 1].resource[4] > 0)
	        {
	        	//printf("unko");
			    p[amount] = pVertex[ary[i]].village;
		        p[amount]--;
		        printf(" %d\n", p[amount]);
		        //Record how many players on the plate
		        amount++;
	    	}
	    }
    }

    if(amount == 0)
    {
    	printf("No players have resources!!!\n");
    	return -1;
    }
    //The case if there's only one player on the plate
    else if (amount == 1)
    {
    	for(i = 0; i < amount; i++){
	    	//printf("unko: %d\n", p[i]);
	    }
    	while(1)
    	{
    		//Randomly select the resource
    		srand(time(NULL));
    		int resource_NO = rand() % 5 + 1;

    		//Determine if the player has the resource, if so, reduce one resource.
    		//If not, randomly select the resource again
    		if(pPlayer[p[0]].resource[resource_NO - 1] > 0)
    		{
    			printf("player %d's bricks were taken away by player %d\n", p[0] + 1, turn + 1);
    			pPlayer[p[0]].resource[resource_NO - 1]--;

    			//Give recource to the player
    			pPlayer[turn].resource[resource_NO - 1]++;
    			break;
    		}
    	}

		//Print player's all resources.
	    for(i = 0; i < 4; i++)
	    {
	    	printf("Player %d's resources:\n" , i + 1);
			printf("grain: %d", pPlayer[i].resource[0]);
			printf(", lumbar: %d", pPlayer[i].resource[1]);
			printf(", wool: %d", pPlayer[i].resource[2]);
			printf(", ore: %d", pPlayer[i].resource[3]);
			printf(", brick: %d", pPlayer[i].resource[4]);
			printf("\n");
	    }
	    printf("\n");
	    printf("Resource remaining:\n");
	    printf("grain: %d", number[0]);
		printf(", lumbar: %d", number[1]);
		printf(", wool: %d", number[2]);
		printf(", ore: %d", number[3]);
		printf(", brick: %d", number[4]);
	    printf("\n");
    	
    }

    //The case if there're more than two players on the plate
    else if(amount > 1)
    {
    	if(turn == 0){
			printf("Which player? (");
	    	for(i = 0; i < amount; i++)
	    	{
	    		printf("%d", p[i] + 1);
	    		if(i != amount - 1)
	    		{
	    			printf(", ");
	    		}
	    	}
	    	printf(")\n");
	    	scanf("%d", &oneplayer);
	    	oneplayer--;
    	}
    	
    	else {
    		srand(time(NULL));
    		oneplayer = rand() % amount + 1;
    		oneplayer = p[oneplayer];
    	}


    	while(1)
    	{
    		//Randomly select the resource
    		srand(time(NULL));
    		int resource_NO = rand() % 5 + 1;
    		//Determine if the player has the resource, if so, reduce one resource.
    		//If not, randomly select the resource again
    		if(pPlayer[oneplayer].resource[resource_NO-1] > 0)
    		{
    			printf("player %d's bricks were taken away by player %d\n", oneplayer + 1, turn + 1);
    			pPlayer[oneplayer].resource[resource_NO-1]--;

    			//Give recource to the player
    			pPlayer[turn].resource[resource_NO - 1]++;
    			break;
    		}
	    }
	    
	    //Print player's all resources.
	    for(i = 0; i < 4; i++)
	    {
	    	printf("Player %d's resources:\n" , i + 1);
    		printf("grain: %d", pPlayer[i].resource[0]);
    		printf(", lumbar: %d", pPlayer[i].resource[1]);
			printf(", wool: %d", pPlayer[i].resource[2]);
			printf(", ore: %d", pPlayer[i].resource[3]);
    		printf(", brick: %d", pPlayer[i].resource[4]);
	    }
	    printf("\n");
	    printf("Resource remaining:\n");
	    printf("grain: %d", number[0]);
		printf(", lumbar: %d", number[1]);
		printf(", wool: %d", number[2]);
		printf(", ore: %d", number[3]);
		printf(", brick: %d", number[4]);
	    printf("\n");
	}
	return 0;
}

void thief(Plate *pPlate, Vertex *pVertex, Player *pPlayer, int32_t turn, int32_t bank_rec[])
{
	int32_t point, a, recent, i, j, cards;
	printf("The Robber!!!\n");
	for(i = 0; i < 4; i++)
	{
		cards = 0;
		for(j = 0; j < 5; j++)
		{
			cards += pPlayer[i].resource[j];
		}
		if(cards > 7 && i == 0)
		{
			int32_t half = cards / 2;
			int32_t count = 0, type, quantity;
			while(1)
			{
				printf("\nYou should throw %d cards.\n", half - count);
				//Print player's all resources.
				printf("Player %d's resources:\n" , 1);
				printf("grain: %d", pPlayer[0].resource[0]);
				printf(", lumbar: %d", pPlayer[0].resource[1]);
				printf(", wool: %d", pPlayer[0].resource[2]);
				printf(", ore: %d", pPlayer[0].resource[3]);
				printf(", brick: %d", pPlayer[0].resource[4]);
			    printf("\n");
				printf("\nPlease enter the type of card and quantity which you throw (Ex: 1, 2)\n");
				printf("1: grain, 2: lumbar, 3: wool, 4: ore, 5: brick\n");
				scanf("%d, %d", &type, &quantity);
				if(pPlayer[0].resource[type - 1] - quantity >= 0 && count + quantity <= half)
				{
					pPlayer[0].resource[type - 1] -= quantity;
					count += quantity;
					bank_rec[type - 1] += quantity;
				} else {
					printf("Please select again.\n");
					continue;
				}
				if(count == half)
				{
					printf("You throwed %d cards!\n", half);
					break;
				}
			}
		}
		if(cards > 7 && i > 0)
		{
			int32_t half = cards / 2;
			int32_t count = 0, type;
			printf("\nPlayer %d should throw %d cards.", i + 1, half);
			while(1)
			{
				srand(time(NULL));
    			int type = rand() % 5 + 1;
				if(pPlayer[0].resource[type - 1] - 1 >= 0 && count + 1 <= half)
				{
					pPlayer[0].resource[type - 1] -= 1;
					count += 1;
					bank_rec[type - 1] += 1;
				} else {
					continue;
				}
				if(count == half)
				{
					printf("\nPlayer %d throwed %d cards!\n", i + 1, half);
					break;
				}
			}
		}
	}
		
    for(i = 0; i < 4; i++)
    {
    	printf("Player %d's resources: " , i);
		printf("grain: %d", pPlayer[i].resource[0]);
		printf(", lumbar: %d", pPlayer[i].resource[1]);
		printf(", wool: %d", pPlayer[i].resource[2]);
		printf(", ore: %d", pPlayer[i].resource[3]);
		printf(", brick: %d", pPlayer[i].resource[4]);
		printf("\n");
	}
	while(1) {
		point = -1;
		printf("\nWhere would you place the bandit? (0 - 18)\n");
		scanf("%d", &point);
		point++;
		a = 0;
		for(i = 0; i < 18; i++)
		{
			if(pPlate[i].bandit != 0)
			{
				pPlate[i].bandit = 0;
				recent = i;
				break;
			}
		}

		int32_t trc[5];
	    for(i = 0; i < 5; i++)
	    {
	        trc[i] = 19;
	    }

		if(point == 1 && point != recent)
		{
			int ary[6] = {0, 3, 4, 7, 8, 12};
	        a = isthief( pVertex, pPlayer, ary, pPlate[0].scene, trc, turn);
	        pPlate[0].bandit = 1;
		}
		else if(point == 2 && point != recent)
		{
	        int ary[6] = {1, 4, 5, 8, 9, 13};
	        a = isthief( pVertex, pPlayer, ary, pPlate[1].scene, trc, turn);
	        pPlate[1].bandit = 1;
	    }
	    else if(point == 3 && point != recent)
	    {
	    	int ary[6] = {2, 5, 6, 9, 10, 14};
	        a = isthief( pVertex, pPlayer, ary, pPlate[2].scene, trc, turn);
	        pPlate[2].bandit = 1;
	    }
	    else if(point == 4 && point != recent)
	    {
	    	int ary[6] = {7, 11, 12, 16, 17, 22};
	        a = isthief( pVertex, pPlayer, ary, pPlate[3].scene, trc, turn);
	        pPlate[3].bandit = 1;
	    }
	    else if(point == 5 && point != recent)
	    {
	    	int ary[6] = {8, 12, 13, 17, 18, 23};
	        a = isthief( pVertex, pPlayer, ary, pPlate[4].scene, trc, turn);
	        pPlate[4].bandit = 1;
	    }
	    else if(point == 6 && point != recent)
	    {
	    	int ary[6] = {9, 13, 14, 18, 19, 24};
	        a = isthief( pVertex, pPlayer, ary, pPlate[5].scene, trc, turn);
	        pPlate[5].bandit = 1;
	    }
	    else if(point == 7 && point != recent)
	    {
	    	int ary[6] = {10, 14, 15, 19, 20, 25};
	        a = isthief( pVertex, pPlayer, ary, pPlate[6].scene, trc, turn);
	        pPlate[6].bandit = 1;
	    }
	    else if(point == 8 && point != recent)
	    {
	    	int ary[6] = {16, 21, 22, 27, 28, 33};
	        a = isthief( pVertex, pPlayer, ary, pPlate[7].scene, trc, turn);
	        pPlate[7].bandit = 1;
	    }
	    else if(point == 9 && point != recent)
	    {
	    	int ary[6] = {17, 22, 23, 28, 29, 34};
	        a = isthief( pVertex, pPlayer, ary, pPlate[8].scene, trc, turn);
	        pPlate[8].bandit = 1;
	    }
	    else if(point == 10 && point != recent)
	    {
	    	int ary[6] = {18, 23, 24, 29, 30, 35};
	        a = isthief( pVertex, pPlayer, ary, pPlate[9].scene, trc, turn);
	        pPlate[9].bandit = 1;
	    }
	    else if(point == 11 && point != recent)
	    {
	    	int ary[6] = {19, 24, 25, 30, 31, 36};
	        a = isthief( pVertex, pPlayer, ary, pPlate[10].scene, trc, turn);
	        pPlate[10].bandit = 1;
	    }
	    else if(point == 12 && point != recent)
	    {
	    	int ary[6] = {20, 25, 26, 31, 32, 37};
	        a = isthief( pVertex, pPlayer, ary, pPlate[11].scene, trc, turn);
	        pPlate[11].bandit = 1;
	    }
	    else if(point == 13 && point != recent)
	    {
	    	int ary[6] = {28, 33, 34, 38, 39, 43};
	        a = isthief( pVertex, pPlayer, ary, pPlate[12].scene, trc, turn);
	        pPlate[12].bandit = 1;
	    }
	    else if(point == 14 && point != recent)
	    {
	    	int ary[6] = {29, 34, 35, 39, 40, 44};
	        a = isthief( pVertex, pPlayer, ary, pPlate[13].scene, trc, turn);
	        pPlate[13].bandit = 1;
	    }
	    else if(point == 15 && point != recent)
	    {
	    	int ary[6] = {30, 35, 36, 40, 41, 45};
	        a = isthief( pVertex, pPlayer, ary, pPlate[14].scene, trc, turn);
	        pPlate[14].bandit = 1;
	    }
	    else if(point == 16 && point != recent)
	    {
	    	int ary[6] = {31, 36, 37, 41, 42, 46};
	        a = isthief( pVertex, pPlayer, ary, pPlate[15].scene, trc, turn);
	        pPlate[15].bandit = 1;
	    }
	    else if(point == 17 && point != recent)
	    {
	    	int ary[6] = {39, 43, 44, 47, 48, 51};
	        a = isthief( pVertex, pPlayer, ary, pPlate[16].scene, trc, turn);
	        pPlate[16].bandit = 1;
	    }
	    else if(point == 18 && point != recent)
	    {
	    	int ary[6] = {40, 44, 45, 48, 49, 52};
	        a = isthief( pVertex, pPlayer, ary, pPlate[17].scene, trc, turn);
	        pPlate[17].bandit = 1;
	    }
	    else if(point == 19 && point != recent)
	    {
	    	int ary[6] = {41, 45, 46, 49, 50, 53};
	        a = isthief( pVertex, pPlayer, ary, pPlate[18].scene, trc, turn);
	        pPlate[18].bandit = 1;
	    } 
	    else if(point == recent)
	    {
	    	printf("You can not put bandit on the same plate!!!\n");
	    }
	    if(a > -1)
	    {
	    	break;
	    } else {
	    	pPlate[point - 1].bandit = 0;
	    	pPlate[recent].bandit = 1;
	    }
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
	thief(ArrayPlate, ArrayVertex, ArrayPlayer, turn, bank_rec);
}