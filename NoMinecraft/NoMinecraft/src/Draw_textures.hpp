#ifndef __TEXTURES_H__
#define __TEXTURES_H__
void drawSkybox(GLuint skybox_texturies[])
{
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[0]);
    //������
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(-400, -400, -400);
    glTexCoord2d(0, 1); glVertex3f(400, -400, -400);
    glTexCoord2d(0, 0); glVertex3f(400, 400, -400);
    glTexCoord2d(1, 0); glVertex3f(-400, 400, -400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[1]);
    //������
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 0); glVertex3f(-400, -400, 400);
    glTexCoord2d(1, 0); glVertex3f(400, -400, 400);
    glTexCoord2d(1, 1); glVertex3f(400, -400, -400);
    glTexCoord2d(0, 1); glVertex3f(-400, -400, -400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[2]);
    //��������
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(400, 400, 400);
    glTexCoord2d(1, 1); glVertex3f(400, -400, 400);
    glTexCoord2d(0, 1); glVertex3f(-400, -400, 400);
    glTexCoord2d(0, 0); glVertex3f(-400, 400, 400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[3]);
    //�����
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(-400, -400, 400);
    glTexCoord2d(0, 1); glVertex3f(-400, -400, -400);
    glTexCoord2d(0, 0); glVertex3f(-400, 400, -400);
    glTexCoord2d(1, 0); glVertex3f(-400, 400, 400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[4]);
    //������
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 1); glVertex3f(400, -400, 400);
    glTexCoord2d(1, 1); glVertex3f(400, -400, -400);
    glTexCoord2d(1, 0); glVertex3f(400, 400, -400);
    glTexCoord2d(0, 0); glVertex3f(400, 400, 400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[5]);
    //�������
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
    //������
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(cube_size, -cube_size, cube_size);
    glTexCoord2d(1, 1); glVertex3f(cube_size, cube_size, cube_size);
    glTexCoord2d(0, 1); glVertex3f(-cube_size, cube_size, cube_size);
    glTexCoord2d(0, 0); glVertex3f(-cube_size, -cube_size, cube_size);
    glEnd();

    //������
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(cube_size, -cube_size, -cube_size);
    glTexCoord2d(1, 1); glVertex3f(cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 1); glVertex3f(cube_size, cube_size, cube_size);
    glTexCoord2d(0, 0); glVertex3f(cube_size, -cube_size, cube_size);
    glEnd();

    //�����
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(-cube_size, -cube_size, cube_size);
    glTexCoord2d(1, 1); glVertex3f(-cube_size, cube_size, cube_size);
    glTexCoord2d(0, 1); glVertex3f(-cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
    glEnd();

    // �������
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, cube_size);
    glTexCoord2d(1, 1); glVertex3f(cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 1); glVertex3f(-cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, cube_size);
    glEnd();

    //������
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(cube_size, -cube_size, -cube_size);
    glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, cube_size);
    glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, cube_size);
    glTexCoord2d(0, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
    glEnd();

    //��������
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(cube_size, -cube_size, -cube_size);
    glTexCoord2d(1, 1); glVertex3f(cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 1); glVertex3f(-cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
    glEnd();
}

#endif __TEXTURES_H__
