void menu_interface() {
    glPopMatrix();
    gluLookAt(0, 0, -1,
        0, 0, 1,
        0.0f, 1.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);


    gluOrtho2D(0.0, 0, 0.0, 0);

    glBegin(GL_QUADS);
    glColor3d(1, 0, 0);      // рисуем треугольник
    glVertex2d(0.9, 0.9);
    glVertex2d(-0.9, 0.9);
    glVertex2d(-0.9, -0.9);
    glVertex2d(0.9, -0.9);
    glEnd();
    glColor3d(1, 1, 1);

    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
}