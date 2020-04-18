
bool trees(int x, int y, int z) {
	
	for (int X = (x - 3); X < (x + 3); X++)
		for (int Y = y; Y < (y + 3); Y++)
			for (int Z = (z - 3); Z < (z + 3); Z++)
				if (cubes[X][Y][Z] == TREE_OAK)
					return 0;

	for (int X = 0; X < 5; X++)
		for (int Y = 0; Y < 7; Y++)
			for (int Z = 0; Z < 5; Z++) {
				if (tree_mass[Y][X][Z] != 0)
					cubes[x+X-2][y+Y + 1][z+Z-2] = tree_mass[Y][X][Z];
			}
	return 1;
	
}
bool head_monument(int x, int y, int z) {
	for (int X = 0; X < 5; X++)
		for (int Y = 0; Y < 12; Y++)
			for (int Z = 0; Z < 6; Z++) {
				if (house_mass[Y][X][Z] != 0)
					cubes[x + X - 2][y + Y][z + Z - 3] = house_mass[Y][X][Z];
			}
	return 1;
}