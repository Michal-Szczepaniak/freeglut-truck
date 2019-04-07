#include <iostream>
#include <GL/glut.h>
#include <cmath>

/* Global variables */
char title[] = "3D Shapes";

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

/* Initialize OpenGL Graphics */
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
}

/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

    glLoadIdentity();
//    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
//    glTranslatef(10.0f, 1.5f, 10.0f);
    glTranslatef(-2.0f, 0.0f, 0.0f);

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
    glTranslatef(0.0f, 0.0f, -9.5f);
//    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    generateObject(0.5f, 0.25f, 20);
    glPopMatrix();
    // end back wheels

    glutSwapBuffers();
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
    // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping volume to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset
    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Enable double buffered mode
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow(title);          // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}