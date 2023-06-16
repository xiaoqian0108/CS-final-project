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
	int32_t develop[5];  // 五種發展卡 0: 騎士卡 1: 進程卡 (資源壟斷) 2: 進程卡 (創新發明) 3: 進程卡 (道路建設) 4: 分數卡
    int32_t new_deve[5];  // 剛拿到的卡
	int32_t special[2];  // 特殊計分卡
}sPlayer;

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
    pVertex[1].village = 0;
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
    pVertex[7].village = 0;
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

void bank_transaction( sPlayer *pPlayer, int32_t bank_res[] )
{
    int32_t choice = 0;
    printf( "Do you want to trade with the bank?\n" );
    printf( "( 0: No, 1: Yes ): ");
    scanf( "%d", &choice );

    if( choice == 0 )
    {
        printf( "Bye!\n" );
    }
    else if( choice == 1 )
    {
        int32_t resource_out = 0;
        printf( "Which resource do you want to use for the exchange?\n" );
        //printf( "( You have to take four same resource to exchange for only one.)\n" );
        printf( "( 0: Wheat, 1: Woods, 2: Wool, 3: Rocks, 4: Bricks ): ");
        scanf( "%d" , &resource_out );

        if( resource_out < 0 || resource_out > 4 )
        {
            printf( "Invaild input. You lost the chance.\n" );
            return;
        }
        
        if( pPlayer[0].resource[resource_out] < 4 )
        {
            printf( "Sorry. You don't have enough resources.\n" );
            return;
        }

        int32_t resource_in = 0;
        printf( "Which resource do you want to get?\n" );
        printf( "( 0: Wheat, 1: Woods, 2: Wool, 3: Rocks, 4: Bricks ): ");
        scanf( "%d" , &resource_in );

        if( resource_in < 0 || resource_in > 4 )
        {
            printf( "Invaild input. You lost the chance.\n" );
            return;
        }

        if( resource_in == resource_out )
        {
            printf( "The two should not be the same.\n" );
            return;
        }

        if( bank_res[resource_in] == 0 )
        {
            printf( "Sorry. There is no enough resource.\n" );
            return;
        }

        pPlayer[0].resource[resource_out] -= 4;
        pPlayer[0].resource[resource_in]++;
        bank_res[resource_out] += 4;
        bank_res[resource_in]--;
    }
    else
    {
        printf( "Invaild input. You lost the chance.\n" );
    }
}

void port_transaction( sPlayer *pPlayer, sVertex *pVertex, int32_t bank_res[] )
{
    int32_t choice = 0;
    printf( "Do you want to trade with the bank at the port?" );
    printf( "( 0: No, 1: Yes ): ");
    scanf( "%d", &choice );

    if( choice == 0 )
    {
        printf( "Bye!\n" );
        return;
    }
    
    if( choice > 1 )
    {
        printf( "Invaild input. You lost the chance.\n" );
        return;
    }

    int32_t port_NO = 0;
    printf( "Enter the vertex that possesses a port: \n" );
    scanf( "%d", &port_NO );

    if ( pVertex[port_NO].port == 0 )
    {
        printf( "Sorry. The vertex is not a port.\n" );
        return;
    }

    int32_t resource_NO = 0;
    printf( "Which other resource do you want to get?\n" );
    scanf( "%d", &resource_NO );

    if( pVertex[port_NO].port == 1 && resource_NO != 0 ) 
    {
        printf( "Take two wheat cards to exchange for something else.\n" );
        if( bank_res[resource_NO] != 0 )
        {
            pPlayer[0].resource[resource_NO]++;
            pPlayer[0].resource[0] -= 2;
            bank_res[0] += 2;
        }
        else if( pPlayer[0].resource[0] < 2 )
        {
            printf( "Sorry. You don't have enough cards.\n" );
        }
        else
        {
            printf( "Sorry. There is no enough resource.\n" );
        }
    }
    else if( pVertex[port_NO].port == 2 && resource_NO != 1 ) 
    {
        printf( "Take two wood cards to exchange for something else.\n" );
        if( bank_res[resource_NO] != 0 )
        {
            pPlayer[0].resource[resource_NO]++;
            pPlayer[0].resource[1] -= 2;
            bank_res[1] += 2;
        }
        else if( pPlayer[0].resource[1] < 2 )
        {
            printf( "Sorry. You don't have enough cards.\n" );
        }
        else
        {
            printf( "Sorry. There is no enough resource.\n" );
        }
    }
    else if( pVertex[port_NO].port == 3 && resource_NO != 2 ) 
    {
        printf( "Take two wool cards to exchange for something else.\n" );
        if( bank_res[resource_NO] != 0 )
        {
            pPlayer[0].resource[resource_NO]++;
            pPlayer[0].resource[2] -= 2;
            bank_res[2] += 2;
        }
        else if( pPlayer[0].resource[2] < 2 )
        {
            printf( "Sorry. You don't have enough cards.\n" );
        }
        else
        {
            printf( "Sorry. There is no enough resource.\n" );
        }
    }
    else if( pVertex[port_NO].port == 4 && resource_NO != 3 ) 
    {
        printf( "Take two stone cards to exchange for something else.\n" );
        if( bank_res[resource_NO] != 0 )
        {
            pPlayer[0].resource[resource_NO]++;
            pPlayer[0].resource[3] -= 2;
            bank_res[3] += 2;
        }
        else if( pPlayer[0].resource[3] < 2 )
        {
            printf( "Sorry. You don't have enough cards.\n" );
        }
        else
        {
            printf( "Sorry. There is no enough resource.\n" );
        }
    }
    else if( pVertex[port_NO].port == 5 && resource_NO != 4 ) 
    {
        printf( "Take two brick cards to exchange for something else.\n" );
        if( bank_res[resource_NO] != 0 )
        {
            pPlayer[0].resource[resource_NO]++;
            pPlayer[0].resource[4] -= 2;
            bank_res[4] += 2;
        }
        else if( pPlayer[0].resource[4] < 2 )
        {
            printf( "Sorry. You don't have enough cards.\n" );
        }
        else
        {
            printf( "Sorry. There is no enough resource.\n" );
        }
    }
    else if( pVertex[port_NO].port == 6 ) 
    {
        int32_t resource_out = 0;
        printf( "Choose the things that you want to take for exchange: \n" );
        scanf( "%d" , &resource_out );

        if( resource_NO == resource_out )
        {
            printf( "Did you exchange for the same thing? Fool!\n" );
            return;
        }
        
        if( bank_res[resource_NO] != 0 )
        {
            pPlayer[0].resource[resource_NO]++;
            pPlayer[0].resource[resource_out] -= 3;
            bank_res[0] += 3;
        }
        else if( pPlayer[0].resource[resource_out] < 3 )
        {
            printf( "Sorry. You don't have enough cards.\n" );
        }
        else
        {
            printf( "Sorry. There is no enough resource.\n" );
        }
    }
}

void print_player_possession( sPlayer *pPlayer )
{
    for( int32_t i = 0; i < 1; i++ )
    {
        printf( "Player %d:\n", i + 1 );
        for( size_t j = 0; j < 5; j++ )
        {
            printf( "%4d" , pPlayer[i].resource[j] );
        }
        printf( "\n" );
        for( size_t j = 0; j < 3; j++ )
        {
            printf( "%4d" , pPlayer[i].building[j] );
        }
        printf( "\n" );
        for( size_t j = 0; j < 5; j++ )
        {
            printf( "%4d" , pPlayer[i].develop[j] );
        }
        printf( "\n" );
        for( size_t j = 0; j < 5; j++ )
        {
            printf( "%4d" , pPlayer[i].new_deve[j] );
        }
        printf( "\n" );
        for( size_t j = 0; j < 2; j++ )
        {
            printf( "%4d" , pPlayer[i].special[j] );
        }
        printf( "\n" );
    }
}
