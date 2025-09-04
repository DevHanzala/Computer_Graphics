#include <GL/glut.h>
#include <cmath>

int windowWidth = 800, windowHeight = 600;

void drawPolygon(int n, float radius, float centerX, float centerY) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n; i++) {
        float angle = 2.0f * acos(-1) * i / n;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);

    drawPolygon(3, 80, 150, 300);
    drawPolygon(4, 80, 400, 300);
    drawPolygon(5, 80, 650, 300);
    drawPolygon(6, 80, 150, 100);
    drawPolygon(8, 80, 400, 100);
    drawPolygon(12, 80, 650, 100);

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
    glutCreateWindow("Task 6 – Regular Polygons");
    initGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
