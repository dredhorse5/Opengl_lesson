

#include <Math.h>
#include <stdio.h>
#include <glut.h>

float View = 45; // угол обзора
int WindW = 1280, WindH = 720; // –азмер окна
int i;
int rotate_y = 0;
int rotate_x = 0;
float cube_size = 1.0;
int quantity_cube_x = 5;
int quantity_cube_y = 5;
float distance_between_cubs = cube_size*2;
float PlayerX = 0.0, PlayerY = 1.0, PlayerZ = 0.0; // координаты камеры
float lx = 0.0f, lz = -1.0f; // координаты вектора направлени€ движени€ камеры
float angle = 0.0; // угол поворота камеры




void specialKeys(int key, int x, int y) 
{   
    float fraction = 0.1f;
    if (key == GLUT_KEY_RIGHT)   rotate_y += 5;
    else if (key == GLUT_KEY_LEFT)  rotate_y -= 5;


    if (key == GLUT_KEY_UP) rotate_x -= 5;
    else if (key == GLUT_KEY_DOWN)  rotate_x += 5;

    if (key == GLUT_ACTIVE_SHIFT) PlayerY += 0.5;
    if (key == GLUT_ACTIVE_CTRL) PlayerY -= 0.5;

    if (rotate_x > 90) rotate_x = 90;
    if (rotate_x < -90) rotate_x = -90;

    
    /*switch (key) {
        case GLUT_KEY_LEFT:
            angle -= 0.01f;
            lx = sin(angle);
            lz = -cos(angle);
            break;

        case GLUT_KEY_RIGHT:
            angle += 0.01f;
            lx = sin(angle);
            lz = -cos(angle);
           break;

       case GLUT_KEY_UP:
           x += lx * fraction;
           z += lz * fraction;
          break;

       case GLUT_KEY_DOWN:
           x -= lx * fraction;
           z -= lz * fraction;
           break;
        case 
    }*/

    //  Request display update
    glutPostRedisplay();
}

void Reshape(int w, int h) // Reshape function
{
    float ratio = w * 1.0 / h;
    // используем матрицу проекции
    glMatrixMode(GL_PROJECTION);
    // обнул€ем матрицу
    glLoadIdentity();
    // установить параметры вьюпорта
    glViewport(0, 0, w, h);
    // установить корректную перспективу
    gluPerspective(View, ratio, 0.1f, 100.0f);
    // вернутьс€ к матрице проекции
    glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y)
{
    if (key == 'w') PlayerZ += 0.5;
    if (key == 's') PlayerZ -= 0.5;

    if (key == 'a') PlayerX += 0.5;
    if (key == 'd') PlayerX -= 0.5;

    if (key == '-') 
    {
        distance_between_cubs += 0.05;
    }
    if (key == '+')
    {
        distance_between_cubs -= 0.05;
    }
    if (View > 90) View = 90;
    if (View < 15) View = 15;
}

void Draw_cube() {
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

void Draw(void) // Window redraw function
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    //glRotatef(rotate_x, 1.0, 0.0, 0.0); // поворот системы кординат по x
    //glRotatef(rotate_y, 0.0, 1.0, 0.0);// поворот системы кординат по y
    //glTranslatef(PlayerX, 0.0, PlayerZ);

    gluLookAt(PlayerX,          PlayerY,    PlayerZ,
              PlayerX + lx,     0.0f,       PlayerZ + lz,
              0.0f,             1.0f,       0.0f            );


    for (int i = -4; i < 4; i++)// рисуем кубы сеткой 8х8
        for (int j = -4; j < 4; j++)
        {
            glPushMatrix();
            glTranslatef(i * distance_between_cubs, -0.2, j * distance_between_cubs);
            Draw_cube();
            glPopMatrix();
        }
    
   
    /*for (float i = 0; i < cube_size * quantity_cube_x; i += cube_size * 2)
    {
        for (float j = 0; j < cube_size * quantity_cube_y; j += cube_size * 2)
        {
            glPushMatrix();
            glTranslatef(i, 5, j);
            Draw_cube();
            glTranslatef(-i, -5, -j);

            gluLookAt(0.0f, 0.0f, 10.0f,
                0.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f);

            glPopMatrix();
        }
    }*/


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

    glutReshapeFunc(Reshape); // Set up reshape function
    glutDisplayFunc(Draw);    // Set up redisplay function 
    glutTimerFunc(40, timf, 0); // Set up timer for 40ms, about 25 fps
    glutVisibilityFunc(Visibility); // Set up visibility funtion
    //glClearColor(0, 128, 255, 100);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(processNormalKeys);


    glutMainLoop();

    return 0;
}//*/