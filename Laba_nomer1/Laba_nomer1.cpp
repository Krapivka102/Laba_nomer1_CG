#include <iostream>
#include <GL/freeglut.h>

void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT); // это очистка буфера кадра
    glutSwapBuffers(); // функция просит GLUT поменять фоновый буфер и буфер кадра местами
}


int main(int argc, char ** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 01");

    glutDisplayFunc(RenderSceneCB);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glutMainLoop(); // GLUT будет вызывать только функцию отображения на экран (RenderSceneCB), что бы дать ей возможность нарисовать кадр.
}

