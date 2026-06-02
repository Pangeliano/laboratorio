#include "turtlec.h"

void tree(Turtle *t, float size, int depth) {
    if (depth == 0 || size < 5.0f)
        return;

    /* Dibujar tronco/rama actual */
    turtleForward(t, size);

    /* Rama izquierda */
    turtleLeft(t, 30.0f);
    tree(t, size * 0.7f, depth - 1);
    turtleRight(t, 30.0f);

    /* Rama derecha */
    turtleRight(t, 30.0f);
    tree(t, size * 0.7f, depth - 1);
    turtleLeft(t, 30.0f);

    /* Volver al punto de origen de esta rama */
    turtleBackward(t, size);
}

void cuadrados(Turtle *t, float size, int depth){
	if(depth == 0 || size < 0.5f){
		return;
	}
	for(int i=0; i<4; i++){
		//turtleForward(t, size);
    		//turtleLeft(t, 90.0f);
		//turtleRight(t, 15.0f);
		//cuadrados(t, 0.5f * size, depth - 1);
		//turtleLeft(t, 15.0f);
		turtleForward(t, size);
        	turtleRight(t, 90.0f);

        	/* En cada esquina, dibujá uno más chico */
        	turtleLeft(t, 15.0f);
        	cuadrados(t, size * 0.5f, depth - 1);
        	turtleRight(t, 15.0f);
	}

}

/*void snowflake(Turtle *t, float length, int level){
   for(int i = 0; i < 3; i++){
     koch(t, length, level);
     turtleRight(t, 120.0f);
   }
 }*/

void koch(Turtle *t, float length, int level){
    if(level == 0){
      turtleForward(t, length);
      return;
    }
  
    koch(t, length / 3.0f, level - 1);
    turtleLeft(t, 60.0f);
    koch(t, length / 3.0f, level - 1);
    turtleRight(t, 120.0f);
    koch(t, length / 3.0f, level - 1);
    turtleLeft(t, 60.0f);
    koch(t, length / 3.0f, level - 1);
 }



void draw(Turtle *t) {
    turtleSetColor(t, 255, 255, 255);
    turtleSetSpeed(t, 180.0f);

    /* Posicionar en la base, apuntando hacia arriba */
    turtlePenUp(t);
    turtleGoTo(t, 250.0f, 450.0f);
    turtleLeft(t, 90.0f);
    turtlePenDown(t);

    //tree(t, 100.0f, 5);
    //cuadrados(t, 200.0f, 5);
    koch(t, 200.f, 6);
}

int main(void) {
    turtleRun(draw, 500, 500, "Arbol Recursivo");
    return 0;
}
