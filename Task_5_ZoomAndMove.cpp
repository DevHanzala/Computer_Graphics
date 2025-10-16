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
    if (!file) {
        std::cout << "Error: File '" << filename << "' not found or cannot be opened!\n";
        exit(1);
    }
    std::vector<Point> poly;
    int x, y;
    while (file >> x >> y) {
        if (x == -1 && y == -1) {
            if (!poly.empty()) {
                shapes.push_back(poly);
                poly.clear();
            }
        }
        else {
            poly.push_back({ x, y });
        }
    }
    if (!poly.empty()) {
        shapes.push_back(poly);
    }
    file.close();
    std::cout << "Loaded " << shapes.size() << " shapes from " << filename << ".\n";
}

void drawDino() {
    const float max_x = 635.0f; // Approx max x from dino.dat
    const float max_y = 439.0f; // Max y from dino.dat
    for (auto& poly : shapes) {
        glBegin(GL_LINE_LOOP);
        for (auto& p : poly) {
            float norm_x = (p.x / max_x) * 640.0f * zoom; // Apply zoom to normalized x
            float norm_y = ((max_y - p.y) / max_y) * 480.0f * zoom; // Apply zoom to normalized y
            glVertex2f(norm_x + panX, norm_y + panY); // Apply pan
        }
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0); // Black lines
    drawDino();
    glFlush();
}

void keyboard(unsigned char key, int, int) {
    if (key == '+') zoom *= 1.1f;
    if (key == '-') zoom /= 1.1f;
    if (key == 'q' || key == 'Q') exit(0); // Added 'Q' for consistency
    if (zoom < 0.1f) zoom = 0.1f; // Prevent zoom out too far
    glutPostRedisplay();
}

void specialKeys(int key, int, int) {
    const float panStep = 10.0f;
    switch (key) {
    case GLUT_KEY_LEFT:  panX -= panStep; break;
    case GLUT_KEY_RIGHT: panX += panStep; break;
    case GLUT_KEY_UP:    panY += panStep; break;
    case GLUT_KEY_DOWN:  panY -= panStep; break;
    }
    glutPostRedisplay();
}

void initGL() {
    glClearColor(1, 1, 1, 1); // White background
    glViewport(0, 0, 640, 480); // Match window size
    gluOrtho2D(0, 640, 0, 480); // Set coordinate system
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