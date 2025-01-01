#include <iostream>
#include "map.h"

// int main(int argc, char *argv[])
// {

// 	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
// 		printf("error initializing SDL: %s\n", SDL_GetError());
// 	}
// 	SDL_Window* win = SDL_CreateWindow("GAME", 
// 									SDL_WINDOWPOS_CENTERED,
// 									SDL_WINDOWPOS_CENTERED,
// 									1000, 1000, 0);

// 	Uint32 render_flags = SDL_RENDERER_ACCELERATED;

// 	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);

	
// 	SDL_Surface* surface;


// 	surface = IMG_Load("../images/user.jpeg");


// 	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);


// 	SDL_FreeSurface(surface);

// 	SDL_Rect dest;


// 	SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);

	
// 	dest.w /= 6;
// 	dest.h /= 6;

// 	dest.x = (1000 - dest.w) / 2;

// 	dest.y = (1000 - dest.h) / 2;

// 	int close = 0;

// 	int speed = 300;

// 	while (!close) {
// 		SDL_Event event;

		
// 		while (SDL_PollEvent(&event)) {
// 			switch (event.type) {

// 			case SDL_QUIT:
				
// 				close = 1;
// 				break;

// 			case SDL_KEYDOWN:
// 				switch (event.key.keysym.scancode) {
// 				case SDL_SCANCODE_W:
// 				case SDL_SCANCODE_UP:
// 					dest.y -= speed / 30;
// 					break;
// 				case SDL_SCANCODE_A:
// 				case SDL_SCANCODE_LEFT:
// 					dest.x -= speed / 30;
// 					break;
// 				case SDL_SCANCODE_S:
// 				case SDL_SCANCODE_DOWN:
// 					dest.y += speed / 30;
// 					break;
// 				case SDL_SCANCODE_D:
// 				case SDL_SCANCODE_RIGHT:
// 					dest.x += speed / 30;
// 					break;
// 				default:
// 					break;
// 				}
// 			}
// 		}

// 		// right boundary
// 		if (dest.x + dest.w > 1000)
// 			dest.x = 1000 - dest.w;

// 		// left boundary
// 		if (dest.x < 0)
// 			dest.x = 0;

// 		// bottom boundary
// 		if (dest.y + dest.h > 1000)
// 			dest.y = 1000 - dest.h;

// 		// upper boundary
// 		if (dest.y < 0)
// 			dest.y = 0;

// 		// clears the screen
// 		SDL_RenderClear(rend);
// 		SDL_RenderCopy(rend, tex, NULL, &dest);

// 		// triggers the double buffers
// 		// for multiple rendering
// 		SDL_RenderPresent(rend);

// 		// calculates to 60 fps
// 		SDL_Delay(1000 / 60);
// 	}

// 	// destroy texture
// 	SDL_DestroyTexture(tex);

// 	// destroy renderer
// 	SDL_DestroyRenderer(rend);

// 	// destroy window
// 	SDL_DestroyWindow(win);
	
// 	// close SDL
// 	SDL_Quit();

// 	return 0;
// }


int	main() {

	Map map;

	map.loadMap();


}	