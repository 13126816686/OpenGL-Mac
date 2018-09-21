//
//  HXGLGlobal.h
//  GLMac
//
//  Created by haoxiang on 2018/9/21.
//  Copyright © 2018年 雷雨庭花. All rights reserved.
//

#ifndef HXGLGlobal_h
#define HXGLGlobal_h

#include "GLTools.h"
#include <glut/glut.h>
#include "GLShaderManager.h"

#include "LineGraph.h"
#include "BarGraph.h"
typedef GLint vertex3[3];
GLint winWidth = 800, winHeight = 600;
GLint winPoxX = 200, winPosY = 150;
enum TESTID
{
    TEST_LINE,
    TEST_BAR
};

void showTestById(TESTID id)
{
    if (id == TEST_LINE)
        showLineGraph();
    else if (id == TEST_BAR)
        showBarGraph();
}

#endif /* HXGLGlobal_h */
