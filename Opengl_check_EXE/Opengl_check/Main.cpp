//#include    <GL/glew.h>
//#include    <GL/gl.h>
//#include    <GL/glu.h>
//
//#ifdef  _WIN32
//#include    <GL/glew.h>
//#else
//#include    <GL/glxew.h>
//#endif
//
//#include    <glut.h>
//#include    <stdio.h>
//#include    <stdlib.h>
//#include    <string.h>
//#include    <ctype.h>
//#include    <math.h>
//
//float   eye[] = { 7, 5, 7, 1 };      // camera position
//float   light[] = { 5, 0, 4, 1 };      // light position
//float   rot[] = { 0, 0, 0 };
//float   angle = 0;
//int     mouseOldX = 0;
//int     mouseOldY = 0;
//
//GLhandleARB program = 0;         // program handles
//GLhandleARB vertexShader = 0;
//GLhandleARB fragmentShader = 0;
//
//bool    checkOpenGLError()
//{
//    bool    retCode = true;
//
//    for (; ; )
//    {
//        GLenum  glErr = glGetError();
//
//        if (glErr == GL_NO_ERROR)
//            return retCode;
//
//        printf("glError: %s\n", gluErrorString(glErr));
//
//        retCode = false;
//        glErr = glGetError();
//    }
//
//    return retCode;
//}
//
//void    printInfoLog(GLhandleARB object)
//{
//    int         logLength = 0;
//    int         charsWritten = 0;
//    GLcharARB* infoLog;
//
//    checkOpenGLError();                    // check for OpenGL errors
//
//    glGetObjectParameterivARB(object, GL_OBJECT_INFO_LOG_LENGTH_ARB, &logLength);
//
//    if (!checkOpenGLError())              // check for OpenGL errors
//        exit(1);
//
//    if (logLength > 0)
//    {
//        infoLog = (GLcharARB*)malloc(logLength);
//
//        if (infoLog == NULL)
//        {
//            printf("ERROR: Could not allocate InfoLog buffer\n");
//
//            exit(1);
//        }
//
//        glGetInfoLogARB(object, logLength, &charsWritten, infoLog);
//
//        printf("InfoLog:\n%s\n\n", infoLog);
//        free(infoLog);
//    }
//
//    if (!checkOpenGLError())             // check for OpenGL errors
//        exit(1);
//}
//
//bool    setUniformVector(GLhandleARB program, const char* name, const float* value)
//{
//    int loc = glGetUniformLocationARB(program, name);
//
//    if (loc < 0)
//        return false;
//
//    glUniform4fvARB(loc, 1, value);
//
//    return true;
//}
//
//void init()
//{
//    glClearColor(0.5, 0.5, 0.5, 1.0);
//    glEnable(GL_DEPTH_TEST);
//    glDepthFunc(GL_LEQUAL);
//
//    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
//    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
//}
//
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    // draw the light
//    glMatrixMode(GL_MODELVIEW);
//    glPushMatrix();
//
//    glTranslatef(light[0], light[1], light[2]);
//    glColor4f(1, 1, 1, 1);
//    glutSolidSphere(0.1f, 15, 15);
//    glPopMatrix();
//
//    glMatrixMode(GL_MODELVIEW);
//    glPushMatrix();
//
//    glRotatef(rot[0], 1, 0, 0);
//    glRotatef(rot[1], 0, 1, 0);
//    glRotatef(rot[2], 0, 0, 1);
//
//    glUseProgramObjectARB(program);
//
//    glutSolidTeapot(2.5);
//
//    glUseProgramObjectARB(0);
//
//    glPopMatrix();
//
//    glutSwapBuffers();
//}
//
//void reshape(int w, int h)
//{
//    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//    glMatrixMode(GL_PROJECTION);
//    // factor all camera ops into projection matrix
//    glLoadIdentity();
//    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 60.0);
//    gluLookAt(eye[0], eye[1], eye[2],  // eye
//        0, 0, 0,                    // center
//        0.0, 0.0, 1.0);            // up
//
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//}
//
//void motion(int x, int y)
//{
//    rot[1] -= ((mouseOldY - y) * 180.0f) / 200.0f;
//    rot[2] -= ((mouseOldX - x) * 180.0f) / 200.0f;
//    rot[0] = 0;
//
//    for (int i = 0; i < 3; i++)
//        if (rot[i] > 360)
//            rot[i] -= 360;
//        else
//            if (rot[i] < -360)
//                rot[i] += 360;
//
//    mouseOldX = x;
//    mouseOldY = y;
//
//    glutPostRedisplay();
//}
//
//void mouse(int button, int state, int x, int y)
//{
//    if (state == GLUT_DOWN)
//    {
//        mouseOldX = x;
//        mouseOldY = y;
//    }
//}
//
//void key(unsigned char key, int x, int y)
//{
//    if (key == 27 || key == 'q' || key == 'Q')    //  quit requested
//        exit(0);
//}
//
//void    animate()
//{
//    angle = 0.004f * glutGet(GLUT_ELAPSED_TIME);
//
//    light[0] = 2 * cos(angle);
//    light[1] = 3 * sin(1.4 * angle);
//    light[2] = 3 + 0.5 * sin(angle / 3);
//
//    glUseProgramObjectARB(program);
//    setUniformVector(program, "eyePos", eye);
//    setUniformVector(program, "lightPos", light);
//    glUseProgramObjectARB(0);
//
//    glutPostRedisplay();
//}
//
//int main(int argc, char* argv[])
//{
//    // initialize glut
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(500, 500);
//
//
//    // create window
//    glutCreateWindow("Example of GLSL Blinn shader");
//
//    // register handlers
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutKeyboardFunc(key);
//    glutMouseFunc(mouse);
//    glutMotionFunc(motion);
//    glutIdleFunc(animate);
//
//    init();
//    glewExperimental = true;
//    if (glewInit() != GLEW_OK)
//    {
//        printf("Error in glewInit\n");
//
//        return 1;
//    }
//
//    GLint       linked;
//
//
//    glutMainLoop();
//
//    return 0;
//}
//#pragma comment(lib, "glew32s.lib")
//#include <GL/glew.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
#include <Math.h>
#include <stdio.h>
#include <ctime>
#include <thread>
#include <iostream>
#include <fstream>
#include "SOIL.h"
//#include <GLFW/glfw3.h>
#include "glut.h"
int width = 1280; int height = 720;


//static const GLfloat globVertexBufferData[] = {
//  -1.0f, -1.0f,  0.0f,
//   1.0f, -1.0f,  0.0f,
//   0.0f,  1.0f,  0.0f,
//};

void Reshape(int w, int h) {
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    glMatrixMode(GL_MODELVIEW);
}
void Draw() {

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glClearColor(1.0, 1.0, 1.0, 0);
    //===============================начало основного цикла================================================================================
    /*GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(
        GL_ARRAY_BUFFER, sizeof(globVertexBufferData),
        globVertexBufferData, GL_STATIC_DRAW);*/
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 0, 0);
    glVertex3f(-0.5, -0.5,0);
    glVertex3f(0.1, -0.5, 0);
    glVertex3f(0.5, 0.5, 0);
    glVertex3f(-0.5, 0.1,0);
    glEnd();*/

    



    
    //=================================конец основного цикла===================================================================================
   
    glPopMatrix();
    glutPostRedisplay();
    glFinish();
}



int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(width, height);
    glutInitDisplayMode(GLUT_RGB /*| GL_DOUBLE*/);
    glutCreateWindow("cubes");
    glEnable(GL_DEPTH_TEST);
    //glutTimerFunc(1000 / FPS, timf, 0); // limit fps
    glutDisplayFunc(Draw);    // Main draw function
    glutReshapeFunc(Reshape); // change window
   /* if (glewInit() != GLEW_OK){
                printf("Error in glewInit\n");
                return 1;
            }*/
    glutMainLoop();
    return 1;
}