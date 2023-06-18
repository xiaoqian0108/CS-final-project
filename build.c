int determine_road( Line *pLine, Vertex *pVertex, Player *pPlayer, int32_t ary[], int32_t turn )
{
	int32_t i, j;
    	int32_t line_and_line_neighbor[72][4] = {
	{1, 6, -1, -1},    	
	{0, 2, 7, -1}, 
    	{1, 7, 5, -1},
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

	int32_t village[10] = {-1}, villages = 0, own_roads[15], roads = 0, available_road[72] = {-1}, output_road[72] = {-1};
	for(i = 0; i <= 71; i++) {
		if( i <= 53 && (pVertex[i].village == turn + 1 || pVertex[i].city == turn + 1) ) {
			village[villages] = i;
			villages++;
		}
		if( pLine[i].road == turn + 1 ) {
			own_roads[roads] = i;
			roads++;
		}
	}
	for(i = 0; i < villages; i++) {
		for(j = 0; j < 72; j++) {
			if( pLine[j].road == 0 && (line_neighbor[j][0] == village[i] || line_neighbor[j][1] == village[i]) ) {
				available_road[j] = 1;
			}
		}
	}
	int32_t n, m;
	for( i = 0; i < roads; i++ ) {
		for( j = 0; j < 4; j++ ) {
			n = own_roads[i], m = line_and_line_neighbor[n][j];
			if( m != -1 && pLine[m].road == 0 ) {
				available_road[m] = i;
			}
		}
	}

	return 0;
}


void build_road( sPlayer *pPlayer, sVertex *pVertex, int32_t bank_res[], int32_t vertex_neighbor[] )
{
    int32_t road_NO = 0;
    printf( "Please enter the road NO that you want to build: ");
    scanf( "%d", &road_NO );

    if( pPlayer[0].resource[1] < 1 || pPlayer[0].resource[4] < 1 )
    {
        printf( "You don't have enough resources.\n" );
        return;
    }

    if( road_NO <= 6 || road_NO == 9 )
    {
        printf( "The road can not be built here.\n" );
        return;
    }
    if( road_NO == 10 || road_NO == 17 )
    {
        printf( "The road can not be built here.\n" );
        return;
    }
    if( road_NO == 18 || road_NO == 22 )
    {
        printf( "The road can not be built here.\n" );
        return;
    }
    if( road_NO == 23 || road_NO == 32 )
    {
        printf( "The road can not be built here.\n" );
        return;
    }
    if( road_NO == 33 || road_NO == 38 )
    {
        printf( "The road can not be built here.\n" );
        return;
    }
    if( road_NO == 39 || road_NO == 48 )
    {
        printf( "The road can not be built here.\n" );
        return;
    }
    if( road_NO == 54 || road_NO == 61 )
    {
        printf( "The road can not be built here.\n" );
        return;
    }
    if( road_NO == 62 || road_NO == 65 )
    {
        printf( "The road can not be built here.\n" );
        return;
    }
    if( road_NO >= 66 || road_NO <= 71 )
    {
        printf( "The road can not be built here.\n" );
        return;
    }

    
}
