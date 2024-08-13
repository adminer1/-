#include <GL/glut.h>
#include <GL/glu.h>

 /* 旋转角度 */
static float angle = 0.0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    /* 设置视角 */
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    /* 旋转正方体 */
    glRotatef(angle, 1.0, 1.0, 0.0);

    /* 启用光照 */
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    /* 设置光源位置 */
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    /* 设置光照属性 */
    GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    /* 启用材质 */
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    /* 绘制正方体的每个面 */
    glBegin(GL_QUADS);

    /* 前面红色 */
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1.0, -1.0,  1.0);
    glVertex3f( 1.0, -1.0,  1.0);
    glVertex3f( 1.0,  1.0,  1.0);
    glVertex3f(-1.0,  1.0,  1.0);

    /* 后面绿色 */
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0,  1.0, -1.0);
    glVertex3f(-1.0,  1.0, -1.0);

    /* 左面蓝色 */
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0,  1.0);
    glVertex3f(-1.0,  1.0,  1.0);
    glVertex3f(-1.0,  1.0, -1.0);

    /* 右面黄色 */
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0,  1.0);
    glVertex3f( 1.0,  1.0,  1.0);
    glVertex3f( 1.0,  1.0, -1.0);

    /* 上面品红色 */
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-1.0,  1.0, -1.0);
    glVertex3f( 1.0,  1.0, -1.0);
    glVertex3f( 1.0,  1.0,  1.0);
    glVertex3f(-1.0,  1.0,  1.0);

    /* 底面青色 */
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0,  1.0);
    glVertex3f(-1.0, -1.0,  1.0);

    glEnd();

    glutSwapBuffers();
}

void timer(int value) {
    /* 增加旋转角度 */
    angle += 2.0;
    if (angle > 360) {
        /* 保持角度在0到360度之间 */
        angle -= 360;
    }
    /* 重新绘制 */
    glutPostRedisplay();
    /* 设置帧数 */
    glutTimerFunc(16, timer, 0);
}

void init() {
    /* 启用深度测试 */
    glEnable(GL_DEPTH_TEST);
    /* 白色背景 */
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    /* 视角设置 */
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotating Cube");
    /* 初始化设置 */
    init();

    glutDisplayFunc(display);
    /* 设置定时器 */
    glutTimerFunc(25, timer, 0);
    glutMainLoop();
    return 0;
}
