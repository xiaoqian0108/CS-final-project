#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"

int isthief( Vertex *pVertex, Player *pPlayer, int32_t ary[], int32_t resource_NO, int32_t number[] )
{   
	int32_t i, j;
	
    int32_t p[4] = {0}, amount = 0, oneplayer, resource;
    for(i = 0; i < 6; i++)
    {
    	if( pVertex[ary[i]].village > 1)
	    {
	        p[amount] = pVertex[i].village;
	        p[amount]--;
	        amount++;
	    }
    }

    if(amount == 0)
    {
    	printf("There is no player!!!\n");
    	return -1;
    }

    else if (amount == 1)
    {
    	while(1)
    	{
    		srand(time(NULL));
    		int resource_NO = rand() % 5 + 1;
    		if(pPlayer[p[0]].resource[resource_NO - 1] > 0)
    		{
    			pPlayer[p[0]].resource[resource_NO - 1]--;
    			number[resource_NO - 1]--;
    			break;
    		}
    	}
    	printf("Player %d's resources:\n" , p[0]);
	    for(i = 0; i < 5; i++)
	    {
	        printf("%4d" , pPlayer[p[0]].resource[i]);
	    }
	    printf("\n");
	    printf("Resource remaining:\n");
	    for(i = 0; i < 5; i++)
	    {
	        printf("%4d" , number[i]);
	    }
	    printf("\n");
    	
    }

    else if(amount > 1)
    {
    	printf("Which player? (");
    	for(i = 0; i < amount; i++)
    	{
    		printf("%d", p[i]);
    		if(i != amount - 1)
    		{
    			printf(", ");
    		}
    	}
    	printf(")\n");
    	scanf("%d", &oneplayer);

    	while(1)
    	{
    		srand(time(NULL));
    		int resource_NO = rand() % 5 + 1;
    		if(pPlayer[oneplayer - 1].resource[resource_NO-1] > 0)
    		{
    			pPlayer[oneplayer - 1].resource[resource_NO-1]--;
    			number[resource_NO-1]--;
    			break;
    		}
    	}
    	printf("Player %d's resources:\n" , oneplayer - 1);
	    for(i = 0; i < 5; i++)
	    {
	        printf("%4d" , pPlayer[oneplayer - 1].resource[i]);
	    }
	    printf("\n");
	    printf("Resource remaining:\n");
	    for(i = 0; i < 5; i++)
	    {
	        printf("%4d" , number[i]);
	    }
	    printf("\n");
    }
    return 0;
}

void thief(Plate *pPlate, Vertex *pVertex, Player *pPlayer)
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
			printf("You should throw %d cards.", half);
			while(1)
			{
				printf("Player %d's resources:\n" , 1);
			    for(i = 0; i < 5; i++)
			    {
			    	if(i == 0)
			    	{
			    		printf("grain: %4d", pPlayer[0].resource[i]);
			    	}
			    	else if(i == 0)
			    	{
			    		printf(", lumbar: %4d", pPlayer[0].resource[i]);
			    	}
			    	else if(i == 0)
			    	{
			    		printf(", wool: %4d", pPlayer[0].resource[i]);
			    	}
			    	else if(i == 0)
			    	{
			    		printf(", ore: %4d", pPlayer[0].resource[i]);
			    	}
			    	else if(i == 0)
			    	{
			    		printf(", brick: %4d", pPlayer[0].resource[i]);
			    	}
			    }
			    printf("\n");
				printf("Please enter the type of card and quantity which you throw (Ex: 1, 2)\n");
				printf("1: grain, 2: lumbar, 3: wool, 4: ore, 5: brick\n");
				scanf("%d, %d", &type, &quantity);
				if(pPlayer[0].resource[type - 1] - quantity >= 0 && count + quantity <= half)
				{
					pPlayer[0].resource[type - 1] -= quantity;
					count += quantity;
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
			printf("You should throw %d cards.", half);
			while(1)
			{
				srand(time(NULL));
    			int type = rand() % 5 + 1;
				if(pPlayer[0].resource[type - 1] - 1 >= 0 && count + 1 <= half)
				{
					pPlayer[0].resource[type - 1] -= 1;
					count += 1;
				} else {
					continue;
				}
				if(count == half)
				{
					printf("Player %d throwed %d cards!\n", i + 1, half);
					break;
				}
			}
		}
	}
	while(1) {
		printf("Where would you place the bandit? (1 - 19)\n");
		scanf("%d", &point);

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
			int ary[] = {0, 3, 4, 7, 8, 12};
	        a = isthief( pVertex, pPlayer, ary, pPlate[0].scene, trc);
	        pPlate[0].bandit = 1;
		}
		else if(point == 2 && point != recent)
		{
	        int ary[] = {1, 4, 5, 8, 9, 13};
	        a = isthief( pVertex, pPlayer, ary, pPlate[1].scene, trc);
	        pPlate[1].bandit = 1;
	    }
	    else if(point == 3 && point != recent)
	    {
	    	int ary[] = {2, 5, 6, 9, 10, 14};
	        a = isthief( pVertex, pPlayer, ary, pPlate[2].scene, trc);
	        pPlate[2].bandit = 1;
	    }
	    else if(point == 4 && point != recent)
	    {
	    	int ary[] = {7, 11, 12, 16, 17, 22};
	        a = isthief( pVertex, pPlayer, ary, pPlate[3].scene, trc);
	        pPlate[3].bandit = 1;
	    }
	    else if(point == 5 && point != recent)
	    {
	    	int ary[] = {8, 12, 13, 17, 18, 23};
	        a = isthief( pVertex, pPlayer, ary, pPlate[4].scene, trc);
	        pPlate[4].bandit = 1;
	    }
	    else if(point == 6 && point != recent)
	    {
	    	int ary[] = {9, 13, 14, 18, 19, 24};
	        a = isthief( pVertex, pPlayer, ary, pPlate[5].scene, trc);
	        pPlate[5].bandit = 1;
	    }
	    else if(point == 7 && point != recent)
	    {
	    	int ary[] = {10, 14, 15, 19, 20, 25};
	        a = isthief( pVertex, pPlayer, ary, pPlate[6].scene, trc);
	        pPlate[6].bandit = 1;
	    }
	    else if(point == 8 && point != recent)
	    {
	    	int ary[] = {16, 21, 22, 27, 28, 33};
	        a = isthief( pVertex, pPlayer, ary, pPlate[7].scene, trc);
	        pPlate[7].bandit = 1;
	    }
	    else if(point == 9 && point != recent)
	    {
	    	int ary[] = {17, 22, 23, 28, 29, 34};
	        a = isthief( pVertex, pPlayer, ary, pPlate[8].scene, trc);
	        pPlate[8].bandit = 1;
	    }
	    else if(point == 10 && point != recent)
	    {
	    	int ary[] = {18, 23, 24, 29, 30, 35};
	        a = isthief( pVertex, pPlayer, ary, pPlate[9].scene, trc);
	        pPlate[9].bandit = 1;
	    }
	    else if(point == 11 && point != recent)
	    {
	    	int ary[] = {19, 24, 25, 30, 31, 36};
	        a = isthief( pVertex, pPlayer, ary, pPlate[10].scene, trc);
	        pPlate[10].bandit = 1;
	    }
	    else if(point == 12 && point != recent)
	    {
	    	int ary[] = {20, 25, 26, 31, 32, 37};
	        a = isthief( pVertex, pPlayer, ary, pPlate[11].scene, trc);
	        pPlate[11].bandit = 1;
	    }
	    else if(point == 13 && point != recent)
	    {
	    	int ary[] = {28, 33, 34, 38, 39, 43};
	        a = isthief( pVertex, pPlayer, ary, pPlate[12].scene, trc);
	        pPlate[12].bandit = 1;
	    }
	    else if(point == 14 && point != recent)
	    {
	    	int ary[] = {29, 34, 35, 39, 40, 44};
	        a = isthief( pVertex, pPlayer, ary, pPlate[13].scene, trc);
	        pPlate[13].bandit = 1;
	    }
	    else if(point == 15 && point != recent)
	    {
	    	int ary[] = {30, 35, 36, 40, 41, 45};
	        a = isthief( pVertex, pPlayer, ary, pPlate[14].scene, trc);
	        pPlate[14].bandit = 1;
	    }
	    else if(point == 16 && point != recent)
	    {
	    	int ary[] = {31, 36, 37, 41, 42, 46};
	        a = isthief( pVertex, pPlayer, ary, pPlate[15].scene, trc);
	        pPlate[15].bandit = 1;
	    }
	    else if(point == 17 && point != recent)
	    {
	    	int ary[] = {39, 43, 44, 47, 48, 51};
	        a = isthief( pVertex, pPlayer, ary, pPlate[16].scene, trc);
	        pPlate[16].bandit = 1;
	    }
	    else if(point == 18 && point != recent)
	    {
	    	int ary[] = {40, 44, 45, 48, 49, 52};
	        a = isthief( pVertex, pPlayer, ary, pPlate[17].scene, trc);
	        pPlate[17].bandit = 1;
	    }
	    else if(point == 19 && point != recent)
	    {
	    	int ary[] = {41, 45, 46, 49, 50, 53};
	        a = isthief( pVertex, pPlayer, ary, pPlate[18].scene, trc);
	        pPlate[18].bandit = 1;
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