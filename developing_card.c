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
	int32_t develop[5];  // 三種發展卡 0: 騎士卡 1: 進程卡 (資源壟斷) 2: 進程卡 (創新發明) 3: 進程卡 (道路建設) 4: 分數卡
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
    pPlayer[0].resource[0] = 1;
    pPlayer[0].resource[1] = 2;
    pPlayer[0].resource[2] = 3;
    pPlayer[0].resource[3] = 2;
    pPlayer[0].resource[4] = 1;
    pPlayer[0].building[0] = 0;
    pPlayer[0].building[1] = 0;
    pPlayer[0].building[2] = 0;
    pPlayer[0].develop[0] = 2;
    pPlayer[0].develop[1] = 1;
    pPlayer[0].develop[2] = 3;
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

void buy_developing_card( sPlayer *pPlayer, int32_t tdc[], int32_t bank_res[] )
{
    for ( size_t i = 0; i < 5; i++ )
    {
        if( pPlayer[0].new_deve[i] == 1 )
        {
            pPlayer[0].develop[i]++;
            pPlayer[0].new_deve[i]--;
        }
    }

    int32_t choice = 0;
    printf( "Do you want to buy a developing card from the bank?\n");
    printf( "( 0: No, 1: Yes ): " );
    scanf( "%d", &choice );

    if( choice == 0 )
    {
        printf( "Bye.\n" );
    }
    else if( choice == 1 )
    {

        if ( pPlayer[0].resource[0] == 0 || pPlayer[0].resource[2] == 0 || pPlayer[0].resource[3] == 0 )
        {
            printf( "Sorry. You don't have enough resources to buy a developing card.\n" );
            return;
        }
        
        int32_t category = 0;
        printf( "Which category do you want?\n" );
        printf( "[ 0: Knight card, 1: Progressing card ( monopoly )\n");
        printf( "  2: Progress card ( acquire resource from the bank )\n" );
        printf( "  3: 2 free roads, 4: Score card ]: " );
        scanf( "%d" , &category );
        
        if( category < 0 || category > 4 )
        {
            printf( "Ivaild input. You lost the chance.\n" );
            return;
        }

        if( tdc[category] == 0 )
        {
            printf( "There is no enough such cards.\n" );
            return;
        }

        for ( size_t i = 0; i < 5; i++ )
        {
            if( i == category && tdc[i] != 0 )
            {
                pPlayer[0].new_deve[i]++;
                tdc[i]--;
                printf( "You successfully got the card.\n" );
                break;
            }
        }
        pPlayer[0].resource[0]--;
        pPlayer[0].resource[2]--;
        pPlayer[0].resource[3]--;
        bank_res[0]++;
        bank_res[2]++;
        bank_res[3]++;
    }
    else
    {
        printf( "Ivaild Input. You lost the chance in this turn.\n" );
    }
}

void progressing_card( sPlayer *pPlayer, int32_t bank_res[] )
{
    int32_t choice = 0;
    printf( "Which progressing card do you want to use in this turn?\n" );
    printf( "( 0: No,thanks. 1: Monopoly 2: Acquire resources from bank 3: 2 free roads ): ");
    scanf( "%d" , &choice );
    
    if( choice > 0 && choice <= 3 )
    {
        if( pPlayer[0].develop[choice] == 0 )
        {
            printf( "You don't have enough progressing cards.\n" );
            return;
        }
    }

    // resource
    // [0]: 麥田 => 生產小麥
    // [1]: 森林 => 生產木頭
    // [2]: 草原 => 生產羊毛
    // [3]: 山脈 => 生產石頭
    // [4]: 丘陵 => 生產磚頭

    int32_t resource_NO = 0;
    if( choice == 0 )
    {
        printf( "Bye!\n" );
    }
    else if( choice == 1 )
    {
        printf( "Which one do you want?\n" );
        printf( "( 0: Wheat, 1: Woods, 2: Wool, 3: Rocks, 4: Bricks ): ");
        scanf( "%d" , &resource_NO );

        // suppose the gamer is the player 1
        int32_t sum = 0;
        for( size_t i = 1; i < 4; i++ )
        {
            sum += pPlayer[i].resource[resource_NO];
            pPlayer[i].resource[resource_NO] = 0;
        }
        pPlayer[0].resource[resource_NO] += sum;
        pPlayer[0].develop[1]--;
    }
    else if( choice == 2 )
    {
        printf( "Which one do you want?\n" );
        printf( "( 0: Wheat, 1: Woods, 2: Wool, 3: Rocks, 4: Bricks ): ");
        scanf( "%d" , &resource_NO );

        // suppose the gamer is the player 1
        if( bank_res[resource_NO] >= 2 )
        {
            pPlayer[0].resource[resource_NO] += 2;
            bank_res[resource_NO] -= 2;
            pPlayer[0].develop[2]--;
        }
        else
        {
            printf( "Sorry. There is no enough roads remaining.\n" );
        }
    }
    else if( choice == 3 )
    {
        int32_t road1 = 0;
        int32_t road2 = 0;

        // suppose the gamer is player 1
        if( pPlayer[0].building[0] <= 13 )
        {
            printf( "Choose the road that you want to build.\n" );
            printf( "Road 1: ");
            scanf( "%d" , &road1 );
            printf( "Road 2: ");
            scanf( "%d" , &road2 );
            printf( "The roads were successfully built.\n" );
            pPlayer[0].building[1] += 2;
            pPlayer[0].develop[3]--;
        }
        else
        {
            printf( "You can not biuld another 2 roads anymore.\n" );
        }
    }
    else
    {
        printf( "Ivaild Input. You lost the chance in this turn.\n" );
    }
}

void score_card( sPlayer *pPlayer )
{
    int32_t choice = 0;
    printf( "Do you want to show one of your score cards?\n" );
    printf( "( 0: No, 1: Yes ): ");
    scanf( "%d" , &choice );

    if( choice == 0 )
    {
        printf( "Bye!\n" );
        return;
    }
    else if( choice > 1 )
    {
        printf( "Invaild Input.\n" );
        return;
    }

    int32_t quantity = 0;
    printf( "The number of score cards that you want to use: ");
    scanf( "%d" , &quantity );

    if( choice == 1 && pPlayer[0].develop[2] >= quantity )
    {
        pPlayer[0].develop[4] -= quantity;
        // points += quantity;
    }
    else if( choice == 1 && pPlayer[0].develop[2] < quantity )
    {
        printf( "Sorry. You don't have enough score cards.\n" );
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
