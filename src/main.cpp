#include <SDL.h>
#include <SDL_image.h>
#include <emscripten.h>
#include <stdlib.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Surface *surface;

SDL_Point points[5]; // Definisikan di luar fungsi agar tetap statis

void drawStaticPolygon() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    // Buat poligon hanya sekali di awal
    if (points[0].x == 0 && points[0].y == 0) {
        // Buat poligon dengan titik-titik yang tetap
        points[0] = {100, 100};
        points[1] = {200, 100};
        points[2] = {200, 200};
        points[3] = {100, 200};
        points[4] = {100, 100};
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLines(renderer, points, 5);

    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(512, 512, 0, &window, &renderer);
    
    emscripten_set_main_loop(drawStaticPolygon, 0, 1);
    return 0;
}


// void drawRandomPixels() {
//     if (SDL_MUSTLOCK(surface)) SDL_LockSurface(surface);

//     Uint8 * pixels = static_cast<Uint8*>(surface->pixels);
    
//     for (int i=0; i < 1048576; i++) {
//         char randomByte = rand() % 255;
//         pixels[i] = randomByte;
//     }

//     if (SDL_MUSTLOCK(surface)) SDL_UnlockSurface(surface);

//     SDL_Texture *screenTexture = SDL_CreateTextureFromSurface(renderer, surface);

//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, screenTexture, NULL, NULL);
//     SDL_RenderPresent(renderer);

//     SDL_DestroyTexture(screenTexture);
// }

// int main(int argc, char* argv[]) {
//     SDL_Init(SDL_INIT_VIDEO);
//     SDL_CreateWindowAndRenderer(512, 512, 0, &window, &renderer);
//     surface = SDL_CreateRGBSurface(0, 512, 512, 32, 0, 0, 0, 0);
    
//     emscripten_set_main_loop(drawRandomPixels, 0, 1);
//     return 0;
// }
