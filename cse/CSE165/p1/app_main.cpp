#include "App.h"

int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
    
    // Instantiate a new App
    App* myApp = new App("doggos", 50, 50, 1600, 1600);

	// Start the app
    myApp->run();
}
