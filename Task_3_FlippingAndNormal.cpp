#include <GL/glut.h>
#include <vector>
#include <fstream>
#include <iostream>

struct Point { int x, y; };
std::vector<std::vector<Point>> shapes;

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

void drawDino(float tx, float ty, float scale, bool flip) {
    glPushMatrix();
    glTranslatef(tx, ty, 0);
    glScalef(scale, flip ? -scale : scale, 1);
    for (auto& poly : shapes) {
        glBegin(GL_LINE_LOOP);
        for (auto& p : poly) glVertex2f(p.x, p.y);
        glEnd();
    }
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; i < 6; i++)
        drawDino(i * 120, 250, 0.2f, i % 2);
    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 800, 0, 600);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Task 3 – Flipped Dinosaur Row");
    init();
    loadData("dino.dat");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
