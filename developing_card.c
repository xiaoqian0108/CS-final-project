#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct _Player
{
	int32_t resource[5];  // 五種資源
    	int32_t building[3];  // 三種建築
	int32_t develop[3];  // 三種發展卡 0:騎士卡 1:進程卡 2:分數卡
    	int32_t new_deve[3];  // 剛拿到的卡
	int32_t special[2];  // 特殊計分卡
}sPlayer;

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
    pPlayer[0].develop[2] = 0;
    pPlayer[0].new_deve[0] = 0;
    pPlayer[0].new_deve[1] = 0;
    pPlayer[0].new_deve[2] = 0;
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
    pPlayer[1].develop[1] = 2;
    pPlayer[1].develop[2] = 1;
    pPlayer[1].new_deve[0] = 0;
    pPlayer[1].new_deve[1] = 0;
    pPlayer[1].new_deve[2] = 0;
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
    pPlayer[2].develop[2] = 1;
    pPlayer[2].new_deve[0] = 0;
    pPlayer[2].new_deve[1] = 0;
    pPlayer[2].new_deve[2] = 0;
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
    pPlayer[3].develop[0] = 1;
    pPlayer[3].develop[1] = 0;
    pPlayer[3].develop[2] = 0;
    pPlayer[3].new_deve[0] = 0;
    pPlayer[3].new_deve[1] = 0;
    pPlayer[3].new_deve[2] = 0;
    pPlayer[3].special[0] = 0;
    pPlayer[3].special[1] = 0;
}

void buy_developing_card( sPlayer *pPlayer, int32_t tdc[] )
{
    int32_t choice = 0;
    printf( "Do you want to buy a developing card from the bank?\n");
    printf( "( 0: No, 1: Yes ): " );
    scanf( "%d", &choice );

    for ( size_t i = 0; i < 3; i++ )
    {
        if( pPlayer[0].new_deve[i] == 1 )
        {
            pPlayer[0].develop[i]++;
            pPlayer[0].new_deve[i]--;
        }
    }

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
        printf( "( 0: Knight card, 1: Progressing card, 2: Score card ): ");
        scanf( "%d" , &category );
        
        if( category < 0 || category > 2 )
        {
            printf( "Ivaild input. You lost the chance.\n" );
            return;
        }

        if( category == 0 && tdc[0] != 0 )
        {
            pPlayer[0].new_deve[0]++;
            tdc[0]--;
        }
        else if( category == 1 && tdc[1] != 0 )
        {
            pPlayer[0].new_deve[1]++;
            tdc[1]--;
        }
        else if( category == 2 && tdc[2] != 0 )
        {
            pPlayer[0].new_deve[2]++;
            tdc[2]--;
        }
        pPlayer[0].resource[0]--;
        pPlayer[0].resource[2]--;
        pPlayer[0].resource[3]--;
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
    printf( "( 0: No,thanks. 1: Monopoly 2:Acquire resources from bank 3: 2 free roads ): ");
    scanf( "%d" , &choice );

    if( choice != 0 && choice <= 3 )
    {
        if( pPlayer[0].develop[1] == 1 && pPlayer[0].new_deve[1] == 1 )
        {
            printf( "It is not permitted to use the progressing card you just acquired in the same turn.\n" );
            return;
        }
        if( pPlayer[0].develop[1] == 0 )
        {
            printf( "You don't have enough progressing cards.\n" );
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
        printf( "( 0: wheat, 1: Woods, 2: Wool, 3: Rocks, 4: Bricks ): ");
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
            pPlayer[0].building[0] += 2;
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

void score_card ( sPlayer *pPlayer )
{
    int32_t choice = 0;
    printf( "Do you want to show one of your score cards?\n" );
    printf( "( 0: No, 1: Yes ): ");
    scanf( "%d" , &choice );

    int32_t quantity = 0;
    printf( "The number of score cards that you want to use: ");
    scanf( "%d" , &quantity );

    if( choice == 0 )
    {
        printf( "Bye!\n" );
    }
    else if( choice == 1 && pPlayer[0].develop[2] >= quantity )
    {
        pPlayer[0].develop[2] -= quantity;
        // points += quantity;
    }
    else if( choice == 1 && pPlayer[0].develop[2] < quantity )
    {
        printf( "Sorry. You don't have enough score cards.\n" );
    }
    else
    {
        printf( "Invaild Input.\n" );
    }
}
