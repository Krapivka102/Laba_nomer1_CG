	#include <GL/glew.h>
	#include <iostream>
	#include <GL/freeglut.h>
	#include <glm/vec3.hpp>

	GLuint VBO; // переменная для хранения указателя на буфер вершин
	void RenderSceneCB() 
	{
		glClear(GL_COLOR_BUFFER_BIT); // очищает буфер цвета
		glEnableVertexAttribArray(0); // индексация

		glBindBuffer(GL_ARRAY_BUFFER, VBO); // привязываем буфер для приготавливания его для отрисовки

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // как воспринимать данные внутри буфера(шейдеры, кол-во компонентов, тип данных, нормализация атрибута)

		glDrawArrays(GL_TRIANGLES, 0, 3); // рисуем все(1 параментр указали тип как точку, это значит, что каждая вершина - одна точка, следующий параметр это индекс первой вершины для отрисовки, последний параметр - количество вершин для отрисовки)


		glDisableVertexAttribArray(0); // отключение индексации
		glutSwapBuffers(); // смена буфера
	}


	int main(int argc, char** argv)
	{
		glutInit(&argc, argv); // инициализируем glut, параметры могут быть переданы прямо из командной строки и включают полезные опции

		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // включение двойной буферизации и буфера цвета(GLUT_DOUBLE включает двойную буферизацию, GLUT_RGBA буфер цвета)

		glutInitWindowSize(1024, 768); // размер
		glutInitWindowPosition(100, 100); // позиция на экране
		glutCreateWindow("Tutorial 01"); // названия окна

		glutDisplayFunc(RenderSceneCB); // регулярно вызывает рендер сцену, эта функция регулярно вызывается GLUT'ом

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // цвет бэк граунда

	
		GLenum res = glewInit(); // инициализируем GLEW и проверяем на ошибки
		if (res != GLEW_OK) // 
		{
			fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
			return 1;
		}

		//glm::vec3 Vertices[1]; // задаем массив и объявляем xyz нулями //
		//Vertices[0] = glm::vec3(0.0f, 0.0f, 0.0f);

		glm::vec3 Vertices[3]; // инициализация точек
		Vertices[0] = glm::vec3(-1.0f, -1.0f, 0.0f); // XYZ
		Vertices[1] = glm::vec3(1.0f, -1.0f, 0.0f);
		Vertices[2] = glm::vec3(0.0f, 1.0f, 0.0f); 

		


		glGenBuffers(1, &VBO); // создание буфера для помещения объектов (часто принимает 2 параметра: первый определяет количество объектов, которые вы хотите создать, и второй ссылка на массив типа GLuints для хранения указателя, по которому будут храниться данные)

		glBindBuffer(GL_ARRAY_BUFFER, VBO); // связываем указатель к названию цели и затем запускаем команду на цель(Параметр GL_ARRAY_BUFFER означает, что буфер будет хранить массив вершин)

		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW); // наполняем данными (буффер массива вершин, размер, массив, статически)

		glutMainLoop(); // цикл вызывающий дисплей фанк, чтобы дать ей возможность нарисовать кадр (GLUT будет вызывать только функцию отображения на экран (RenderSceneCB))


	
	}
