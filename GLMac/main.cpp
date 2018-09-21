
#include "HXGLGlobal.h"

// 初始化
void init()
{
    // 指定刷新颜色缓冲区时所用的颜色
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    // 设置投影类型和投影区域
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0f, 800.0f, 0.0f, 600.0f);
}

void Reshape(int w, int h)
{
    glViewport(0, 0, w, h);
}

void Render()
{
    // 根据glClearColor设置的色值刷新颜色缓冲区
    glClear(GL_COLOR_BUFFER_BIT);
    // 指定要显示输出图源的类型
    showTestById(TEST_BAR);
    // 强制清空所有缓存处理OpenGL函数
    glFlush();
}

int main(int argc, char* argv[])
{
    // 初始化GLUT
    glutInit(&argc, argv);
    // 设置窗口位置，相对于屏幕左上角
    glutInitWindowPosition(winPoxX, winPosY);
    // 设置窗口大小
    glutInitWindowSize(winWidth, winHeight);
    // 创建显示窗口
    glutCreateWindow("OpenGL Test");
    // 设置缓存和颜色模型等选项
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // 初始化窗口显示
    init();
    // 窗口改变时调用
    glutReshapeFunc(&Reshape);
    // 将图形描述到窗口绘制，也就是设置渲染函数
    glutDisplayFunc(&Render);
    // 必须是最后一个，显示图形程序，并开始无限循环
    glutMainLoop();
    return 0;
}

//// 错误信息
//GLenum errorCheck()
//{
//    GLenum code = glGetError();
//    if (code != GL_NO_ERROR)
//    {
//        const GLubyte* str = gluErrorString(code);
//        fprintf(stderr, "OpenGL Error %s\n", str);
//    }
//    return code;
//}
//
//// 画线
//// GL_LINES两两组合（奇数最后一个会被忽略）
//// GL_LINE_STRIP（生成折线）
//// GL_LINE_LOOP（生成闭合折线）
//void DrawLine()
//{
//    glBegin(GL_LINES);
//    glVertex2i(0, 0);
//    glVertex2i(800, 600);
//    glEnd();
//}
//
//// 画点
//// GL_POLYGON 逆时针包围并填充一个图形
//// GL_TRIANGLES 每三个顶点定义一个三角形
//// GL_TRIANGLE_STRIP 可获得 n-2个三角形带
//// GL_TRIANGLE_FAN 共享第一个顶点生成扇状相连三角行
//void DrawPoint()
//{
//    glBegin(GL_POINTS);
//    glVertex2i(50, 100);
//    glVertex2i(75, 150);
//    glVertex2i(100, 200);
//    glEnd();
//}
//
//// 画多边形
//void DrawShape()
//{
//    glBegin(GL_TRIANGLE_FAN);
//    int v1[] = { 0, 100 };
//    int v2[] = { 100, 0 };
//    int v3[] = { 200, 0 };
//    int v4[] = { 300, 100 };
//    int v5[] = { 200, 200 };
//    int v6[] = { 100, 200 };
//    glVertex2iv(v1);
//    glVertex2iv(v2);
//    glVertex2iv(v3);
//    glVertex2iv(v4);
//    glVertex2iv(v5);
//    glVertex2iv(v6);
//    glEnd();
//}
//
//// 立方体
//void DrawSquare()
//{
//    vertex3 pt[8] = {
//        { 0, 0, 0 }, { 0, 1, 0 }, { 1, 0, 0 }, { 1, 1, 0 },
//        { 0, 0, 1 }, { 0, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 }
//    };
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3, GL_INT, 0, pt);
//    GLubyte vertexIndex[] = {
//        6, 2, 3, 7,
//        5, 1, 0, 4,
//        7, 3, 1, 5,
//        4, 0, 2, 6,
//        2, 0, 1, 3,
//        7, 5, 4, 5
//    };
//    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, vertexIndex);
//}

//// 简单的批次容器
//GLBatch triangleBatch;
//// 定义一个着色器管理器
//GLShaderManager shaderManager;
//
////窗口大小改变时接受新的宽度和高度，其中0,0代表窗口中视口的左下角坐标，w，h代表像素
//
//void ChangeSize(int w,int h) {
//    glViewport(0,0, w, h);
//}
//
////为程序作一次性的设置
//
//void SetupRC()
//
//{
//
//    //设置背影颜色
//
//    glClearColor(0.0f,0.0f,1.0f,1.0f);
//
//    //初始化着色管理器
//
//    shaderManager.InitializeStockShaders();
//
//    //设置三角形，其中数组vVert包含所有3个顶点的x,y,笛卡尔坐标对。
//
//    GLfloat vVerts[] = {
//
//        -0.5f,0.0f,0.0f,
//
//        0.5f,0.0f,0.0f,
//
//        0.5f,0.5f,0.0f,
//        -0.5f,0.5f,0.0f,
//    };
//
//    //批次处理
//
//    triangleBatch.Begin(GL_TRIANGLES,4);
//
//    triangleBatch.CopyVertexData3f(vVerts);
//
//    triangleBatch.End();
//
//}
//
////开始渲染
//
//void RenderScene(void)
//
//{
//
//    //清除一个或一组特定的缓冲区
//
//    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
//
//    //设置一组浮点数来表示红色
//
//    GLfloat vRed[] = {1.0f,0.0f,0.0f,1.0f};
//
//    //传递到存储着色器，即GLT_SHADER_IDENTITY着色器，这个着色器只是使用指定颜色以默认笛卡尔坐标第在屏幕上渲染几何图形
//
//    shaderManager.UseStockShader(GLT_SHADER_IDENTITY,vRed);
//
//    //提交着色器
//
//    triangleBatch.Draw();
//
//    //将在后台缓冲区进行渲染，然后在结束时交换到前台
//
//    glutSwapBuffers();
//
//}

//int main(int argc,char* argv[]) {
//    //设置当前工作目录，针对MAC OS X
//    gltSetWorkingDirectory(argv[0]);
//
//    //初始化GLUT库
//    glutInit(&argc, argv);
//
//    /*初始化双缓冲窗口，其中标志GLUT_DOUBLE、GLUT_RGBA、GLUT_DEPTH、GLUT_STENCIL分别指
//
//     双缓冲窗口、RGBA颜色模式、深度测试、模板缓冲区*/
//
//    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH|GLUT_STENCIL);
//
//    //GLUT窗口大小，标题窗口
//
//    glutInitWindowSize(800,600);
//
//    glutCreateWindow("Triangle");
//
//    //注册回调函数
//
//    glutReshapeFunc(ChangeSize);
//
//    glutDisplayFunc(RenderScene);
//
//    //驱动程序的初始化中没有出现任何问题。
//
//    GLenum err = glewInit();
//
//    if(GLEW_OK != err) {
//
//        fprintf(stderr,"glew error:%s\n",glewGetErrorString(err));
//
//        return 1;
//
//    }
//
//    //调用SetupRC
//
//    SetupRC();
//
//    glutMainLoop();
//
//    return 0;
//
//}


