void processNormalKeysDOWN(unsigned char key, int x, int y){
    switch (key) {
        //if (MENU == Menu_types::game) {
        case 'w':
        case 'W': {
            int mode = glutGetModifiers();
            if (mode == GLUT_ACTIVE_SHIFT) {
                KeyFront = 1.4;
            }
            else KeyFront = 1.0;

            break;
        }
        case 's':
        case 'S':
            KeyFront = -1.0; break;

        case 'a':
        case 'A':
            KeySide = -1.0;
            break;

        case 'd':
        case 'D':
            KeySide = 1.0;
            break;

        case 'B':
        case 'b':
            steve.PlayerX = 1 / 2 + 0.5 * cube_size;
            steve.PlayerY = (20) * cube_size;
            steve.PlayerZ = 1 / 2 + 0.5 * cube_size;
            steve.dy = 0;
            break;

        

        case 'Q':
        case 'q':
            if (MENU == Menu_types::game) {
                MENU = Menu_types::game_menu;
                ReshapeOrtho(width, height);
            }
            else {
                MENU = Menu_types::game;
                Reshape(width, height);
            }
            break;

        case 32:
            steve.jump();
            break;

        case 27:
            exit(0);

        case 'E':
        case 'e': {
            std::thread th(close_game);
            th.detach();
            break;
        }

        case 9:
            if (!Draw_debug_Menu_key) {
                Draw_debug_Menu_key = 1;
            }
            else Draw_debug_Menu_key = 0;

        case 'R':
        case 'r':
            IDblocks++;
            if (IDblocks > blocks) IDblocks = 0;
            break;
        
        case 'f':
        case 'F':
            IDblocks--;
            if (IDblocks < 0) IDblocks = blocks;
            break;
    }
    //}
}
void processNormalKeysUP(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
    case 'W':
    case 's':
    case 'S':
        KeyFront = 0;
        break;
    case 'a':
    case 'A':
    case 'd':
    case 'D':
        KeySide = 0;
        break;

    }
}
void mouseMove(int x, int y) {
    if (mouseXOld != 0 or mouseYOld != 0) {
        angleX -= mouseXOld * 0.001f;
        angleY -= mouseYOld * 0.001f;

        if (angleY > 3.14 / 2) angleY = 3.14 / 2;
        if (angleY < -3.14 / 2) angleY = -3.14 / 2;

        mouseXOld = 0; mouseYOld = 0;

        // update camera's direction
        lx = float(sin(angleX));
        lz = float(-cos(angleX));
        ly = float(-tan(angleY));          

    }
    else {

        mouseXOld = (width / 2) - x;
        mouseYOld = (height / 2) - y;
        glutWarpPointer((width / 2), (height / 2));
    }

    //glutPostRedisplay();

}
void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        switch (state) {
        case GLUT_DOWN:		//Если нажата
            mLeft = true;
            break;
        case GLUT_UP:
            mLeft = false;
            break;
        }
    }

    if (button == GLUT_RIGHT_BUTTON) {
        switch (state) {
        case GLUT_DOWN:		//Если нажата
            mRight = true;
            break;
        case GLUT_UP:
            mRight = false;
            break;
        }
    }
    //if (button == GLUT_WHEEL_DOWN)
}