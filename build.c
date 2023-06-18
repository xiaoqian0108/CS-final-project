int determine_road( Line *pLine, Player *pPlayer, int32_t ary[], turn )
{
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

    pPlayer[0].resource[1]--;
    pPlayer[0].resource[4]--;
    bank_res[1]++;
    bank_res[4]++;
}
