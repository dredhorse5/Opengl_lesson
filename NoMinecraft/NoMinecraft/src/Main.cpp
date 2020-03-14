#include <Math.h>
#include <stdio.h>
#include <ctime>
#include "glut.h"
#include "SOIL.h"
#include "Draw_textures.hpp"
#include "Help.hpp"
#include "Load_textures.hpp"
#pragma comment(lib, "SOIL.lib")
#define GL_CLAMP_TO_EDGE 0x812F

// textures
GLuint cursor_tex[1];
GLuint dirt[1];
GLuint skybox_texturies[6];
GLuint stone[1];
GLuint planks[1];

// cubes
float cube_size = 2.0f; // size of cubes
const int width = 1280, height = 720; // size of window
int quantity_cube_x = 20; // quanity cubes of x
int quantity_cube_y = 40; // quanity cubes of y
int quantity_cube_z = 20; // quanity cubes of z
bool cubes[100][100][100];
short int cubes_types[100][100][100];
short int IDblocks = 1;
short int blocks = 3;

// камера
float lx = 1.0f, lz = 0.0f, ly = 0.0f; // координаты вектора направления движения камеры
float angleX = 0.0f, angleY = 5.0f; // угол поворота камеры
int mouseXOld = 1, mouseYOld = 1;
bool mLeft = 0, mRight = 0; // mouse bottons

// разное
double FPS = 60; // FPS 60
float KeyFront = 0, KeySide = 0; // ключ к изменению перемещения вперед/назад
bool Draw_debug_Menu_key = false;
float a = 1;


bool check(int x, int y, int z) {
    if ((x < 0) or (x > quantity_cube_x*2) or
        (y < 0) or (y > 50) or
        (z < 0) or (z > quantity_cube_z*2)) return false;
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

    Player(float x0, float y0, float z0) {
        PlayerX = x0; PlayerY= y0; PlayerZ= z0;
        dx = 0; dy = 0; dz = 0;
        dSideX = 0; dSideZ = 0;
        dFrontX = 0; dFrontZ = 0;
        w = 0.5f; h = 2.0f; d = 0.5f; speed = 0.14;
        onGround = false; 
        View =90; // угол обзора
    }
    void update() {
        if (KeyFront) {
            dFrontX = lx * speed * KeyFront;
            dFrontZ = lz * speed * KeyFront;
        }
        if (KeySide) {
            dSideX = -lz * speed * KeySide;
            dSideZ = lx * speed * KeySide;
        }
       
        dy -= 0.02;
        onGround = 0;

        dx = dSideX + dFrontX;
        PlayerX += dx;
        collision(dx, 0, 0);
        PlayerY += dy;
        collision(0, dy, 0);
        dz = dSideZ + dFrontZ;
        PlayerZ += dz;
        collision(0, 0, dz);

        
        //mLeft = mRight = false;
        dx = dz = dSideX = dSideZ = dFrontX = dFrontZ = 0;


    }
    void mousePressed() {
        //if (mRight or mLeft) {
            float mousex = PlayerX;
            float mousey = PlayerY + h / 2;
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
                        cubes_types[oldX][oldY][oldZ] = IDblocks;
                        cubes[oldX][oldY][oldZ] = 1;
                        cubes[int(PlayerX/2)][int(PlayerY/2)][int(PlayerZ/2)] = 0;
                        cubes[int(PlayerX/2)][int(PlayerY/2)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2)][int(PlayerY/2)][int(PlayerZ/2 - d/2 + 0.01)] = 0;
                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2)][int(PlayerZ/2)] = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2)][int(PlayerZ/2)] = 0;

                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2 - 1)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2 - 1)][int(PlayerZ/2 - d/2 + 0.01)] = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2 - 1)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2 - 1)][int(PlayerZ/2 - d/2 + 0.01)] = 0;

                        cubes[int(PlayerX/2)][int(PlayerY/2 - 1)][int(PlayerZ/2)] = 0;
                        cubes[int(PlayerX/2)][int(PlayerY/2 - 1)][int(PlayerZ/2 + d/2 - 0.01)] = 0;
                        cubes[int(PlayerX/2)][int(PlayerY/2 - 1)][int(PlayerZ/2 - d/2 + 0.01)] = 0;
                        cubes[int(PlayerX/2 + w/2 - 0.01)][int(PlayerY/2 - 1)][int(PlayerZ/2)] = 0;
                        cubes[int(PlayerX/2 - w/2 + 0.01)][int(PlayerY/2 - 1)][int(PlayerZ/2)] = 0;

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
};
Player steve(1, 5, 1);
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
        //float Z =(0.7 / (tan(120/2)*14)*a);
        float Z = 0.2 * a; // 0.32 max
        glBindTexture(GL_TEXTURE_2D, tex[0]);
        glTranslatef(Z * lx * cos(angleY) + steve.PlayerX, -Z * sin(angleY) + steve.PlayerY + steve.h / 2, Z * lz * cos(angleY) + steve.PlayerZ); // двойки задают удаленность от игрока
        glBegin(GL_POLYGON);
        glTexCoord2d(1, 1); glVertex3f( x1 * lz + y1 * sin(angleY) * lx,  y1 * cos(angleY), -x1 * lx + y1 * sin(angleY) * lz); // .: // двойка позволяет двигать вверх/вниз 0.356
        glTexCoord2d(0, 1); glVertex3f(-x2 * lz + y2 * sin(angleY) * lx,  y2 * cos(angleY),  x2 * lx + y2 * sin(angleY) * lz); // :. // тройка позволяет двигать влево/право
        glTexCoord2d(0, 0); glVertex3f(-x3 * lz - y3 * sin(angleY) * lx, -y3 * cos(angleY),  x3 * lx - y3 * sin(angleY) * lz); // :'
        glTexCoord2d(1, 0); glVertex3f( x4 * lz - y4 * sin(angleY) * lx, -y4 * cos(angleY), -x4 * lx - y4 * sin(angleY) * lz); // ':
        glEnd();
        glTranslatef(-Z * lx * cos(angleY) - steve.PlayerX, Z * sin(angleY) - steve.PlayerY - steve.h / 2, -Z * lz * cos(angleY) - steve.PlayerZ); // двойки задают удаленность от игрока  
    }
};

GUI cursor(0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f);

void DrawdebugScreen(float x, float y, float z, void* font,
    std::string PlayerX, std::string PlayerY, std::string PlayerZ, std::string speedX,
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
            for (int i = 0; i < PlayerX.length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, PlayerX[i]);
            glRasterPos3f(x + PlayerX.length()*7 + 40, y , z); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '/');
            glRasterPos3f(x + PlayerX.length() * 9 + 40, y, z);
            for (int i = 0; i < PlayerY.length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, PlayerY[i]);
            glRasterPos3f(x + PlayerY.length() * 7 + PlayerX.length() * 9 + 40, y, z); glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '/'); //+ PlayerX.length() * 9
            glRasterPos3f(x + PlayerX.length() * 9 + PlayerY.length() * 9 + 40, y, z);
            for (int i = 0; i < PlayerZ.length() - 3; i++) glutBitmapCharacter(GLUT_BITMAP_9_BY_15, PlayerZ[i]);


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
    }
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
        steve.PlayerX = 0;
        steve.PlayerY = 5;
        steve.PlayerZ = 0;
        steve.dy = 0;
        break;
    case 'f':
        a -= 0.1;
        IDblocks++;
        break;
    
    case 32:
        if (steve.onGround) {
            steve.onGround = false;
            steve.dy = 0.34;
        }
        break;

    case 27:    exit(0);

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
    gluPerspective(steve.View, ratio, 0.1f, 180.0f);
    glMatrixMode(GL_MODELVIEW);
}
void timf(int value){
    glutPostRedisplay();  // Redraw windows
    glutTimerFunc(1000 / FPS, timf, 0); // Setup next timer
}


void Draw() // Window redraw function
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    //===============================начало основного цикла================================================================================
    

    gluLookAt(steve.PlayerX,        steve.PlayerY + steve.h/2,        steve.PlayerZ,
              steve.PlayerX + lx,   steve.PlayerY + ly + steve.h/2,   steve.PlayerZ + lz,
              0.0f,                 1.0f,                             0.0f                            );

    DrawdebugScreen(5, 30, 0, GLUT_BITMAP_HELVETICA_18, std::to_string(steve.PlayerX/2 + 0.5), std::to_string(steve.PlayerY / 2),
        std::to_string(steve.PlayerZ / 2 + 0.5), std::to_string(steve.dx), std::to_string(steve.dy), std::to_string(steve.dz), std::to_string(lx), std::to_string(ly),
        std::to_string(lz), std::to_string(steve.onGround), std::to_string(52), std::to_string(IDblocks), std::to_string(cos(angleY)));

    cursor.update(cursor_tex);
    //glDisable(GL_LIGHTING);
    
    glTranslatef(steve.PlayerX, steve.PlayerY, steve.PlayerZ);
    drawSkybox(skybox_texturies);
    glTranslatef(-steve.PlayerX, -steve.PlayerY, -steve.PlayerZ);
    //glEnable(GL_LIGHTING);
    //glPushMatrix();
    //GLfloat light1_diffuse[] = { 1, 1, 1 };
    //GLfloat light1_position[] = { quantity_cube_x/2, 50,quantity_cube_z/2, 1 };
    //glEnable(GL_LIGHT1);
    //glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    //glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    //glPopMatrix();

   
    for (int x = 0; x < quantity_cube_x; x++) // drawing cubs
        for (int y = 0; y < 50; y++)
            for (int z = 0; z < quantity_cube_z; z++)
            {
                if (!cubes[x][y][z]) continue; 
                glPushMatrix();
                glTranslatef(x * cube_size + cube_size / 2, y * cube_size + cube_size / 2, z * cube_size + cube_size / 2);
                
                switch (cubes_types[x][y][z]) {
                case 1:   draw_dirt(dirt, cube_size / 2, x, y, z, cubes); break;
                case 2:   draw_stone(stone, cube_size / 2, x, y, z, cubes); break;
                case 3:   draw_planks(planks, cube_size / 2, x, y, z, cubes); break;
                }
                
                glTranslatef(-x * cube_size - cube_size / 2, -y * cube_size - cube_size / 2, -z * cube_size - cube_size / 2);
                glPopMatrix();
            }
    if (IDblocks > blocks) IDblocks = 1;



    steve.update();
    steve.mousePressed();

    //=================================конец основного цикла===================================================================================
    //glutPostRedisplay();
    glPopMatrix();
    glFinish();
    //glDisable(GL_LIGHT0);
    glutSwapBuffers();
}



void main(int argc, char* argv[])
{
    //===========================INITIALIZATION===========================================
    glutInit(&argc, argv);
    glutInitWindowSize(width, height);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("cubes");
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    glFrontFace(GL_CCW);
    glutTimerFunc(1000 / FPS, timf, 0); // limit fps
    glEnable(GL_TEXTURE_2D);
    glutDisplayFunc(Draw);    // Main draw function
    glutReshapeFunc(Reshape); // change window
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE); //for light
    glEnable(GL_NORMALIZE); //for light
    glutSetCursor(GLUT_CURSOR_NONE);
    //=====================================TEXTURES=======================================
    skybox(skybox_texturies, width, height);
    dirtTexturies(dirt, width, height);
    stoneTextures(stone, width, height);
    planksTextures(planks, width, height);
    cursorTextures(cursor_tex, width, height);
    //====================================================================================
    glutPassiveMotionFunc(mouseMove);

    glutMouseFunc(mouseButton);

    glutKeyboardFunc(processNormalKeysDOWN);// working when keyBoard down
    glutKeyboardUpFunc(processNormalKeysUP);// working when keyboard up

   
    // заполнение массива блоками
    for (int x = 0; x < quantity_cube_x; x++)
        for (int y = 0; y < quantity_cube_y; y++)
            for (int z = 0; z < quantity_cube_z; z++) {

                if (y == 0 or y == 1 or y == 2 or y == 3 or y == 4) {
                    cubes[x][y][z] = 1; 
                    cubes_types[x][y][z] = 1;
                }
                
                if ((rand() % 2) == 1) cubes_types[x][y][z] = 2;
            }



    //glutIdleFunc(Draw); // какая-то херня, которая увердохера загружает видюху. как будто игнорит ограничение fps
    


    glutMainLoop();
}//*/
