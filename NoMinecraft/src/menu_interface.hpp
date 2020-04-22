void hotbar_icons() {
    glPushMatrix();
    for (int i = 1; i <= blocks; i++) {
        glTranslatef(-0.1491 + i*0.0373, -0.18, 0);
        switch (i) {
        case STONE:
            glBindTexture(GL_TEXTURE_2D, stone_icon);
            break;
        case SUPER_GRASS:
            glBindTexture(GL_TEXTURE_2D, super_grass_icon);
            break;
        case DIRT:
            glBindTexture(GL_TEXTURE_2D, dirt_icon);
            break;
        case COBBLESTONE:
            glBindTexture(GL_TEXTURE_2D, cobblestone_tex_icon);
            break;
        case PLANKS:
            glBindTexture(GL_TEXTURE_2D, planks_icon);
            break;
        case TREE_OAK:
            glBindTexture(GL_TEXTURE_2D, tree_oak_icon);
            break;
        case LEAVES:
            glBindTexture(GL_TEXTURE_2D, leaves_icon);
            break;
        case BRICKS:
            glBindTexture(GL_TEXTURE_2D, bricks_icon);
            break;
        }

        glBegin(GL_QUADS);
        glTexCoord2d(1, 0); glVertex3f(0.015, 0.015, -0.2);
        glTexCoord2d(1, 1); glVertex3f(0.015, -0.015, -0.2);
        glTexCoord2d(0, 1); glVertex3f(-0.015, -0.015, -0.2);
        glTexCoord2d(0, 0); glVertex3f(-0.015, 0.015, -0.2);
        glEnd();
        glTranslatef(0.1491 - i*0.0373, 0.18, 0);
    }

    glTranslatef(-0.1491 + IDblocks * 0.0373, -0.18, 0);
    glBindTexture(GL_TEXTURE_2D, GUI_tex);
    glBegin(GL_QUADS);
    glTexCoord2d(0.995f, 0.775f);     glVertex3f(0.02, 0.02, -0.2); // :. 
    glTexCoord2d(0.995f, 0.885f);     glVertex3f(0.02, -0.02, -0.2); // :' 
    glTexCoord2d(0.885f, 0.885f);      glVertex3f(-0.02, -0.02, -0.2); // ':
    glTexCoord2d(0.885f, 0.775f);      glVertex3f(-0.02, 0.02, -0.2); //.:
    glEnd();

    glPopMatrix();
}

//void menu_interface() {
//    glPopMatrix();
//    gluLookAt(0, 0, -1,
//        0, 0, 1,
//        0.0f, 1.0f, 0.0f);
//    glMatrixMode(GL_PROJECTION);
//
//
//    gluOrtho2D(0.0, 0, 0.0, 0);
//
//    glBegin(GL_QUADS);
//    glColor3d(1, 0, 0);      // рисуем треугольник
//    glVertex2d(0.9, 0.9);
//    glVertex2d(-0.9, 0.9);
//    glVertex2d(-0.9, -0.9);
//    glVertex2d(0.9, -0.9);
//    glEnd();
//    glColor3d(1, 1, 1);
//
//    
//    glMatrixMode(GL_MODELVIEW);
//    glPushMatrix();
//}