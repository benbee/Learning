#include <GL/glew.h>
#include <GL/freeglut.h>

void display(void) {
    glClearColor(0.0f, 0.0f, 0.1f, 1.0f); /* Clear out
                                             background of our windo to red */
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();           /* load the identity Matrix
                                   to reset our drawing location */
    glFlush();                  /* Flush the OpenGL buffers to the window */
}

void reshape(int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    /* Set our view port  to the size of our window */
    glMatrixMode(GL_PROJECTION);
    /* switch the projection matrix so that we can manipulate
     how our scen is viewed*/
    glLoadIdentity();
    gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("I don\'t know nth window...");
    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
    glutReshapFunc(reshape);
    glutMainLoop();
    return 0;
}
