#include <cassert>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600

void setWindowFullscreen(SDL_Window* window, uint32_t flags, bool fullscreen) {
	if (fullscreen) flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
	else flags &= ~SDL_WINDOW_FULLSCREEN_DESKTOP;
	SDL_SetWindowFullscreen(window, flags);
}

int main(int argc, char** argv) {
	uint32_t windowFlags = SDL_WINDOW_OPENGL;
	SDL_Window* window = SDL_CreateWindow(
			"Test",
			0, 0,
			DEFAULT_WIDTH, DEFAULT_HEIGHT,
			windowFlags);
	assert(window);
	SDL_GLContext context = SDL_GL_CreateContext(window);

	bool running = true;
	bool fullscreen = false;
	while (running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						running = false;
						break;
					case 'f':
						fullscreen = !fullscreen;
						setWindowFullscreen(window, windowFlags, fullscreen);
						break;
					default:
						break;
				}
			} else if (event.type == SDL_QUIT) {
				running = false;
			}
		}

		glViewport(0, 0, DEFAULT_WIDTH, DEFAULT_HEIGHT);
		glClearColor(1.f, 0.f, 1.f, 0.f);
		glClear(GL_COLOR_BUFFER_BIT);

		SDL_GL_SwapWindow(window);
	}
	return 0;
}
