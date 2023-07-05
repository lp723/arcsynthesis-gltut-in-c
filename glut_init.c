#include <GL/glut.h>
#include <GL/freeglut_ext.h>

unsigned int defaults(unsigned int displayMode, int *width, int *height);

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
}


// this should be moved out of the framework
unsigned int defaults(unsigned int displayMode, int *width, int *height) {
    // Function implementation
    
    return displayMode;
}
