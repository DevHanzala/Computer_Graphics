#include <GL/glut.h>
#include <vector>
#include <fstream>
#include <iostream>

struct Point { int x, y; };

std::vector<std::vector<Point>> shapes;

void loadData(const char* filename) {
    std::ifstream file(filename);
    if (!file) { std::cout << "File not found!"; exit(1); }
    int n;
    while (file >> n) {
        std::vector<Point> poly;
        for (int i = 0; i < n; i++) {
            Point p; file >> p.x >> p.y;
            poly.push_back(p);
        }
        shapes.push_back(poly);
    }
    file.close();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    for (auto& poly : shapes) {
        glBegin(GL_LINE_LOOP);
        for (auto& p : poly) glVertex2f(p.x, p.y);
        glEnd();
    }
    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Task 1 – Dinosaur");
    init();
    loadData("dino.dat");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
