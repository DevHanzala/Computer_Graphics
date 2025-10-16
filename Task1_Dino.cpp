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
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0, 0, 0); // Black lines
//    const float max_x = 635.0f; // Approx max x from dino.dat
//    const float max_y = 439.0f; // Max y from dino.dat
//    const float scale_x = 640.0f / max_x; // Scale to fit 640 width
//    const float scale_y = 480.0f / max_y; // Scale to fit 480 height
//    const float scale = std::min(scale_x, scale_y); // Use smaller scale to fit both
//
//    for (auto& poly : shapes) {
//        glBegin(GL_LINE_LOOP);
//        for (auto& p : poly) {
//            float norm_x = p.x * scale; // Scale x
//            float norm_y = (max_y - p.y) * scale; // Flip and scale y
//            glVertex2f(norm_x, norm_y);
//        }
//        glEnd();
//    }
//    glFlush();
//}
//
//void init() {
//    glClearColor(1, 1, 1, 1); // White background
//    glViewport(0, 0, 640, 480); // Match window size
//    gluOrtho2D(0, 640, 0, 480); // Set coordinate system
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(640, 480);
//    glutCreateWindow("Task 1 – Dinosaur");
//    init();
//    loadData("dino.dat");
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}