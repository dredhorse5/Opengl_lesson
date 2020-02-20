
#include <Math.h>
#include <stdio.h>
#include <glut.h>

int WindW, WindH;
int i;
int alpha;
int rotate_y = 0;
int rotate_x = 0;
float cube_size = 0.5;
float translate_z = 0;
float translate_x = 0;
int quantity_cube_x = 5;
int quantity_cube_y = 5;

void processNormalKeys(unsigned char key, int x, int y)
{
    if (key == 'w') translate_z += 0.05;
    if (key == 's') translate_z -= 0.05;

    if (key == 'a') translate_x += 0.05;
    if (key == 'd') translate_x -= 0.05;


}


void specialKeys(int key, int x, int y) {

    //  Right arrow - increase rotation by 5 degree
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;

    //  Left arrow - decrease rotation by 5 degree
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;

    if (key == GLUT_KEY_UP)
        rotate_x -= 5;

    else if (key == GLUT_KEY_DOWN)
        rotate_x += 5;

    if (rotate_x > 90) rotate_x = 90;
    if (rotate_x < -90) rotate_x = -90;


    //  Request display update
    glutPostRedisplay();

}

void Reshape(int width, int height) // Reshape function
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    WindW = width;
    WindH = height;
}

void Draw(void) // Window redraw function
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    //glRotatef(alpha, 1.1f, 0.9f, 1.0f);
    //alpha += 4;
    //if (alpha > 359) alpha = 0

    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glTranslatef(translate_x, 0.0, translate_z);

    // Ѕела€ сторона Ч «јƒЌяя
    for (float i = 0; i < cube_size * quantity_cube_x; i += cube_size * 2)
    {
        for (float j = 0; j < cube_size * quantity_cube_y; j += cube_size * 2)
        {

            glTranslatef(i, 0.0, j);

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
            glTranslatef(-i, 0.0, -j);

        }
    }

    glPopMatrix();

    glFlush();
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
    WindW = 1000;
    WindH = 1000;
    alpha = 0;

    glutInit(&argc, argv);
    glutInitWindowSize(WindW, WindH);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("cubes");
    glEnable(GL_DEPTH_TEST);

    glutReshapeFunc(Reshape); // Set up reshape function
    glutDisplayFunc(Draw);    // Set up redisplay function 
    glutTimerFunc(40, timf, 0); // Set up timer for 40ms, about 25 fps
    glutVisibilityFunc(Visibility); // Set up visibility funtion
    glClearColor(0, 128, 255, 100);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(processNormalKeys);


    glutMainLoop();

    return 0;
}