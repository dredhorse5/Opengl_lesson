#ifndef __TEXTURES_H__
#define __TEXTURES_H__
void drawSkybox(GLuint skybox_texturies[])
{
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[0]);
    //задн€€
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(-400, -400, -400);
    glTexCoord2d(0, 1); glVertex3f(400, -400, -400);
    glTexCoord2d(0, 0); glVertex3f(400, 400, -400);
    glTexCoord2d(1, 0); glVertex3f(-400, 400, -400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[1]);
    //нижн€€
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 0); glVertex3f(-400, -400, 400);
    glTexCoord2d(1, 0); glVertex3f(400, -400, 400);
    glTexCoord2d(1, 1); glVertex3f(400, -400, -400);
    glTexCoord2d(0, 1); glVertex3f(-400, -400, -400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[2]);
    //передн€€
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(400, 400, 400);
    glTexCoord2d(1, 1); glVertex3f(400, -400, 400);
    glTexCoord2d(0, 1); glVertex3f(-400, -400, 400);
    glTexCoord2d(0, 0); glVertex3f(-400, 400, 400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[3]);
    //лева€
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(-400, -400, 400);
    glTexCoord2d(0, 1); glVertex3f(-400, -400, -400);
    glTexCoord2d(0, 0); glVertex3f(-400, 400, -400);
    glTexCoord2d(1, 0); glVertex3f(-400, 400, 400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[4]);
    //права€
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 1); glVertex3f(400, -400, 400);
    glTexCoord2d(1, 1); glVertex3f(400, -400, -400);
    glTexCoord2d(1, 0); glVertex3f(400, 400, -400);
    glTexCoord2d(0, 0); glVertex3f(400, 400, 400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[5]);
    //верхн€€
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 0); glVertex3f(-400, 400, -400);
    glTexCoord2d(1, 0); glVertex3f(400, 400, -400);
    glTexCoord2d(1, 1); glVertex3f(400, 400, 400);
    glTexCoord2d(0, 1); glVertex3f(-400, 400, 400);
    glEnd();

}
void draw_dirt(int dirt, int cube_size)
{
    glBindTexture(GL_TEXTURE_2D, dirt);
    //задн€€
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(cube_size, -cube_size, cube_size);
    glTexCoord2d(1, 1); glVertex3f(cube_size, cube_size, cube_size);
    glTexCoord2d(0, 1); glVertex3f(-cube_size, cube_size, cube_size);
    glTexCoord2d(0, 0); glVertex3f(-cube_size, -cube_size, cube_size);
    glEnd();

    //ѕ–ј¬јя
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(cube_size, -cube_size, -cube_size);
    glTexCoord2d(1, 1); glVertex3f(cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 1); glVertex3f(cube_size, cube_size, cube_size);
    glTexCoord2d(0, 0); glVertex3f(cube_size, -cube_size, cube_size);
    glEnd();

    //Ћ≈¬јя
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(-cube_size, -cube_size, cube_size);
    glTexCoord2d(1, 1); glVertex3f(-cube_size, cube_size, cube_size);
    glTexCoord2d(0, 1); glVertex3f(-cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
    glEnd();

    // ¬≈–’Ќяя
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, cube_size);
    glTexCoord2d(1, 1); glVertex3f(cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 1); glVertex3f(-cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, cube_size);
    glEnd();

    //Ќ»∆Ќяя
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(cube_size, -cube_size, -cube_size);
    glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, cube_size);
    glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, cube_size);
    glTexCoord2d(0, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
    glEnd();

    //передн€€
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(cube_size, -cube_size, -cube_size);
    glTexCoord2d(1, 1); glVertex3f(cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 1); glVertex3f(-cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
    glEnd();
}

#endif __TEXTURES_H__
