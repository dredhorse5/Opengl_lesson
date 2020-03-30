#include <Math.h>
#include <stdio.h>
#include <ctime>
#include <thread>
#include <iostream>
#include <fstream>
#include "glut.h"
#include "SOIL.h"
#include "Draw_textures.hpp"
#include "Load_textures.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#pragma comment(lib, "SOIL.lib")
#define GL_CLAMP_TO_EDGE 0x812F

// textures
GLuint cursor_tex[1];
GLuint super_grass[1];
GLuint skybox_texturies[6];
GLuint stone[1];
GLuint planks[1];
GLuint HeightMap[1];
GLuint dirt[1];
GLuint GUI_tex[1];
// cubes
float cube_size = 2.0f; // size of cubes
const int width = 1280, height = 720; // size of window
int quantity_cube_x = 256; // quanity cubes of x
int quantity_cube_y = 50; // quanity cubes of y
int quantity_cube_z = 256; // quanity cubes of z
int cubes[257][50][257];
short int IDblocks = 1;
short int blocks = 5;

// камера
float lx = 1.0f, lz = 0.0f, ly = 0.0f; // координаты вектора направления движения камеры
float angleX = 0.0f, angleY = 5.0f; // угол поворота камеры
int mouseXOld = 1, mouseYOld = 1;
bool mLeft = 0, mRight = 0; // mouse bottons
float FPS = 60;
// разное
float KeyFront = 0, KeySide = 0; // ключ к изменению перемещения вперед/назад
bool Draw_debug_Menu_key = true;
time_t oldtime = 1;
time_t newtime = 1;

bool check(int x, int y, int z) {
    if ((x < 0) or (x > quantity_cube_x) or
        (y < 0) or (y > quantity_cube_y) or
        (z < 0) or (z > quantity_cube_z)) return false;
    return cubes[x][y][z];

}

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
    float time;

    Player(float x0, float y0, float z0) {
        PlayerX = x0; PlayerY= y0; PlayerZ= z0;
        dx = 0; dy = 0; dz = 0;
        dSideX = 0; dSideZ = 0;
        dFrontX = 0; dFrontZ = 0;
        w = 0.5f; h = 1.9f; d = 0.5f; speed = 0.5;
        onGround = false; 
        View =90; // угол обзора
    }
    void update(float time) {
        this->time = time;
        mousePressed();
        if (KeyFront) {
            dFrontX = lx * speed * KeyFront * time/50;
            dFrontZ = lz * speed * KeyFront * time / 50;
        }
        if (KeySide) {
            dSideX = -lz * speed * KeySide * time / 50;
            dSideZ = lx * speed * KeySide * time / 50;
        }
       
        dy -= 0.1 * pow(time/50,2);
        onGround = 0;

        dx = dSideX + dFrontX;
        PlayerX += dx;
        //std::thread one(Player::*collision, dx, 0, 0);
        collision(dx, 0, 0);
        PlayerY += dy;
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

                    if (mLeft) { cubes[X][Y][Z] = 0;          break; }
                    if (mRight) {
                        //cubes_types[oldX][oldY][oldZ] = IDblocks;
                        cubes[oldX][oldY][oldZ] = IDblocks;
                        cubes[int(PlayerX/2)][int(PlayerY/2)][int(PlayerZ/2)] = 0;
                        cubes[int(PlayerX/2)][int(PlayerY/2)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2)][int(PlayerY/2)][int(PlayerZ/2 - d/2 + 0.01)] = 0;
                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2)][int(PlayerZ/2)] = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2)][int(PlayerZ/2)] = 0;

                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2 - h / 2)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2 - h / 2)][int(PlayerZ/2 - d/2 + 0.01)] = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2 - h / 2)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2 - h / 2)][int(PlayerZ/2 - d/2 + 0.01)] = 0;

                        cubes[int(PlayerX/2)][int(PlayerY/2 - h / 2)][int(PlayerZ/2)] = 0;
                        cubes[int(PlayerX/2)][int(PlayerY/2 - h / 2)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2)][int(PlayerY/2 - h / 2)][int(PlayerZ/2 - d/2 + 0.01)] = 0;
                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2 - h / 2)][int(PlayerZ/2)] = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2 - h / 2)][int(PlayerZ/2)] = 0;

                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2)][int(PlayerZ/2 - d/2 + 0.01)] = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2)][int(PlayerZ/2 - d/2 + 0.01)] = 0;

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
            dy = 0.3;
        }
    }
};
Player steve(quantity_cube_x/2,60, quantity_cube_z/2);
class GUI {
public:
    float x1; float y1;
    float x2; float y2;
    float x3; float y3;
    float x4; float y4;
    
    GUI(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
        this->x1 = x1; this->y1 = y1;
        this->x2 = x2; this->y2 = y2;
        this->x3 = x3; this->y3 = y3;
        this->x4 = x4; this->y4 = y4;
    }

    void update(GLuint tex[1]) {
        glBindTexture(GL_TEXTURE_2D, tex[0]);
        glTranslatef(0.2 * lx * cos(angleY) + steve.PlayerX, -0.2 * sin(angleY) + steve.PlayerY + steve.h / 2, 0.2 * lz * cos(angleY) + steve.PlayerZ); // двойки задают удаленность от игрока
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f( x1 * lz + y1 * sin(angleY) * lx,  y1 * cos(angleY), -x1 * lx + y1 * sin(angleY) * lz); // .: // двойка позволяет двигать вверх/вниз 0.356
        glTexCoord2d(0, 1); glVertex3f(-x2 * lz + y2 * sin(angleY) * lx,  y2 * cos(angleY),  x2 * lx + y2 * sin(angleY) * lz); // :. // тройка позволяет двигать влево/право
        glTexCoord2d(0, 0); glVertex3f(-x3 * lz - y3 * sin(angleY) * lx, -y3 * cos(angleY),  x3 * lx - y3 * sin(angleY) * lz); // :'
        glTexCoord2d(1, 0); glVertex3f( x4 * lz - y4 * sin(angleY) * lx, -y4 * cos(angleY), -x4 * lx - y4 * sin(angleY) * lz); // ':
        glEnd();
        glTranslatef(-0.2 * lx * cos(angleY) - steve.PlayerX, 0.2 * sin(angleY) - steve.PlayerY - steve.h / 2, -0.2 * lz * cos(angleY) - steve.PlayerZ); // двойки задают удаленность от игрока  
    }
    void update(GLuint tex[1],float x1h, float y1h, float x2h, float y2h, float x3h, float y3h, float x4h, float y4h) {
        glBindTexture(GL_TEXTURE_2D, tex[0]);
        glTranslatef(0.2 * lx * cos(angleY) + steve.PlayerX, -0.2 * sin(angleY) + steve.PlayerY + steve.h / 2, 0.2 * lz * cos(angleY) + steve.PlayerZ); // двойки задают удаленность от игрока
        glBegin(GL_POLYGON);
        glTexCoord2d(x1h, y1h); glVertex3f(x1 * lz + y1 * sin(angleY) * lx, y1 * cos(angleY), -x1 * lx + y1 * sin(angleY) * lz); // .: // двойка позволяет двигать вверх/вниз 0.356
        glTexCoord2d(x2h, y2h); glVertex3f(-x2 * lz + y2 * sin(angleY) * lx, y2 * cos(angleY), x2 * lx + y2 * sin(angleY) * lz); // :. // тройка позволяет двигать влево/право
        glTexCoord2d(x3h, y3h); glVertex3f(-x3 * lz - y3 * sin(angleY) * lx, -y3 * cos(angleY), x3 * lx - y3 * sin(angleY) * lz); // :'
        glTexCoord2d(x4h, y4h); glVertex3f(x4 * lz - y4 * sin(angleY) * lx, -y4 * cos(angleY), -x4 * lx - y4 * sin(angleY) * lz); // ':
        glEnd();
        glTranslatef(-0.2 * lx * cos(angleY) - steve.PlayerX, 0.2 * sin(angleY) - steve.PlayerY - steve.h / 2, -0.2 * lz * cos(angleY) - steve.PlayerZ); // двойки задают удаленность от игрока  
    }
    void update() {
        glColor3f(1, 0, 0);
        glTranslatef(0.2 * lx * cos(angleY) + steve.PlayerX, -0.2 * sin(angleY) + steve.PlayerY + steve.h / 2, 0.2 * lz * cos(angleY) + steve.PlayerZ); // двойки задают удаленность от игрока
        glBegin(GL_POLYGON);
        glVertex3f(x1 * lz + y1 * sin(angleY) * lx, y1 * cos(angleY), -x1 * lx + y1 * sin(angleY) * lz); // .: // двойка позволяет двигать вверх/вниз 0.356
        glVertex3f(-x2 * lz + y2 * sin(angleY) * lx, y2 * cos(angleY), x2 * lx + y2 * sin(angleY) * lz); // :. // тройка позволяет двигать влево/право
        glVertex3f(-x3 * lz - y3 * sin(angleY) * lx, -y3 * cos(angleY), x3 * lx - y3 * sin(angleY) * lz); // :'
        glVertex3f(x4 * lz - y4 * sin(angleY) * lx, -y4 * cos(angleY), -x4 * lx - y4 * sin(angleY) * lz); // ':
        glEnd();
        glTranslatef(-0.2 * lx * cos(angleY) - steve.PlayerX, 0.2 * sin(angleY) - steve.PlayerY - steve.h / 2, -0.2 * lz * cos(angleY) - steve.PlayerZ); // двойки задают удаленность от игрока  
        glColor3f(1, 1, 1);
    }
};

GUI cursor(0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f);
GUI quad(0.357f, 0.2f, -0.2f, 0.2f, -0.2f, 0.01f, 0.357f, 0.01f);
GUI hotbar_down(0.15f, -0.165f,        0.15f, -0.165f,        0.15f, 0.2f,        0.15f, 0.2f);
 
inline void DrawdebugScreen(float x, float y, float z, void* font, std::string speedX,
    std::string speedY, std::string speedZ, std::string lX, std::string lY, std::string lZ, std::string Onground,
    std::string DxCHECK, std::string DyCHECK, std::string DzCHECK) {if (Draw_debug_Menu_key) {
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

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        {
            glRasterPos3f(x, y, z);
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'X'); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'Y'); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'Z');
            glRasterPos3f(x + 40, y , z);
            for (int i = 0; i < std::to_string(steve.PlayerX/2 + 0.5).length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, std::to_string(steve.PlayerX / 2 + 0.5)[i]);
            glRasterPos3f(x + std::to_string(steve.PlayerX / 2 + 0.5).length()*7 + 40, y , z); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '/');
            glRasterPos3f(x + std::to_string(steve.PlayerX / 2 + 0.5).length() * 9 + 40, y, z);
            for (int i = 0; i < std::to_string(steve.PlayerY / 2 + 0.5).length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, std::to_string(steve.PlayerY / 2 + 0.5)[i]);
            glRasterPos3f(x + std::to_string(steve.PlayerY / 2 + 0.5).length() * 7 + std::to_string(steve.PlayerX / 2 + 0.5).length() * 9 + 40, y, z); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '/'); //+ PlayerX.length() * 9
            glRasterPos3f(x + std::to_string(steve.PlayerX / 2 + 0.5).length() * 9 + std::to_string(steve.PlayerY / 2 + 0.5).length() * 9 + 40, y, z);
            for (int i = 0; i < std::to_string(steve.PlayerZ / 2 + 0.5).length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, std::to_string(steve.PlayerZ / 2 + 0.5)[i]);


            /*glRasterPos3f(x+ 50, y + 40, z);
            for (int i = 0; i < speedX.length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, speedX[i]);

            glRasterPos3f(x + 100, y + 40, z);
            for (int i = 0; i < speedY.length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, speedY[i]);

            glRasterPos3f(x + 150, y + 40, z);
            for (int i = 0; i < speedZ.length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, speedZ[i]);*/

            glRasterPos3f(x, y + 30, z);
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'L'); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '('); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'X');
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'Y'); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'Z'); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ')');

            glRasterPos3f(x + 60, y + 30, z);
            for (int i = 0; i < lX.length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, lX[i]);
            glRasterPos3f(x + lX.length() * 7 + 60, y + 30, z); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '/');

            glRasterPos3f(x + lX.length() * 7 + 60 + 20, y + 30, z);
            for (int i = 0; i < lY.length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, lY[i]);

            glRasterPos3f(x + 200, y + 30, z);
            for (int i = 0; i < lZ.length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, lZ[i]);

            glRasterPos3f(x, y + 340, z);
            for (int i = 0; i < Onground.length(); i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, Onground[i]);

            glRasterPos3f(x, y + 390, z);
            for (int i = 0; i < DxCHECK.length(); i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, DxCHECK[i]);

            glRasterPos3f(x, y + 420, z);
            for (int i = 0; i < DyCHECK.length(); i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, DyCHECK[i]);

            glRasterPos3f(x, y + 450, z);
            for (int i = 0; i < DzCHECK.length(); i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, DzCHECK[i]);
        }


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        glPopMatrix();

        glMatrixMode(GL_PROJECTION);
        //восстановить предыдущую матрицу проекции
        glPopMatrix();
        //вернуться в режим модели
        glMatrixMode(GL_MODELVIEW);
        quad.update();
    }
}

void close_game() {
    int msg;
        std::ofstream fout("Text.txt", std::fstream::trunc);
        for (int x = 0; x < quantity_cube_x; x++)
            for(int y = 0; y < quantity_cube_y; y++)
                for (int z = 0; z < quantity_cube_z; z++) {
                    fout << cubes[x][y][z];
                }
        fout.close();
    exit(0);
}
void processNormalKeysDOWN(unsigned char key, int x, int y)
{
    switch (key) {
    case 'w':
    case 'W':
        KeyFront = 1.0; break;
    case 's':
    case 'S':
        KeyFront = -1.0; break;
    case 'a':
    case 'A':
        KeySide = -1.0; break;
    case 'd':
    case 'D':
        KeySide = 1.0; break;
    case 'b':
        steve.PlayerX = 257/2             * cube_size;
        steve.PlayerY = 100              * cube_size;
        steve.PlayerZ = 257/2             * cube_size;
        steve.dy = 0;
        break;
    case 'f':
        IDblocks++;
        if (IDblocks > blocks) IDblocks = 0;
        break;
    
    case 32:
        steve.jump();
        
        break;

    case 27: {
        //std::thread th(close_game);
        //th.detach();    
        /*int msg;
        std::ofstream fout("Text.txt", std::fstream::trunc);
        for (int x = 0; x < quantity_cube_x; x++)
            for(int y = 0; y < quantity_cube_y; y++)
                for (int z = 0; z < quantity_cube_z; z++) {
                    fout << cubes[x][y][z];
                }
        fout.close();*/
        exit(0);
        
    }
    }
    if (key == 9) {
        if (!Draw_debug_Menu_key) {
            Draw_debug_Menu_key = 1;
        }
        else Draw_debug_Menu_key = 0;
    }

}
void processNormalKeysUP(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
        case 'W':
        case 's':
        case 'S':
            KeyFront = 0;
            break;
        case 'a':
        case 'A':
        case 'd':
        case 'D':
            KeySide = 0;
            break;

    }
}
void mouseMove(int x, int y) {
    if ( mouseXOld != 0 or mouseYOld != 0) {
        angleX -= mouseXOld * 0.001f;
        angleY -= mouseYOld * 0.001f;

        if (angleY > 3.14 / 2) angleY = 3.14 / 2;
        if (angleY < -3.14 / 2) angleY = -3.14 / 2;

        mouseXOld = 0; mouseYOld = 0;

        // update camera's direction
        lx = float(sin(angleX));
        lz = float(-cos(angleX));
        ly = float(-tan(angleY));
        
    } else {
        
        mouseXOld = (width /2) - x;
        mouseYOld = (height /2) - y;
        glutWarpPointer((width /2), (height /2));
    } 

    //glutPostRedisplay();
    
}
void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON){
        switch (state){
        case GLUT_DOWN:		//Если нажата
            mLeft = true;
            break;
        case GLUT_UP:
            mLeft = false;
            break;
        }
    }

    if (button == GLUT_RIGHT_BUTTON){
        switch (state){
        case GLUT_DOWN:		//Если нажата
            mRight = true;
            break;
        case GLUT_UP:
            mRight = false;
            break;
        }
    }
}
void Reshape(int w, int h){
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(steve.View, ratio, 0.1f, 360.0f);
    glMatrixMode(GL_MODELVIEW);
}
void timf(int value){
    glutPostRedisplay();  // Redraw windows
    glutTimerFunc(1000 / FPS, timf, 0); // Setup next timer
}
inline void Draw_cubes() {
    for (int x = steve.PlayerX / 2 - 50; x < steve.PlayerX / 2 + 50; x++) // drawing cubs
        for (int y = 0; y < quantity_cube_y; y++)
            for (int z = steve.PlayerZ / 2 - 50; z < steve.PlayerZ / 2 + 50; z++ )
            {
                if (x < 0 or x > quantity_cube_x) continue;
                if (z < 0 or z > quantity_cube_z)  continue;
                int type = cubes[x][y][z];
                if (!type or   (bool(type) == bool(cubes[x][y + 1][z]) and bool(type) == bool(cubes[x][y - 1][z]) and
                                bool(type) == bool(cubes[x + 1][y][z]) and bool(type) == bool(cubes[x - 1][y][z]) and
                                bool(type) == bool(cubes[x][y][z + 1]) and bool(type) == bool(cubes[x][y][z - 1])    )) continue;
               /* if (!type or bool(type == cubes[x][y + 1][z] and type == cubes[x][y - 1][z] and
                                    type == cubes[x + 1][y][z] and type == cubes[x - 1][y][z] and
                                    type == cubes[x][y][z + 1] and type == cubes[x][y][z - 1])     ) continue;*/
                glPushMatrix();
                glTranslatef(x * cube_size + cube_size / 2, y * cube_size + cube_size / 2, z * cube_size + cube_size / 2);

                switch (type) {
                case 1: {draw_stone(      stone,       cube_size / 2, x, y, z, cubes, steve.PlayerX, steve.PlayerY, steve.PlayerZ); break; }
                case 2: {draw_super_grass(super_grass, cube_size / 2, x, y, z, cubes, steve.PlayerX, steve.PlayerY, steve.PlayerZ); break; }
                case 3: {draw_dirt(       dirt,        cube_size / 2, x, y, z, cubes, steve.PlayerX, steve.PlayerY, steve.PlayerZ); break; }
                case 4: {draw_planks(     planks,      cube_size / 2, x, y, z, cubes, steve.PlayerX, steve.PlayerY, steve.PlayerZ); break; }
                }

                //glTranslatef(-x * cube_size - cube_size / 2, -y * cube_size - cube_size / 2, -z * cube_size - cube_size / 2);
                glPopMatrix();
            }
}

void Draw(){
 
    std::thread glclear_th(glClear, GL_COLOR_BUFFER_BIT); 
    glClear(GL_DEPTH_BUFFER_BIT);
    glclear_th.join();

    glPushMatrix();
    
    //===============================начало основного цикла================================================================================


    gluLookAt(steve.PlayerX,        steve.PlayerY + steve.h/2,        steve.PlayerZ,
              steve.PlayerX + lx,   steve.PlayerY + ly + steve.h/2,   steve.PlayerZ + lz,
              0.0f,                 1.0f,                             0.0f                            );
    Draw_cubes();
    cursor.update(cursor_tex);
    hotbar_down.update(GUI_tex, 1, 1,     0.09f, 1,      0.09f, 0.89f,     1, 0.89f);
    
    glTranslatef(steve.PlayerX, steve.PlayerY, steve.PlayerZ);
    drawSkybox(skybox_texturies);
    glTranslatef(-steve.PlayerX, -steve.PlayerY, -steve.PlayerZ);


    

    DrawdebugScreen( 5, 30, 0, GLUT_BITMAP_HELVETICA_18, std::to_string(steve.dx), std::to_string(steve.dy), std::to_string(steve.dz), std::to_string(lx), std::to_string(ly),
        std::to_string(lz), std::to_string(steve.onGround), std::to_string(52), std::to_string(IDblocks), std::to_string(ly/*cos(angleY)*/));
    

    

    newtime = clock();
    float times = newtime - oldtime;
    oldtime = clock();
    steve.update(times);
    //steve.mousePressed();
    //=================================конец основного цикла===================================================================================
    glutPostRedisplay();
    glPopMatrix();
    glutSwapBuffers();
}



int main(int argc, char* argv[])
{
    //===========================INITIALIZATION===========================================
    glutInit(&argc, argv);
    glutInitWindowSize(width, height);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("cubes");
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    //glutTimerFunc(1000 / FPS, timf, 0); // limit fps
    glEnable(GL_TEXTURE_2D);
    glutDisplayFunc(Draw);    // Main draw function
    glutReshapeFunc(Reshape); // change window
    glutSetCursor(GLUT_CURSOR_NONE);
    //=====================================TEXTURES=======================================
    skybox(skybox_texturies, width, height);
    super_grass_Texturies(super_grass, width, height);
    stoneTextures(stone, width, height);
    planksTextures(planks, width, height);
    dirtTextures(dirt, width, height);
    cursorTextures(cursor_tex, width, height);
    HeightMap_Load(HeightMap, width, height);
    GUITextures(GUI_tex, width, height);
    //====================================================================================
    glutPassiveMotionFunc(mouseMove);
    glutMotionFunc(mouseMove);

    glutMouseFunc(mouseButton);

    glutKeyboardFunc(processNormalKeysDOWN);// working when keyBoard is down
    glutKeyboardUpFunc(processNormalKeysUP);// working when keyboard is up

    std::ifstream fout("Text.txt", std::ifstream::binary);





sf::Image im; im.loadFromFile("textures/heightmap.png");
    for (int x = 0; x < quantity_cube_x; x++)
        for (int z = 0; z < quantity_cube_z; z++) {
            int c = im.getPixel(x,z).r/10 +10;
            for(int y = 4; y<=c; y++){
                    //cubes[x][y][z] = 1;
                if (y == c) {
                    cubes[x][y][z] = 2;
                }
                else if (y > c - 3)  cubes[x][y][z] = 3;
                else if (y == 4) cubes[x][y][z] = 999;
                    else cubes[x][y][z] = 1;
                }
        }
    


    glutMainLoop();
}//*/
