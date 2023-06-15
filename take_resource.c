#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct _Plate
{
	int32_t res_num;  // 資源數字指示
	int32_t scene;  // 六種場地
	int32_t bandit;  // 盜賊
}sPlate;

typedef struct _Vertex
{
	int32_t type;  // 節點種類(3種)
	int32_t village;  // 村莊
	int32_t city;  // 城市
	int32_t port;  // 港口類型
  int32_t res_num[3];  //:{0,5,8}  // 鄰近的資源數字指示
	int32_t res_type[3];  //:{0,2,1}  // 鄰近的資源種類
}sVertex;

typedef struct _Line
{
	int32_t type;  // 道路種類
	int32_t road;  // 道路的擁有權
}sLine;

typedef struct _Player
{
	int32_t resource[5];  // 五種資源
    int32_t building[3];  // 三種建築
	int32_t develop[3];  // 三種發展卡
   	int32_t new_deve[3];  // 剛拿到的卡
	int32_t special[2];  // 特殊計分卡
}sPlayer;

void isVillage( sVertex *pVertex, sPlayer *pPlayer, int32_t i, int32_t resource_NO, int32_t number[] )
{   
    int32_t player = 0;
    if( pVertex[i].village != 0 )
    {
        player = pVertex[i].village;

        if( number[resource_NO-1] != 0 )
        {
            pPlayer[player-1].resource[resource_NO-1]++;
            number[resource_NO-1]--;
        }
    }

    printf( "Player %d's resources:\n" , player );
    for( int32_t j = 0; j < 5; j++ )
    {
        printf( "%4d" , pPlayer[player-1].resource[j] );
    }
    printf( "\n" );
    printf( "Resource remaining:\n" );
    for( int32_t j = 0; j < 5; j++ )
    {
        printf( "%4d" , number[j] );
    }
    printf( "\n" );
}

void init_plate ( sPlate *pPlate )
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

void init_vertex( sVertex *pVertex )
{
    // 2
    pVertex[1].type = 0;
    pVertex[1].village = 1;
    pVertex[1].city = 0;
    pVertex[1].port = 2;
    pVertex[1].res_num[0] = 0;
    pVertex[1].res_num[1] = 0;
    pVertex[1].res_num[2] = 11;
    pVertex[1].res_type[0] = 0;
    pVertex[1].res_type[1] = 0;
    pVertex[1].res_type[2] = 2;

    // 8
    pVertex[7].type = 1;
    pVertex[7].village = 4;
    pVertex[7].city = 0;
    pVertex[7].port = 5;
    pVertex[7].res_num[0] = 0;
    pVertex[7].res_num[1] = 4;
    pVertex[7].res_num[2] = 8;
    pVertex[7].res_type[0] = 0;
    pVertex[7].res_type[1] = 1;
    pVertex[7].res_type[2] = 4;

    // 25
    pVertex[24].type = 2;
    pVertex[24].village = 2;
    pVertex[24].city = 0;
    pVertex[24].port = 0;
    pVertex[24].res_num[0] = 6;
    pVertex[24].res_num[1] = 11;
    pVertex[24].res_num[2] = 5;
    pVertex[24].res_type[0] = 1;
    pVertex[24].res_type[1] = 5;
    pVertex[24].res_type[2] = 1;
}

int32_t drop_dice()
{
    int32_t dice1_number = 0;
    int32_t dice2_number = 0;
    int32_t dice_total = 0;

    srand(time(NULL));
    dice1_number = rand() % 6 + 1;
    dice2_number = rand() % 6 + 1;
    dice_total = dice1_number + dice2_number;

    printf( "Dice 1: %d\n", dice1_number );
    printf( "Dice 2: %d\n", dice2_number );
    printf( "Dice 1 + 2: %d\n", dice_total );
    
    return dice_total;
}

void init_player( sPlayer *pPlayer )
{
    // set
    for( size_t i = 0; i < 5; i++ )
    {
        pPlayer -> resource[i] = 0;
    }
    for( size_t i = 0; i < 3; i++ )
    {
        pPlayer -> building[i] = 0;
    }
    for( size_t i = 0; i < 3; i++ )
    {
        pPlayer -> develop[i] = 0;
    }
    for( size_t i = 0; i < 3; i++ )
    {
        pPlayer -> new_deve[i] = 0;
    }
    for( size_t i = 0; i < 2; i++ )
    {
        pPlayer -> special[i] = 0;
    }
    /*
    // print
    for( size_t i = 0; i < 5; i++ )
    {
        printf( "%4d" , pPlayer->resource[i] );
    }
    printf( "\n" );
    for( size_t i = 0; i < 3; i++ )
    {
        printf( "%4d" , pPlayer->building[i] );
    }
    printf( "\n" );
    for( size_t i = 0; i < 3; i++ )
    {
        printf( "%4d" , pPlayer->develop[i] );
    }
    printf( "\n" );
    for( size_t i = 0; i < 3; i++ )
    {
        printf( "%4d" , pPlayer->new_deve[i] );
    }
    printf( "\n" );
    for( size_t i = 0; i < 2; i++ )
    {
        printf( "%4d" , pPlayer->special[i] );
    }
    printf( "\n" );
    */
}

void bandit_function()
{
    printf( "Bandit moved.\n" );
}

int32_t take_resource( int32_t dice , sPlate *pPlate, sVertex *pVertex, sPlayer *pPlayer )
{
    if( dice == 7 )
    {
        return -1;
    }
    
    printf( "Start to take resource.\n" );
    
    // the total of the cards
    // [0]: 麥田 => 生產小麥
    // [1]: 森林 => 生產木頭
    // [2]: 草原 => 生產羊毛
    // [3]: 山脈 => 生產石頭
    // [4]: 丘陵 => 生產磚頭
    int32_t trc[5];
    // the number of total resource cards
    for ( size_t i = 0; i < 5; i++ )
    {
        trc[i] = 19;
    }

    /* // test
    if( dice == 11 )
    {
        isVillage( pVertex, pPlayer, 1, pPlate[1].scene, trc );
    }
    else if( dice == 8 )
    {
        isVillage( pVertex, pPlayer, 7, pPlate[3].scene,  trc );
    }
    else if( dice == 6 )
    {
        isVillage( pVertex, pPlayer, 24, pPlate[5].scene, trc );
    }
    */

    if( dice == 2 && pPlate[12].bandit == 0 )
    {
        isVillage( pVertex, pPlayer, 28, pPlate[12].scene, trc );
        isVillage( pVertex, pPlayer, 33, pPlate[12].scene, trc );
        isVillage( pVertex, pPlayer, 34, pPlate[12].scene, trc );
        isVillage( pVertex, pPlayer, 38, pPlate[12].scene, trc );
        isVillage( pVertex, pPlayer, 39, pPlate[12].scene, trc );
        isVillage( pVertex, pPlayer, 43, pPlate[12].scene, trc );
    }
    else if ( dice == 3 )
    {
        if( pPlate[4].bandit == 0 )
        {
            isVillage( pVertex, pPlayer, 8, pPlate[4].scene, trc );
            isVillage( pVertex, pPlayer, 12, pPlate[4].scene, trc );
            isVillage( pVertex, pPlayer, 13, pPlate[4].scene, trc );
            isVillage( pVertex, pPlayer, 17, pPlate[4].scene, trc );
            isVillage( pVertex, pPlayer, 18, pPlate[4].scene, trc );
            isVillage( pVertex, pPlayer, 23, pPlate[4].scene, trc );
        }
        if( pPlate[17].bandit == 0 )
        {
            isVillage( pVertex, pPlayer, 40, pPlate[17].scene, trc );
            isVillage( pVertex, pPlayer, 44, pPlate[17].scene, trc );
            isVillage( pVertex, pPlayer, 45, pPlate[17].scene, trc );
            isVillage( pVertex, pPlayer, 48, pPlate[17].scene, trc );
            isVillage( pVertex, pPlayer, 49, pPlate[17].scene, trc );
            isVillage( pVertex, pPlayer, 52, pPlate[17].scene, trc );
        }
    }
    else if ( dice == 4 )
    {
        if( pPlate[0].bandit == 0 )
        {
            isVillage( pVertex, pPlayer, 0, pPlate[0].scene, trc );
            isVillage( pVertex, pPlayer, 3, pPlate[0].scene, trc );
            isVillage( pVertex, pPlayer, 4, pPlate[0].scene, trc );
            isVillage( pVertex, pPlayer, 7, pPlate[0].scene, trc );
            isVillage( pVertex, pPlayer, 8, pPlate[0].scene, trc );
            isVillage( pVertex, pPlayer, 12, pPlate[0].scene, trc );
        }
        if( pPlate[14].bandit == 0 )
        {
            isVillage( pVertex, pPlayer, 30, pPlate[14].scene, trc );
            isVillage( pVertex, pPlayer, 35, pPlate[14].scene, trc );
            isVillage( pVertex, pPlayer, 36, pPlate[14].scene, trc );
            isVillage( pVertex, pPlayer, 40, pPlate[14].scene, trc );
            isVillage( pVertex, pPlayer, 41, pPlate[14].scene, trc );
            isVillage( pVertex, pPlayer, 45, pPlate[14].scene, trc );
        }
    }
    else if ( dice == 5 )
    {
        if( pPlate[7].bandit == 0 )
        {
            isVillage( pVertex, pPlayer, 16, pPlate[7].scene, trc );
            isVillage( pVertex, pPlayer, 21, pPlate[7].scene, trc );
            isVillage( pVertex, pPlayer, 22, pPlate[7].scene, trc );
            isVillage( pVertex, pPlayer, 27, pPlate[7].scene, trc );
            isVillage( pVertex, pPlayer, 28, pPlate[7].scene, trc );
            isVillage( pVertex, pPlayer, 33, pPlate[7].scene, trc );
        }
        if( pPlate[10].bandit == 0 )
        {
            isVillage( pVertex, pPlayer, 19, pPlate[10].scene, trc );
            isVillage( pVertex, pPlayer, 24, pPlate[10].scene, trc );
            isVillage( pVertex, pPlayer, 25, pPlate[10].scene, trc );
            isVillage( pVertex, pPlayer, 30, pPlate[10].scene, trc );
            isVillage( pVertex, pPlayer, 31, pPlate[10].scene, trc );
            isVillage( pVertex, pPlayer, 36, pPlate[10].scene, trc );
        }
    }
    else if ( dice == 6 )
    {
        if( pPlate[5].bandit == 0 )
        {
            isVillage( pVertex, pPlayer, 9, pPlate[5].scene, trc );
            isVillage( pVertex, pPlayer, 13, pPlate[5].scene, trc );
            isVillage( pVertex, pPlayer, 14, pPlate[5].scene, trc );
            isVillage( pVertex, pPlayer, 18, pPlate[5].scene, trc );
            isVillage( pVertex, pPlayer, 19, pPlate[5].scene, trc );
            isVillage( pVertex, pPlayer, 24, pPlate[5].scene, trc );
        }
        if( pPlate[16].bandit == 0 )
        {
            isVillage( pVertex, pPlayer, 39, pPlate[16].scene, trc );
            isVillage( pVertex, pPlayer, 43, pPlate[16].scene, trc );
            isVillage( pVertex, pPlayer, 44, pPlate[16].scene, trc );
            isVillage( pVertex, pPlayer, 47, pPlate[16].scene, trc );
            isVillage( pVertex, pPlayer, 48, pPlate[16].scene, trc );
            isVillage( pVertex, pPlayer, 51, pPlate[16].scene, trc );
        }
    }
    else if ( dice == 8 )
    {
        if( pPlate[3].bandit == 0 )
        {
            isVillage( pVertex, pPlayer, 7, pPlate[3].scene, trc );
            isVillage( pVertex, pPlayer, 11, pPlate[3].scene, trc );
            isVillage( pVertex, pPlayer, 12, pPlate[3].scene, trc );
            isVillage( pVertex, pPlayer, 16, pPlate[3].scene, trc );
            isVillage( pVertex, pPlayer, 17, pPlate[3].scene, trc );
            isVillage( pVertex, pPlayer, 22, pPlate[3].scene, trc );
        }
        if( pPlate[18].bandit == 0 )
        {
            isVillage( pVertex, pPlayer, 41, pPlate[18].scene, trc );
            isVillage( pVertex, pPlayer, 45, pPlate[18].scene, trc );
            isVillage( pVertex, pPlayer, 46, pPlate[18].scene, trc );
            isVillage( pVertex, pPlayer, 49, pPlate[18].scene, trc );
            isVillage( pVertex, pPlayer, 50, pPlate[18].scene, trc );
            isVillage( pVertex, pPlayer, 53, pPlate[18].scene, trc );
        }
    }
    else if ( dice == 9 )
    {
        if( pPlate[6].bandit == 0 )
        {
            isVillage( pVertex, pPlayer, 10, pPlate[6].scene, trc );
            isVillage( pVertex, pPlayer, 14, pPlate[6].scene, trc );
            isVillage( pVertex, pPlayer, 15, pPlate[6].scene, trc );
            isVillage( pVertex, pPlayer, 19, pPlate[6].scene, trc );
            isVillage( pVertex, pPlayer, 20, pPlate[6].scene, trc );
            isVillage( pVertex, pPlayer, 25, pPlate[6].scene, trc );
        }
        if( pPlate[13].bandit == 0 )
        {
            isVillage( pVertex, pPlayer, 29, pPlate[13].scene, trc );
            isVillage( pVertex, pPlayer, 34, pPlate[13].scene, trc );
            isVillage( pVertex, pPlayer, 35, pPlate[13].scene, trc );
            isVillage( pVertex, pPlayer, 39, pPlate[13].scene, trc );
            isVillage( pVertex, pPlayer, 40, pPlate[13].scene, trc );
            isVillage( pVertex, pPlayer, 44, pPlate[13].scene, trc );
        }
    }
    else if ( dice == 10 )
    {
        if( pPlate[8].bandit == 0 )
        {
            isVillage( pVertex, pPlayer, 17, pPlate[8].scene, trc );
            isVillage( pVertex, pPlayer, 22, pPlate[8].scene, trc );
            isVillage( pVertex, pPlayer, 23, pPlate[8].scene, trc );
            isVillage( pVertex, pPlayer, 28, pPlate[8].scene, trc );
            isVillage( pVertex, pPlayer, 29, pPlate[8].scene, trc );
            isVillage( pVertex, pPlayer, 34, pPlate[8].scene, trc );
        }
        if( pPlate[11].bandit == 0 )
        {
            isVillage( pVertex, pPlayer, 20, pPlate[11].scene, trc );
            isVillage( pVertex, pPlayer, 25, pPlate[11].scene, trc );
            isVillage( pVertex, pPlayer, 26, pPlate[11].scene, trc );
            isVillage( pVertex, pPlayer, 31, pPlate[11].scene, trc );
            isVillage( pVertex, pPlayer, 32, pPlate[11].scene, trc );
            isVillage( pVertex, pPlayer, 37, pPlate[11].scene, trc );
        }
    }
    else if ( dice == 11 )
    {
        if( pPlate[1].bandit == 0 )
        {
            isVillage( pVertex, pPlayer, 1, pPlate[1].scene, trc );
            isVillage( pVertex, pPlayer, 4, pPlate[1].scene, trc );
            isVillage( pVertex, pPlayer, 5, pPlate[1].scene, trc );
            isVillage( pVertex, pPlayer, 8, pPlate[1].scene, trc );
            isVillage( pVertex, pPlayer, 9, pPlate[1].scene, trc );
            isVillage( pVertex, pPlayer, 13, pPlate[1].scene, trc );
        }
        if( pPlate[9].bandit == 0 )
        {
            isVillage( pVertex, pPlayer, 18, pPlate[9].scene, trc );
            isVillage( pVertex, pPlayer, 23, pPlate[9].scene, trc );
            isVillage( pVertex, pPlayer, 24, pPlate[9].scene, trc );
            isVillage( pVertex, pPlayer, 29, pPlate[9].scene, trc );
            isVillage( pVertex, pPlayer, 30, pPlate[9].scene, trc );
            isVillage( pVertex, pPlayer, 35, pPlate[9].scene, trc );
        }
    }
    else if ( dice == 12 && pPlate[2].bandit == 0 )
    {
        isVillage( pVertex, pPlayer, 2, pPlate[2].scene, trc );
        isVillage( pVertex, pPlayer, 5, pPlate[2].scene, trc );
        isVillage( pVertex, pPlayer, 6, pPlate[2].scene, trc );
        isVillage( pVertex, pPlayer, 9, pPlate[2].scene, trc );
        isVillage( pVertex, pPlayer, 10, pPlate[2].scene, trc );
        isVillage( pVertex, pPlayer, 14, pPlate[2].scene, trc );
    }

    return 0;
}
