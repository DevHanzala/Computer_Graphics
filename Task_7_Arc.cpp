#include <GL/glut.h>
#include <cmath>

int windowWidth = 800, windowHeight = 600;

void drawArc(float cx, float cy, float r, float start, float end) {
    glBegin(GL_LINE_STRIP);
    for (float a = start; a <= end; a += 0.01f) {
        float x = cx + r * cos(a);
        float y = cy + r * sin(a);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    drawArc(400, 300, 150, 0, acos(-1));
    glFlush();
}

void initGL() {
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, windowWidth, 0, windowHeight);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Task 7 – Arc");
    initGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
