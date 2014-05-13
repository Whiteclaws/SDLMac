/* SDLMac(ros) ~ A Header file with many useful macros
/ Made by Whiteclaws ~ All Rights Reserved.
 - NEEDS SDL lIBS & HEADERS -
/*/

//Put this below the includes
#define __macVars__ SDL_Window *window; SDL_Renderer *renderer; SDL_Texture **pool; int nTex = 0;
#define macQuit(c) if((c)) { macClear(); exit(EXIT_FAILURE); } /* Quits if condition is true */
#define macCreateWindow(title, width, height, wflags, rflags) SDL_DisplayMode mode; macQuit(SDL_GetDesktopDisplayMode(0, &mode) < 0) macQuit((window = SDL_CreateWindow(title, (mode.w / 2 - width / 2) , (mode.h / 2 - height / 2), width, height, wflags)) == 0); macQuit((renderer = SDL_CreateRenderer(window, -1, rflags)) == 0);
#define macLoadTex(path) ++nTex; pool = realloc(pool, sizeof(SDL_Texture *) * nTex); macQuit(!(pool[nTex - 1] = IMG_LoadTexture(renderer, path))); // Loads a texture at n (n being current number of textures minus this one)
#define macDrawTex(tex, _x, _y, angle) SDL_Rect dst; dst.x = _x; dst.y = _y; SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h); SDL_RenderCopyEx(renderer, tex, NULL, &dst, angle, NULL, SDL_FLIP_NONE);
#define macTex(i) pool[i] /* Just returns texture at that index */
#define macClearColor(r, g, b, a) SDL_SetRenderDrawColor(renderer, r, g, b, a);
#define macClearWindow() SDL_RenderClear(renderer);
#define macUpdateWindow() SDL_RenderPresent(renderer);
#define macClear() if(window) SDL_DestroyWindow(window); if(renderer) SDL_DestroyRenderer(renderer); for(int i = 0; i < nTex; i++) if(pool[i]) SDL_DestroyTexture(pool[i]); if(pool) free(pool); SDL_Quit();
#define macRenderer renderer
#define macWindow window

/** TODO **/
// Should set up a way to just malloc once with macLoadTex(), without having to re-do realloc for each ...
// Also tells you that it can only load in BMPS if you don't
