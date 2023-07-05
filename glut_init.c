
#include <GL/freeglut.h>

unsigned int defaults(unsigned int displayMode, int *width, int *height);
void init();
void display();
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	int width = 500;
	int height = 500;
	unsigned int displayMode = GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_STENCIL;
	displayMode = defaults(displayMode, &width, &height);

	glutInitDisplayMode (displayMode);
	glutInitContextVersion (3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
#ifdef DEBUG
	glutInitContextFlags(GLUT_DEBUG);
#endif
	glutInitWindowSize (width, height); 
	glutInitWindowPosition (300, 200);
	int window = glutCreateWindow (argv[0]);

	//glload::LoadFunctions();
	
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	
	init();

	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

//Called after the window and OpenGL are initialized. Called exactly once, before the main loop.
void init()
{
	//InitializeProgram();
	//InitializeVertexBuffer();

	//glGenVertexArrays(1, &vao);
	//glBindVertexArray(vao);
}

// this should be moved out of the framework
unsigned int defaults(unsigned int displayMode, int *width, int *height) {
    // Function implementation
    
    return displayMode;
}

//Called to update the display.
//You should call glutSwapBuffers after all of your rendering to display what you rendered.
//If you need continuous updates of the screen, call glutPostRedisplay() at the end of the function.
void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

}

//Called whenever the window is resized. The new window size is given, in pixels.
//This is an opportunity to call glViewport or glScissor to keep up with the change in size.
void reshape (int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}

//Called whenever a key on the keyboard was pressed.
//The key is given by the ''key'' parameter, which is in ASCII.
//It's often a good idea to have the escape key (ASCII value 27) call glutLeaveMainLoop() to 
//exit the program.
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	  case 27:
		  glutLeaveMainLoop();
		  return;
	}
}

