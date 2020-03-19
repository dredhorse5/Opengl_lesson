#ifndef __LOAD_TEXTURES_H__
#define __LOAD_TEXTURES_H__
#include <string>
#include <glut.h>
#include <SOIL.h>
#define GL_CLAMP_TO_EDGE 0x812F

void dirtTexturies(GLuint dirt[1], int W, int H)
{
    unsigned char* top = SOIL_load_image("textures/Super_Grass.png", &W, &H, 0, SOIL_LOAD_RGB); // загружаем текстуру в soil
    glGenTextures(1, &dirt[0]); // говорим, что начинаем работать с переменной Dirt, чтобы дальше записать в нее текстуру soil
    glBindTexture(GL_TEXTURE_2D, dirt[0]); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, top); // загружаем текстуру soil в перменную dirt
    SOIL_free_image_data(top); // освобождаем текстуру из soil
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
} 
void stoneTextures(GLuint stone[1], int W, int H) {
    unsigned char* SOILT = SOIL_load_image("textures/stone.png", &W, &H, 0, SOIL_LOAD_RGB); // загружаем текстуру в soil
    glGenTextures(1, &stone[0]); // говорим, что начинаем работать с переменной Dirt, чтобы дальше записать в нее текстуру soil
    glBindTexture(GL_TEXTURE_2D, stone[0]); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, SOILT); // загружаем текстуру soil в перменную dirt
    SOIL_free_image_data(SOILT); // освобождаем текстуру из soil
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}
void planksTextures(GLuint planks[1], int W, int H) {
    unsigned char* SOILT = SOIL_load_image("textures/planks.png", &W, &H, 0, SOIL_LOAD_RGB); // загружаем текстуру в soil
    glGenTextures(1, &planks[0]); // говорим, что начинаем работать с переменной Dirt, чтобы дальше записать в нее текстуру soil
    glBindTexture(GL_TEXTURE_2D, planks[0]); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, SOILT); // загружаем текстуру soil в перменную dirt
    SOIL_free_image_data(SOILT); // освобождаем текстуру из soil
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}
void cursorTextures(GLuint cursor[1], int W, int H) {

    unsigned char* SOILT = SOIL_load_image("textures/cursor.png", &W, &H, 0, SOIL_LOAD_RGBA); // загружаем текстуру в soil
    glGenTextures(1, &cursor[0]); // говорим, что начинаем работать с переменной Dirt, чтобы дальше записать в нее текстуру soil
    glBindTexture(GL_TEXTURE_2D, cursor[0]); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.8f);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, W, H, 0, GL_RGBA, GL_UNSIGNED_BYTE, SOILT); // загружаем текстуру soil в перменную dirt
    SOIL_free_image_data(SOILT); // освобождаем текстуру из soil
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}
void HeightMap_Load(GLuint HeightMap[1], int W, int H) {

    unsigned char* SOILT = SOIL_load_image("textures/heightmap.png", &W, &H, 0, SOIL_LOAD_RGBA); // загружаем текстуру в soil
    glGenTextures(1, &HeightMap[0]); // говорим, что начинаем работать с переменной Dirt, чтобы дальше записать в нее текстуру soil
    glBindTexture(GL_TEXTURE_2D, HeightMap[0]); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.8f);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, W, H, 0, GL_RGBA, GL_UNSIGNED_BYTE, SOILT); // загружаем текстуру soil в перменную dirt
    SOIL_free_image_data(SOILT); // освобождаем текстуру из soil
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}
void skybox(GLuint skybox_texturies[6], int W, int H)
{
    //back
    unsigned char* back = SOIL_load_image("textures/skybox2/skybox_back.bmp", &W, &H, 0, SOIL_LOAD_RGB); // загружаем текстуру в soil
    glGenTextures(1, &skybox_texturies[0]);
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[0]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, back);
    SOIL_free_image_data(back);
    glBindTexture(GL_TEXTURE_2D, 0);
    //===========================================================================================================================
    //bottom
    unsigned char* bottom = SOIL_load_image("textures/skybox2/skybox_bottom.bmp", &W, &H, 0, SOIL_LOAD_RGB); // загружаем текстуру в soil
    glGenTextures(1, &skybox_texturies[1]);
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[1]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, bottom);
    SOIL_free_image_data(bottom);
    glBindTexture(GL_TEXTURE_2D, 0);
    //===========================================================================================================================
    //front
    unsigned char* front = SOIL_load_image("textures/skybox2/skybox_front.bmp", &W, &H, 0, SOIL_LOAD_RGB); // загружаем текстуру в soil
    glGenTextures(1, &skybox_texturies[2]);
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[2]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, front);
    SOIL_free_image_data(front);
    glBindTexture(GL_TEXTURE_2D, 0);
    //===========================================================================================================================
    //left
    unsigned char* left = SOIL_load_image("textures/skybox2/skybox_left.bmp", &W, &H, 0, SOIL_LOAD_RGB); // загружаем текстуру в soil
    glGenTextures(1, &skybox_texturies[3]);
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[3]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, left);
    SOIL_free_image_data(left);
    glBindTexture(GL_TEXTURE_2D, 0);
    //===========================================================================================================================
    //right
    unsigned char* right = SOIL_load_image("textures/skybox2/skybox_right.bmp", &W, &H, 0, SOIL_LOAD_RGB); // загружаем текстуру в soil
    glGenTextures(1, &skybox_texturies[4]);
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[4]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, right);
    SOIL_free_image_data(right);
    glBindTexture(GL_TEXTURE_2D, 0);
    //===========================================================================================================================
    //top
    unsigned char* top = SOIL_load_image("textures/skybox2/skybox_top.bmp", &W, &H, 0, SOIL_LOAD_RGB); // загружаем текстуру в soil
    glGenTextures(1, &skybox_texturies[5]);
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[5]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, top);
    SOIL_free_image_data(top);
    glBindTexture(GL_TEXTURE_2D, 0);
    //===========================================================================================================================

}


#endif __LOAD_TEXTURES_H__#pragma once
