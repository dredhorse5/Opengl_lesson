#ifndef __TEXTURES_H__
#define __TEXTURES_H__
//void draw_stone(int X, int Y, int Z, int PX, int PY, int PZ) {
    //    //bool cubes = cubes;
    //    glBindTexture(GL_TEXTURE_2D, stone[0]);
    //    glBegin(GL_QUADS);
    //    ///задняя
    //    glColor3f(0.8, 0.8, 0.8);
    //     if ((PZ / 2 + 0.5 > Z) and !cubes[X][Y][Z + 1]) {
    //        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    //    }
    //    //передняя
    //    if ((PZ / 2 + 0.5 < Z) and !cubes[X][Y][Z - 1]) { // Z == 0 or  { // Z == 0 or 
    //        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    //    }
    //    //ПРАВАЯ
    //        glColor3f(0.7, 0.7, 0.7);
    //    if ((PX / 2 + 0.5 > X) and !cubes[X+1][Y][Z]) {
    //        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    //    }
    //    //ЛЕВАЯ
    //    if ((PX / 2 + 0.5 < X) and !cubes[X - 1][Y][Z]) { // X == 0 or 
    //        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    //    }
    //    glColor3f(0.5, 0.5, 0.5);
    //    //НИЖНЯЯ
    //    if ((PY / 2 + 0.5 < Y) and !cubes[X][Y - 1][Z]) {
    //        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    //    }
    //    glColor3f(1, 1, 1);
    //    //ВЕРХНЯЯ
    //    if ((PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
    //        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    //    }
    //    glEnd();
    //}
    //void draw_planks( int X, int Y, int Z, int PX, int PY, int PZ)
    //{
    //    //bool cubes = cubes;
    //    glBindTexture(GL_TEXTURE_2D, planks[0]);
    //    glBegin(GL_QUADS);
    //    ///задняя
    //    glColor3f(0.8, 0.8, 0.8);
    //     if ((PZ / 2 + 0.5 > Z) and !cubes[X][Y][Z + 1]) {
    //        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    //    }
    //    //передняя
    //    if ((PZ / 2 + 0.5 < Z) and !cubes[X][Y][Z - 1]) { // Z == 0 or  { // Z == 0 or 
    //        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    //    }
    //    //ПРАВАЯ
    //    glColor3f(0.7, 0.7, 0.7);
    //    if ((PX / 2 + 0.5 > X) and !cubes[X+1][Y][Z]) {
    //        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    //    }
    //    //ЛЕВАЯ
    //    if ((PX / 2 + 0.5 < X) and !cubes[X - 1][Y][Z]) { // X == 0 or 
    //        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    //    }
    //    glColor3f(0.5, 0.5, 0.5);
    //    //НИЖНЯЯ
    //    if ((PY / 2 + 0.5 < Y) and !cubes[X][Y - 1][Z]) {
    //        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    //    }
    //    glColor3f(1, 1, 1);
    //    //ВЕРХНЯЯ
    //    if ((PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
    //        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    //    }
    //    glEnd();
    //
    //}
    //void draw_dirt( int X, int Y, int Z,  int PX, int PY, int PZ) {
    //    glBindTexture(GL_TEXTURE_2D, dirt[0]);
    //    glBegin(GL_QUADS);
    //    ///задняя
    //    glColor3f(0.8, 0.8, 0.8);
    //     if ((PZ / 2 + 0.5 > Z) and !cubes[X][Y][Z + 1]) {
    //        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    //    }
    //    //передняя
    //    if ((PZ / 2 + 0.5 < Z) and !cubes[X][Y][Z - 1]) { // Z == 0 or  { // Z == 0 or 
    //        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    //    }
    //    //ПРАВАЯ
    //    glColor3f(0.7, 0.7, 0.7);
    //    if ((PX / 2 + 0.5 > X) and !cubes[X+1][Y][Z]) {
    //        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    //    }
    //    //ЛЕВАЯ
    //    if ((PX / 2 + 0.5 < X) and !cubes[X - 1][Y][Z]) { // X == 0 or 
    //        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    //    }
    //    glColor3f(0.5, 0.5, 0.5);
    //    //НИЖНЯЯ
    //    if ((PY / 2 + 0.5 < Y) and !cubes[X][Y - 1][Z]) {
    //        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    //    }
    //    glColor3f(1, 1, 1);
    //    //ВЕРХНЯЯ
    //    if ((PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
    //        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    //    }
    //    glEnd();
    //}
    //void draw_leaves( int X, int Y, int Z,  int PX, int PY, int PZ) {
    //    //bool cubes = cubes;
    //    glBindTexture(GL_TEXTURE_2D, leaves[0]);
    //    glBegin(GL_QUADS);
    //    ///задняя
    //    glColor3f(0.8, 0.8, 0.8);
    //     if ((PZ / 2 + 0.5 > Z) and !cubes[X][Y][Z + 1]) {
    //        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    //    }
    //    //передняя
    //    if ((PZ / 2 + 0.5 < Z) and !cubes[X][Y][Z - 1]) { // Z == 0 or  { // Z == 0 or 
    //        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    //    }
    //    //ПРАВАЯ
    //    glColor3f(0.7, 0.7, 0.7);
    //    if ((PX / 2 + 0.5 > X) and !cubes[X+1][Y][Z]) {
    //        glTexCoord2d(1, 1); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    //    }
    //    //ЛЕВАЯ
    //    if ((PX / 2 + 0.5 < X) and !cubes[X - 1][Y][Z]) { // X == 0 or 
    //        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    //    }
    //    glColor3f(0.5, 0.5, 0.5);
    //    //НИЖНЯЯ
    //    if ((PY / 2 + 0.5 < Y) and !cubes[X][Y - 1][Z]) {
    //        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    //    }
    //    glColor3f(1, 1, 1);
    //    //ВЕРХНЯЯ
    //    if ((PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
    //        glTexCoord2d(1, 1); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 1); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    //        glTexCoord2d(0, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    //        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    //    }
    //    glEnd();
    //}
//void draw_cobblestone(int X, int Y, int Z, int PX, int PY, int PZ) {
//    glBindTexture(GL_TEXTURE_2D, cobblestone_tex[0]);
//    glBegin(GL_QUADS);
//    ///задняя
//    glColor3f(0.8, 0.8, 0.8);
//    if ((PZ / 2 + 0.5 > Z) and !cubes[X][Y][Z + 1]) {
//        glTexCoord2d(1, 1); glVertex3f(cube_size / 2, -cube_size / 2, cube_size / 2);
//        glTexCoord2d(0, 1); glVertex3f(-cube_size / 2, -cube_size / 2, cube_size / 2);
//        glTexCoord2d(0, 0); glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
//        glTexCoord2d(1, 0); glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
//    }
//    //передняя
//    if ((PZ / 2 + 0.5 < Z) and !cubes[X][Y][Z - 1]) { // Z == 0 or  { // Z == 0 or 
//        glTexCoord2d(1, 1); glVertex3f(-cube_size / 2, -cube_size / 2, -cube_size / 2);
//        glTexCoord2d(0, 1); glVertex3f(cube_size / 2, -cube_size / 2, -cube_size / 2);
//        glTexCoord2d(0, 0); glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
//        glTexCoord2d(1, 0); glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
//    }
//    //ПРАВАЯ
//    glColor3f(0.7, 0.7, 0.7);
//    if ((PX / 2 + 0.5 > X) and !cubes[X + 1][Y][Z]) {
//        glTexCoord2d(1, 1); glVertex3f(cube_size / 2, -cube_size / 2, -cube_size / 2);
//        glTexCoord2d(0, 1); glVertex3f(cube_size / 2, -cube_size / 2, cube_size / 2);
//        glTexCoord2d(0, 0); glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
//        glTexCoord2d(1, 0); glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
//    }
//    //ЛЕВАЯ
//    if ((PX / 2 + 0.5 < X) and !cubes[X - 1][Y][Z]) { // X == 0 or 
//        glTexCoord2d(1, 1); glVertex3f(-cube_size / 2, -cube_size / 2, cube_size / 2);
//        glTexCoord2d(0, 1); glVertex3f(-cube_size / 2, -cube_size / 2, -cube_size / 2);
//        glTexCoord2d(0, 0); glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
//        glTexCoord2d(1, 0); glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
//    }
//    glColor3f(0.5, 0.5, 0.5);
//    //НИЖНЯЯ
//    if ((PY / 2 + 0.5 < Y) and !cubes[X][Y - 1][Z]) {
//        glTexCoord2d(1, 1); glVertex3f(-cube_size / 2, -cube_size / 2, cube_size / 2);
//        glTexCoord2d(0, 1); glVertex3f(cube_size / 2, -cube_size / 2, cube_size / 2);
//        glTexCoord2d(0, 0); glVertex3f(cube_size / 2, -cube_size / 2, -cube_size / 2);
//        glTexCoord2d(1, 0); glVertex3f(-cube_size / 2, -cube_size / 2, -cube_size / 2);
//    }
//    glColor3f(1, 1, 1);
//    //ВЕРХНЯЯ
//    if ((PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
//        glTexCoord2d(1, 1); glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
//        glTexCoord2d(0, 1); glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
//        glTexCoord2d(0, 0); glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
//        glTexCoord2d(1, 0); glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
//    }
//    glEnd();
//}
//void draw_bricks(int X, int Y, int Z, int PX, int PY, int PZ) {
//    glBindTexture(GL_TEXTURE_2D, bricks[0]);
//    glBegin(GL_QUADS);
//    ///задняя
//    glColor3f(0.8, 0.8, 0.8);
//    if ((PZ / 2 + 0.5 > Z) and !cubes[X][Y][Z + 1]) {
//        glTexCoord2d(1, 1); glVertex3f(cube_size / 2, -cube_size / 2, cube_size / 2);
//        glTexCoord2d(0, 1); glVertex3f(-cube_size / 2, -cube_size / 2, cube_size / 2);
//        glTexCoord2d(0, 0); glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
//        glTexCoord2d(1, 0); glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
//    }
//    //передняя
//    if ((PZ / 2 + 0.5 < Z) and !cubes[X][Y][Z - 1]) { // Z == 0 or  { // Z == 0 or 
//        glTexCoord2d(1, 1); glVertex3f(-cube_size / 2, -cube_size / 2, -cube_size / 2);
//        glTexCoord2d(0, 1); glVertex3f(cube_size / 2, -cube_size / 2, -cube_size / 2);
//        glTexCoord2d(0, 0); glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
//        glTexCoord2d(1, 0); glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
//    }
//    //ПРАВАЯ
//    glColor3f(0.7, 0.7, 0.7);
//    if ((PX / 2 + 0.5 > X) and !cubes[X + 1][Y][Z]) {
//        glTexCoord2d(1, 1); glVertex3f(cube_size / 2, -cube_size / 2, -cube_size / 2);
//        glTexCoord2d(0, 1); glVertex3f(cube_size / 2, -cube_size / 2, cube_size / 2);
//        glTexCoord2d(0, 0); glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
//        glTexCoord2d(1, 0); glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
//    }
//    //ЛЕВАЯ
//    if ((PX / 2 + 0.5 < X) and !cubes[X - 1][Y][Z]) { // X == 0 or 
//        glTexCoord2d(1, 1); glVertex3f(-cube_size / 2, -cube_size / 2, cube_size / 2);
//        glTexCoord2d(0, 1); glVertex3f(-cube_size / 2, -cube_size / 2, -cube_size / 2);
//        glTexCoord2d(0, 0); glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
//        glTexCoord2d(1, 0); glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
//    }
//    glColor3f(0.5, 0.5, 0.5);
//    //НИЖНЯЯ
//    if ((PY / 2 + 0.5 < Y) and !cubes[X][Y - 1][Z]) {
//        glTexCoord2d(1, 1); glVertex3f(-cube_size / 2, -cube_size / 2, cube_size / 2);
//        glTexCoord2d(0, 1); glVertex3f(cube_size / 2, -cube_size / 2, cube_size / 2);
//        glTexCoord2d(0, 0); glVertex3f(cube_size / 2, -cube_size / 2, -cube_size / 2);
//        glTexCoord2d(1, 0); glVertex3f(-cube_size / 2, -cube_size / 2, -cube_size / 2);
//    }
//    glColor3f(1, 1, 1);
//    //ВЕРХНЯЯ
//    if ((PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
//        glTexCoord2d(1, 1); glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
//        glTexCoord2d(0, 1); glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
//        glTexCoord2d(0, 0); glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
//        glTexCoord2d(1, 0); glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
//    }
//    glEnd();
//}
void draw_super_grass( int X, int Y, int Z, int PX, int PY, int PZ)
{ 

    glBindTexture(GL_TEXTURE_2D, super_grass);
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
     //ВЕРХНЯЯ
    glColor3f(1, 1, 1);
    if (((X+Y+Z)%4 == 0) and (PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
        glTexCoord2d(1, 0.5); glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(0.5, 0.5); glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
        glTexCoord2d(0.5, 0); glVertex3f(cube_size/2, cube_size/2, cube_size/2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    }
    if (((X+Y+Z)%4 == 1) and (PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
        glTexCoord2d(0.5, 0.5); glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
        glTexCoord2d(0.5, 0); glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
        glTexCoord2d(1, 0); glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
        glTexCoord2d(1, 0.5); glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
    }
    if (((X+Y+Z)%4 == 2) and (PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
        glTexCoord2d(0.5, 0); glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
        glTexCoord2d(1, 0); glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
        glTexCoord2d(1, 0.5); glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
        glTexCoord2d(0.5, 0.5); glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
    }
    if (((X+Y+Z)%4 == 3) and (PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
        glTexCoord2d(1, 0); glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
        glTexCoord2d(1, 0.5); glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
        glTexCoord2d(0.5, 0.5); glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
        glTexCoord2d(0.5, 0); glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
    }
    glEnd();
}
void draw_tree_oak( int X, int Y, int Z,  int PX, int PY, int PZ) {
    //bool cubes = cubes;
    glBindTexture(GL_TEXTURE_2D, tree_oak);
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
    if ((PX / 2 + 0.5 > X) and !cubes[X + 1][Y][Z]) {
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

void one_texture_blocks(GLuint textures, int X, int Y, int Z, int PX, int PY, int PZ) {
    glBindTexture(GL_TEXTURE_2D, textures);
    glBegin(GL_QUADS);
    ///задняя
    glColor3f(0.8, 0.8, 0.8);
    if ((PZ / 2 + 0.5 > Z) and !cubes[X][Y][Z + 1]) {
        glTexCoord2d(1, 1); glVertex3f(cube_size / 2, -cube_size / 2, cube_size / 2);
        glTexCoord2d(0, 1); glVertex3f(-cube_size / 2, -cube_size / 2, cube_size / 2);
        glTexCoord2d(0, 0); glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
        glTexCoord2d(1, 0); glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
    }
    //передняя
    if ((PZ / 2 + 0.5 < Z) and !cubes[X][Y][Z - 1]) { // Z == 0 or  { // Z == 0 or 
        glTexCoord2d(1, 1); glVertex3f(-cube_size / 2, -cube_size / 2, -cube_size / 2);
        glTexCoord2d(0, 1); glVertex3f(cube_size / 2, -cube_size / 2, -cube_size / 2);
        glTexCoord2d(0, 0); glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
    }
    //ПРАВАЯ
    glColor3f(0.7, 0.7, 0.7);
    if ((PX / 2 + 0.5 > X) and !cubes[X + 1][Y][Z]) {
        glTexCoord2d(1, 1); glVertex3f(cube_size / 2, -cube_size / 2, -cube_size / 2);
        glTexCoord2d(0, 1); glVertex3f(cube_size / 2, -cube_size / 2, cube_size / 2);
        glTexCoord2d(0, 0); glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
        glTexCoord2d(1, 0); glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
    }
    //ЛЕВАЯ
    if ((PX / 2 + 0.5 < X) and !cubes[X - 1][Y][Z]) { // X == 0 or 
        glTexCoord2d(1, 1); glVertex3f(-cube_size / 2, -cube_size / 2, cube_size / 2);
        glTexCoord2d(0, 1); glVertex3f(-cube_size / 2, -cube_size / 2, -cube_size / 2);
        glTexCoord2d(0, 0); glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
    }
    glColor3f(0.5, 0.5, 0.5);
    //НИЖНЯЯ
    if ((PY / 2 + 0.5 < Y) and !cubes[X][Y - 1][Z]) {
        glTexCoord2d(1, 1); glVertex3f(-cube_size / 2, -cube_size / 2, cube_size / 2);
        glTexCoord2d(0, 1); glVertex3f(cube_size / 2, -cube_size / 2, cube_size / 2);
        glTexCoord2d(0, 0); glVertex3f(cube_size / 2, -cube_size / 2, -cube_size / 2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size / 2, -cube_size / 2, -cube_size / 2);
    }
    glColor3f(1, 1, 1);
    //ВЕРХНЯЯ
    if ((PY / 2 + 0.5 > Y) and !cubes[X][Y + 1][Z]) { // Y == 0 or 
        glTexCoord2d(1, 1); glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
        glTexCoord2d(0, 1); glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
        glTexCoord2d(0, 0); glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
        glTexCoord2d(1, 0); glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
    }
    glEnd();
}

void drawSkybox()
{
    glTranslatef(steve.PlayerX, steve.PlayerY, steve.PlayerZ);
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies);
    glBegin(GL_QUADS);
    //задняя
    glTexCoord2d(0.001f, 0.665f); glVertex3f(-400, -400, 400);
    glTexCoord2d(0.25f, 0.665f); glVertex3f(400, -400, 400);
    glTexCoord2d(0.25f, 0.334f); glVertex3f(400, 400, 400);
    glTexCoord2d(0.001f, 0.334f); glVertex3f(-400, 400, 400);
    //==================================================================
    //правая
    glTexCoord2d(0.25f, 0.666666f); glVertex3f(400, -400, 400);
    glTexCoord2d(0.5f, 0.666666f); glVertex3f(400, -400, -400);
    glTexCoord2d(0.5f, 0.334f); glVertex3f(400, 400, -400);
    glTexCoord2d(0.25f, 0.334f); glVertex3f(400, 400, 400);

    //передняя
    glTexCoord2d(0.5f, 0.334f); glVertex3f(400, 400, -400);
    glTexCoord2d(0.5f, 0.666666f); glVertex3f(400, -400, -400);
    glTexCoord2d(0.75f, 0.666666f); glVertex3f(-400, -400, -400);
    glTexCoord2d(0.75f, 0.334f); glVertex3f(-400, 400, -400);

    //левая
    glTexCoord2d(0.75, 0.666666f); glVertex3f(-400, -400, -400);
    glTexCoord2d(0.9999f, 0.666666f); glVertex3f(-400, -400, 400);
    glTexCoord2d(0.9999f, 0.334f); glVertex3f(-400, 400, 400);
    glTexCoord2d(0.75f, 0.334f); glVertex3f(-400, 400, -400);

    //нижняя
    glTexCoord2d(0.5f, 0.999f); glVertex3f(-400, -400, -400);
    glTexCoord2d(0.5f, 0.6666f);  glVertex3f(400, -400, -400);
    glTexCoord2d(0.25f, 0.6666f); glVertex3f(400, -400, 400);
    glTexCoord2d(0.25f, 0.999f);  glVertex3f(-400, -400, 400);
    //==================================================================
    
    //верхняя
    glBegin(GL_POLYGON);
    glTexCoord2d(0.2501f, 0.001f); glVertex3f(-400, 400, 400);
    glTexCoord2d(0.2501f, 0.33333f); glVertex3f(400, 400, 400);
    glTexCoord2d(0.4999f, 0.33333f); glVertex3f(400, 400, -400);
    glTexCoord2d(0.4999f, 0.001f);  glVertex3f(-400, 400, -400);
    
    glEnd();
    glTranslatef(-steve.PlayerX, -steve.PlayerY, -steve.PlayerZ);
}


#endif __TEXTURES_H__
                                            