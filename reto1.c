#include <stdio.h>
#include <turtlec.h>

void fractalTree3(Turtle *t, float len, int depth){
  	if (depth == 0 || len < 5) 
		return;

  	turtleForward(t, len);

  	turtleLeft(t, 30);
  	fractalTree3(t, len * 0.65, depth - 1);
  	turtleRight(t, 30);

  	fractalTree3(t, len * 0.60, depth - 1);

  	turtleRight(t, 30);
  	fractalTree3(t, len * 0.65, depth - 1);
  	turtleLeft(t, 30);

  	turtleBackward(t, len);
}
