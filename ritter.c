#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"

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
    	printf("\nThere is no player!!!\n");
    	return -1;
    } 
    amount = 0;
    for(i = 0; i < 6; i++)
    { 
    	if( pVertex[ary[i]].village != turn && pVertex[ary[i]].village > 0)
	    {
	    	j = pVertex[ary[i]].village;
	        if(pPlayer[j - 1].resource[0] > 0 || pPlayer[j - 1].resource[1] > 0 || pPlayer[j - 1].resource[2] > 0 || pPlayer[j - 1].resource[3] > 0 || pPlayer[j - 1].resource[4] > 0)
	        {
	        	//printf("unko");
			    p[amount] = pVertex[ary[i]].village;
		        p[amount]--;
		        //Record how many players on the plate
		        amount++;
	    	}
	    }
    }

    if(amount == 0)
    {
    	printf("\nNo players have resources!!!\n");
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
    			printf("\nplayer \x1b[31m%d\x1b[0m's bricks were taken away by player \x1b[31m%d\x1b[0m\n", p[0] + 1, turn + 1);
    			pPlayer[p[0]].resource[resource_NO - 1]--;

    			//Give recource to the player
    			pPlayer[turn].resource[resource_NO - 1]++;
    			break;
    		}
    	}

		//Print player's all resources.
	    for(i = 0; i < 4; i++)
	    {
	    	printf("\nPlayer %d's resources:\n" , i + 1);
			printf("grain: \x1b[31m%d\x1b[0m", pPlayer[i].resource[0]);
			printf(", lumbar: \x1b[31m%d\x1b[0m", pPlayer[i].resource[1]);
			printf(", wool: \x1b[31m%d\x1b[0m", pPlayer[i].resource[2]);
			printf(", ore: \x1b[31m%d\x1b[0m", pPlayer[i].resource[3]);
			printf(", brick: \x1b[31m%d\x1b[0m", pPlayer[i].resource[4]);
			printf("\n");
	    }
	    printf("\n");
	    printf("Resource remaining:\n");
	    printf("grain: \x1b[31m%d\x1b[0m", number[0]);
		printf(", lumbar: \x1b[31m%d\x1b[0m", number[1]);
		printf(", wool: \x1b[31m%d\x1b[0m", number[2]);
		printf(", ore: \x1b[31m%d\x1b[0m", number[3]);
		printf(", brick: \x1b[31m%d\x1b[0m", number[4]);
	    printf("\n");
    	
    }

    //The case if there're more than two players on the plate
    else if(amount > 1)
    {
    	for(i = 0; i < amount; i++){
    		for(j = i + 1; j < amount; j++){
    			if(p[i] > p[j]){
    				int32_t tmp = p[i];
    				p[i] = p[j];
    				p[j] = tmp;
    			}
    		}
    	}
    	if(turn == 0){
			printf("\nWhich player? (");
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
    			printf("\nplayer \x1b[31m%d\x1b[0m's bricks were taken away by player \x1b[31m%d\x1b[0m\n", oneplayer + 1, turn + 1);
    			pPlayer[oneplayer].resource[resource_NO-1]--;

    			//Give recource to the player
    			pPlayer[turn].resource[resource_NO - 1]++;
    			break;
    		}
	    }
	    
	    //Print player's all resources.
	    for(i = 0; i < 4; i++)
	    {
	    	printf("\nPlayer %d's resources:" , i + 1);
    		printf("grain: \x1b[31m%d\x1b[0m", pPlayer[i].resource[0]);
    		printf(", lumbar: \x1b[31m%d\x1b[0m", pPlayer[i].resource[1]);
			printf(", wool: \x1b[31m%d\x1b[0m", pPlayer[i].resource[2]);
			printf(", ore: \x1b[31m%d\x1b[0m", pPlayer[i].resource[3]);
    		printf(", brick: \x1b[31m%d\x1b[0m", pPlayer[i].resource[4]);
	    }
	    printf("\n");
	    printf("\nResource remaining:\n");
	    printf("grain: \x1b[31m%d\x1b[0m", number[0]);
		printf(", lumbar: \x1b[31m%d\x1b[0m", number[1]);
		printf(", wool: \x1b[31m%d\x1b[0m", number[2]);
		printf(", ore: \x1b[31m%d\x1b[0m", number[3]);
		printf(", brick: \x1b[31m%d\x1b[0m", number[4]);
	    printf("\n");
	}
	return 0;
}
void ritter(Plate *pPlate, Vertex *pVertex, Player *pPlayer, int32_t turn){
	int32_t point, a, recent;
	while(1) {
		printf("Where would you place the bandit? (1 - 19)\n");
		scanf("%d", &point);

		for(int32_t i = 0; i < 18; i++){
			if(pPlate[i].bandit != 0){
				pPlate[i].bandit = 0;
				recent = i;
				break;
			}
		}

		int32_t trc[5];
	    for ( size_t i = 0; i < 5; i++ )
	    {
	        trc[i] = 19;
	    }

		if( point == 1 && point != recent)
		{
			int ary[] = {0, 3, 4, 7, 8, 12};
	        a = isthief( pVertex, pPlayer, ary, pPlate[0].scene, trc, turn);
	        pPlate[0].bandit = 1;
		}
		else if( point == 2 && point != recent)
		{
	        int ary[] = {1, 4, 5, 8, 9, 13};
	        a = isthief( pVertex, pPlayer, ary, pPlate[1].scene, trc, turn);
	        pPlate[1].bandit = 1;
	    }
	    else if(point == 3 && point != recent)
	    {
	    	int ary[] = {2, 5, 6, 9, 10, 14};
	        a = isthief( pVertex, pPlayer, ary, pPlate[2].scene, trc, turn);
	        pPlate[2].bandit = 1;
	    }
	    else if(point == 4 && point != recent)
	    {
	    	int ary[] = {7, 11, 12, 16, 17, 22};
	        a = isthief( pVertex, pPlayer, ary, pPlate[3].scene, trc, turn);
	        pPlate[3].bandit = 1;
	    }
	    else if(point == 5 && point != recent)
	    {
	    	int ary[] = {8, 12, 13, 17, 18, 23};
	        a = isthief( pVertex, pPlayer, ary, pPlate[4].scene, trc, turn);
	        pPlate[4].bandit = 1;
	    }
	    else if(point == 6 && point != recent)
	    {
	    	int ary[] = {9, 13, 14, 18, 19, 24};
	        a = isthief( pVertex, pPlayer, ary, pPlate[5].scene, trc, turn);
	        pPlate[5].bandit = 1;
	    }
	    else if(point == 7 && point != recent)
	    {
	    	int ary[] = {10, 14, 15, 19, 20, 25};
	        a = isthief( pVertex, pPlayer, ary, pPlate[6].scene, trc, turn);
	        pPlate[6].bandit = 1;
	    }
	    else if(point == 8 && point != recent)
	    {
	    	int ary[] = {16, 21, 22, 27, 28, 33};
	        a = isthief( pVertex, pPlayer, ary, pPlate[7].scene, trc, turn);
	        pPlate[7].bandit = 1;
	    }
	    else if(point == 9 && point != recent)
	    {
	    	int ary[] = {17, 22, 23, 28, 29, 34};
	        a = isthief( pVertex, pPlayer, ary, pPlate[8].scene, trc, turn);
	        pPlate[8].bandit = 1;
	    }
	    else if(point == 10 && point != recent)
	    {
	    	int ary[] = {18, 23, 24, 29, 30, 35};
	        a = isthief( pVertex, pPlayer, ary, pPlate[9].scene, trc, turn);
	        pPlate[9].bandit = 1;
	    }
	    else if(point == 11 && point != recent)
	    {
	    	int ary[] = {19, 24, 25, 30, 31, 36};
	        a = isthief( pVertex, pPlayer, ary, pPlate[10].scene, trc, turn);
	        pPlate[10].bandit = 1;
	    }
	    else if(point == 12 && point != recent)
	    {
	    	int ary[] = {20, 25, 26, 31, 32, 37};
	        a = isthief( pVertex, pPlayer, ary, pPlate[11].scene, trc, turn);
	        pPlate[11].bandit = 1;
	    }
	    else if(point == 13 && point != recent)
	    {
	    	int ary[] = {28, 33, 34, 38, 39, 43};
	        a = isthief( pVertex, pPlayer, ary, pPlate[12].scene, trc, turn);
	        pPlate[12].bandit = 1;
	    }
	    else if(point == 14 && point != recent)
	    {
	    	int ary[] = {29, 34, 35, 39, 40, 44};
	        a = isthief( pVertex, pPlayer, ary, pPlate[13].scene, trc, turn);
	        pPlate[13].bandit = 1;
	    }
	    else if(point == 15 && point != recent)
	    {
	    	int ary[] = {30, 35, 36, 40, 41, 45};
	        a = isthief( pVertex, pPlayer, ary, pPlate[14].scene, trc, turn);
	        pPlate[14].bandit = 1;
	    }
	    else if(point == 16 && point != recent)
	    {
	    	int ary[] = {31, 36, 37, 41, 42, 46};
	        a = isthief( pVertex, pPlayer, ary, pPlate[15].scene, trc, turn);
	        pPlate[15].bandit = 1;
	    }
	    else if(point == 17 && point != recent)
	    {
	    	int ary[] = {39, 43, 44, 47, 48, 51};
	        a = isthief( pVertex, pPlayer, ary, pPlate[16].scene, trc, turn);
	        pPlate[16].bandit = 1;
	    }
	    else if(point == 18 && point != recent)
	    {
	    	int ary[] = {40, 44, 45, 48, 49, 52};
	        a = isthief( pVertex, pPlayer, ary, pPlate[17].scene, trc, turn);
	        pPlate[17].bandit = 1;
	    }
	    else if(point == 19 && point != recent)
	    {
	    	int ary[] = {41, 45, 46, 49, 50, 53};
	        a = isthief( pVertex, pPlayer, ary, pPlate[18].scene, trc, turn);
	        pPlate[18].bandit = 1;
	    }
	    if(a > -1){
	    	break;
	    } else {
	    	pPlate[point - 1].bandit = 0;
	    	pPlate[recent].bandit = 1;
	    }
	}
}