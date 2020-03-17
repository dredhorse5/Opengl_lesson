#ifndef __TEXTURES_H__
#define __TEXTURES_H__
void draw_dirt(GLuint dirt[1], float cube_size,int X, int Y, int Z,bool cubes[300][100][300])
{

    glBindTexture(GL_TEXTURE_2D, dirt[0]);
    ///задн€€
    if ((cubes[X][Y][Z] != cubes[X][Y][Z + 1])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0.5); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0.5, 1); glVertex3f(-cube_size, cube_size, cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(cube_size, cube_size, cube_size);
        glEnd();
    }
    //ѕ–ј¬јя
    if ((cubes[X][Y][Z] != cubes[X+1][Y][Z])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0.5); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0.5, 1); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(cube_size, cube_size, -cube_size);
        glEnd();
    }
    //Ћ≈¬јя
    if (cubes[X - 1][Y][Z] != cubes[X][Y][Z]) { // X == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0.5); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0.5, 1); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    //передн€€
    if (cubes[X][Y][Z-1] != cubes[X][Y][Z]) { // Z == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0.5); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0.5, 1); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(-cube_size, cube_size, -cube_size);
        glEnd();
    }
     //¬≈–’Ќяя
    if (cubes[X][Y][Z] != cubes[X][Y + 1][Z]) { // Y == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0.5); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(0.5, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    //Ќ»∆Ќяя
    if (cubes[X][Y - 1][Z] != cubes[X][Y][Z]) {
        glBegin(GL_POLYGON);
        glTexCoord2d(0.5, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0.5); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(-cube_size, -cube_size, -cube_size);
        glEnd();
    }
   
}
void draw_stone(GLuint stone[1], float cube_size, int X, int Y, int Z, bool cubes[300][100][300]) {
    glBindTexture(GL_TEXTURE_2D, stone[0]);
    ///задн€€
    if ((cubes[X][Y][Z] != cubes[X][Y][Z + 1])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, cube_size);
        glEnd();
    }
    //ѕ–ј¬јя
    if ((cubes[X][Y][Z] != cubes[X + 1][Y][Z])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, -cube_size);
        glEnd();
    }
    //Ћ≈¬јя
    if (cubes[X - 1][Y][Z] != cubes[X][Y][Z]) { // X == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    //передн€€
    if (cubes[X][Y][Z - 1] != cubes[X][Y][Z]) { // Z == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, -cube_size);
        glEnd();
    }
    //¬≈–’Ќяя
    if (cubes[X][Y][Z] != cubes[X][Y + 1][Z]) { // Y == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    //Ќ»∆Ќяя
    if (cubes[X][Y - 1][Z] != cubes[X][Y][Z]) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
        glEnd();
    }
}
void draw_planks(GLuint planks[1], float cube_size, int X, int Y, int Z, bool cubes[300][100][300])
{
    glBindTexture(GL_TEXTURE_2D, planks[0]);
    ///задн€€
    if ((cubes[X][Y][Z] != cubes[X][Y][Z + 1])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, cube_size);
        glEnd();
    }
    //ѕ–ј¬јя
    if ((cubes[X][Y][Z] != cubes[X + 1][Y][Z])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, -cube_size);
        glEnd();
    }
    //Ћ≈¬јя
    if (cubes[X - 1][Y][Z] != cubes[X][Y][Z]) { // X == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    //передн€€
    if (cubes[X][Y][Z - 1] != cubes[X][Y][Z]) { // Z == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, -cube_size);
        glEnd();
    }
    //¬≈–’Ќяя
    if (cubes[X][Y][Z] != cubes[X][Y + 1][Z]) { // Y == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    //Ќ»∆Ќяя
    if (cubes[X][Y - 1][Z] != cubes[X][Y][Z]) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
        glEnd();
    }

}

void draw_lines_cubes(float cube_size,int X, int Y,int Z) {
    glLineWidth(4);
    //glColor3f(1, 1, 1);
    cube_size = cube_size/2 + 0.004;
    glTranslatef(X*2+1, Y*2+1, Z*2+1);
    //вертикальные
    glBegin(GL_LINES);
    glColor3d(0, 1, 1);
    glVertex3f(-cube_size, -cube_size, -cube_size);
    glVertex3f(-cube_size, cube_size, -cube_size);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(cube_size, -cube_size, -cube_size);
    glVertex3f(cube_size, cube_size, -cube_size);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(cube_size, -cube_size, cube_size);
    glVertex3f(cube_size, cube_size, cube_size);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-cube_size, -cube_size, cube_size);
    glVertex3f(-cube_size, cube_size, cube_size);
    glEnd();
    // нижние
    glBegin(GL_LINES);
    glVertex3f(-cube_size, -cube_size, -cube_size);
    glVertex3f(cube_size, -cube_size, -cube_size);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(cube_size, -cube_size, -cube_size);
    glVertex3f(cube_size, -cube_size, cube_size);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(cube_size, -cube_size, cube_size);
    glVertex3f(-cube_size, -cube_size, cube_size);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-cube_size, -cube_size, cube_size);
    glVertex3f(-cube_size, -cube_size, -cube_size);
    glEnd();
    //верхние
    glBegin(GL_LINES);
    glVertex3f(-cube_size, cube_size, -cube_size);
    glVertex3f(cube_size, cube_size, -cube_size);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(cube_size, cube_size, -cube_size);
    glVertex3f(cube_size, cube_size, cube_size);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(cube_size, cube_size, cube_size);
    glVertex3f(-cube_size, cube_size, cube_size);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-cube_size, cube_size, cube_size);
    glVertex3f(-cube_size, cube_size, -cube_size);
    glEnd();
    glTranslatef(-(X*2)-1, -Y*2-1, -Z*2-1);
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 1, 1);     // красный цвет

}

void drawSkybox(GLuint skybox_texturies[])
{
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[0]);
    //задн€€
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(-100, -100, 100);
    glTexCoord2d(0, 1); glVertex3f(100, -100, 100);
    glTexCoord2d(0, 0); glVertex3f(100, 100, 100);
    glTexCoord2d(1, 0); glVertex3f(-100, 100, 100);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[1]);
    //нижн€€
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 0); glVertex3f(-100, -100, -100);
    glTexCoord2d(1, 0); glVertex3f(100, -100, -100);
    glTexCoord2d(1, 1); glVertex3f(100, -100, 100);
    glTexCoord2d(0, 1); glVertex3f(-100, -100, 100);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[2]);
    //передн€€
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(100, 100, -100);
    glTexCoord2d(1, 1); glVertex3f(100, -100, -100);
    glTexCoord2d(0, 1); glVertex3f(-100, -100, -100);
    glTexCoord2d(0, 0); glVertex3f(-100, 100, -100);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[3]);
    //лева€
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(-100, -100, -100);
    glTexCoord2d(0, 1); glVertex3f(-100, -100, 100);
    glTexCoord2d(0, 0); glVertex3f(-100, 100, 100);
    glTexCoord2d(1, 0); glVertex3f(-100, 100, -100);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[4]);
    //права€
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(100, -100, 100);
    glTexCoord2d(0, 1); glVertex3f(100, -100, -100);
    glTexCoord2d(0, 0); glVertex3f(100, 100, -100);
    glTexCoord2d(1, 0); glVertex3f(100, 100, 100);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[5]);
    //верхн€€
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 0); glVertex3f(-100, 100, 100);
    glTexCoord2d(1, 0); glVertex3f(100, 100, 100);
    glTexCoord2d(1, 1); glVertex3f(100, 100, -100);
    glTexCoord2d(0, 1); glVertex3f(-100, 100, -100);
    glEnd();
    
}


#endif __TEXTURES_H__
