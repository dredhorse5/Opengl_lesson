#include <locale.h>
#include <Windows.h>
#include <Math.h>
#include <stdio.h>
#include <string>
#include <glut.h>
#include <SOIL.h>
#include "Draw_textures.hpp"
#include "Help.hpp"
#include "Load_textures.hpp"
#include <time.h>
#include <ctime>
#pragma comment(lib, "SOIL.lib")
#define GL_CLAMP_TO_EDGE 0x812F

float cube_size = 1.0f; // размер кубов
const int width = 1280, height = 720; // Размер окна
int quantity_cube_x = 10; // колличество кубиков по оси x
int quantity_cube_y = 10; // колличество кубиков по оси y
int quantity_cube_z = 10; // колличество кубиков по оси z
//float PlayerX = 0.0f, PlayerY = 4.0f, PlayerZ = 0.0f; // координаты камеры
//float speed_Player = 1.0;
//float PlayerY_key = 0.0; // ключ к изменению координаты Y игрока
float lx = 1.0f, lz = 0.0f, ly = 0.0f; // координаты вектора направления движения камеры
float angleX = 0.0f, angleY = 5.0f; // угол поворота камеры
double FPS = 60; // FPS 60
float distange_between_cubs = cube_size * 2; //настоящее растояние между кубами;
bool KeyW, KeyS, KeyA, KeyD = 0.0; // ключ к изменению пермещения вперед/назад
float deltaMoveSide = 0.0; // ключ к изменению перемещения вбок
float deltaMove = 0;
int mouseXOld = 1, mouseYOld = 1;
int cubes[100][100][100];
GLuint dirt[3];
GLuint skybox_texturies[6];

bool check(int x, int y, int z) {
    if ((x < 0) or (x >= 1000) or
        (y < 0) or (y >= 1000) or
        (z < 0) or (z >= 1000)) return false;
    return cubes[z][y][z];

}
class Player {
public:
    float PlayerX, PlayerY, PlayerZ;
    float dx, dy, dz;
    float w, h, d;
    bool onGround;
    float speed;
    float View; // угол обзора

    Player(float x0, float y0, float z0) {
        PlayerX = x0; PlayerY= y0; PlayerZ= z0;
        dx = 0; dy = 0; dz = 0;
        w = 1.0; h = 2; d = 1.0; speed = 1;
        onGround = false; 
        View = 75; // угол обзора
    }

    void update(float time) {
        if (!onGround) dy -= 0.1 * time;
        onGround = 0;
        PlayerX += dx * time;
        collision(dx, 0, 0);
        PlayerY += dy * time;
        collision(0, dy, 0);
        PlayerZ += dz * time;
        collision(0, 0, dz);

        dx = dz = 0;


    }
    void collision(float Dx, float Dy, float Dz) {
        for (int X = (PlayerX - w) / cube_size; X < (PlayerX + w) / cube_size; X++)
        for (int Y = (PlayerY - h) / cube_size; Y < (PlayerY + h) / cube_size; Y++)
        for (int Z = (PlayerZ - d) / cube_size; Z < (PlayerZ + d) / cube_size; Z++)
            if(check(X,Y,Z))
            {
                if (Dx > 0) PlayerX = X * cube_size - w;
                if (Dx < 0) PlayerX = X * cube_size + cube_size + w;
                if (Dy > 0) PlayerY = Y * cube_size - h;
                if (Dy < 0){PlayerY = Y * cube_size + cube_size + h; onGround = true; dy = 0; }
                if (Dz > 0) PlayerZ = Z * cube_size - d;
                if (Dz < 0) PlayerZ = Z * cube_size + cube_size + d;
            }
    }

    void moveFront() {
        dx = lx * speed;
        dz = lz * speed;
    }
    void moveBack() {
        dx = -lx * speed;
        dz = -lz * speed;
    }
    void moveRight() {
        dx = -lz * speed;
        dz = lx * speed;
    }
    void moveLeft() {
        dx = lz * speed;
        dz = -lx * speed;
    }
};

Player steve(2, 10, 2.5);

void drawText(float x, float y, float z, float r, float g, float b, std::string string) {
    glColor3f(r, g, b);
    glRasterPos3f(x, y + 1, z);
    for (int i = 0; i < string.length(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
    }
}
void drawDebug(float time) {

    drawText(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, std::to_string(time));

}


void processNormalKeysDOWN(unsigned char key, int x, int y)
{
    switch (key) {
    case 'w':
    case 'W':
        KeyW = true; break;
    case 's':
    case 'S':
        KeyS = true; break;
    case 'a':
    case 'A':
        KeyA = true; break;
    
    case 'd':
    case 'D':
        KeyD = true; break;
    
    case 32:
        if (steve.onGround) {
            steve.onGround = false;
            steve.dy = 2;
        }
        break;

    case 27:    exit(0);

    }

}
void processNormalKeysUP(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
        case 'W':
        case 's':
        case 'S':
            KeyW = false;
            KeyS = false;
            break;
        case 'a':
        case 'A':
        case 'd':
        case 'D':
            KeyA = false;
            KeyD = false;
            break;

    }
}

void mouseMove(int x, int y) 
{
    if ( mouseXOld != 0 or mouseYOld != 0) {
        angleX -= mouseXOld * 0.001f;
        angleY -= mouseYOld * 0.001f;

        if (angleY > 3.14 / 2) angleY = 3.14 / 2;
        if (angleY < -3.14 / 2) angleY = -3.14 / 2;

        mouseXOld = 0; mouseYOld = 0;

        // update camera's direction
        lx = sin(angleX);
        lz = -cos(angleX);
        ly = -tan(angleY);
        
    } else {
        
        mouseXOld = (width /2) - x;
        mouseYOld = (height /2) - y;
        glutWarpPointer((width /2), (height /2));
    }
    //glutPostRedisplay();

}
void Reshape(int w, int h) // Reshape function
{
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(steve.View, ratio, 0.1f, 750.0f);
    glMatrixMode(GL_MODELVIEW);
}
void Draw() // Window redraw function
{

    double Newtime = clock();
    /*if (deltaMoveFront)
    {
        PlayerX += deltaMoveFront * lx * 0.1f;
        PlayerZ += deltaMoveFront * lz * 0.1f;
    }
    if (deltaMoveSide)
    {
        PlayerX += deltaMoveSide *  lz * 0.1f;
        PlayerZ += deltaMoveSide * (-lx) * 0.1f;
    }*/


    if (KeyW) steve.moveFront();
    if (KeyS) steve.moveBack();
    if (KeyD) steve.moveRight();
    if (KeyA) steve.moveLeft();
    //if (PlayerY_key) PlayerY += PlayerY_key;
    //===============================начало основного цикла================================================================================
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    gluLookAt(steve.PlayerX,        steve.PlayerY,      steve.PlayerZ,
              steve.PlayerX + lx,   steve.PlayerY + ly, steve.PlayerZ + lz,
              0.0f,                 1.0f,               0.0f                    );



    for (int x = 0; x < quantity_cube_x; x++) // рисуем кубы сеткой
        for (int y = 0; y < quantity_cube_y; y++)
            for (int z = 0; z < quantity_cube_z; z++)
            {
                if (!cubes[x][y][z]) continue;
                glPushMatrix();
                glTranslatef(x * distange_between_cubs, y * distange_between_cubs, z * distange_between_cubs);
                draw_dirt(dirt, cube_size);
                glPopMatrix();
            }
    


    glTranslatef(steve.PlayerX, steve.PlayerY, steve.PlayerZ);
    drawSkybox(skybox_texturies);
    glTranslatef(-steve.PlayerX, -steve.PlayerY, -steve.PlayerZ);
    //=================================конец основного цикла===================================================================================

    double OldTime = clock();
    float time = (OldTime - Newtime) / 10;


    steve.update(time);

    drawDebug(time);
    glPopMatrix();
    glFinish();
    glutSwapBuffers();
}
void timf(int value) // Timer function
{
    glutPostRedisplay();  // Redraw windows
    glutTimerFunc(1000 / FPS, timf, 0); // Setup next timer
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
    glFrontFace(GL_CCW);
    glutTimerFunc(1000 / FPS, timf, 0); // ограничение fps
    glEnable(GL_TEXTURE_2D);
    glutDisplayFunc(Draw);    // основная функция рисования
    glutReshapeFunc(Reshape); // функция изменения окна
    glutSetCursor(GLUT_CURSOR_NONE);
    //=====================================TEXTURES=======================================
    skybox(skybox_texturies, width, height);
    dirtTexturies(dirt, width, height);
    //====================================================================================
    glutPassiveMotionFunc(mouseMove);

    glutKeyboardFunc(processNormalKeysDOWN);// срабатывает когда клавиша нажалась
    glutKeyboardUpFunc(processNormalKeysUP);// срабатывает когда клавиша отжалась

   
    // заполнение массива блоками
    for (int x = 0; x < 50; x++)
        for (int y = 0; y < 50; y++)
            for (int z = 0; z < 50; z++) {
                if (y == 0 or rand() % 100 == 1) cubes[x][y][z] = 1;
            }


    //glutMouseFunc(mouseButton);
    //glutSpecialFunc(SpecialKeyDOWN);
    //glutSpecialUpFunc(SpecialKeyUP);      
    //glClearColor(0, 128, 255, 100); // цвет фона
    //glutSetKeyRepeat(GLUT_KEY_REPEAT_ON); // хз зачем, ничего не меняет
    //glutIgnoreKeyRepeat(0); хз зачем, при быстрой смене направления движения при кооф 1 не двигает камеру :/ 
    //glutIdleFunc(Draw); // какая-то херня, которая увердохера загружает видюху. как будто игнорит ограничение fps
    


    glutMainLoop();

    return 0;
}//*/