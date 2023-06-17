#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "longestroad.h"
#include "map.h"


int32_t initList( sList *pList )
{
    if( pList == NULL )
    {
        printf( "%s(%d) %s: NULL pointer!\n", __FILE__, __LINE__, __FUNCTION__ );
        return -1;
    }
    
    pList -> size = 0;
    pList -> pHead = NULL; 
    pList -> pTail = NULL; 
    
    return 0;
}

int32_t addNode( sList *pList, int32_t val )
{
    if( pList == NULL )
    {
        printf( "%s(%d) %s: NULL pointer!\n", __FILE__, __LINE__, __FUNCTION__ );
        return -1;
    }    
    
    sListNode *pNewNode = calloc( 1, sizeof( sListNode ) );
    pNewNode -> data = val;
    pNewNode -> pNext = NULL;
    
    if( pList -> size == 0 )
    {
        pList -> pHead = pNewNode;
        pList -> pTail = pNewNode;
    }
    else
    {
        pList -> pTail -> pNext = pNewNode;
        pList -> pTail = pNewNode;
    }
    
    pList -> size += 1;
    
    return 0;    
}


int32_t LongestRoadLength(int32_t player, int32_t currentVertex, int32_t prevVertex, int32_t vertex_neighbor[][3], int32_t line_neighbor[][2], Vertex *ArrayVertex, Line *ArrayLine, int32_t visited_line[72])  
{
    int32_t maxLength = 0;
	int32_t matter = 0;

    for (int32_t i = 0; i < 3; i++) 
	{
		if( i == 2 && vertex_neighbor[currentVertex][i] == 0)
		{
			continue;
		}
		
        int32_t adjacentLine = vertex_neighbor[currentVertex][i];

		if( visited_line[adjacentLine] == 1 )
		{
			continue;
		}
		else if( ArrayLine[adjacentLine].road == player)
		{
			visited_line[adjacentLine] = 1;
			int32_t adjacentVertex = (line_neighbor[adjacentLine][0] != currentVertex) ? line_neighbor[adjacentLine][0] : line_neighbor[adjacentLine][1];
			if ( adjacentVertex != prevVertex && 
				(ArrayVertex[adjacentVertex].village == 0 || ArrayVertex[adjacentVertex].village == player || ArrayVertex[adjacentVertex].city == 0 || ArrayVertex[adjacentVertex].city == player) )
			{
				int32_t length = LongestRoadLength(player, adjacentVertex, currentVertex, vertex_neighbor, line_neighbor, ArrayVertex, ArrayLine, visited_line);
				maxLength = (length > maxLength) ? length : maxLength;
//				printf("%d\n", maxLength);
			}
		}
    }

    return maxLength + 1;
}


int32_t LongestRoad(int32_t player, int32_t line, Vertex *ArrayVertex, Line *ArrayLine)
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
	
    int32_t longestRoad = 0;
	int32_t visited_line[72] = {0};

	for(int32_t i = 0; i < 2; i++)
	{
		int32_t check_ver = line_neighbor[line][i];
		int32_t length1 = LongestRoadLength(player, check_ver, -1, vertex_neighbor, line_neighbor, ArrayVertex, ArrayLine, visited_line) - 1;
		for(int32_t j = 0; j < 72; j++)
		{
			visited_line[j] = 0;
		}
//		printf("%d.\n", visited_line[2]);
		longestRoad = (length1 > longestRoad) ? length1 : longestRoad;
	}

    return longestRoad;
}



/*
    主函式裡的寫法
	ArrayVertex[9].village == 1;
	ArrayVertex[1].village == 1;
	ArrayVertex[8].village == 1;

	ArrayLine[2].road = 1;
	ArrayLine[3].road = 1;
	ArrayLine[7].road = 1;
	ArrayLine[8].road = 1;
	ArrayLine[13].road = 1;
	ArrayLine[14].road = 1;
	ArrayLine[15].road = 1;

	sList list_player1;

	addNode( &list_player1, 2);
	addNode( &list_player1, 3);
	addNode( &list_player1, 7);
	addNode( &list_player1, 8);
	addNode( &list_player1, 13);
	addNode( &list_player1, 14);
	addNode( &list_player1, 15);

	sListNode *pNewNode = calloc( 1, sizeof( sListNode ) );
	pNewNode = list_player1.pHead;

	int32_t player = 1;
	int32_t longestRoad = 0;
	

	for(int32_t i = 0; i < (list_player1.size); i++)
	{
    	int32_t temp_longestRoad = LongestRoad(player, pNewNode -> data, ArrayVertex, ArrayLine);
		longestRoad = (temp_longestRoad > longestRoad) ? temp_longestRoad : longestRoad;
		pNewNode = pNewNode -> pNext;
	}

    printf("Player %d has the longest road with length %d.\n", player, longestRoad);
*/
