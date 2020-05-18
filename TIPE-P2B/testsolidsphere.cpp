#include <GLUT/glut.h>

static void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 0.0f);
    glutSolidSphere(0.5f, 50, 60);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("SolidSphere");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}