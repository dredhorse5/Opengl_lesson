#include <locale.h>
#include <Windows.h>
#include <Math.h>
#include <stdio.h>
#include <string>
#include <glut.h>
#include <SOIL.h>
#pragma comment(lib, "SOIL.lib")
#define GL_CLAMP_TO_EDGE 0x812F
float cube_size = 1.0; // ������ �����
const int width = 1920, height = 1080; // ������ ����
int W = width, H = height;
int quantity_cube_x = 40; // ����������� ������� �� ��� x
int quantity_cube_z = 40; // ����������� ������� �� ��� z
float PlayerX = 0.0f, PlayerY = 4.0f, PlayerZ = 0.0f; // ���������� ������
float PlayerY_key = 0.0; // ���� � ��������� ���������� Y ������
float lx = 1.0f, lz = 1.0f, ly = 1.0f; // ���������� ������� ����������� �������� ������
float angleX = 0.0f, angleY = 5.0f; // ���� �������� ������
float View = 75; // ���� ������
double FPS = 60; // FPS 60
float distance_between_cubs_key =  0; // ���� � ��������� �������� ���������� ����� ������
float distange_between_cubs = 2; //��������� ��������� ����� ������;
float deltaMoveFront = 0.0; // ���� � ��������� ���������� ������/�����
float deltaMoveSide = 0.0; // ���� � ��������� ����������� ����
float deltaMove = 0;
int mouseXOld = 1, mouseYOld = 1;
GLuint  dirt;
GLuint skybox_texturies[6];

void skybox()
{
    //back
    unsigned char* back = SOIL_load_image("textures/skybox2/skybox_back.bmp", &W, &H, 0, SOIL_LOAD_RGB); // ��������� �������� � soil
    glGenTextures(1, &skybox_texturies[0]); 
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[0]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, back); 
    SOIL_free_image_data(back); 
    glBindTexture(GL_TEXTURE_2D, 0);
    //===========================================================================================================================
    //bottom
    unsigned char* bottom = SOIL_load_image("textures/skybox2/skybox_bottom.bmp", &W, &H, 0, SOIL_LOAD_RGB); // ��������� �������� � soil
    glGenTextures(1, &skybox_texturies[1]);
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[1]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, bottom);
    SOIL_free_image_data(bottom);
    glBindTexture(GL_TEXTURE_2D, 0);
    //===========================================================================================================================
    //front
    unsigned char* front = SOIL_load_image("textures/skybox2/skybox_front.bmp", &W, &H, 0, SOIL_LOAD_RGB); // ��������� �������� � soil
    glGenTextures(1, &skybox_texturies[2]);
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[2]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, front);
    SOIL_free_image_data(front);
    glBindTexture(GL_TEXTURE_2D, 0);
    //===========================================================================================================================
    //left
    unsigned char* left = SOIL_load_image("textures/skybox2/skybox_left.bmp", &W, &H, 0, SOIL_LOAD_RGB); // ��������� �������� � soil
    glGenTextures(1, &skybox_texturies[3]);
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[3]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, left);
    SOIL_free_image_data(left);
    glBindTexture(GL_TEXTURE_2D, 0);
    //===========================================================================================================================
    //right
    unsigned char* right = SOIL_load_image("textures/skybox2/skybox_right.bmp", &W, &H, 0, SOIL_LOAD_RGB); // ��������� �������� � soil
    glGenTextures(1, &skybox_texturies[4]);
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[4]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, right);
    SOIL_free_image_data(right);
    glBindTexture(GL_TEXTURE_2D, 0);
    //===========================================================================================================================
    //top
    unsigned char* top = SOIL_load_image("textures/skybox2/skybox_top.bmp", &W, &H, 0, SOIL_LOAD_RGB); // ��������� �������� � soil
    glGenTextures(1, &skybox_texturies[5]);
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[5]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, top);
    SOIL_free_image_data(top);
    glBindTexture(GL_TEXTURE_2D, 0);
    //===========================================================================================================================

}
void drawSkybox()
{
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[0]);
    //������
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(-400, -400, -400);
    glTexCoord2d(0, 1); glVertex3f(400, -400, -400);
    glTexCoord2d(0, 0); glVertex3f(400, 400, -400);
    glTexCoord2d(1, 0); glVertex3f(-400, 400, -400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[1]);
    //������
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 0); glVertex3f(-400, -400, 400);
    glTexCoord2d(1, 0); glVertex3f(400, -400, 400);
    glTexCoord2d(1, 1); glVertex3f(400, -400, -400);
    glTexCoord2d(0, 1); glVertex3f(-400, -400, -400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[2]);
    //��������
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(400, 400, 400);
    glTexCoord2d(1, 1); glVertex3f(400,-400, 400);
    glTexCoord2d(0, 1); glVertex3f(-400, -400, 400);
    glTexCoord2d(0, 0); glVertex3f(-400, 400, 400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[3]);
    //�����
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 1); glVertex3f(-400, -400, 400);
    glTexCoord2d(0, 1); glVertex3f(-400, -400, -400);
    glTexCoord2d(0, 0); glVertex3f(-400, 400, -400);
    glTexCoord2d(1, 0); glVertex3f(-400, 400, 400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[4]);
    //������
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 1); glVertex3f(400, -400, 400);
    glTexCoord2d(1, 1); glVertex3f(400, -400, -400);
    glTexCoord2d(1, 0); glVertex3f(400, 400, -400);
    glTexCoord2d(0, 0); glVertex3f(400, 400, 400);
    glEnd();
    //==================================================================
    glBindTexture(GL_TEXTURE_2D, skybox_texturies[5]);
    //�������
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 0); glVertex3f(-400, 400, -400);
    glTexCoord2d(1, 0); glVertex3f(400, 400, -400);
    glTexCoord2d(1, 1); glVertex3f(400, 400, 400);
    glTexCoord2d(0, 1); glVertex3f(-400, 400, 400);
    glEnd();

}
void dirtTexturies()
{
    unsigned char* dirt_image = SOIL_load_image("textures/dirt.jpg", &W, &H, 0, SOIL_LOAD_RGB); // ��������� �������� � soil
    glGenTextures(1, &dirt); // �������, ��� �������� �������� � ���������� Dirt, ����� ������ �������� � ��� �������� soil
    glBindTexture(GL_TEXTURE_2D, dirt); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, W, H, 0, GL_RGB, GL_UNSIGNED_BYTE, dirt_image); // ��������� �������� soil � ��������� dirt
    SOIL_free_image_data(dirt_image); // ����������� �������� �� soil
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

}
void drawText(float x, float y, float z, float r, float g, float b, std::string string) {
    glColor3f(r, g, b);
    glRasterPos3f(x, y+2, z);
    for (int i = 0; i < string.length(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
    }
}
void drawDebug() {

    drawText(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, std::to_string(PlayerY));

}
//void SpecialKeyUP(int key, int x, int y)
//void SpecialKeyDOWN(int key, int x, int y)
void processNormalKeysDOWN(unsigned char key, int x, int y)
{
    switch (key) {
        //case '-':   distance_between_cubs_key = -0.05; break;
        //case '+':   distance_between_cubs_key = 0.05; break;

        case 'w':   deltaMoveFront =  1.0f; break; 
        case 's':   deltaMoveFront = -1.0f; break; 
        case 'a':   deltaMoveSide  =  1.0; break;
        case 'd':   deltaMoveSide  = -1.0; break;
        case 32 :   PlayerY_key    =  0.1; break;
        case 'c':   PlayerY_key    = -0.1; break;
        
        case 27:    exit(0); 

    }

}
void processNormalKeysUP(unsigned char key, int x, int y) {
    switch (key) {
        //case '+':
        //case '-':
        //    distance_between_cubs_key = 0.0; break;
        case 'w':
        case 's':
            deltaMoveFront = 0.0; break;
        case 'a':
        case 'd':
            deltaMoveSide = 0.0;  break;
        case 32 :
        case 'c':   
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
void draw_dirt()
{
    glBindTexture(GL_TEXTURE_2D, dirt);
    //������
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(cube_size, -cube_size, cube_size);
    glTexCoord2d(1, 1); glVertex3f(cube_size, cube_size, cube_size);
    glTexCoord2d(0, 1); glVertex3f(-cube_size, cube_size, cube_size);
    glTexCoord2d(0, 0); glVertex3f(-cube_size, -cube_size, cube_size);
    glEnd();

    //������
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(cube_size, -cube_size, -cube_size);
    glTexCoord2d(1, 1); glVertex3f(cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 1); glVertex3f(cube_size, cube_size, cube_size);
    glTexCoord2d(0, 0); glVertex3f(cube_size, -cube_size, cube_size);
    glEnd();

    //�����
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(-cube_size, -cube_size, cube_size);
    glTexCoord2d(1, 1); glVertex3f(-cube_size, cube_size, cube_size);
    glTexCoord2d(0, 1); glVertex3f(-cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
    glEnd();

    // �������
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(cube_size, cube_size, cube_size);
    glTexCoord2d(1, 1); glVertex3f(cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 1); glVertex3f(-cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 0); glVertex3f(-cube_size, cube_size, cube_size);
    glEnd();

    //������
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(cube_size, -cube_size, -cube_size);
    glTexCoord2d(1, 1); glVertex3f(cube_size, -cube_size, cube_size);
    glTexCoord2d(0, 1); glVertex3f(-cube_size, -cube_size, cube_size);
    glTexCoord2d(0, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
    glEnd();

    //��������
    glBegin(GL_POLYGON);
    glTexCoord2d(1, 0); glVertex3f(cube_size, -cube_size, -cube_size);
    glTexCoord2d(1, 1); glVertex3f(cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 1); glVertex3f(-cube_size, cube_size, -cube_size);
    glTexCoord2d(0, 0); glVertex3f(-cube_size, -cube_size, -cube_size);
    glEnd();
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

    for (int i = -quantity_cube_x/2; i < quantity_cube_x/2; i++) // ������ ���� ������
    {
        for (int j = -quantity_cube_z/2; j < quantity_cube_z/2; j++)
        {
            glPushMatrix();
            glTranslatef(i * distange_between_cubs, 0, j * distange_between_cubs);
            draw_dirt();
            glPopMatrix();
        }
    }

    glTranslatef(PlayerX, PlayerY, PlayerZ);
    drawSkybox();
    glTranslatef(-PlayerX, -PlayerY, -PlayerZ);

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
    glutInitWindowSize(width, height);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("cubes");
    glEnable(GL_DEPTH_TEST /*and GL_CULL_FACE*/);
    glutTimerFunc(1000 / FPS, timf, 0); // ����������� fps
    glEnable(GL_TEXTURE_2D);
    glutDisplayFunc(Draw);    // �������� ������� ���������
    glutReshapeFunc(Reshape); // ������� ��������� ����
    glutSetCursor(GLUT_CURSOR_NONE);
    //====================================================================================
    skybox();
    dirtTexturies();

    glutPassiveMotionFunc(mouseMove);

    glutKeyboardFunc(processNormalKeysDOWN);// ����������� ����� ������� ��������
    glutKeyboardUpFunc(processNormalKeysUP);// ����������� ����� ������� ��������


    //glutMouseFunc(mouseButton);
    //glutSpecialFunc(SpecialKeyDOWN);
    //glutSpecialUpFunc(SpecialKeyUP);      
    //glClearColor(0, 128, 255, 100); // ���� ����
    //glutSetKeyRepeat(GLUT_KEY_REPEAT_ON); // �� �����, ������ �� ������
    //glutIgnoreKeyRepeat(0); �� �����, ��� ������� ����� ����������� �������� ��� ���� 1 �� ������� ������ :/ 
    //glutIdleFunc(Draw); // �����-�� �����, ������� ���������� ��������� ������. ��� ����� ������� ����������� fps
    


    glutMainLoop();

    return 0;
}//*/




