//我有稍微改一下編號，跟line上傳的不太一樣，我把點、邊、板塊都從0開始編，這樣大家可能寫他們的陣列時比較值觀(第幾個陣列的元素就是地圖上的第幾個)
void init_map( Plate *ArrayPlate )
{
	//Line 1
	printf("            ");
	for(int32_t i = 0; i < 3; i++)
	{
		printf("\033[0;32m%02d\033[m      ", i);
	}
	printf("      \n");

	//Line 2
	printf("          ");
	for(int32_t i = 0; i < 6; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
	}
	printf("        \n");

	//Line 3
	printf("        ");
	for(int32_t i = 3; i < 7; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("  \n");
	
	//Line 4
	printf("        ");
	for(int32_t i = 6; i < 9; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
		printf("%02d", ArrayPlate[i - 6].res_num);
		printf("  ");
	}
	printf("\033[0;33m09\033[m");
	printf("        \n");

	//Line 5
	printf("        ");
	for(int32_t i = 7; i < 11; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("  \n");

	//Line 6
	printf("      ");
	for(int32_t i = 10; i < 18; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
	}
	printf("    \n");
	
	//Line 7
	printf("    ");
	for(int32_t i = 11; i < 15; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("\033[0;32m15\033[m    \n");
	
	//Line 8
	printf("    ");
	for(int32_t i = 18; i < 22; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
		printf("%02d", ArrayPlate[i - 15].res_num);
		printf("  ");
	}
	printf("\033[0;33m22\033[m    \n");

	//Line 9
	printf("    ");
	for(int32_t i = 16; i < 20; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("\033[0;32m20\033[m    \n");

	//Line 10
	printf("  ");
	for(int32_t i = 23; i < 33; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
	}
	printf("\n");

	//Line 11
	for(int32_t i = 21; i < 26; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("\033[0;32m26\033[m\n");

	//Line 12
	for(int32_t i = 33; i < 38; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
		printf("%02d", ArrayPlate[i - 26].res_num);
		printf("  ");
	}
	printf("\033[0;33m38\033[m\n");

	//Line 13
	for(int32_t i = 27; i < 32; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("\033[0;32m32\033[m\n");

	//Line 14
	printf("  ");
	for(int32_t i = 39; i < 49; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
	}
	printf("\n");

	//Line 15
	printf("    ");
	for(int32_t i = 33; i < 37; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("\033[0;32m37\033[m    \n");

	//Line 16
	printf("    ");
	for(int32_t i = 49; i < 53; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
		printf("%02d", ArrayPlate[i - 37].res_num);
		printf("  ");
	}
	printf("\033[0;33m53\033[m    \n");

	//Line 17
	printf("    ");
	for(int32_t i = 38; i < 42; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("\033[0;32m42\033[m    \n");

	//Line 18
	printf("      ");
	for(int32_t i = 54; i < 62; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
	}
	printf("    \n");

	//Line 19
	printf("        ");
	for(int32_t i = 43; i < 47; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("  \n");

	//Line 20
	printf("        ");
	for(int32_t i = 62; i < 65; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
		printf("%02d", ArrayPlate[i - 46].res_num);
		printf("  ");
	}
	printf("\033[0;33m65\033[m        \n");

	//Line 21
	printf("        ");
	for(int32_t i = 47; i < 50; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("  \n");

	//Line 22
	printf("          ");
	for(int32_t i = 66; i < 72; i++)
	{
		printf("\033[0;33m%02d\033[m", i);
		printf("  ");
	}
	printf("        \n");

	//Line 23
	printf("            ");
	for(int32_t i = 51; i < 54; i++)
	{
		printf("\033[0;32m%02d\033[m", i);
		printf("      ");
	}
	printf("      \n");

	return;
}