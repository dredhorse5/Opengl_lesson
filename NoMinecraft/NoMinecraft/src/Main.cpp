#include <locale.h>
#include <Windows.h>
#include <Math.h>
#include <stdio.h>
#include <string>
#include <glut.h>
float cube_size = 1.0; // ������ �����
const int WindW = 1280, WindH = 720; // ������ ����
int quantity_cube_x = 40; // ����������� ������� �� ��� x
int quantity_cube_z = 40; // ����������� ������� �� ��� z
float PlayerX = 0.0f, PlayerY = 0.0f, PlayerZ = 0.0f; // ���������� ������
float PlayerY_key = 0.0; // ���� � ��������� ���������� Y ������
float lx = 0.0f, lz = -1.0f, ly = 0.0f; // ���������� ������� ����������� �������� ������
float angleX = 0.0f, angleY = 5.0f; // ���� �������� ������
float View = 45; // ���� ������
double FPS = 60; // FPS 60
float distance_between_cubs_key =  0; // ���� � ��������� �������� ���������� ����� ������
float distange_between_cubs = 3; //��������� ��������� ����� ������;
float deltaangleX = 0.0f;    // ���� � ��������� ����
float deltaMoveFront = 0.0; // ���� � ��������� ���������� ������/�����
float deltaMoveSide = 0.0; // ���� � ��������� ����������� ����
float deltaMove = 0;
int mouseXOld = 1, mouseYOld = 1;
bool huina = false;


void drawText(float x, float y, float z, float r, float g, float b, std::string string) {
    glColor3f(r, g, b);
    glRasterPos3f(x, y, z);
    for (int i = 0; i < string.length(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
    }
}
//void SpecialKeyUP(int key, int x, int y) {
//void SpecialKeyDOWN(int key, int x, int y)
void processNormalKeysDOWN(unsigned char key, int x, int y)
{
    int fraction = 0.1f;
    switch (key) {
        case '-':   distance_between_cubs_key = -0.05; break;
        case '+':   distance_between_cubs_key = 0.05; break;

        case 'w':   deltaMoveFront =  0.5f; break; 
        case 's':   deltaMoveFront = -0.5f; break; 
        case 'a':   deltaMoveSide  =  0.5; break;
        case 'd':   deltaMoveSide  = -0.5; break;

    }

}
void processNormalKeysUP(unsigned char key, int x, int y) {
    switch (key) {
        case '+':
        case '-':
            distance_between_cubs_key = 0.0; break;
        case 'w':
        case 's':
            deltaMoveFront = 0.0; break;
        case 'a':
        case 'd':
            deltaMoveSide = 0.0;  break;

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
        
        mouseXOld = (WindW / 2) - x;
        mouseYOld = (WindH / 2) - y;
        glutWarpPointer((WindW / 2), (WindH / 2));
    }
    //glutPostRedisplay();

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

    // ���������� ������� � ������
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(cube_size, -cube_size, -cube_size);
    glVertex3f(cube_size, cube_size, -cube_size);
    glVertex3f(cube_size, cube_size, cube_size);
    glVertex3f(cube_size, -cube_size, cube_size);
    glEnd();

    // ������� ������� � �����
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-cube_size, -cube_size, cube_size);
    glVertex3f(-cube_size, cube_size, cube_size);
    glVertex3f(-cube_size, cube_size, -cube_size);
    glVertex3f(-cube_size, -cube_size, -cube_size);
    glEnd();

    // ����� ������� � �������
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(cube_size, cube_size, cube_size);
    glVertex3f(cube_size, cube_size, -cube_size);
    glVertex3f(-cube_size, cube_size, -cube_size);
    glVertex3f(-cube_size, cube_size, cube_size);
    glEnd();

    // ������� ������� � ������
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(cube_size, -cube_size, -cube_size);
    glVertex3f(cube_size, -cube_size, cube_size);
    glVertex3f(-cube_size, -cube_size, cube_size);
    glVertex3f(-cube_size, -cube_size, -cube_size);
    glEnd();

    // ������� ������� � ��������
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.1, 0.9);
    glVertex3f(cube_size, -cube_size, -cube_size);
    glVertex3f(cube_size, cube_size, -cube_size);
    glVertex3f(-cube_size, cube_size, -cube_size);
    glVertex3f(-cube_size, -cube_size, -cube_size);
    glEnd();
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
void drawDebug() {

    drawText(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, std::to_string(deltaangleX));
    
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

    gluLookAt(PlayerX,              PlayerY,        PlayerZ,
              PlayerX + lx,         PlayerY + ly,        PlayerZ + lz, 
              0.0f,                 1.0f,           0.0f                    );

    for (int i = -quantity_cube_x/2; i < quantity_cube_x/2; i++) // ������ ���� ������ 8�8
    {
        for (int j = -quantity_cube_z/2; j < quantity_cube_z/2; j++)
        {
            glPushMatrix();
            glTranslatef(i * distange_between_cubs, -2, j * distange_between_cubs);
            draw_cube();
            glPopMatrix();
        }
    }

    drawDebug();

    glPopMatrix();
    glFinish();
    glutSwapBuffers();
}
void timf(int value) // Timer function
{
    glutPostRedisplay();  // Redraw windows
    glutTimerFunc(1000/FPS, timf, 0); // Setup next timer
}



int main(int argc, char* argv[])
{
    

    glutInit(&argc, argv);
    glutInitWindowSize(WindW, WindH);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("cubes");
    glEnable(GL_DEPTH_TEST /*and GL_CULL_FACE*/);
    glutTimerFunc(1000 / FPS, timf, 0); // ����������� fps

    glutDisplayFunc(Draw);    // �������� ������� ���������
    glutReshapeFunc(Reshape); // ������� ��������� ����
    //glutMouseFunc(mouseButton);
    glutPassiveMotionFunc(mouseMove);
    glutSetCursor(GLUT_CURSOR_NONE);
    // �������� �� ���������( �� ��������� )- ����������� ������ �������, ������� ������������� ��������� ��������
    // � �������� �� ������ �������, ������� ������� �����������. ��� ���������� ������� ����������� ������ �������
    // � ������������� �������� �������� 0, ��� �������� � ����������� ��������.
    // ��� ������� ��� ����, ����� ������ ������������ � ���������� ���������, � �� �������
    glutKeyboardFunc(processNormalKeysDOWN);// ����������� ����� ������� ��������
    glutKeyboardUpFunc(processNormalKeysUP);// ����������� ����� ������� ��������
    
    //glutSpecialFunc(SpecialKeyDOWN);
    //glutSpecialUpFunc(SpecialKeyUP);
    
    
    
                                      
    //glClearColor(0, 128, 255, 100); // ���� ����
    //glutSetKeyRepeat(GLUT_KEY_REPEAT_ON); // �� �����, ������ �� ������
    //glutIgnoreKeyRepeat(0); �� �����, ��� ������� ����� ����������� �������� ��� ���� 1 �� ������� ������ :/ 
    //glutIdleFunc(Draw); // �����-�� �����, ������� ���������� ��������� ������. ��� ����� ������� ����������� fps
    


    glutMainLoop();

    return 0;
}//*/




