#include "sphere.h"

SoSeparator *root;

SoSeparator* sphere :: canvas()
{
   root = new SoSeparator;
   SoMaterial *material = new SoMaterial;
   material->diffuseColor.setValue(0.0f, 0.5f, 1.0f);
   root->addChild(material);

   SoSphere *sphere = new SoSphere;
   root->addChild(sphere);

   return root;
}

void keyboard(int key, int x, int y)
{
   sphere *temp;
   switch(key)
   {
      case GLUT_KEY_UP:   temp->upKeyPressed();
                          break;
      case GLUT_KEY_DOWN: temp->downKeyPressed();
                          break;
      case GLUT_KEY_LEFT: temp->leftKeyPressed();
                          break;
      case GLUT_KEY_RIGHT:temp->rightKeyPressed();
                          break;
   }
}


void sphere :: upKeyPressed()
{
   //upKeyPressed
    SoTransform * trans0 = new SoTransform;
    trans0->rotation.setValue(SbVec3f(0, 0, 1), 1.5707963f);
    root->addChild(trans0);
}

void sphere :: downKeyPressed()
{
   //downkeyPressed
}

void sphere :: leftKeyPressed()
{
   //leftkeypressed
}

void sphere :: rightKeyPressed()
{
   //rightkeypressed
}
