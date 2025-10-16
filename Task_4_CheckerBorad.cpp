//#include <GL/glut.h>
//
//int windowSize = 600;
//
//void drawCheckerboard(int rows, int cols) {
//    float cellW = (float)windowSize / cols;
//    float cellH = (float)windowSize / rows;
//
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            if ((i + j) % 2 == 0) glColor3f(0, 0, 0);
//            else glColor3f(1, 1, 1);
//            glBegin(GL_POLYGON);
//            glVertex2f(j * cellW, i * cellH);
//            glVertex2f((j + 1) * cellW, i * cellH);
//            glVertex2f((j + 1) * cellW, (i + 1) * cellH);
//            glVertex2f(j * cellW, (i + 1) * cellH);
//            glEnd();
//        }
//    }
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    drawCheckerboard(8, 8);
//    glFlush();
//}
//
//void init() {
//    glClearColor(1, 1, 1, 1);
//    gluOrtho2D(0, windowSize, 0, windowSize);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(windowSize, windowSize);
//    glutCreateWindow("Task 4 – Checkerboard");
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}
