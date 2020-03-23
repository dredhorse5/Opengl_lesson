#ifndef __TEXTURES_H__
#define __TEXTURES_H__
void draw_super_grass(GLuint dirt[1], float cube_size,int X, int Y, int Z,int cubes[300][100][300])
{
    //bool cubes = cubes;
    glBindTexture(GL_TEXTURE_2D, dirt[0]);
    ///çàäíÿÿ
    glColor3f(0.8, 0.8, 0.8);
    if ((bool (cubes[X][Y][Z]) != bool(cubes[X][Y][Z + 1]))) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0.5); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0.5, 1); glVertex3f(-cube_size, cube_size, cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(cube_size, cube_size, cube_size);
        glEnd();
    }
    //ïåðåäíÿÿ
    if (bool(cubes[X][Y][Z - 1]) != bool(cubes[X][Y][Z])) { // Z == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0.5); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0.5, 1); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(-cube_size, cube_size, -cube_size);
        glEnd();
    }
    glColor3f(0.7, 0.7, 0.7);
    //ÏÐÀÂÀß
    if ((bool(cubes[X][Y][Z]) != bool(cubes[X+1][Y][Z]))) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0.5); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0.5, 1); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(cube_size, cube_size, -cube_size);
        glEnd();
    }
    //ËÅÂÀß
    if (bool(cubes[X - 1][Y][Z]) != bool(cubes[X][Y][Z])) { // X == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0.5); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0.5, 1); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    glColor3f(0.5, 0.5, 0.5);
    //ÍÈÆÍßß
    if (bool(cubes[X][Y - 1][Z]) != bool(cubes[X][Y][Z])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(0.5, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0.5); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(-cube_size, -cube_size, -cube_size);
        glEnd();
    }
    glColor3f(1, 1, 1);
     //ÂÅÐÕÍßß
    if (bool(cubes[X][Y][Z]) != bool(cubes[X][Y + 1][Z])) { // Y == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 0.5); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(0.5, 0.5); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(0.5, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
}
void draw_stone(GLuint stone[1], float cube_size, int X, int Y, int Z, int cubes[300][100][300]) {
    //bool cubes = cubes;
    glBindTexture(GL_TEXTURE_2D, stone[0]);
    ///çàäíÿÿ
    glColor3f(0.8, 0.8, 0.8);
    if ((bool(cubes[X][Y][Z]) != bool(cubes[X][Y][Z + 1]))) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, cube_size);
        glEnd();
    }
    //ïåðåäíÿÿ
    if (bool(cubes[X][Y][Z - 1]) != bool(cubes[X][Y][Z])) { // Z == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, -cube_size);
        glEnd();
    }
    //ÏÐÀÂÀß
        glColor3f(0.7, 0.7, 0.7);
    if ((bool(cubes[X][Y][Z]) != bool(cubes[X + 1][Y][Z]))) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, -cube_size);
        glEnd();
    }
    //ËÅÂÀß
    if (bool(cubes[X - 1][Y][Z]) != bool(cubes[X][Y][Z])) { // X == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    glColor3f(0.5, 0.5, 0.5);
    //ÍÈÆÍßß
    if (bool(cubes[X][Y - 1][Z]) != bool(cubes[X][Y][Z])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
        glEnd();
    }
    glColor3f(1, 1, 1);
    //ÂÅÐÕÍßß
    if (bool(cubes[X][Y][Z]) != bool(cubes[X][Y + 1][Z])) { // Y == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
}
void draw_planks(GLuint planks[1], float cube_size, int X, int Y, int Z, int cubes[300][100][300])
{
    //bool cubes = cubes;
    glBindTexture(GL_TEXTURE_2D, planks[0]);
    ///çàäíÿÿ
    glColor3f(0.8, 0.8, 0.8);
    if ((bool(cubes[X][Y][Z]) != bool(cubes[X][Y][Z + 1]))) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, cube_size);
        glEnd();
    }
    //ïåðåäíÿÿ
    if (bool(cubes[X][Y][Z - 1]) != bool(cubes[X][Y][Z])) { // Z == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, -cube_size);
        glEnd();
    }
    glColor3f(0.7, 0.7, 0.7);
    //ÏÐÀÂÀß
    if ((bool(cubes[X][Y][Z]) != bool(cubes[X + 1][Y][Z]))) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, -cube_size);
        glEnd();
    }
    //ËÅÂÀß
    if (bool(cubes[X - 1][Y][Z]) != bool(cubes[X][Y][Z])) { // X == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    glColor3f(0.5, 0.5, 0.5);
    //ÍÈÆÍßß
    if (bool(cubes[X][Y - 1][Z]) != bool(cubes[X][Y][Z])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
        glEnd();
    }
    glColor3f(1, 1, 1);
    //ÂÅÐÕÍßß
    if (bool(cubes[X][Y][Z]) != bool(cubes[X][Y + 1][Z])) { // Y == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    glColor3f(0.5, 0.5, 0.5);
    //ÍÈÆÍßß
    if (bool(cubes[X][Y - 1][Z]) != bool(cubes[X][Y][Z])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
        glEnd();
    }

}
void draw_dirt(GLuint dirt[1], float cube_size, int X, int Y, int Z, int cubes[300][100][300]) {
    //bool cubes = cubes;
    glBindTexture(GL_TEXTURE_2D, dirt[0]);
    ///çàäíÿÿ
    glColor3f(0.8, 0.8, 0.8);
    if ((bool(cubes[X][Y][Z]) != bool(cubes[X][Y][Z + 1]))) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, cube_size);
        glEnd();
    }
    //ïåðåäíÿÿ
    if (bool(cubes[X][Y][Z - 1]) != bool(cubes[X][Y][Z])) { // Z == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, -cube_size);
        glEnd();
    }
    glColor3f(0.7, 0.7, 0.7);
    //ÏÐÀÂÀß
    if ((bool(cubes[X][Y][Z]) != bool(cubes[X + 1][Y][Z]))) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, -cube_size);
        glEnd();
    }
    //ËÅÂÀß
    if (bool(cubes[X - 1][Y][Z]) != bool(cubes[X][Y][Z])) { // X == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
    glColor3f(0.5, 0.5, 0.5);
    //ÍÈÆÍßß
    if (bool(cubes[X][Y - 1][Z]) != bool(cubes[X][Y][Z])) {
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, -cube_size, cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, -cube_size, -cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
        glEnd();
    }
    glColor3f(1, 1, 1);
    //ÂÅÐÕÍßß
    if (bool(cubes[X][Y][Z]) != bool(cubes[X][Y + 1][Z])) { // Y == 0 or 
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f(-cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 1); glVertex3f(cube_size, cube_size, -cube_size);
        glTexCoord2d(0, 0); glVertex3f(cube_size, cube_size, cube_size);
        glTexCoord2d(1, 0); glVertex3f(-cube_size, cube_size, cube_size);
        glEnd();
    }
}
void draw_lines_cubes(float cube_size,int X, int Y,int Z) {
    glLineWidth(4);
    //glColor3f(1, 1, 1);
    cube_size = cube_size/2 + 0.004;
    glTranslatef(X*2+1, Y*2+1, Z*2+1);
    //âåðòèêàëüíûå
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
    // íèæíèå
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
    //âåðõíèå
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
    glColor3d(1, 1, 1);     // êðàñíûé öâåò

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
