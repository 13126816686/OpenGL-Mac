//
//  BarGraph.h
//  GLMac
//
//  Created by haoxiang on 2018/9/21.
//  Copyright © 2018年 雷雨庭花. All rights reserved.
//

#ifndef BarGraph_h
#define BarGraph_h
#include "HXGLGlobal.h"

void showBarGraph()
{
    GLint month, k;
    glColor3f(1.0f, 0.0f, 0.0f);
    for (k=0; k<12; ++k)
        glRecti(20+k*50, 165.40, k*50, dataValue[k]);
    glColor3f(0.0f, 0.0f, 0.0f);
    GLint xRaster = 0, yRaster = 150;
    glRasterPos2i(xRaster, yRaster);
    for (month=0; month<12; ++month)
    {
        glRasterPos2i(xRaster, yRaster);
        for (k = 3 * month; k < 3 * month + 3; ++k)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, label[k]);
        xRaster += 50;
    }
}

#endif /* BarGraph_h */
