void computer_build_road( sPlayer *pPlayer, sVertex *pVertex, sLine *pLine, int32_t bank_res[], int32_t vertex_neighbor[][3], int32_t line_neighbor[][4], int32_t player_NO )
{
    if( pPlayer[player_NO].resource[1] < 1 || pPlayer[player_NO].resource[4] < 1 )
    {
        printf( "Player %d doesn't have enough resources to build a road.\n", player_NO+1 );
    }

	if( pPlayer[player_NO].building[1] == 15 )
	{
		printf( "Sorry. You can not build a road.\n" );
		return;
	}

	int32_t line_NO = 0;
	int32_t isVertexVillage = 0;
	for( int32_t i = 0; i < 54; i++ )
	{	
		if( pVertex[i].village == player_NO )
		{
			for( int32_t j = 0; j < 3; j++ )
			{
				if( vertex_neighbor[i][j] == 0 )
				{
					pLine[vertex_neighbor[i][j]].road = player_NO;
					line_NO = vertex_neighbor[i][j];
					isVertexVillage = 1;
					break;
				}
			}
		}
	}

	if( isVertexVillage == 1 )
	{
		pPlayer[player_NO].resource[1]--;
		pPlayer[player_NO].resource[4]--;
		pPlayer[player_NO].building[1]++;
		return;
	}

	int32_t available = 0;
	for( int32_t i = 0; i < 72; i++ )
	{
		if( pLine[i].road == player_NO )
		{
			for( int32_t j = 0; j < 4; j++ )
			{
				available = isAvailable( pLine[i].road, pLine[line_neighbor[i][j]].road, vertex_neighbor, pVertex, player_NO );
				if( pLine[line_neighbor[i][j]].road == 0 && available == 0 )
				{
					pLine[line_neighbor[i][j]].road = player_NO;
					line_NO = line_neighbor[i][j];
					break;
				}
			}
		}
	}

    pPlayer[player_NO].resource[1]--;
    pPlayer[player_NO].resource[4]--;
    pPlayer[player_NO].building[1]++;
}
