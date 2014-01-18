#ifndef SPHERE_H_
#define SPHERE_H_

#include <GL/glut.h>

//! Used to draw sphere
#include <Inventor/nodes/SoSphere.h>

//! SoSeparator provides group of nodes.
//! the separator child are seprated from the main scene
#include <Inventor/nodes/SoSeparator.h>

//! Provides surface material definition node
#include <Inventor/nodes/SoMaterial.h>

#include <Inventor/nodes/SoTransform.h>

void keyboard(int key, int x, int y);

extern SoSeparator *root;

class sphere
{
public: 
        SoSeparator* canvas();
        void upKeyPressed();
        void downKeyPressed();
        void leftKeyPressed();
        void rightKeyPressed();
};

#endif
