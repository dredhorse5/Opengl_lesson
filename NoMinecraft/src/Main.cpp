#include <Math.h>
#include <stdio.h>
#include <ctime>
#include <thread>
#include <iostream>
#include <fstream>
#include <string>
#include "glut.h"
#include "SOIL.h"
#include <SFML/Graphics.hpp>
//#include <SFML/OpenGL.hpp>
#pragma comment(lib, "SOIL.lib")
#pragma warning(disable:26451)
#pragma warning(disable:4018)
#define GL_CLAMP_TO_EDGE 0x812F



// идентификаторы меню
int Visibility_Menu, shrinkMenu, mainMenu, BlocksMenu;
// статус меню
int menuFlag = 0;

// textures of blocks
GLuint super_grass, super_grass_icon;
GLuint stone, stone_icon;
GLuint planks, planks_icon;
GLuint dirt, dirt_icon;
GLuint leaves, leaves_icon;
GLuint tree_oak, tree_oak_icon;
GLuint cobblestone_tex, cobblestone_tex_icon;
GLuint bricks, bricks_icon;

// some textures
GLuint backround_tex;
GLuint cursor_tex;
GLuint skybox_texturies;
GLuint HeightMap;
GLuint GUI_tex;
GLuint save_icon_tex;
// cubes
float cube_size = 2; // size of cubes
const int width = 1280, height = 720; // size of window
int W = width, H = height;
int quantity_cube_x = 540; // quanity cubes of x
int quantity_cube_y = 50; // quanity cubes of y
int quantity_cube_z = 540; // quanity cubes of z
int cubes[540][50][540];

short int IDblocks = 1;
short int blocks = 8;

// камера
float lx = 1.0f, lz = 0.0f, ly = 0.0f; // координаты вектора направления движения камеры
float angleX = 0.0f, angleY = 5.0f; // угол поворота камеры
int mouseXOld = 1, mouseYOld = 1;
bool mLeft = 0, mRight = 0; // mouse bottons
float FPS = 60;
// разное
float KeyFront = 0, KeySide = 0; // ключ к изменению перемещения вперед/назад
bool Draw_debug_Menu_key = true;
int MENU = 0;
time_t oldtime = 1;
time_t newtime = 1;
time_t thistime = 1;
int Visibility_range = 50;
float r, g, b = 1.0f;
bool is_saving = 0;
bool keytime = 1;
// постройки
char tree_mass[7][5][5] = { {
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 6, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0} },
{
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 6, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0} },
{
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 6, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0} },
{
{ 7, 7, 7, 7, 7 },
{ 7, 7, 7, 7, 7 },
{ 7, 7, 6, 7, 7 },
{ 7, 7, 7, 7, 7 },
{ 7, 7, 7, 7, 7 } },
{
{ 7, 7, 7, 7, 7 },
{ 7, 7, 7, 7, 7 },
{ 7, 7, 6, 7, 7 },
{ 7, 7, 7, 7, 7 },
{ 7, 7, 7, 7, 7 } },
{
{ 0, 0, 0, 0, 0 },
{ 0, 7, 7, 7, 0 },
{ 0, 7, 6, 7, 0 },
{ 0, 7, 7, 7, 0 },
{ 0, 0, 0, 0, 0 } },
{
{ 0, 0, 0, 0, 0 },
{ 0, 0, 7, 0, 0 },
{ 0, 7, 7, 7, 0 },
{ 0, 0, 7, 0, 0 },
{ 0, 0, 0, 0, 0 } }, };
char monument_mass[12][5][6] = { {
{1, 1, 4, 4, 1, 0},
{1, 1, 1, 1, 4, 0},
{4, 1, 1, 1, 1, 0},
{4, 1, 1, 1, 4, 0},
{1, 4, 1, 4, 4, 0}},
{
{1, 1, 4, 4, 1, 0},
{1, 1, 1, 1, 4, 0},
{4, 1, 1, 1, 1, 0},
{4, 1, 1, 1, 4, 0},
{1, 4, 1, 4, 4, 0}},
{
{1, 1, 4, 4, 1, 0},
{1, 1, 1, 1, 4, 1},
{4, 1, 1, 1, 1, 1},
{4, 1, 1, 1, 4, 1},
{1, 4, 1, 4, 4, 0}},
{
{1, 1, 4, 4, 1, 0},
{1, 1, 1, 1, 1, 0},
{1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 0},
{1, 1, 1, 4, 4, 0}},
{
{4, 4, 1, 4, 4, 0},
{4, 1, 1, 1, 4, 0},
{1, 1, 1, 1, 1, 4},
{1, 1, 1, 1, 1, 0},
{4, 1, 1, 1, 1, 0}},
{
{1, 1, 1, 1, 0, 0},
{1, 1, 1, 1, 0, 0},
{1, 1, 1, 1, 4, 1},
{4, 1, 1, 1, 0, 0},
{1, 1, 1, 4, 0, 0}},
{
{1, 4, 1, 1, 1, 1},
{4, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 4},
{4, 1, 1, 4, 1, 1}},
{
{1, 4, 1, 1, 1, 0},
{4, 1, 1, 1, 4, 0},
{1, 1, 1, 1, 1, 0},
{1, 1, 1, 1, 1, 0},
{1, 4, 1, 1, 4, 0}},
{
{1, 1, 4, 4, 1, 0},
{1, 1, 1, 1, 1, 0},
{1, 1, 1, 1, 1, 0},
{1, 1, 1, 1, 4, 0},
{1, 4, 1, 4, 1, 0}},
{
{1, 4, 4, 1, 1, 0},
{4, 1, 1, 1, 1, 0},
{4, 1, 1, 1, 4, 0},
{4, 1, 1, 1, 1, 0},
{1, 1, 4, 1, 1, 0}},
{
{1, 4, 1, 1, 1, 0},
{4, 1, 1, 1, 1, 0},
{1, 1, 1, 1, 1, 0},
{1, 1, 1, 1, 1, 0},
{4, 1, 1, 4, 1, 0}},
{
{0, 0, 0, 0, 0, 0},
{0, 1, 1, 1, 0, 0},
{0, 1, 1, 1, 0, 0},
{0, 4, 4, 1, 0, 0},
{0, 0, 0, 0, 0, 0}},
 };
#include "Load_textures.hpp"


void draw_lines_cubes(float, int , int , int );

enum visibility_modes {
    Very_high,
    High,
    Medium,
    Low,
    Very_low,
};
enum Blocks {
    AIR,
    STONE,
    SUPER_GRASS,
    DIRT,
    COBBLESTONE,
    PLANKS,
    TREE_OAK,
    LEAVES,
    BRICKS

};
enum Menu_types {
    game,
    game_menu
};
#include "builders.hpp"
class Player {
public:
    float PlayerX, PlayerY, PlayerZ;
    float dx, dy, dz;
    float dSideX, dSideZ;
    float dFrontX, dFrontZ;
    float w, h, d;
    bool onGround;
    float speed;
    float View; // угол обзора
    Player(float x0, float y0, float z0) {
        PlayerX = x0; PlayerY= y0; PlayerZ= z0;
        dx = 0; dy = 0; dz = 0;
        dSideX = 0; dSideZ = 0;
        dFrontX = 0; dFrontZ = 0;
        w = 0.5f; h = 1.9f; d = 0.5f; speed = 0.5;
        onGround = false; 
        View =90; // угол обзора
    }
    bool check(int x, int y, int z) {
        if ((x < 0) or (x > quantity_cube_x) or
            (y < 0) or (y > quantity_cube_y) or
            (z < 0) or (z > quantity_cube_z)) return false;
        return cubes[x][y][z];


    }
    void update(float time) {

        if (PlayerY < 0) {
            PlayerY = 20 * cube_size;
            dy = 0;
        }

        mousePressed();

        if (KeyFront) {
            dFrontX = lx * speed * KeyFront * time / 50;
            dFrontZ = lz * speed * KeyFront * time / 50;
        }
        if (KeySide) {
            dSideX = -lz * speed * KeySide * time / 50;
            dSideZ = lx * speed * KeySide * time / 50;
        }
       
        dy -= 0.12 * (time/50);
        onGround = 0;

        dx = dSideX + dFrontX;
        PlayerX += dx;
        collision(dx, 0, 0);
        PlayerY += dy * (time / 50);
        collision(0, dy, 0);
        dz = dSideZ + dFrontZ;
        PlayerZ += dz;
        collision(0, 0, dz);
        //one.join();

        
        dx = dz = dSideX = dSideZ = dFrontX = dFrontZ = 0;
    }
    void mousePressed() {
        //if (mRight or mLeft) {
            float mousex = PlayerX;
            float mousey = PlayerY +h / 2;
            float mousez = PlayerZ;
            int  X = 0, Y = 0, Z = 0;
            int oldX = 0, oldY = 0, oldZ = 0;
            float dist = 0.0f;

            while (dist < 80) {
                dist += 0.2;
                mousex += lx / 50; X = mousex / cube_size;
                mousey += ly / 50; Y = mousey / cube_size; 
                mousez += lz / 50; Z = mousez / cube_size;

                if (check(X, Y, Z) ) {
                    draw_lines_cubes(cube_size,X,Y,Z);
                    
                    if (mLeft) { cubes[X][Y][Z] = 0; break; }
                    if (mRight) {
                        //cubes_types[oldX][oldY][oldZ] = IDblocks;
                        cubes[oldX][oldY][oldZ] = IDblocks;
                        cubes[int(PlayerX/2)]             [int(PlayerY/2 + h/2 - 0.05)][int(PlayerZ/2)]              = 0;
                        cubes[int(PlayerX/2)]             [int(PlayerY/2 + h/2 - 0.05)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2)]             [int(PlayerY/2 + h/2 - 0.05)][int(PlayerZ/2 - d/2 + 0.01)] = 0;
                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2 + h/2 - 0.05)][int(PlayerZ/2)]              = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2 + h/2 - 0.05)][int(PlayerZ/2)]              = 0;
                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2 + h/2 - 0.05)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2 + h/2 - 0.05)][int(PlayerZ/2 - d/2 + 0.01)] = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2 + h/2 - 0.05)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2 + h/2 - 0.05)][int(PlayerZ/2 - d/2 + 0.01)] = 0;
                        
                        cubes[int(PlayerX/2)]             [int(PlayerY/2)][int(PlayerZ/2)]              = 0;
                        cubes[int(PlayerX/2)]             [int(PlayerY/2)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2)]             [int(PlayerY/2)][int(PlayerZ/2 - d/2 + 0.01)] = 0;
                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2)][int(PlayerZ/2)]              = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2)][int(PlayerZ/2)]              = 0;
                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2)][int(PlayerZ/2 - d/2 + 0.01)] = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2)][int(PlayerZ/2 - d/2 + 0.01)] = 0;
                        
                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2 - h/2 + 0.01)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2 - h/2 + 0.01)][int(PlayerZ/2 - d/2 + 0.01)] = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2 - h/2 + 0.01)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2 - h/2 + 0.01)][int(PlayerZ/2 - d/2 + 0.01)] = 0;
                        cubes[int(PlayerX/2)]             [int(PlayerY/2 - h/2 + 0.01)][int(PlayerZ/2)]              = 0;
                        cubes[int(PlayerX/2)]             [int(PlayerY/2 - h/2 + 0.01)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2)]             [int(PlayerY/2 - h/2 + 0.01)][int(PlayerZ/2 - d/2 + 0.01)] = 0;
                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2 - h/2 + 0.01)][int(PlayerZ/2)]              = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2 - h/2 + 0.01)][int(PlayerZ/2)]              = 0;

                        break;
                    }
                    break;
                }

                oldX = X; oldY = Y; oldZ = Z;
            }
        //}
        mLeft = mRight = false;
    }
    void collision(float Dx, float Dy, float Dz) {
        for (int X = (PlayerX - w) / cube_size; X < (PlayerX + w) / cube_size; X++)
        for (int Y = (PlayerY - h) / cube_size; Y < (PlayerY + h) / cube_size; Y++)
        for (int Z = (PlayerZ - d) / cube_size; Z < (PlayerZ + d) / cube_size; Z++)
            if(check(X,Y,Z))
            {
                if (Dx > 0) PlayerX = X * cube_size - w;
                if (Dx < 0) PlayerX = X * cube_size + cube_size + w;
              
                if (Dy > 0) { PlayerY = Y * cube_size - h; dy = 0; }
                if (Dy < 0) { PlayerY = Y * cube_size + cube_size + h; onGround = true; dy = 0;}
             
                if (Dz > 0) PlayerZ = Z * cube_size - d; 
                if (Dz < 0) PlayerZ = Z * cube_size + cube_size + d;  
               
            }
    }
    void jump() {
        if (onGround) {
            onGround = false;
            dy = 0.8;
        }
    }
};
class GUI_Menu {
public:
                    /* .: */ float X11; float Y11;
     float x11, y11;/* :. */ float X21; float Y21;
                    /* :' */ float X22; float Y22;
     float x22, y22;/* ': */ float X12; float Y12;
    GLuint* tex;
    bool G = 0;
    GUI_Menu(GLuint* tex,float x11, float y11,float x22, float y22,
             float X11, float Y11f, float X21 , float Y21 ,float X22 ,float Y22,float X12 , float Y12 ) {
        this->x11 = x11; this->y11 = y11;
        this->x22 = x22; this->y22 = y22;
        this->tex = tex;
    }
    void mouse(float x, float y) {
        x /= width/2; y /= height/2;
        x -= 1; y -= 1;
        x *= 0.36; y *= -1 * 0.2;
        //std::cout << "x this is: " << x << "    y this is: " << y << std::endl;
        if (x > x22 and x < x11 and y > y22 and y < y11) {
            G = 1;
        }
        else G = 0;

    }
    void update() {
        glBindTexture(GL_TEXTURE_2D, *tex);
        glBegin(GL_QUADS);
        glTexCoord2d(X11, Y11); glVertex3f(x11, y11, -0.2);
        glTexCoord2d(X21, Y21); glVertex3f(x11, y22, -0.2);
        glTexCoord2d(X22, Y22); glVertex3f(x22, y22, -0.2);
        glTexCoord2d(X12, Y12); glVertex3f(x22, y11, -0.2);
        glEnd();
        if (G) {
            glBindTexture(GL_TEXTURE_2D, *tex);
            glBegin(GL_QUADS);
            glTexCoord2d(X11, Y11); glVertex3f(x11, y11, -0.2);
            glTexCoord2d(X21, Y21); glVertex3f(x11, y22, -0.2);
            glTexCoord2d(X22, Y22); glVertex3f(x22, y22, -0.2);
            glTexCoord2d(X12, Y12); glVertex3f(x22, y11, -0.2);
            glEnd();
        }
    }
};
GUI_Menu gy(&dirt, 0.05f, 0.05f, -0.05f, -0.05f, /**/ 0, 0.47f, 1, 0.47f, );
Player steve(quantity_cube_x/2,60, quantity_cube_z/2);
#include "menu_interface.hpp"
//class GUI {
//public:
//    float x1; float y1;
//    float x2; float y2;
//    float x3; float y3;
//    float x4; float y4;
//    
//    GUI(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
//        this->x1 = x1; this->y1 = y1;
//        this->x2 = x2; this->y2 = y2;
//        this->x3 = x3; this->y3 = y3;
//        this->x4 = x4; this->y4 = y4;
//    }
//
//    
//    void update(GLuint tex[1],float x1h, float y1h, float x2h, float y2h, float x3h, float y3h, float x4h, float y4h) {
//        glBindTexture(GL_TEXTURE_2D, tex[0]);
//        glTranslatef(0.2 * lx * cos(angleY) + steve.PlayerX, -0.2 * sin(angleY) + steve.PlayerY + steve.h / 2, 0.2 * lz * cos(angleY) + steve.PlayerZ); // двойки задают удаленность от игрока
//        glBegin(GL_POLYGON);
//        glTexCoord2d(x1h, y1h); glVertex3f(x1 * lz + y1 * sin(angleY) * lx, y1 * cos(angleY), -x1 * lx + y1 * sin(angleY) * lz); // .: // двойка позволяет двигать вверх/вниз 0.356
//        glTexCoord2d(x2h, y2h); glVertex3f(-x2 * lz + y2 * sin(angleY) * lx, y2 * cos(angleY), x2 * lx + y2 * sin(angleY) * lz); // :. // тройка позволяет двигать влево/право
//        glTexCoord2d(x3h, y3h); glVertex3f(-x3 * lz - y3 * sin(angleY) * lx, -y3 * cos(angleY), x3 * lx - y3 * sin(angleY) * lz); // :'
//        glTexCoord2d(x4h, y4h); glVertex3f(x4 * lz - y4 * sin(angleY) * lx, -y4 * cos(angleY), -x4 * lx - y4 * sin(angleY) * lz); // ':
//        glEnd();
//        glTranslatef(-0.2 * lx * cos(angleY) - steve.PlayerX, 0.2 * sin(angleY) - steve.PlayerY - steve.h / 2, -0.2 * lz * cos(angleY) - steve.PlayerZ); // двойки задают удаленность от игрока  
//    }
//    void update() {
//        glColor3f(1, 0, 0);
//        glTranslatef(0.2 * lx * cos(angleY) + steve.PlayerX, -0.2 * sin(angleY) + steve.PlayerY + steve.h / 2, 0.2 * lz * cos(angleY) + steve.PlayerZ); // двойки задают удаленность от игрока
//        glBegin(GL_POLYGON);
//        glVertex3f(x1 * lz + y1 * sin(angleY) * lx, y1 * cos(angleY), -x1 * lx + y1 * sin(angleY) * lz); // .: // двойка позволяет двигать вверх/вниз 0.356
//        glVertex3f(-x2 * lz + y2 * sin(angleY) * lx, y2 * cos(angleY), x2 * lx + y2 * sin(angleY) * lz); // :. // тройка позволяет двигать влево/право
//        glVertex3f(-x3 * lz - y3 * sin(angleY) * lx, -y3 * cos(angleY), x3 * lx - y3 * sin(angleY) * lz); // :'
//        glVertex3f(x4 * lz - y4 * sin(angleY) * lx, -y4 * cos(angleY), -x4 * lx - y4 * sin(angleY) * lz); // ':
//        glEnd();
//        glTranslatef(-0.2 * lx * cos(angleY) - steve.PlayerX, 0.2 * sin(angleY) - steve.PlayerY - steve.h / 2, -0.2 * lz * cos(angleY) - steve.PlayerZ); // двойки задают удаленность от игрока  
//        glColor3f(1, 1, 1);
//    }
//    void update(GLuint tex[1]) {
//        update(tex, 1.0f,1.0f,    0.0f,1.0f,    0.0f,0.0f,     1.0f, 0.0f);
//
//    }
//};
//GUI cursor(0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f);
//GUI quad(0.357f, 0.2f, -0.2f, 0.2f, -0.2f, 0.01f, 0.357f, 0.01f);
//GUI hotbar_down(0.15f, -0.165f,        0.15f, -0.165f,        0.15f, 0.2f,        0.15f, 0.2f);
//GUI background(0.357, 0.2, 0.357f, 0.2, 0.357f, 0.2, 0.357f, 0.2);
#include "Draw_textures.hpp"
 
inline void DrawdebugScreen(float x, float y, float z, std::string speedX,
    std::string speedY, std::string speedZ, std::string lX, std::string lY, std::string lZ, std::string Onground,
    std::string timer) {if (Draw_debug_Menu_key) {
        glMatrixMode(GL_PROJECTION);
        //Сохраняем предыдущую матрицу, которая содержит параметры перспективной проекции
        glPushMatrix();
        //обнуляем матрицу
        glLoadIdentity();
        //устанавливаем 2D ортогональную проекцию
        gluOrtho2D(0, width, height, 0);
        //выбираем режим обзора модели
        glMatrixMode(GL_MODELVIEW);

        glPushMatrix();

        glLoadIdentity();

        
        glColor3d(1, 1, 1);
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        {
            // XYZ = PX / PY / PZ
            glRasterPos3f(x, y, z);
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'X'); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'Y'); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'Z');
            glRasterPos3f(x + 40, y , z);

            for (int i = 0; i < std::to_string(steve.PlayerX/2 + 0.5).length() - 3; i++)       glutBitmapCharacter(GLUT_BITMAP_9_BY_15, std::to_string(steve.PlayerX / 2 + 0.5)[i]);
            glRasterPos3f(x + std::to_string(steve.PlayerX / 2 + 0.5).length()*7 + 40, y , z); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '/');
            glRasterPos3f(x + std::to_string(steve.PlayerX / 2 + 0.5).length() * 9 + 40, y, z);

            for (int i = 0; i < std::to_string(steve.PlayerY / 2).length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, std::to_string(steve.PlayerY/2 +0.05)[i]);
            glRasterPos3f(x + std::to_string(steve.PlayerY / 2).length() * 7 + std::to_string(steve.PlayerX / 2 + 0.5).length() * 9 + 40, y, z); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '/'); //+ PlayerX.length() * 9
            glRasterPos3f(x + std::to_string(steve.PlayerX / 2 + 0.5).length() * 9 + std::to_string(steve.PlayerY / 2 + 0.5).length() * 9 + 40, y, z);

            for (int i = 0; i < std::to_string(steve.PlayerZ / 2 + 0.5).length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, std::to_string(steve.PlayerZ / 2 + 0.5)[i]);



            //L(XYZ) = PX / PY / PZ
            glRasterPos3f(x, y + 30, z);
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'L'); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '('); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'X');
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'Y'); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'Z'); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ')');

            glRasterPos3f(x + 60, y + 30, z);     for (int i = 0; i < lX.length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, lX[i]); // lX
            glRasterPos3f(x + lX.length() * 7 + 60,          y + 30,    z); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '/'); /// '/'

            glRasterPos3f(x + lX.length() * 7 + 60 + 10,     y + 30,    z);  for (int i = 0; i < lY.length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, lY[i]); // LY
            glRasterPos3f(x + lX.length() * 7 + lY.length() * 7 + 60 + 10, y + 30, z); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '/'); /// '/'

            glRasterPos3f(x + lX.length() * 7 + lY.length() * 7 + 60 + 10 + 10, y + 30, z);  for (int i = 0; i < lZ.length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, lZ[i]); // LZ


            // FPS: 60
            glRasterPos3f(x, y + 80, z);
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'F'); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'P'); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'S'); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ':'); // fps
            
            glRasterPos3f(x + 50, y + 80, z);  for (int i = 0; i < timer.length(); i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, timer[i]); // 60
        }


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        glPopMatrix();

        glMatrixMode(GL_PROJECTION);
        //восстановить предыдущую матрицу проекции
        glPopMatrix();
        //вернуться в режим модели
        glMatrixMode(GL_MODELVIEW);
        //quad.update();
    }
}// ------------------------------------//

void GUI_Menu_draw() {
    gy.update();
    keytime = 0;
}
void GUI() {
    // по оси x край 0.36
    // по оси y край 0.2
    // идет по часовой стрелки
    glColor3d(1, 1, 1);

    if (Draw_debug_Menu_key) {
        // фон отладчика
        glColor3d(0.3, 0.3, 0.3);
        glBegin(GL_QUADS);
        glVertex3f(-0.2, 0.2, -0.2);
        glVertex3f(-0.2, 0.13, -0.2);
        glVertex3f(-0.36, 0.13, -0.2);
        glVertex3f(-0.36, 0.2, -0.2);
        glEnd();
        glColor3d(1, 1, 1);
    }
    // ============================ курсор =========================
    glBindTexture(GL_TEXTURE_2D, cursor_tex);
    glBegin(GL_QUADS);
    glTexCoord2d(1.0f, 1.0f); glVertex3f(0.01, 0.01, -0.2);
    glTexCoord2d(0.0f, 1.0f); glVertex3f(0.01, -0.01, -0.2);
    glTexCoord2d(0.0f, 0.0f); glVertex3f(-0.01, -0.01, -0.2);
    glTexCoord2d(1.0f, 0.0f); glVertex3f(-0.01, 0.01, -0.2);
    glEnd();
    //==============================================================
    hotbar_icons();
    // ============================ хотбар =========================
    glBindTexture(GL_TEXTURE_2D, GUI_tex);
    glBegin(GL_QUADS);
    glTexCoord2d(0.09f, 1);         glVertex3f(0.17, -0.16, -0.2);  // идем с верхнего левого угла
    glTexCoord2d(0.09f, 0.89f);     glVertex3f(0.17, -0.2, -0.2);
    glTexCoord2d(1, 0.89f);         glVertex3f(-0.17, -0.2, -0.2);
    glTexCoord2d(1, 1);             glVertex3f(-0.17, -0.16, -0.2);
    glEnd();

    //значок сохранения 
    if (is_saving) {
        glBindTexture(GL_TEXTURE_2D, save_icon_tex);
        glBegin(GL_QUADS);
        glTexCoord2d(0, 0);     glVertex3f(0.36, 0.2, -0.2);
        glTexCoord2d(0, 1);     glVertex3f(0.36, 0.16, -0.2);
        glTexCoord2d(1, 1);    glVertex3f(0.32, 0.16, -0.2);
        glTexCoord2d(1, 0);     glVertex3f(0.32, 0.2, -0.2);
        glEnd();
    }
}

void processMenuStatus(int status, int x, int y) {
        KeyFront = 0;
        KeySide = 0;
        keytime = 0;
    
}
void processMainMenu(int option) {  }
void processVisibility_Menu(int option) {
    switch (option) {
    case Very_high:
        Visibility_range = 120;
        break;
    case High:
        Visibility_range = 80;
            break;

    case Medium:
        Visibility_range = 50;
            break;

    case Low:
        Visibility_range = 35;
            break;

    case Very_low:
        Visibility_range = 20;
            break;
    }

}
void processBlocksMenu(int option) {
    switch (option) {
    case AIR:
        IDblocks = AIR;
        break;

    case STONE:
        IDblocks = STONE;
        break;

    case SUPER_GRASS:
        IDblocks = SUPER_GRASS;
        break;

    case DIRT:
        IDblocks = DIRT;
        break;

    case COBBLESTONE:
        IDblocks = COBBLESTONE;
        break;

    case PLANKS:
        IDblocks = PLANKS;
        break;

    case TREE_OAK:
        IDblocks = TREE_OAK;
        break;

    case LEAVES:
        IDblocks = LEAVES;
        break;
    }
}
void createPopupMenus() {
    //====================================================================================
    Visibility_Menu = glutCreateMenu(processVisibility_Menu);
    glutAddMenuEntry("Very High", Very_high);
    glutAddMenuEntry("High", High);
    glutAddMenuEntry("Medium", Medium);
    glutAddMenuEntry("Low", Low);
    glutAddMenuEntry("Very low", Very_low);
    //====================================================================================
    BlocksMenu = glutCreateMenu(processBlocksMenu);
    glutAddMenuEntry("AIR", AIR);
    glutAddMenuEntry("STONE", STONE);
    glutAddMenuEntry("GRASS", SUPER_GRASS);
    glutAddMenuEntry("DIRT", DIRT);
    glutAddMenuEntry("COBBLESTONE", COBBLESTONE);
    glutAddMenuEntry("PLANKS", PLANKS);
    glutAddMenuEntry("TREE OAK", TREE_OAK);
    glutAddMenuEntry("LEAVES", LEAVES);
    //====================================================================================
    mainMenu = glutCreateMenu(processMainMenu);
    glutAddSubMenu("Visibility ", Visibility_Menu);
    glutAddSubMenu("Blocks", BlocksMenu);
    //====================================================================================

    glutAttachMenu(GLUT_MIDDLE_BUTTON);    // прикрепить меню к средней кнопке
    glutMenuStatusFunc(processMenuStatus);   //статус активности меню
}


void close_game() {
    is_saving = 1;
    FILE* pFile;
    fopen_s(&pFile, "World1.txt", "w");
        for(int x = 0; x < quantity_cube_x; x++)
            for (int y = 4; y < quantity_cube_y; y++)
                for (int z = 0; z < quantity_cube_z; z++)  {
                    fprintf(pFile, "%i", cubes[x][y][z]);
                }
        fclose(pFile);
    is_saving = 0;
    exit(0);
}
void Reshape(int w, int h){
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(steve.View, ratio, 0.1f, 693.0f);
    glMatrixMode(GL_MODELVIEW);
}
void timf(int value){
    glutPostRedisplay();  // Redraw windows

    glutTimerFunc(1000 / FPS, timf, 0); // Setup next timer
}
inline void Draw_cubes() {
    for (int x = steve.PlayerX / 2 - Visibility_range; x < steve.PlayerX / 2 + Visibility_range; x++) // drawing cubs
        for (int y = 4; y < quantity_cube_y; y++)
            for (int z = steve.PlayerZ / 2 - Visibility_range; z < steve.PlayerZ / 2 + Visibility_range; z++ )
            {
                if (x < 0 or x > quantity_cube_x) continue;
                if (z < 0 or z > quantity_cube_z)  continue;
                int type = cubes[x][y][z];
                if (!type or   (bool(type) == bool(cubes[x][y + 1][z]) and bool(type) == bool(cubes[x][y - 1][z]) and
                                bool(type) == bool(cubes[x + 1][y][z]) and bool(type) == bool(cubes[x - 1][y][z]) and
                                bool(type) == bool(cubes[x][y][z + 1]) and bool(type) == bool(cubes[x][y][z - 1])      )) continue;
                glPushMatrix();
                glTranslatef(x * cube_size + cube_size / 2, y * cube_size + cube_size / 2, z * cube_size + cube_size / 2);

                switch (type) {
                case Blocks::STONE:       {one_texture_blocks(stone,            x, y, z, steve.PlayerX, steve.PlayerY, steve.PlayerZ); break; }
                case Blocks::COBBLESTONE: {one_texture_blocks(cobblestone_tex,  x, y, z, steve.PlayerX, steve.PlayerY, steve.PlayerZ); break; }
                case Blocks::SUPER_GRASS: {draw_super_grass(                    x, y, z, steve.PlayerX, steve.PlayerY, steve.PlayerZ); break; }
                case Blocks::DIRT:        {one_texture_blocks(dirt,             x, y, z, steve.PlayerX, steve.PlayerY, steve.PlayerZ); break; }
                case Blocks::PLANKS:      {one_texture_blocks(planks,           x, y, z, steve.PlayerX, steve.PlayerY, steve.PlayerZ); break; }
                case Blocks::LEAVES:      {one_texture_blocks(leaves,           x, y, z, steve.PlayerX, steve.PlayerY, steve.PlayerZ); break; }
                case Blocks::TREE_OAK:    {draw_tree_oak(                       x, y, z, steve.PlayerX, steve.PlayerY, steve.PlayerZ); break; }
                case Blocks::BRICKS:      {one_texture_blocks(bricks,           x, y, z, steve.PlayerX, steve.PlayerY, steve.PlayerZ); break; }
                }

                glPopMatrix();
            }
}
void Draw() {
    static int a = 0;
    static int timer = 1;
    double times;

    glClear(GL_DEPTH_BUFFER_BIT);

    switch (MENU){
    case game: GUI(); break;
    case game_menu: GUI_Menu_draw(); break;
    }


    glPushMatrix();

    gluLookAt(steve.PlayerX, steve.PlayerY + steve.h / 2, steve.PlayerZ,
        steve.PlayerX + lx, steve.PlayerY + ly + steve.h / 2, steve.PlayerZ + lz,
        0.0f, 1.0f, 0.0f);

    newtime = clock();
    times = newtime - oldtime * keytime;
    oldtime = clock();



    //===============================начало основного цикла================================================================================


    Draw_cubes();
    drawSkybox();



    if (newtime - thistime > 150) {
        timer = times;
        thistime = newtime;
    }

    if (MENU == game)
        DrawdebugScreen(5, 30, 0, std::to_string(steve.dx), std::to_string(steve.dy), std::to_string(steve.dz), std::to_string(lx), std::to_string(ly),
        std::to_string(lz), std::to_string(steve.onGround), std::to_string(1000 / timer));



    steve.update(times * keytime);
    keytime = 1;



    //=================================конец основного цикла===================================================================================
    glPopMatrix();
    glutPostRedisplay();
    //glutSwapBuffers();
    glFinish();
}


#include "Mouse_and_keyboard.hpp"

int main(int argc, char** argv){
    //===========================INITIALIZATION===========================================
    glutInit(&argc, argv);
    glutInitWindowSize(width, height);
    glutInitDisplayMode(GLUT_RGBA /*| GL_DOUBLE*/);
    glutCreateWindow("cubes");
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    glutTimerFunc(1000 / FPS, timf, 0); // limit fps
    glEnable(GL_TEXTURE_2D);
    glutDisplayFunc(Draw);    // Main draw function
    glutReshapeFunc(Reshape); // change window
    
    glutSetCursor(GLUT_CURSOR_NONE);
    //=====================================TEXTURES=======================================
    load_textures();
    //====================================================================================
    glutPassiveMotionFunc(mouseMove);
    glutMotionFunc(mouseMove);
     
    glutMouseFunc(mouseButton);

    glutKeyboardFunc(processNormalKeysDOWN);// working when keyBoard is down
    glutKeyboardUpFunc(processNormalKeysUP);// working when keyboard is up


    std::ifstream fout("World1.txt", std::ifstream::binary);
    char n;
    
    if (fout) {
        for (int x = 0; x < quantity_cube_x; x++)
            for (int y = 4; y < quantity_cube_y; y++)
                for (int z = 0; z < quantity_cube_z; z++) {
                    fout.get(n);
                    cubes[x][y][z] = int(n) - 48;
                }
    }
    else{
        time_t seed;
        seed = time(NULL);
        sf::Image im; im.loadFromFile("textures/heightmap1.jpg");
        for (int x = 0; x < quantity_cube_x; x++) 
            for (int z = 0; z < quantity_cube_z; z++) {
                int c = im.getPixel(x, z).r / 10 + 10;
                for (int y = 0; y <= c; y++) {

                    if (y == c)         cubes[x][y][z] = Blocks::SUPER_GRASS;
                    else if (y > c - 3) cubes[x][y][z] = Blocks::DIRT;
                    else                cubes[x][y][z] = Blocks::STONE;
                }
            }
        for (int x = 0; x < quantity_cube_x; x++)
            for (int z = 0; z < quantity_cube_z; z++) {
                int c = im.getPixel(x, z).r / 10 + 10;
                for (int y = 4; y <= c; y++)
                    if (x > 5 and x < quantity_cube_x - 5 and z > 5 and x < quantity_cube_z - 5)
                        if ((rand() * rand() + seed) % 100000 == 1) head_monument(x, c, z);
            }

        for (int x = 0; x < quantity_cube_x; x++)
            for (int z = 0; z < quantity_cube_z; z++) {
                int c = im.getPixel(x, z).r / 10 + 10;
                for (int y = 4; y <= c; y++) 
                    if (x > 5 and x < quantity_cube_x - 5 and z > 5 and x < quantity_cube_z - 5) 
                        if ((rand() + seed) % 500 == 1)   trees(x, c, z);
                    
                
            }
    }
    fout.close();
    createPopupMenus();

    


    glutMainLoop();
}//*/
