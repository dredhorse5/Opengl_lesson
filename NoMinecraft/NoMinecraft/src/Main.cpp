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
#pragma comment(lib, "SOIL.lib")
#define GL_CLAMP_TO_EDGE 0x812F

float cube_size = 1.0; // размер кубов
const int width = 1280, height = 720; // Размер окна
int W = width, H = height;
int quantity_cube_x = 40; // колличество кубиков по оси x
int quantity_cube_z = 40; // колличество кубиков по оси z
float PlayerX = 0.0f, PlayerY = 4.0f, PlayerZ = 0.0f; // координаты камеры
float PlayerY_key = 0.0; // ключ к изменению координаты Y игрока
float lx = 1.0f, lz = 0.0f, ly = 0.0f; // координаты вектора направления движения камеры
float angleX = 0.0f, angleY = 5.0f; // угол поворота камеры
float View = 75; // угол обзора
double FPS = 60; // FPS 60
float distance_between_cubs_key =  0; // ключ к изменению скорости расстояния между кубами
float distange_between_cubs = 2; //настоящее растояние между кубами;
float deltaMoveFront = 0.0; // ключ к изменению пермещения вперед/назад
float deltaMoveSide = 0.0; // ключ к изменению перемещения вбок
float deltaMove = 0;
int mouseXOld = 1, mouseYOld = 1;
bool cubes[50][50][50];
GLuint dirt[3];
GLuint skybox_texturies[6];



void drawText(float x, float y, float z, float r, float g, float b, std::string string) {
    glColor3f(r, g, b);
    glRasterPos3f(x, y + 2, z);
    for (int i = 0; i < string.length(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
    }
}
void drawDebug() {

    drawText(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, std::to_string(ly));

}
//void SpecialKeyUP(int key, int x, int y)
//void SpecialKeyDOWN(int key, int x, int y)
void processNormalKeysDOWN(unsigned char key, int x, int y)
{
    switch (key) {
        //case '-':   distance_between_cubs_key = -0.05; break;
        //case '+':   distance_between_cubs_key = 0.05; break;

        case 'w':
        case 'W':
            deltaMoveFront =  1.0f; break; 
        case 's':
        case 'S':
            deltaMoveFront = -1.0f; break; 
        case 'a':
        case 'A':
            deltaMoveSide  =  1.0; break;
        case 'd':
        case 'D':
            deltaMoveSide  = -1.0; break;

        case 32 :   PlayerY_key    =  0.1; break;
        
        case 'c':
        case 'C':
            PlayerY_key    = -0.1; break;
        
        case 27:    exit(0); 

    }

}
void processNormalKeysUP(unsigned char key, int x, int y) {
    switch (key) {
        //case '+':
        //case '-':
        //    distance_between_cubs_key = 0.0; break;
        case 'w':
        case 'W':
        case 's':
        case 'S':
            deltaMoveFront = 0.0; break;
        case 'a':
        case 'A':
        case 'd':
        case 'D':
            deltaMoveSide = 0.0;  break;
        case 32 :

        case 'c':
        case 'C':
            PlayerY_key = 0; break;

    }
}
void mouseMove(int x, int y) 
{
    if ( mouseXOld != 0 or mouseYOld != 0) {
        angleX -= mouseXOld * 0.001f;
        angleY -= mouseYOld * 0.001f;

        if (angleY > 3.14 /2) angleY = 3.14/2 ;
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
    gluPerspective(View, ratio, 0.1f, 750.0f);
    glMatrixMode(GL_MODELVIEW);
}
void Draw() // Window redraw function
{
    if (deltaMoveFront)
    {
        PlayerX += deltaMoveFront * lx * 0.1f;
        PlayerZ += deltaMoveFront * lz * 0.1f;
    }
    if (deltaMoveSide)
    {
        PlayerX += deltaMoveSide *  lz * 0.1f;
        PlayerZ += deltaMoveSide * (-lx) * 0.1f;
    }
    if (distance_between_cubs_key) distange_between_cubs += distance_between_cubs_key;
    if (PlayerY_key) PlayerY += PlayerY_key;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    gluLookAt(PlayerX,              PlayerY,            PlayerZ,
              PlayerX + lx,         PlayerY + ly,       PlayerZ + lz, 
              0.0f,                 1.0f,               0.0f                    );

    for (int x = 0; x < quantity_cube_x; x++) // рисуем кубы сеткой
        for(int y = 0; y < quantity_cube_x; y++)
            for (int z = 0; z < quantity_cube_z; z++)
            {
                if (!cubes[x][y][z]) continue;
                glPushMatrix();
                glTranslatef(x * distange_between_cubs, y * distange_between_cubs, z * distange_between_cubs);
                draw_dirt(dirt, cube_size);
                glPopMatrix();
            }
    

    
            
    


    glTranslatef(PlayerX, PlayerY, PlayerZ);
    drawSkybox(skybox_texturies);
    glTranslatef(-PlayerX, -PlayerY, -PlayerZ);



    drawDebug();
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
    skybox(skybox_texturies, W, H);
    dirtTexturies(dirt, W, H);
    //====================================================================================
    glutPassiveMotionFunc(mouseMove);

    glutKeyboardFunc(processNormalKeysDOWN);// срабатывает когда клавиша нажалась
    glutKeyboardUpFunc(processNormalKeysUP);// срабатывает когда клавиша отжалась


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

