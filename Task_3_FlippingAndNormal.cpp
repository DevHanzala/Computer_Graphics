//#include <GL/glut.h>
//#include <vector>
//#include <fstream>
//#include <iostream>
//
//struct Point { int x, y; };
//std::vector<std::vector<Point>> shapes;
//
//void loadData(const char* filename) {
//    std::ifstream file(filename);
//    if (!file) {
//        std::cout << "Error: File '" << filename << "' not found or cannot be opened!\n";
//        exit(1);
//    }
//    std::vector<Point> poly;
//    int x, y;
//    while (file >> x >> y) {
//        if (x == -1 && y == -1) {
//            if (!poly.empty()) {
//                shapes.push_back(poly);
//                poly.clear();
//            }
//        }
//        else {
//            poly.push_back({ x, y });
//        }
//    }
//    if (!poly.empty()) {
//        shapes.push_back(poly);
//    }
//    file.close();
//    std::cout << "Loaded " << shapes.size() << " shapes from " << filename << ".\n";
//}
//
//void drawDino(float tx, float ty, float scale, bool flip) {
//    glPushMatrix();
//    glTranslatef(tx, ty, 0);
//    glScalef(scale, flip ? -scale : scale, 1);
//    const float max_y = 439.0f; // Max y from dino.dat
//    for (auto& poly : shapes) {
//        glBegin(GL_LINE_LOOP);
//        for (auto& p : poly) {
//            float norm_x = p.x;
//            float norm_y = p.y; // y will be flipped by scale if needed
//            glVertex2f(norm_x, norm_y);
//        }
//        glEnd();
//    }
//    glPopMatrix();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0, 0, 0); // Black lines
//    const float max_x = 635.0f; // Approx max x from dino.dat
//    const float max_y = 439.0f; // Max y from dino.dat
//    const float scale_x = 800.0f / (max_x * 6); // Scale for 6 dinosaurs across 800
//    const float scale_y = 600.0f / max_y; // Scale to fit height
//    const float scale = std::min(scale_x, scale_y) * 0.9f; // Slight reduction to fit
//
//    for (int i = 0; i < 6; i++) {
//        drawDino(i * (800.0f / 6.0f), 300.0f, scale, i % 2); // Center vertically
//    }
//    glFlush();
//}
//
//void init() {
//    glClearColor(1, 1, 1, 1); // White background
//    glViewport(0, 0, 800, 600); // Match window size
//    gluOrtho2D(0, 800, 0, 600); // Set coordinate system
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Task 3 – Flipped Dinosaur Row");
//    init();
//    loadData("dino.dat");
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}