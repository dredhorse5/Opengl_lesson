#include    <glew.h>
#include    <GL/gl.h>
#include    <GL/glu.h>

#ifdef  _WIN32
#include    <GL/wglew.h>
#else
#include    <GL/glxew.h>
#endif

#include    <glut.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <ctype.h>
#include    <math.h>

// cubes
float cube_size = 2.0f; // size of cubes
const int width = 1280, height = 720; // size of window
int quantity_cube_x = 256; // quanity cubes of x
int quantity_cube_y = 50; // quanity cubes of y
int quantity_cube_z = 256; // quanity cubes of z
int cubes[257][50][257];
short int IDblocks = 1;
short int blocks = 7;

// камера
float lx = 1.0f, lz = 0.0f, ly = 0.0f; // координаты вектора направления движения камеры
float angleX = 0.0f, angleY = 5.0f; // угол поворота камеры
int mouseXOld = 1, mouseYOld = 1;
bool mLeft = 0, mRight = 0; // mouse bottons
float FPS = 60;
// разное
float KeyFront = 0, KeySide = 0; // ключ к изменению перемещения вперед/назад
bool Draw_debug_Menu_key = true;
int tick = 0;

void Reshape(int w, int h) {
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    //gluPerspective(60, ratio, 0.1f, 360.0f);
    glMatrixMode(GL_MODELVIEW);
}
void timf(int value) {
    glutPostRedisplay();  // Redraw windows
    glutTimerFunc(1000 / FPS, timf, 0); // Setup next timer
}


void Draw() {

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 0, 0, 0);
    glPushMatrix();
    //=================================конец основного цикла===================================================================================
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
    //=================================конец основного цикла===================================================================================
    glPopMatrix();
    glutPostRedisplay();
    glFinish();
}



int main(int argc, char* argv[])
{
    //===========================INITIALIZATION===========================================
    glutInit(&argc, argv);
    glutInitWindowSize(width, height);
    glutInitDisplayMode(GLUT_RGB /*| GL_DOUBLE*/);
    glutCreateWindow("cubes");
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    //glutTimerFunc(1000 / FPS, timf, 0); // limit fps
    glEnable(GL_TEXTURE_2D);
    glutDisplayFunc(Draw);    // Main draw function
    glutReshapeFunc(Reshape); // change window
    //glutSetCursor(GLUT_CURSOR_NONE);
    //====================================================================================
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        printf("Error in glewInit\n");

        return 1;
    }
    static const GLfloat globVertexBufferData[] = {
  -1.0f, -1.0f,  0.0f,
   1.0f, -1.0f,  0.0f,
   0.0f,  1.0f,  0.0f,
    };

    // ...

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(
        GL_ARRAY_BUFFER, sizeof(globVertexBufferData),
        globVertexBufferData, GL_STATIC_DRAW
        );
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    




    glutMainLoop();
}//*/
