#ifndef COMMON_H_
#define COMMON_H_

#include <GL/glut.h>

/*!
   SoDB holds all scene graphs
   scene graph is collection of SoNode objects 
*/
#include <Inventor/SoDB.h>

/*!
   SoInteraction is used to initialize all node classes
   Using static function named init()
*/
#include <Inventor/SoInteraction.h>

/*!
   SoSceneManager renders and handle events
   in a window provided by caller
*/
#include <Inventor/SoSceneManager.h>

/*!
   It defines the styles to use when rendering scene
*/
#include <Inventor/nodes/SoDrawStyle.h>

#include <Inventor/nodes/SoDirectionalLight.h>
#include <Inventor/nodes/SoPerspectiveCamera.h>

#include "sphere.h"

//! Specify total number of windows
const int SCENEWINDOWS = 2;

SoSceneManager *sceneManager[SCENEWINDOWS];
int glut_window[SCENEWINDOWS];

int  id2idx(const int window_id);
void redraw(void *user, SoSceneManager *manager);
void expose();
void reshape(int w, int h);
void idle();

SoDrawStyle         *drawStyle;
SoPerspectiveCamera *camera;
#endif
