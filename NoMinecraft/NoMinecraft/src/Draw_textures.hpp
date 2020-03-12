#ifndef __TEXTURES_H__
#define __TEXTURES_H__
void draw_dirt(GLuint dirt[1], float cube_size,int X, int Y, int Z,bool cubes[100][100][100])
{

    glBindTexture(GL_TEXTURE_2D, dirt[0]);
    ///çàäíÿÿ
    if ((cubes[X][Y][Z] != cubes[X][Y][Z + 1])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0.5); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0.5, 1); glVertex3f(-cube_size, cube_size, cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(cube_size, cube_size, cube_size);
        glEnd();
    }
    //ÏÐÀÂÀß
    if ((cubes[X ][Y][Z] != cubes[X+1][Y][Z])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0.5); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0.5, 1); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(cube_size, cube_size, -cube_size);
        glEnd();
    }
    //ËÅÂÀß
    if (cubes[X - 1][Y][Z] != cubes[X][Y][Z]) { // X == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0.5); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0.5, 1); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    //ïåðåäíÿÿ
    if (cubes[X][Y][Z-1] != cubes[X][Y][Z]) { // Z == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0.5); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0.5, 1); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(-cube_size, cube_size, -cube_size);
        glEnd();
    }
     //ÂÅÐÕÍßß
    if (cubes[X][Y][Z] != cubes[X][Y + 1][Z]) { // Y == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0.5); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(0.5, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    //ÍÈÆÍßß
    if (cubes[X][Y - 1][Z] != cubes[X][Y][Z]) {
        glBegin(GL_POLYGON);
        glTexCoord2d(0.5, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0.5); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(-cube_size, -cube_size, -cube_size);
        glEnd();
    }
   
}
void draw_stone(GLuint stone[1], float cube_size, int X, int Y, int Z, bool cubes[100][100][100]) {
    glBindTexture(GL_TEXTURE_2D, stone[0]);
    ///çàäíÿÿ
    if ((cubes[X][Y][Z] != cubes[X][Y][Z + 1])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, cube_size);
        glEnd();
    }
    //ÏÐÀÂÀß
    if ((cubes[X][Y][Z] != cubes[X + 1][Y][Z])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, -cube_size);
        glEnd();
    }
    //ËÅÂÀß
    if (cubes[X - 1][Y][Z] != cubes[X][Y][Z]) { // X == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    //ïåðåäíÿÿ
    if (cubes[X][Y][Z - 1] != cubes[X][Y][Z]) { // Z == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, -cube_size);
        glEnd();
    }
    //ÂÅÐÕÍßß
    if (cubes[X][Y][Z] != cubes[X][Y + 1][Z]) { // Y == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    //ÍÈÆÍßß
    if (cubes[X][Y - 1][Z] != cubes[X][Y][Z]) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
        glEnd();
    }
}
void draw_planks(GLuint planks[1], float cube_size, int X, int Y, int Z, bool cubes[100][100][100])
{
    glBindTexture(GL_TEXTURE_2D, planks[0]);
    ///çàäíÿÿ
    if ((cubes[X][Y][Z] != cubes[X][Y][Z + 1])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, cube_size);
        glEnd();
    }
    //ÏÐÀÂÀß
    if ((cubes[X][Y][Z] != cubes[X + 1][Y][Z])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, -cube_size);
        glEnd();
    }
    //ËÅÂÀß
    if (cubes[X - 1][Y][Z] != cubes[X][Y][Z]) { // X == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    //ïåðåäíÿÿ
    if (cubes[X][Y][Z - 1] != cubes[X][Y][Z]) { // Z == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, -cube_size);
        glEnd();
    }
    //ÂÅÐÕÍßß
    if (cubes[X][Y][Z] != cubes[X][Y + 1][Z]) { // Y == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    //ÍÈÆÍßß
    if (cubes[X][Y - 1][Z] != cubes[X][Y][Z]) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
        glEnd();
    }

}

void drawSkybox(GLuint skybox_texturies[])
{
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[0]);
    //çàäíÿÿ
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(-100, -100, 100);
    glTexCoord2d(0, 1); glVertex3f(100, -100, 100);
    glTexCoord2d(0, 0); glVertex3f(100, 100, 100);
    glTexCoord2d(1, 0); glVertex3f(-100, 100, 100);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[1]);
    //íèæíÿÿ
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 0); glVertex3f(-100, -100, -100);
    glTexCoord2d(1, 0); glVertex3f(100, -100, -100);
    glTexCoord2d(1, 1); glVertex3f(100, -100, 100);
    glTexCoord2d(0, 1); glVertex3f(-100, -100, 100);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[2]);
    //ïåðåäíÿÿ
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(100, 100, -100);
    glTexCoord2d(1, 1); glVertex3f(100, -100, -100);
    glTexCoord2d(0, 1); glVertex3f(-100, -100, -100);
    glTexCoord2d(0, 0); glVertex3f(-100, 100, -100);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[3]);
    //ëåâàÿ
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(-100, -100, -100);
    glTexCoord2d(0, 1); glVertex3f(-100, -100, 100);
    glTexCoord2d(0, 0); glVertex3f(-100, 100, 100);
    glTexCoord2d(1, 0); glVertex3f(-100, 100, -100);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[4]);
    //ïðàâàÿ
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(100, -100, 100);
    glTexCoord2d(0, 1); glVertex3f(100, -100, -100);
    glTexCoord2d(0, 0); glVertex3f(100, 100, -100);
    glTexCoord2d(1, 0); glVertex3f(100, 100, 100);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[5]);
    //âåðõíÿÿ
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 0); glVertex3f(-100, 100, 100);
    glTexCoord2d(1, 0); glVertex3f(100, 100, 100);
    glTexCoord2d(1, 1); glVertex3f(100, 100, -100);
    glTexCoord2d(0, 1); glVertex3f(-100, 100, -100);
    glEnd();
    
}


#endif __TEXTURES_H__
