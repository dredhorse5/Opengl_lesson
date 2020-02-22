#include <locale.h>
#include <Windows.h>
#include <Math.h>
#include <stdio.h>
#include <glut.h>
float cube_size = 1.0; // размер кубов
int WindW = 1280, WindH = 720; // –азмер окна
int quantity_cube_x = 5; // колличество кубиков по оси x
int quantity_cube_y = 5; // колличество кубиков по оси z
float PlayerX = 0.0, PlayerY = 0.0, PlayerZ = 0.0; // координаты камеры
float lx = 0.0f, lz = -1.0f; // координаты вектора направлени€ движени€ камеры
float angle = 0.0; // угол поворота камеры
float View = 45; // угол обзора
float distance_between_cubs =  2;
float angleY = 0.0f;
float deltaAngle = 0.0f;
float deltaMove = 0.0;

void computePos(float deltaMove)
{
    PlayerX += deltaMove * lx * 0.1f;
    PlayerZ += deltaMove * lz * 0.1f;
}
void releaseKey(int key, int x, int y) {

    switch (key) {
    case GLUT_KEY_LEFT:
    case GLUT_KEY_RIGHT:
        deltaAngle = 0.0f;
        break;
    case GLUT_KEY_UP:
    case GLUT_KEY_DOWN:
        deltaMove = 0;
        break;
    }
}
void computeDir(float deltaAngle)
{
    angle += deltaAngle;
    lx = sin(angle);
    lz = -cos(angle);
}
void draw_cube()
{
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(cube_size, -cube_size, cube_size);
    glVertex3f(cube_size, cube_size, cube_size);
    glVertex3f(-cube_size, cube_size, cube_size);
    glVertex3f(-cube_size, -cube_size, cube_size);
    glEnd();

    // ‘иолетова€ сторона Ч ѕ–ј¬јя
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(cube_size, -cube_size, -cube_size);
    glVertex3f(cube_size, cube_size, -cube_size);
    glVertex3f(cube_size, cube_size, cube_size);
    glVertex3f(cube_size, -cube_size, cube_size);
    glEnd();

    // «елена€ сторона Ч Ћ≈¬јя
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-cube_size, -cube_size, cube_size);
    glVertex3f(-cube_size, cube_size, cube_size);
    glVertex3f(-cube_size, cube_size, -cube_size);
    glVertex3f(-cube_size, -cube_size, -cube_size);
    glEnd();

    // —ин€€ сторона Ч ¬≈–’Ќяя
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(cube_size, cube_size, cube_size);
    glVertex3f(cube_size, cube_size, -cube_size);
    glVertex3f(-cube_size, cube_size, -cube_size);
    glVertex3f(-cube_size, cube_size, cube_size);
    glEnd();

    //  расна€ сторона Ч Ќ»∆Ќяя
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(cube_size, -cube_size, -cube_size);
    glVertex3f(cube_size, -cube_size, cube_size);
    glVertex3f(-cube_size, -cube_size, cube_size);
    glVertex3f(-cube_size, -cube_size, -cube_size);
    glEnd();

    //  расна€ сторона Ч передн€€
    glBegin(GL_POLYGON);
    glColor3f(cube_size, 1.0, cube_size);
    glVertex3f(cube_size, -cube_size, -cube_size);
    glVertex3f(cube_size, cube_size, -cube_size);
    glVertex3f(-cube_size, cube_size, -cube_size);
    glVertex3f(-cube_size, -cube_size, -cube_size);
    glEnd();
}
void SpecialKey(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_LEFT:
            deltaAngle = -0.01f;
            break;
        case GLUT_KEY_RIGHT:
            deltaAngle = 0.01f;
            break;
        case GLUT_KEY_UP:
            deltaMove = 0.5f;
            break;
        case GLUT_KEY_DOWN:
            deltaMove = -0.5f;
            break;
    }
    //glutPostRedisplay();
}
void processNormalKeys(unsigned char key, int x, int y)
{   
    int fraction = 0.1f;
    if (key == '-')     distance_between_cubs -= 0.05;
    if (key == '+')     distance_between_cubs += 0.05;
    
    if (key == 'w')     PlayerY += 0.1;
    if (key == 's')     PlayerY -= 0.1;

    if (key == 'r') angleY += 0.1;
    if (key == 'f') angleY -= 0.1;
}
void Reshape(int w, int h) // Reshape function
{
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(View, ratio, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}
void Draw() // Window redraw function
{
    if (deltaMove)
        computePos(deltaMove);
    if (deltaAngle)
        computeDir(deltaAngle);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    gluLookAt(PlayerX,          PlayerY,        PlayerZ,
              PlayerX + lx,     PlayerY+angleY,        PlayerZ + lz,
              0.0f,             1.0f,           0.0f            );


    for (int i = -4; i < 4; i++) // рисуем кубы сеткой 8х8
    {
        for (int j = -4; j < 4; j++)
        {
            glPushMatrix();
            glTranslatef(i * distance_between_cubs, -2, j * distance_between_cubs);
            draw_cube();
            glPopMatrix();
        }
    }

    glPopMatrix();
    glFinish();
    glutSwapBuffers();
}
void Visibility(int state) // Visibility function
{
    if (state == GLUT_NOT_VISIBLE) printf("Window not visible!\n");
    if (state == GLUT_VISIBLE) printf("Window visible!\n");
}
void timf(int value) // Timer function
{
    glutPostRedisplay();  // Redraw windows
    glutTimerFunc(40, timf, 0); // Setup next timer
}



int main(int argc, char* argv[])
{
    

    glutInit(&argc, argv);
    glutInitWindowSize(WindW, WindH);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("cubes");
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(Draw);    // Set up redisplay function 
    glutReshapeFunc(Reshape); // Set up reshape function
    glutIdleFunc(Draw);
    glutSpecialFunc(SpecialKey);

    glutIgnoreKeyRepeat(1);
    glutSpecialUpFunc(releaseKey);

    glutTimerFunc(1, timf, 0); // Set up timer for 40ms, about 25 fps
    glutVisibilityFunc(Visibility); // Set up visibility funtion
    //glClearColor(0, 128, 255, 100); // цвет фона
    //glutSetKeyRepeat(GLUT_KEY_REPEAT_ON);
    glutKeyboardFunc(processNormalKeys);


    glutMainLoop();

    return 0;
}//*/




