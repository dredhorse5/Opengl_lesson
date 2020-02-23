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
float PlayerY_key = 0.0; // ключ к изменению координаты Y игрока
float lx = 0.0f, lz = -1.0f; // координаты вектора направлени€ движени€ камеры
float angle = 0.0; // угол поворота камеры
float View = 45; // угол обзора
double FPS = 60; // FPS 60
float distance_between_cubs_key =  0; // ключ к изменению скорости рассто€ни€ между кубами
float distange_between_cubs = 8; //насто€щее расто€ние между кубами
float angleY = 0.0f;
float deltaAngle = 0.0f;
float deltaMoveFront = 0.0; // ключ к изменению пермещени€ вперед/назад
float deltaMoveSide = 0.0; // ключ к изменению перемещени€ вбок



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
        case 'a':   deltaMoveSide  = 0.5; break;
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
            deltaMoveSide = 0.0; break;

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
    if (deltaMoveFront)
    {
        PlayerX += deltaMoveFront * lx * 0.1f;
        PlayerZ += deltaMoveFront * lz * 0.1f;
    }
    if (deltaMoveSide)
    {
        PlayerX += deltaMoveSide * lz * 0.1f;
        PlayerZ += deltaMoveSide * lx * 0.1f;
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

    gluLookAt(PlayerX,                  PlayerY,                    PlayerZ,
              float(PlayerX + lx),      float(PlayerY+angleY),      float(PlayerZ + lz), 
              0.0f,                     1.0f,                       0.0f                    );


    for (int i = -4; i < 4; i++) // рисуем кубы сеткой 8х8
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
    glutTimerFunc(1000 / FPS, timf, 0); // ограничение fps

    glutDisplayFunc(Draw);    // основна€ функци€ рисовани€
    glutReshapeFunc(Reshape); // функци€ изменени€ окна
    
    // нажимаем на стрелочки( не отспуска€ )- срабатывает перва€ функци€, котора€ устанавливает ненулевую скорость
    // и передает ее другой функции, котора€ считает перемещение. при отпускании клавиши срабатывает втора€ функци€
    // и устанваливает значение скорости 0, что приводит к прекращению движени€.
    // это сделано дл€ того, чтобы камера перемещалась с посто€нной скоростью, а не рывками
    glutKeyboardFunc(processNormalKeysDOWN);// срабатывает когда клавиша нажалась
    glutKeyboardUpFunc(processNormalKeysUP);// срабатывает когда клавиша отжалась
    
    //glutSpecialFunc(SpecialKeyDOWN);
    //glutSpecialUpFunc(SpecialKeyUP);
    
    
    
                                      
    //glClearColor(0, 128, 255, 100); // цвет фона
    //glutSetKeyRepeat(GLUT_KEY_REPEAT_ON); // хз зачем, ничего не мен€ет
    //glutIgnoreKeyRepeat(0); хз зачем, при быстрой смене направлени€ движени€ при кооф 1 не двигает камеру :/ 
    //glutIdleFunc(Draw); // кака€-то херн€, котора€ увердохера загружает видюху. как будто игнорит ограничение fps
    


    glutMainLoop();

    return 0;
}//*/




