#include <locale.h>
#include <Windows.h>
#include <Math.h>
#include <stdio.h>
#include <glut.h>
float cube_size = 1.0; // ������ �����
int WindW = 1280, WindH = 720; // ������ ����
int quantity_cube_x = 5; // ����������� ������� �� ��� x
int quantity_cube_y = 5; // ����������� ������� �� ��� z
float PlayerX = 0.0, PlayerY = 0.0, PlayerZ = 0.0; // ���������� ������
float PlayerY_key = 0.0; // ���� � ��������� ���������� Y ������
float lx = 0.0f, lz = -1.0f; // ���������� ������� ����������� �������� ������
float angle = 0.0; // ���� �������� ������
float View = 45; // ���� ������
double FPS = 60; // FPS 60
float distance_between_cubs_key =  0; // ���� � ��������� �������� ���������� ����� ������
float distange_between_cubs = 8; //��������� ��������� ����� ������
float angleY = 0.0f;
float deltaAngle = 0.0f;
float deltaMove = 0.0;



void SpecialKeyUP(int key, int x, int y) {

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
void SpecialKeyDOWN(int key, int x, int y)
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
void processNormalKeysDOWN(unsigned char key, int x, int y)
{
    int fraction = 0.1f;
    switch (key) {
        case '-':     distance_between_cubs_key = -0.05; break;
        case '+':     distance_between_cubs_key = 0.05; break;
        case 'w':     PlayerY_key = 0.1; break;
        case 's':     PlayerY_key = -0.1; break;
    }

}
void processNormalKeysUP(unsigned char key, int x, int y) {
    switch (key) {
        case '+':
        case '-':
            distance_between_cubs_key = 0.0; break;
        case 'w':
        case 's':
            PlayerY_key = 0.0; break;

    }
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
    glColor3f(cube_size, 1.0, cube_size);
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
void Draw() // Window redraw function
{
    if (deltaMove)
    {
        PlayerX += deltaMove * lx * 0.1f;
        PlayerZ += deltaMove * lz * 0.1f;
    }
    if (deltaAngle) 
    {
        angle += deltaAngle;
        lx = sin(angle);
        lz = -cos(angle);
    }
    if (distance_between_cubs_key) distange_between_cubs += distance_between_cubs_key;
    if (PlayerY_key) PlayerY += PlayerY_key;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    gluLookAt(PlayerX,          PlayerY,        PlayerZ,
              PlayerX + lx,     PlayerY+angleY,        PlayerZ + lz, 
              0.0f,             1.0f,           0.0f            );


    for (int i = -4; i < 4; i++) // ������ ���� ������ 8�8
    {
        for (int j = -4; j < 4; j++)
        {
            glPushMatrix();
            glTranslatef(i * distange_between_cubs, -2, j * distange_between_cubs);
            draw_cube();
            glPopMatrix();
        }
    }

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
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(Draw);    // Set up redisplay function 
    glutReshapeFunc(Reshape); // Set up reshape function
    
    glutKeyboardFunc(processNormalKeysDOWN);
    glutKeyboardUpFunc(processNormalKeysUP);
    // �������� �� ���������( �� ��������� )- ����������� ������ �������, ������� ������������� ��������� ��������
    // � �������� �� ������ �������, ������� ������� �����������. ��� ���������� ������� ����������� ������ �������
    // � ������������� �������� �������� 0, ��� �������� � ����������� ��������.
    // ��� ������� ��� ����, ����� ������ ������������ � ���������� ���������, � �� �������
    glutSpecialFunc(SpecialKeyDOWN);// ����������� ����� ������� ��������
    glutSpecialUpFunc(SpecialKeyUP); // ����������� ����� ������� ��������
    
    glutTimerFunc(1000/FPS, timf, 0); // ����������� fps
    
                                      
    //glClearColor(0, 128, 255, 100); // ���� ����
    //glutSetKeyRepeat(GLUT_KEY_REPEAT_ON); // �� �����, ������ �� ������
    //glutIgnoreKeyRepeat(0); �� �����, ��� ������� ����� ����������� �������� ��� ���� 1 �� ������� ������ :/ 
    //glutIdleFunc(Draw); // �����-�� �����, ������� ���������� ��������� ������. ��� ����� ������� ����������� fps
    


    glutMainLoop();

    return 0;
}//*/




