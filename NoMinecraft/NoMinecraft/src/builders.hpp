
void trees(int x, int y, int z) {
	
	cubes[x+2][y + 4][z-2] = 5; cubes[x + 2][y + 4][z - 1] = 5; cubes[x + 2][y + 4][z] = 5; cubes[x + 2][y + 4][z + 1] = 5; cubes[x + 2][y + 4][z + 2] = 5;
	cubes[x+1][y + 4][z-2] = 5; cubes[x + 1][y + 4][z - 1] = 5; cubes[x + 1][y + 4][z] = 5; cubes[x + 1][y + 4][z + 1] = 5; cubes[x + 1][y + 4][z + 2] = 5;
	cubes[x  ][y + 4][z-2] = 5; cubes[x    ][y + 4][z - 1] = 5;                             cubes[x    ][y + 4][z + 1] = 5; cubes[x][y + 4][z + 2]     = 5;
	cubes[x-1][y + 4][z-2] = 5; cubes[x - 1][y + 4][z - 1] = 5; cubes[x - 1][y + 4][z] = 5; cubes[x - 1][y + 4][z + 1] = 5; cubes[x - 1][y + 4][z + 2] = 5;
	cubes[x-2][y + 4][z-2] = 5; cubes[x - 2][y + 4][z - 1] = 5; cubes[x - 2][y + 4][z] = 5; cubes[x - 2][y + 4][z + 1] = 5; cubes[x - 2][y + 4][z + 2] = 5;

	cubes[x+2][y + 5][z-2] = 5; cubes[x + 2][y + 5][z - 1] = 5; cubes[x + 2][y + 5][z] = 5; cubes[x + 2][y + 5][z + 1] = 5; cubes[x + 2][y + 5][z + 2] = 5;
	cubes[x+1][y + 5][z-2] = 5; cubes[x + 1][y + 5][z - 1] = 5; cubes[x + 1][y + 5][z] = 5; cubes[x + 1][y + 5][z + 1] = 5; cubes[x + 1][y + 5][z + 2] = 5;
	cubes[x  ][y + 5][z-2] = 5; cubes[x    ][y + 5][z - 1] = 5;                             cubes[x    ][y + 5][z + 1] = 5; cubes[x][y + 5][z + 2]     = 5;
	cubes[x-1][y + 5][z-2] = 5; cubes[x - 1][y + 5][z - 1] = 5; cubes[x - 1][y + 5][z] = 5; cubes[x - 1][y + 5][z + 1] = 5; cubes[x - 1][y + 5][z + 2] = 5;
	cubes[x-2][y + 5][z-2] = 5; cubes[x - 2][y + 5][z - 1] = 5; cubes[x - 2][y + 5][z] = 5; cubes[x - 2][y + 5][z + 1] = 5; cubes[x - 2][y + 5][z + 2] = 5;
	
	cubes[x-1][y + 6][z-1] = 5; cubes[x - 1][y + 6][z] = 5; cubes[x - 1][y + 6][z + 1] = 5; 
	cubes[x  ][y + 6][z-1] = 5;                             cubes[x    ][y + 6][z + 1] = 5;
	cubes[x+1][y + 6][z-1] = 5; cubes[x + 1][y + 6][z] = 5; cubes[x + 1][y + 6][z + 1] = 5;  
	
	                            cubes[x - 1][y + 7][z] = 5; 
	cubes[x  ][y + 7][z-1] = 5; cubes[x    ][y + 7][z] = 5; cubes[x    ][y + 7][z + 1] = 5;
	                            cubes[x + 1][y + 7][z] = 5; 

	cubes[x][y + 1][z] = 6; cubes[x][y + 2][z] = 6; cubes[x][y + 3][z] = 6; cubes[x][y + 4][z] = 6; cubes[x][y + 5][z] = 6; cubes[x][y + 6][z] = 6;

}