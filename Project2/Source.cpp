#include <iostream> 
#include <GL/glut.h>

double deltaX = 0;
double deltaA = 0;
double deltaC = 0;

void gambar() {
	glPointSize(30);
	glBegin(GL_POINTS);
	{glColor3ub(100, 100, 100);
	glVertex2f(50, 50);
	}
	glEnd();
	glPointSize(10);
	glBegin(GL_POINTS);
	{glColor3ub(170, 186, 251);
	glVertex2f(sin(deltaX) * 10 + 50, cos(deltaX) * 10 + 50);
	}
	glEnd();
	glPointSize(15);
	glBegin(GL_POINTS);
	{glColor3ub(164, 200, 144);
	glVertex2f(sin(deltaA) * 20 + 50, cos(deltaA) * 20 + 50);
	}
	glEnd();
	glPointSize(20);
	glBegin(GL_POINTS);
	{glColor3ub(199, 154, 211);
	glVertex2f(sin(deltaA) * 30 + 50, cos(deltaA) * 30 + 50);
	}
	glEnd();
	glPointSize(15);
	glBegin(GL_POINTS);
	{glColor3ub(160, 210, 225);
	glVertex2f(sin(deltaC) * 40 + 50, cos(deltaC) * 40 + 50);
	}
	glEnd();
	glFlush();
}
void ondisplay() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	gambar();
}
void onupdate(int) {
	glutPostRedisplay();
	deltaX += 0.07f;
	deltaA += 0.05f;
	deltaC += 0.04f;
	glutTimerFunc(15, onupdate, 1);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Tugas 2 Tweening");
	glutInitWindowSize(1000, 1000);
	gluOrtho2D(0, 100, 100, 0);
	glEnable(GL_POINT_SMOOTH);
	glutDisplayFunc(ondisplay);
	glutTimerFunc(17, onupdate, 1);
	glutMainLoop();
	return 0;
}