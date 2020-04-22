#ifndef __LOAD_TEXTURES_H__
#define __LOAD_TEXTURES_H__
#include <SOIL.h> 
#define GL_CLAMP_TO_EDGE 0x812F
#define RGB 0
#define RGBA 1

void load_textures(const char *image, GLuint* texturesy, bool type) {
    unsigned char* top = SOIL_load_image(image , &W, &H, 0, SOIL_LOAD_RGBA); // загружаем текстуру в soil
    glGenTextures(1, texturesy); // говорим, что начинаем работать с переменной Dirt, чтобы дальше записать в нее текстуру soil
    glBindTexture(GL_TEXTURE_2D, *texturesy); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    if (type) {
        glEnable(GL_ALPHA_TEST);
        glAlphaFunc(GL_GREATER, 0.8f);
    }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, W, H, 0, GL_RGBA, GL_UNSIGNED_BYTE, top); // загружаем текстуру soil в перменную dirt
    SOIL_free_image_data(top); // освобождаем текстуру из soil
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}
void load_textures_smooth(const char* image, GLuint* texturesy, bool type) {
    unsigned char* top = SOIL_load_image(image, &W, &H, 0, SOIL_LOAD_RGBA); // загружаем текстуру в soil
    glGenTextures(1, texturesy); // говорим, что начинаем работать с переменной Dirt, чтобы дальше записать в нее текстуру soil
    glBindTexture(GL_TEXTURE_2D, *texturesy); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (type) {
        glEnable(GL_ALPHA_TEST);
        glAlphaFunc(GL_GREATER, 0.8f);
    }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, W, H, 0, GL_RGBA, GL_UNSIGNED_BYTE, top); // загружаем текстуру soil в перменную dirt
    SOIL_free_image_data(top); // освобождаем текстуру из soil
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}



void load_textures() {
    load_textures("textures/dirt.png", &dirt, RGB);
    load_textures("textures/Super_Grass.png", &super_grass, RGB);
    load_textures("textures/stone.png", &stone, RGB);
    load_textures("textures/planks.png", &planks, RGB);
    load_textures("textures/heightmap.png", &HeightMap, RGB);
    load_textures("textures/leaves.png", &leaves, RGB);
    load_textures("textures/tree_oak.png", &tree_oak, RGB);
    load_textures("textures/bricks.png", &bricks, RGB);
    load_textures("textures/cobblestone.png", &cobblestone_tex, RGB);

    load_textures("textures/icons/cobblestone.png", &cobblestone_tex_icon, RGBA);
    load_textures("textures/icons/super_grass.png", &super_grass_icon, RGBA);
    load_textures("textures/icons/dirt.png", &dirt_icon, RGBA);
    load_textures("textures/icons/stone.png", &stone_icon, RGBA);
    load_textures("textures/icons/planks.png", &planks_icon, RGBA);
    load_textures("textures/icons/leaves.png", &leaves_icon, RGBA);
    load_textures("textures/icons/tree_oak.jpg", &tree_oak_icon, RGBA);
    load_textures("textures/icons/bricks_icon.png", &bricks_icon, RGBA);


    load_textures("textures/cursor.png", &cursor_tex, RGBA);
    load_textures("textures/GUI.png", &GUI_tex, RGBA);
    load_textures("textures/icons/save_icon.png", &save_icon_tex, RGBA);
    load_textures_smooth("textures/skybox.jpg", &skybox_texturies, RGBA);
}

#endif __LOAD_TEXTURES_H__
