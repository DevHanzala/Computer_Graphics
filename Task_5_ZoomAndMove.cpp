#include <GL/glut.h>
#include <vector>
#include <fstream>
#include <iostream>

struct Point { int x, y; };
std::vector<std::vector<Point>> shapes;

float zoom = 1.0f;
float panX = 0.0f, panY = 0.0f;

void loadData(const char* filename) {
    std::ifstream file(filename);
    int n;
    while (file >> n) {
        std::vector<Point> poly;
        for (int i = 0; i < n; i++) {
            Point p; file >> p.x >> p.y;
            poly.push_back(p);
        }
        shapes.push_back(poly);
    }
}

void drawDino() {
    for (auto& poly : shapes) {
        glBegin(GL_LINE_LOOP);
        for (auto& p : poly) glVertex2f(p.x, p.y);
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(panX, panY, 0);
    glScalef(zoom, zoom, 1);
    glColor3f(0, 0, 0);
    drawDino();
    glPopMatrix();
    glFlush();
}

void keyboard(unsigned char key, int, int) {
    if (key == '+') zoom *= 1.1f;
    if (key == '-') zoom /= 1.1f;
    if (key == 'q') exit(0);
    glutPostRedisplay();
}

void specialKeys(int key, int, int) {
    switch (key) {
    case GLUT_KEY_LEFT:  panX -= 10; break;
    case GLUT_KEY_RIGHT: panX += 10; break;
    case GLUT_KEY_UP:    panY += 10; break;
    case GLUT_KEY_DOWN:  panY -= 10; break;
    }
    glutPostRedisplay();
}

void initGL() {
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Task 5 – Zoom & Pan Dinosaur");
    initGL();
    loadData("dino.dat");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
