#include <GL/glew.h>
#include <GL/glut.h>

#include <stdio.h>
#include <math.h>

typedef struct {
    int X;
    int Y;
    int Z;
} VERTICES;

double angle = 0;
const double PI = 3.1415926535897;
const int space = 10;               /* the bigger the squarer */
const int VertexCount = (90 / space) * (360 / space) * 4; /* total number of vertices */

VERTICES VERTEX[VertexCount];

void display(void);
void CreateSphere(double R, double H, double K, double Z);
void DisplaySphere(double R);
void init(void);
void reshape(int w, int h);

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);      /* Initialize GLUT */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); /* set up a basic
                                                      display buffer */
    glutInitWindowSize(500, 500);     /* width, height of the window */
    glutInitWindowPosition(100, 100); /* Set the position of the window */
    glutCreateWindow("Draw sphere");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}

void display(void)
{
    glClearDepth(1);
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     /* clear the colout buffer */
    glLoadIdentity();                 /* loat the identity matrix
                                         to reset out drawing locations */
    glTranslatef(0, 0, -10);
    glRotatef(angle, 0, 1, 0);

    DisplaySphere(5);
    glutSwapBuffers();
    angle++;
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


/* void CreateSphere2(double R, double H, double K, double Z) */
/* { */
/*     int n;                      /\* current vertex we are working *\/ */
/*     double a; */
/*     double b; */

/*     n = 0;                      /\* first vertex start 0 *\/ */

/*     for (b = 0; b <= 90; b += space) { */
/*         for (a = 0 ; a <= 360; a += space) { */
/*             VERTEX[n].X = R * sin((a) / 180 * PI)*sin((b) / 180 * PI) - H; */
/*             VERTEX[n].Y = R * cos((a) / 180 * PI)*sin((b) / 180 * PI) + K; */
/*             VERTEX[n].Z = R * cos((b) / 180 * PI) - Z; */
/*             n++; */

/*             VERTEX[n].X = R * sin((a) / 180 * PI)*sin((b) / 180 * PI) - H; */
/*             VERTEX[n].Y = R * cos((a) / 180 * PI)*sin((b) / 180 * PI) + K; */
/*             VERTEX[n].Z = R * cos((b) / 180 * PI) - Z; */
/*             n++; */

/*             VERTEX[n].X = R * sin((a) / 180 * PI)*sin((b) / 180 * PI) - H; */
/*             VERTEX[n].Y = R * cos((a) / 180 * PI)*sin((b) / 180 * PI) + K; */
/*             VERTEX[n].Z = R * cos((b) / 180 * PI) - Z; */
/*             n++; */

/*             VERTEX[n].X = R * sin((a) / 180 * PI)*sin((b) / 180 * PI) - H; */
/*             VERTEX[n].Y = R * cos((a) / 180 * PI)*sin((b) / 180 * PI) + K; */
/*             VERTEX[n].Z = R * cos((b) / 180 * PI) - Z; */
/*             n++; */
/*         } */
/*     } */
/* } */

void DisplaySphere(double R)
{
	int b;

	glScalef(0.0125 * R, 0.0125 * R, 0.0125 * R);
	glRotatef(90, 1, 0, 0);

    glBegin(GL_TRIANGLE_STRIP);

    for (b = 0; b <= VertexCount; b++) {
        glVertex3f(VERTEX[b].X, VERTEX[b].Y, -VERTEX[b].Z);
    }

    for ( b = 0; b <= VertexCount; b++){
        glVertex3f (VERTEX[b].X, VERTEX[b].Y, VERTEX[b].Z);
    }
    glEnd();
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    CreateSphere(70, 0, 0, 0);
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}
