#include <raylib.h>

int main(void)
{
	/* Initialization */
	/*------------------------------------------------------------------------*/
	const int screenHeight = 600;
	const int screenWidth  = 600;

	InitWindow(screenWidth, screenHeight, "Window Title");

    Rectangle box    = {0, 0, 200, 200};
    Vector2 mousePos = {0.0, 0.0};
	/*------------------------------------------------------------------------*/

	while(!WindowShouldClose())
	{
        mousePos = GetMousePosition();
        
        if(CheckCollisionPointRec(mousePos, box))
        {
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                box.x = GetMouseX() - box.width/2;
                box.y = GetMouseY() - box.height/2;
            }
        }

        BeginDrawing();
        
        DrawRectangleRec(box, GREEN); 
        ClearBackground(GOLD);
        
        EndDrawing();
    }
	/* Deinitialization */
    /*------------------------------------------------------------------------*/
    CloseWindow(); 
    /*------------------------------------------------------------------------*/

	return 0;
}
