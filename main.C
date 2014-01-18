#include "main.h"

int id2idx(const int window_id)
{
   for(int i=0; i<SCENEWINDOWS; i++)
   {
      if(window_id == glut_window[i])
         return i;
   }
}

void redraw(void *user, SoSceneManager *manager)
{
   unsigned int idx = (uintptr_t)user;
   glutSetWindow(glut_window[idx]);
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_LIGHTING);
   sceneManager[idx]->render();

   glutSwapBuffers();
}

void expose()
{
   sceneManager[id2idx(glutGetWindow())]->render();
   glutSwapBuffers();
}

void reshape(int w, int h)
{
   int idx = id2idx(glutGetWindow());

   sceneManager[idx]->setWindowSize(SbVec2s(w,h));
   sceneManager[idx]->setSize(SbVec2s(w, h));
   sceneManager[idx]->setViewportRegion(SbViewportRegion(w, h));
   sceneManager[idx]->scheduleRedraw();
}

void idle()
{
   SoDB::getSensorManager()->processTimerQueue();
   SoDB::getSensorManager()->processDelayQueue(TRUE);
}

int main(int argc, char **argv)
{
   SoDrawStyle         *drawStyle;
   SoPerspectiveCamera *camera;

   sphere *s1;
   SoDB::init();
   SoInteraction::init();

   glutInit(&argc, argv);

   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

   SoSeparator *root[SCENEWINDOWS];

   for (unsigned int i=0; i < SCENEWINDOWS; i++)
   {
      root[i] = new SoSeparator;
      root[i]->ref();
      SoPerspectiveCamera *camera = new SoPerspectiveCamera;
      root[i]->addChild(camera);
      root[i]->addChild(new SoDirectionalLight);
      SoDrawStyle *drawstyle = new SoDrawStyle;
      drawstyle->style.setValue(i % 3);
      root[i]->addChild(drawstyle);
      root[i]->addChild(s1->canvas());

      sceneManager[i] = new SoSceneManager;
      sceneManager[i]->setRenderCallback(redraw, (void *)i);
      sceneManager[i]->setBackgroundColor(SbColor(0.2f, 0.2f, i * 0.2f));
      sceneManager[i]->activate();
      camera->viewAll(root[i], sceneManager[i]->getViewportRegion());
      sceneManager[i]->setSceneGraph(root[i]);

      glutInitWindowSize(512, 400);
      SbString title("Sphere");
      glut_window[i] = glutCreateWindow(title.getString());
      glutDisplayFunc(expose);
      glutReshapeFunc(reshape);
      glutSpecialFunc(keyboard);
    }

   glutIdleFunc(idle);
   glutMainLoop();

   for(int j=0; j< SCENEWINDOWS; j++)
   {
      root[j]->unref();
      delete sceneManager[j];
   }
return 0;
}
