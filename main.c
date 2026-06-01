#include <stdio.h>
#include <turtlec.h>
void fractalTree(Turtle *turtle, float length, int depth) {
	if( depth == 0 || length < 5)
	return;

	turtleForward (turtle, length);

	turtleLeft (turtle, 30);
	fractalTree (turtle, length * 0.7, depth - 1);

	turtleRight (turtle, 60);
	fractalTree (turtle, length * 0.7, depth - 1);

	turtleLeft (turtle, 30);
	turtleBackward (turtle, length);
 }

int main(void){
	TurtleApp *app = turtleAppCreate(800, 800, "Arbol Fractal");

  	if(app == NULL)
    		return 1;

  	Turtle *t = turtleAppGetTurtle(app);
	turtleSetColor(t, 0, 255, 43);
  	turtleSetSpeed(t, 5.0f);
  	
	turtlePenUp(t);
	turtleRight(t, 90.0f);
	turtleForward(t, 200.0f);

	turtleLeft(t, 180.0f);
	turtlePenDown(t);
	fractalTree(t, 200.0f, 7);

  	turtleAppRun(app);
  	turtleAppDestroy(app);

  	return 0;
}
