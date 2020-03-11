#ifndef __TEXTURES_H__
#define __TEXTURES_H__
void drawSkybox(GLuint skybox_texturies[])
{
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[0]);
    //задн€€
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(-400, -400, 400);
    glTexCoord2d(0, 1); glVertex3f(400, -400, 400);
    glTexCoord2d(0, 0); glVertex3f(400, 400, 400);
    glTexCoord2d(1, 0); glVertex3f(-400, 400, 400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[1]);
    //нижн€€
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 0); glVertex3f(-400, -400, -400);
    glTexCoord2d(1, 0); glVertex3f(400, -400, -400);
    glTexCoord2d(1, 1); glVertex3f(400, -400, 400);
    glTexCoord2d(0, 1); glVertex3f(-400, -400, 400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[2]);
    //передн€€
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(400, 400, -400);
    glTexCoord2d(1, 1); glVertex3f(400, -400, -400);
    glTexCoord2d(0, 1); glVertex3f(-400, -400, -400);
    glTexCoord2d(0, 0); glVertex3f(-400, 400, -400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[3]);
    //лева€
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(-400, -400, -400);
    glTexCoord2d(0, 1); glVertex3f(-400, -400, 400);
    glTexCoord2d(0, 0); glVertex3f(-400, 400, 400);
    glTexCoord2d(1, 0); glVertex3f(-400, 400, -400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[4]);
    //права€
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(400, -400, 400);
    glTexCoord2d(0, 1); glVertex3f(400, -400, -400);
    glTexCoord2d(0, 0); glVertex3f(400, 400, -400);
    glTexCoord2d(1, 0); glVertex3f(400, 400, 400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[5]);
    //верхн€€
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 0); glVertex3f(-400, 400, 400);
    glTexCoord2d(1, 0); glVertex3f(400, 400, 400);
    glTexCoord2d(1, 1); glVertex3f(400, 400, -400);
    glTexCoord2d(0, 1); glVertex3f(-400, 400, -400);
    glEnd();
    
}
void draw_dirt(GLuint dirt[3], float cube_size,int X, int Y, int Z,bool cubes[50][50][50])
{

    glBindTexture(GL_TEXTURE_2D, dirt[0]);
    ///задн€€
    if ((cubes[X][Y][Z] != cubes[X][Y][Z + 1])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, cube_size);
        glEnd();
    }
    //ѕ–ј¬јя
    if ((cubes[X ][Y][Z] != cubes[X+1][Y][Z])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, -cube_size);
        glEnd();
    }
    //Ћ≈¬јя
    if (X == 0 or (cubes[X - 1][Y][Z] != cubes[X][Y][Z])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    //передн€€
    if (Z == 0 or (cubes[X][Y][Z-1] != cubes[X][Y][Z])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, -cube_size);
        glEnd();
    }
     //¬≈–’Ќяя
    //glBindTexture(GL_TEXTURE_2D, dirt[0]);
    if (Y == 0 or (cubes[X][Y][Z] != cubes[X][Y + 1][Z])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(1, 1); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    //Ќ»∆Ќяя
    //glBindTexture(GL_TEXTURE_2D, dirt[0]);
    if (cubes[X][Y - 1][Z] != cubes[X][Y][Z]) {
        glBegin(GL_POLYGON);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
        glEnd();
    }
   
}

#endif __TEXTURES_H__
