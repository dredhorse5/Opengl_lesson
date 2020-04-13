#ifndef __TEXTURES_H__
#define __TEXTURES_H__
void draw_super_grass( int X, int Y, int Z, int PX, int PY, int PZ)
{ 

    glBindTexture(GL_TEXTURE_2D, super_grass[0]);
    glBegin(GL_QUADS);
    ///задняя 
    glColor3f(0.8, 0.8, 0.8); // cool glColor3f(1.8, 0.8, 0.8);
    if ((PZ / 2 + 0.5 > Z) and !cubes[X][Y][Z + 1]) {
        glTexCoord2d(1, 0.5); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0.5, 1); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(0.5, 0.5); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    }
    //передняя
    if ((PZ / 2 + 0.5 < Z) and !cubes[X][Y][Z - 1]) { // Z == 0 or 
        glTexCoord2d(1, 0.5); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0.5, 1); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(0.5, 0.5); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    }
    glColor3f(0.7, 0.7, 0.7);
    //ПРАВАЯ
    if ((PX / 2 + 0.5 > X) and !cubes[X+1][Y][Z]) {
        glTexCoord2d(1, 0.5); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0.5, 1); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(0.5, 0.5); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    }
    //ЛЕВАЯ
    if ((PX / 2 + 0.5 < X) and !cubes[X - 1][Y][Z]) { // X == 0 or 
        glTexCoord2d(1, 0.5); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0.5, 1); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(0.5, 0.5); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    }
    glColor3f(0.5, 0.5, 0.5);
    //НИЖНЯЯ
    if ((PY / 2 + 0.5 < Y) and !cubes[X][Y - 1][Z]) {
        glTexCoord2d(0.5, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 0.5); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0.5, 0.5); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    }
    glColor3f(1, 1, 1);
     //ВЕРХНЯЯ
    if ((PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
        glTexCoord2d(1, 0.5); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(0.5, 0.5); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(0.5, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    }
    glEnd();
}
void draw_stone(  int X, int Y, int Z, int PX, int PY, int PZ) {
    //bool cubes = cubes;
    glBindTexture(GL_TEXTURE_2D, stone[0]);
    glBegin(GL_QUADS);
    ///задняя
    glColor3f(0.8, 0.8, 0.8);
     if ((PZ / 2 + 0.5 > Z) and !cubes[X][Y][Z + 1]) {
        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    }
    //передняя
    if ((PZ / 2 + 0.5 < Z) and !cubes[X][Y][Z - 1]) { // Z == 0 or  { // Z == 0 or 
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    }
    //ПРАВАЯ
        glColor3f(0.7, 0.7, 0.7);
    if ((PX / 2 + 0.5 > X) and !cubes[X+1][Y][Z]) {
        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    }
    //ЛЕВАЯ
    if ((PX / 2 + 0.5 < X) and !cubes[X - 1][Y][Z]) { // X == 0 or 
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    }
    glColor3f(0.5, 0.5, 0.5);
    //НИЖНЯЯ
    if ((PY / 2 + 0.5 < Y) and !cubes[X][Y - 1][Z]) {
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    }
    glColor3f(1, 1, 1);
    //ВЕРХНЯЯ
    if ((PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    }
    glEnd();
}
void draw_planks( int X, int Y, int Z, int PX, int PY, int PZ)
{
    //bool cubes = cubes;
    glBindTexture(GL_TEXTURE_2D, planks[0]);
    glBegin(GL_QUADS);
    ///задняя
    glColor3f(0.8, 0.8, 0.8);
     if ((PZ / 2 + 0.5 > Z) and !cubes[X][Y][Z + 1]) {
        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    }
    //передняя
    if ((PZ / 2 + 0.5 < Z) and !cubes[X][Y][Z - 1]) { // Z == 0 or  { // Z == 0 or 
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    }
    //ПРАВАЯ
    glColor3f(0.7, 0.7, 0.7);
    if ((PX / 2 + 0.5 > X) and !cubes[X+1][Y][Z]) {
        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    }
    //ЛЕВАЯ
    if ((PX / 2 + 0.5 < X) and !cubes[X - 1][Y][Z]) { // X == 0 or 
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    }
    glColor3f(0.5, 0.5, 0.5);
    //НИЖНЯЯ
    if ((PY / 2 + 0.5 < Y) and !cubes[X][Y - 1][Z]) {
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    }
    glColor3f(1, 1, 1);
    //ВЕРХНЯЯ
    if ((PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    }
    glEnd();

}
void draw_dirt( int X, int Y, int Z,  int PX, int PY, int PZ) {
    //bool cubes = cubes;
    glBindTexture(GL_TEXTURE_2D, dirt[0]);
    glBegin(GL_QUADS);
    ///задняя
    glColor3f(0.8, 0.8, 0.8);
     if ((PZ / 2 + 0.5 > Z) and !cubes[X][Y][Z + 1]) {
        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    }
    //передняя
    if ((PZ / 2 + 0.5 < Z) and !cubes[X][Y][Z - 1]) { // Z == 0 or  { // Z == 0 or 
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    }
    //ПРАВАЯ
    glColor3f(0.7, 0.7, 0.7);
    if ((PX / 2 + 0.5 > X) and !cubes[X+1][Y][Z]) {
        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    }
    //ЛЕВАЯ
    if ((PX / 2 + 0.5 < X) and !cubes[X - 1][Y][Z]) { // X == 0 or 
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    }
    glColor3f(0.5, 0.5, 0.5);
    //НИЖНЯЯ
    if ((PY / 2 + 0.5 < Y) and !cubes[X][Y - 1][Z]) {
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    }
    glColor3f(1, 1, 1);
    //ВЕРХНЯЯ
    if ((PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    }
    glEnd();
}
void draw_leaves( int X, int Y, int Z,  int PX, int PY, int PZ) {
    //bool cubes = cubes;
    glBindTexture(GL_TEXTURE_2D, leaves[0]);
    glBegin(GL_QUADS);
    ///задняя
    glColor3f(0.8, 0.8, 0.8);
     if ((PZ / 2 + 0.5 > Z) and !cubes[X][Y][Z + 1]) {
        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    }
    //передняя
    if ((PZ / 2 + 0.5 < Z) and !cubes[X][Y][Z - 1]) { // Z == 0 or  { // Z == 0 or 
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    }
    //ПРАВАЯ
    glColor3f(0.7, 0.7, 0.7);
    if ((PX / 2 + 0.5 > X) and !cubes[X+1][Y][Z]) {
        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    }
    //ЛЕВАЯ
    if ((PX / 2 + 0.5 < X) and !cubes[X - 1][Y][Z]) { // X == 0 or 
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    }
    glColor3f(0.5, 0.5, 0.5);
    //НИЖНЯЯ
    if ((PY / 2 + 0.5 < Y) and !cubes[X][Y - 1][Z]) {
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    }
    glColor3f(1, 1, 1);
    //ВЕРХНЯЯ
    if ((PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    }
    glEnd();
}
void draw_tree_oak( int X, int Y, int Z,  int PX, int PY, int PZ) {
    //bool cubes = cubes;
    glBindTexture(GL_TEXTURE_2D, tree_oak[0]);
    glBegin(GL_QUADS);
    ///задняя
    glColor3f(0.8, 0.8, 0.8);
     if ((PZ / 2 + 0.5 > Z) and !cubes[X][Y][Z + 1]) {
        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0.5, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0.5, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    }
    //передняя
    if ((PZ / 2 + 0.5 < Z) and !cubes[X][Y][Z - 1]) { // Z == 0 or  
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0.5, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0.5, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    }
    //ПРАВАЯ
    glColor3f(0.7, 0.7, 0.7);
    if ((PX / 2 + 0.5 > X) and !cubes[X+1][Y][Z]) {
        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0.5, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0.5, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    }
    //ЛЕВАЯ
    if ((PX / 2 + 0.5 < X) and !cubes[X - 1][Y][Z]) { // X == 0 or 
        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0.5, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0.5, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    }
    glColor3f(0.5, 0.5, 0.5);
    //НИЖНЯЯ
    if ((PY / 2 + 0.5 < Y) and !cubes[X][Y - 1][Z]) {
        glTexCoord2d(0.5, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
        glTexCoord2d(0.5, 0); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    }
    glColor3f(1, 1, 1);
    //ВЕРХНЯЯ
    if ((PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
        glTexCoord2d(0.5, 1); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(0, 1); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(0.5, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    }
    glEnd();
}

void draw_lines_cubes(float cube_size,int X, int Y,int Z) {
    glLineWidth(2);
    cube_size = cube_size/2 + 0.004;
    glTranslatef(X*2+1, Y*2+1, Z*2+1);
    glBegin(GL_LINES);
    glColor3d(0, 0, 0);
    glVertex3f(-cube_size, -cube_size, -cube_size);
    glVertex3f(-cube_size, cube_size, -cube_size);

    glVertex3f(cube_size, -cube_size, -cube_size);
    glVertex3f(cube_size, cube_size, -cube_size);

    glVertex3f(cube_size, -cube_size, cube_size);
    glVertex3f(cube_size, cube_size, cube_size);

    glVertex3f(-cube_size, -cube_size, cube_size);
    glVertex3f(-cube_size, cube_size, cube_size);

    glVertex3f(-cube_size, -cube_size, -cube_size);
    glVertex3f(cube_size, -cube_size, -cube_size);

    glVertex3f(cube_size, -cube_size, -cube_size);
    glVertex3f(cube_size, -cube_size, cube_size);

    glVertex3f(cube_size, -cube_size, cube_size);
    glVertex3f(-cube_size, -cube_size, cube_size);

    glVertex3f(-cube_size, -cube_size, cube_size);
    glVertex3f(-cube_size, -cube_size, -cube_size);

    glVertex3f(-cube_size, cube_size, -cube_size);
    glVertex3f(cube_size, cube_size, -cube_size);

    glVertex3f(cube_size, cube_size, -cube_size);
    glVertex3f(cube_size, cube_size, cube_size);

    glVertex3f(cube_size, cube_size, cube_size);
    glVertex3f(-cube_size, cube_size, cube_size);

    glVertex3f(-cube_size, cube_size, cube_size);
    glVertex3f(-cube_size, cube_size, -cube_size);
    glEnd();
    glTranslatef(-(X*2)-1, -Y*2-1, -Z*2-1);
    glColor3d(1, 1, 1);

}

void drawSkybox(GLuint skybox_texturies[])
{
    glTranslatef(steve.PlayerX, steve.PlayerY, steve.PlayerZ);
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[0]);
    //задняя
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(-200, -200, 200);
    glTexCoord2d(0, 1); glVertex3f(200, -200, 200);
    glTexCoord2d(0, 0); glVertex3f(200, 200, 200);
    glTexCoord2d(1, 0); glVertex3f(-200, 200, 200);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[1]);
    //нижняя
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 0); glVertex3f(-200, -200, -200);
    glTexCoord2d(1, 0); glVertex3f(200, -200, -200);
    glTexCoord2d(1, 1); glVertex3f(200, -200, 200);
    glTexCoord2d(0, 1); glVertex3f(-200, -200, 200);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[2]);
    //передняя
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(200, 200, -200);
    glTexCoord2d(1, 1); glVertex3f(200, -200, -200);
    glTexCoord2d(0, 1); glVertex3f(-200, -200, -200);
    glTexCoord2d(0, 0); glVertex3f(-200, 200, -200);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[3]);
    //левая
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(-200, -200, -200);
    glTexCoord2d(0, 1); glVertex3f(-200, -200, 200);
    glTexCoord2d(0, 0); glVertex3f(-200, 200, 200);
    glTexCoord2d(1, 0); glVertex3f(-200, 200, -200);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[4]);
    //правая
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(200, -200, 200);
    glTexCoord2d(0, 1); glVertex3f(200, -200, -200);
    glTexCoord2d(0, 0); glVertex3f(200, 200, -200);
    glTexCoord2d(1, 0); glVertex3f(200, 200, 200);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[5]);
    //верхняя
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 0); glVertex3f(-200, 200, 200);
    glTexCoord2d(1, 0); glVertex3f(200, 200, 200);
    glTexCoord2d(1, 1); glVertex3f(200, 200, -200);
    glTexCoord2d(0, 1); glVertex3f(-200, 200, -200);
    glEnd();
    glTranslatef(-steve.PlayerX, -steve.PlayerY, -steve.PlayerZ);
}


#endif __TEXTURES_H__
                                            