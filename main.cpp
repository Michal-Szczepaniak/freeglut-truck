#include <iostream>
#include <GL/glut.h>
#include <cmath>

/* Global variables */
char title[] = "3D Shapes";
int menuClicked = -1;

int menuId;

GLfloat calculateCubeBorder(GLfloat radius) {
    return static_cast<GLfloat>(radius * (sqrt(2) - 1) / sqrt(2));
}

void generateObject(GLfloat radius, GLfloat height, GLint points) {
    glPolygonMode(GL_FRONT, GL_FILL);

    GLfloat step = (M_PI*2)/points;

    for(GLfloat t = 0.0f; t <= M_PI*2; t += step) {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f/((M_PI*2)/((M_PI*2)-(t/2))), 0.0f);
        glVertex3f(radius*cos(t), 0.0f, radius*sin(t));
        glVertex3f(radius*cos(t), height, radius*sin(t));
        glVertex3f(radius*cos(t+step), height, radius*sin(t+step));
        glVertex3f(radius*cos(t+step), 0.0f, radius*sin(t+step));
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(radius*cos(t), 0.0f, radius*sin(t));
        glVertex3f(radius*cos(t+step), 0.0f, radius*sin(t+step));
        glVertex3f(0.0f, 0.0f, 0.0f);

        glVertex3f(radius*cos(t), height, radius*sin(t));
        glVertex3f(radius*cos(t+step), height, radius*sin(t+step));
        glVertex3f(0.0f, height, 0.0f);
        glEnd();
    }

}

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    switch (menuClicked) {
        case 0:
            //top view
            glTranslatef(-2.0f, -10.0f, -10.0f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            break;
        case 1:
            // front view
            glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
            glTranslatef(10.0f, 1.0f, 10.0f);
            break;
        case 2:
        default:
            glTranslatef(-2.0f, 0.0f, 0.0f);
            break;
        case 3:
            glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
            glTranslatef(5.0f, 0.5f, 5.0f);
            break;
    }

    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    // start tank
    glPushMatrix();
    glTranslatef(-0.8f, -0.25f, -10.0f);
    glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
    generateObject(0.75f, 7.0f, 20);
    glPopMatrix();
    // end tank

    // start cabin
    glPushMatrix();
    glTranslatef(-2.0f, -1.0f, -10.0f);
    glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
    generateObject(1.0f, 2.2f, 4);
    glPopMatrix();
    // end cabin

    // start light left
    glPushMatrix();
    glTranslatef(-3.05f + calculateCubeBorder(1.0f), -1.25f + calculateCubeBorder(1.0f)/4, -10.5f);
    glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
    generateObject(0.128f, 0.05f, 20);
    glPopMatrix();
    // end light left

    // start light right
    glPushMatrix();
    glTranslatef(-3.05f + calculateCubeBorder(1.0f), -1.25f + calculateCubeBorder(1.0f)/4, -9.5f);
    glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
    generateObject(0.125f, 0.05f, 20);
    glPopMatrix();
    // end light right

    // start exhaust
    glPushMatrix();
    glTranslatef(-1.8f + calculateCubeBorder(1.0f), -1.0f, -9.275f - calculateCubeBorder(1.0f));
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.125f, 0.5f, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.8f + calculateCubeBorder(1.0f), -1.0f, -8.775f - calculateCubeBorder(1.0f));
    glRotatef(45.0f, 1.0f, 0.0f, 0.0f);
    glTranslated(0.0f, -0.088f, -0.038f);
    generateObject(0.125f, 0.175f, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.8f + calculateCubeBorder(1.0f), -1.0f, -8.775f - calculateCubeBorder(1.0f));
    generateObject(0.125f, 2.5f, 20);
    glPopMatrix();
    // end exhaust

    // start front platform
    glPushMatrix();
    glTranslatef(-3.0f + calculateCubeBorder(1.0f), -1.25f + calculateCubeBorder(1.0f)/4, -10.0f);
    glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.25f, 1.0f, 1.0f);
    glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
    generateObject(1.0f, 4.5f, 4);
    glPopMatrix();
    // end front platform

    // start back platform
    glPushMatrix();
    glTranslatef(3.2f, -1.25f + calculateCubeBorder(1.0f)/4, -10.0f);
    glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.25f, 1.0f, 1.0f);
    glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
    generateObject(1.0f, 3.0f, 4);
    glPopMatrix();
    // end back platform

    // start drive shaft
    glPushMatrix();
    glTranslatef(-2.0f, -2.0f, -10.0f);
    glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
    generateObject(0.128f, 7.5f, 20);
    glPopMatrix();
    // end drive shaft

    // start front wheels
    // start front wheel 1
    glPushMatrix();
    glTranslatef(-2.0f, -2.0f, -9.5f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.5f, 0.25f, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0f, -2.0f, -10.75f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.5f, 0.25f, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0f, -2.0f, -10.75f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.125f, 1.5f, 20);
    glPopMatrix();
    // end front wheel 1

    // start front wheel 2
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, -9.5f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.5f, 0.25f, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -2.0f, -10.75f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.5f, 0.25f, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -2.0f, -10.75f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.125f, 1.5f, 20);
    glPopMatrix();
    // end front wheel 2

    // start front wheel 3
    glPushMatrix();
    glTranslatef(1.2f, -2.0f, -9.5f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.5f, 0.25f, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2f, -2.0f, -10.75f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.5f, 0.25f, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2f, -2.0f, -10.75f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.125f, 1.5f, 20);
    glPopMatrix();
    // end front wheel 3
    // end front wheels

    // start back front wheels
    glPushMatrix();
    glTranslatef(4.3f, -2.0f, -9.5f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.5f, 0.25f, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.3f, -2.0f, -10.75f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.5f, 0.25f, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.3f, -2.0f, -10.75f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.125f, 1.5f, 20);
    glPopMatrix();
    // end back front wheels

    // start back wheels
    glPushMatrix();
    glTranslatef(5.5f, -2.0f, -9.5f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.5f, 0.25f, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.5f, -2.0f, -10.75f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.5f, 0.25f, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.5f, -2.0f, -10.75f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.125f, 1.5f, 20);
    glPopMatrix();
    // end back wheels

    // start input 1
    glPushMatrix();
    glTranslatef(0.0f, 0.4f, -10.0f);
    generateObject(0.40f, 0.25f, 20);
    glPopMatrix();
    // end input 1

    // start input 2
    glPushMatrix();
    glTranslatef(1.8f, 0.4f, -10.0f);
    generateObject(0.40f, 0.25f, 20);
    glPopMatrix();
    // end input 2

    // start input 3
    glPushMatrix();
    glTranslatef(3.6f, 0.4f, -10.0f);
    generateObject(0.40f, 0.25f, 20);
    glPopMatrix();
    // end input 3

    // start input 4
    glPushMatrix();
    glTranslatef(5.4f, 0.4f, -10.0f);
    generateObject(0.40f, 0.25f, 20);
    glPopMatrix();
    // end input 4

    glutSwapBuffers();
}

void menu(int value) {
    menuClicked = value;

    glutPostRedisplay();
}

void createMenu() {
    menuId = glutCreateMenu(menu);

    glutAddMenuEntry("Widok z gory", 0);
    glutAddMenuEntry("Widok z przodu", 1);
    glutAddMenuEntry("Widok z boku", 2);
    glutAddMenuEntry("Widok pod katem", 3);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(title);
    createMenu();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initGL();
    glutMainLoop();

    return 0;
}