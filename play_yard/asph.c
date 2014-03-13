#include <GL/gl.h>
#include <GL/glut.h>

#include <stdio.h>
#include <math.h>


double angle = 0;

typedef struct
{
    int X;
    int Y;
    int Z;
}VERTICES;

const double PI = 3.1415926535897;

const int space = 1;

const int VertexCount = (90 / space) * (360 / space) * 4;

VERTICES VERTEX[VertexCount];

void DisplaySphere (double R){

    int b;
    glScalef (0.0125 * R, 0.0125 * R, 0.0125 * R);
    glRotatef (90, 1, 0, 0);
    glBegin (GL_TRIANGLE_STRIP);
    for ( b = 0; b <= VertexCount; b++){
        glVertex3f (VERTEX[b].X, VERTEX[b].Y, -VERTEX[b].Z);
    }

    for ( b = 0; b <= VertexCount; b++){
        glVertex3f (VERTEX[b].X, VERTEX[b].Y, VERTEX[b].Z);
    }
    glEnd();
}

void CreateSphere (double R, double H, double K, double Z) {
    int n;
    double a;
    double b;
    n = 0;

    for( b = 0; b <= 90 - space; b+=space){
        for( a = 0; a <= 360 - space; a+=space){
            VERTEX[n].X = R * sin((a) / 180 * PI) * sin((b) / 180 * PI) - H;
            VERTEX[n].Y = R * cos((a) / 180 * PI) * sin((b) / 180 * PI) + K;
            VERTEX[n].Z = R * cos((b) / 180 * PI) - Z;
            n++;
            VERTEX[n].X = R * sin((a) / 180 * PI) * sin((b + space) / 180 * PI
                ) - H;
            VERTEX[n].Y = R * cos((a) / 180 * PI) * sin((b + space) / 180 * PI
                ) + K;
            VERTEX[n].Z = R * cos((b + space) / 180 * PI) - Z;
            n++;

            VERTEX[n].X = R * sin((a + space) / 180 * PI) * sin((b) / 180 * PI
                ) - H;
            VERTEX[n].Y = R * cos((a + space) / 180 * PI) * sin((b) / 180 * PI
                ) + K;

            VERTEX[n].Z = R * cos((b) / 180 * PI) - Z;
            n++;

            VERTEX[n].X = R * sin((a + space) / 180 * PI) * sin((b + space) /
                                                                180 * PI) - H;
            VERTEX[n].Y = R * cos((a + space) / 180 * PI) * sin((b + space) /
                                                                180 * PI) + K;
            VERTEX[n].Z = R * cos((b + space) / 180 * PI) - Z;
            n++;
        }
    }
}

void display (void) {
    glClearDepth(1);
    glClearColor (0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0,0,-10);
    glRotatef(angle,0,1,0);
    DisplaySphere(5);
    glutSwapBuffers();
    angle ++;
}

void init (void) {

    glEnable(GL_DEPTH_TEST);

    glDepthFunc(GL_LEQUAL);

    CreateSphere(70,0,0,0);
}
void reshape (int w, int h) {

    glViewport (0, 0, (GLsizei)w, (GLsizei)h);

    glMatrixMode (GL_PROJECTION);

    glLoadIdentity ();

    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 100.0);

    glMatrixMode (GL_MODELVIEW);
}

int main (int argc, char **argv) {

    glutInit (&argc, argv);

    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize (500, 500);

    glutInitWindowPosition (100, 100);

    glutCreateWindow("lala");

    init();

    glutDisplayFunc (display);

    glutIdleFunc (display);

    glutReshapeFunc (reshape);

    glutMainLoop ();

    return 0;
}
