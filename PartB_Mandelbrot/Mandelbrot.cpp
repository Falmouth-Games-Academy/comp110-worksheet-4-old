#include <SDL2/SDL.h>
#include <iostream>
#include <complex>

int main()
{
  enum { Width = 500, Height = 500 };
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    std::cerr << "SDL_Init(SDL_INIT_VIDEO)\n";
    return -1;
  }
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_CreateWindowAndRenderer(Width, Height, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS, &window, &renderer);
  SDL_SetWindowPosition(window, 65, 126);

  enum { PaletteSize = 32 };
  int palette[PaletteSize + 1][3];
  for (int i = 0; i <= PaletteSize; ++i)
  {
    palette[i][0] = i < 2 * PaletteSize / 3 ? i * 255 * 3 / (2 * PaletteSize) : 255;
    palette[i][1] = i < PaletteSize / 3 ? 0 : (i - PaletteSize / 3) * 255 * 3 / (2 * PaletteSize);
    palette[i][2] = 0;
  }

  for (int y = 0; y < Height; ++y)
    for (int x = 0; x < Width; ++x)

