//#include <GL/glut.h>
//#include <vector>
//#include <fstream>
//#include <iostream>
//
//struct Point { int xx, yy; };  // Renamed to avoid conflict with any globals
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
//void drawDino(float tx, float ty, float scale) {
//    const float min_x = 2.0f;
//    const float max_y = 439.0f;
//    const float dino_width = 633.0f;
//    const float dino_height = 439.0f;
//    const float tile_width = 800.0f / 5.0f;  // 160
//    const float tile_height = 600.0f / 3.0f; // 200
//    float adj_scale = std::min(tile_width / dino_width, tile_height / dino_height);  // ~0.25
//    float x_offset = (tile_width - (dino_width * adj_scale)) / 2.0f;
//    float y_offset = (tile_height - (dino_height * adj_scale)) / 2.0f;
//
//    glPushMatrix();
//    glTranslatef(tx + x_offset, ty + y_offset, 0);
//    glScalef(adj_scale, adj_scale, 1);
//    for (auto& poly : shapes) {
//        glBegin(GL_LINE_LOOP);
//        for (auto& p : poly) {
//            float norm_x = p.xx - min_x;
//            float norm_y = max_y - p.yy;  // Flip y for correct orientation
//            glVertex2f(norm_x, norm_y);
//        }
//        glEnd();
//    }
//    glPopMatrix();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0, 0, 0);  // Black lines
//    for (int i = 0; i < 5; i++)
//        for (int j = 0; j < 3; j++)
//            drawDino(i * (800.0f / 5.0f), j * (600.0f / 3.0f), 1.0f);  // Pass 1.0; adjusted inside
//    glFlush();
//}
//
//void init() {
//    glClearColor(1, 1, 1, 1);  // White background
//    glViewport(0, 0, 800, 600);
//    gluOrtho2D(0, 800, 0, 600);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Task 2 – Tiled Dinosaur");
//    init();
//    loadData("dino.dat");
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}