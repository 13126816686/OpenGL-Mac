//
//  LineGraph.h
//  GLMac
//
//  Created by haoxiang on 2018/9/21.
//  Copyright © 2018年 雷雨庭花. All rights reserved.
//

#ifndef LineGraph_h
#define LineGraph_h

GLubyte label[36] = {
    'J', 'a', 'n', 'F', 'e', 'b', 'M', 'a', 'r',
    'A', 'p', 'r', 'M', 'a', 'y', 'J', 'u', 'n',
    'J', 'u', 'l', 'A', 'u', 'g', 'S', 'e', 'p',
    'O', 'c', 't', 'N', 'o', 'v', 'D', 'e', 'c'
};

GLint dataValue[12] = {
    420, 342, 324, 310, 262, 185, 190, 196, 217, 240, 312, 438
};

void showLineGraph()
{
    GLint month, k;
    GLint x = 30;
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINE_STRIP);
    for (k=0; k<12; ++k)
        glVertex2i(x + k * 50, dataValue[k]);
    glEnd();
    glColor3f(1.0f, 0.0f, 0.0f);
    GLint xRaster = 25, yRaster = 150;
    for (k=0; k<12; ++k)
    {
        glRasterPos2i(xRaster + k * 50, dataValue[k] - 4);
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '*');
    }
    glColor3f(0.0f, 0.0f, 0.0f);
    for (month=0; month<12; ++month)
    {
        glRasterPos2i(xRaster, yRaster);
        for (k = 3 * month; k < 3 * month + 3; ++k)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, label[k]);
        xRaster += 50;
    }
    
    glRasterPos2i(0, 0);
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'A');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'B');
}

#endif /* LineGraph_h */
