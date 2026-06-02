#include <stdio.h>
#include <turtlec.h>
#include <math.h>

void levy(Turtle *t, float len, int depth) {
  if (depth == 0) {
    turtleForward(t, len);
    return;
  }

  turtleLeft(t, 45);
  levy(t, len / sqrt(2), depth - 1);

  turtleRight(t, 90);
  levy(t, len / sqrt(2), depth - 1);

  turtleLeft(t, 45);
}
