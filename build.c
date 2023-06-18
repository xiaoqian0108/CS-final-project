int determine_road( Line *pLine, Player *pPlayer, int32_t ary[], turn )
{


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
