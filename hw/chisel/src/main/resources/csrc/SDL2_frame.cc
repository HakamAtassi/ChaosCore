#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define FRAME_WIDTH 320
#define FRAME_HEIGHT 240


// Global SDL variables to be used by both functions.
static SDL_Window   *window   = NULL;
static SDL_Renderer *renderer = NULL;
static SDL_Texture  *texture  = NULL;


unsigned char frame_buffer[FRAME_HEIGHT * FRAME_WIDTH * 3];

// Create and initialize an SDL window, renderer, and texture.
extern "C" void create_window() {
    printf("Creating SDL2 window\n");
    // Initialize SDL video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
         fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
         exit(1);
    }

    // Create window
    window = SDL_CreateWindow("PPM Viewer",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              FRAME_WIDTH, FRAME_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
         fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
         SDL_Quit();
         exit(1);
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
         fprintf(stderr, "Could not create renderer: %s\n", SDL_GetError());
         SDL_DestroyWindow(window);
         SDL_Quit();
         exit(1);
    }

    // Create texture for rendering pixel data
    texture = SDL_CreateTexture(renderer,
                                SDL_PIXELFORMAT_RGB24,
                                SDL_TEXTUREACCESS_STATIC,
                                FRAME_WIDTH, FRAME_HEIGHT);
    if (!texture) {
         fprintf(stderr, "Could not create texture: %s\n", SDL_GetError());
         SDL_DestroyRenderer(renderer);
         SDL_DestroyWindow(window);
         SDL_Quit();
         exit(1);
    }

    // Create an initial black frame
    //memset(frame_buffer, 0, sizeof(frame_buffer));

    SDL_UpdateTexture(texture, NULL, frame_buffer, FRAME_WIDTH * 3);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // Optionally, run a simple event loop in a separate thread or let your simulation call refresh_window.
    // Here, we just print a message.
}

extern "C" void write_frame(uint32_t address, uint32_t data){

    if (address + 2 >= sizeof(frame_buffer)) {
        fprintf(stderr, "Address out of bounds: %u\n", address);
        return;
    }
    frame_buffer[address]   = data&0xFF;
    frame_buffer[address+1] = (data>>8) & 0xFF;
    frame_buffer[address+2] = (data>>16) & 0xFF;

}

// Refresh the window with updated pixel data from the provided memory.
extern "C" void refresh_window() {
    if (!texture || !renderer) {
       fprintf(stderr, "SDL context not initialized.\n");
       return;
    }


    // poll for exit
    SDL_Event e;
    if (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT){
            SDL_DestroyTexture(texture);
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
            exit(1);
        }
    }


    // update frame
    SDL_UpdateTexture(texture, NULL, frame_buffer, FRAME_WIDTH * 3);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);


}
