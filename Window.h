#ifndef WINDOW_H
#define WINDOW_H

#include "SDL.h"

/* window class */ 
class Window {
private:
  SDL_Window*   m_window; 
  SDL_Renderer* m_renderer; 

public:
  Window(const char* title, int width, int height); 
  ~Window() {
    if(m_window) 
      SDL_DestroyWindow(m_window); 
    if(m_renderer) 
      SDL_DestroyRenderer(m_renderer); 
  }

  /* get the window renderer */ 
  SDL_Renderer* getRenderer() {
    return m_renderer; 
  }
  
  /* set render draw color */ 
  void setDrawColor(SDL_Color color); 

  /* clear the window renderer */ 
  void clear(); 

  /* update the window renderer */ 
  void update(); 

  /* render texture */ 
  void renderTexture(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination); 
};

#include "Window.cpp"
#endif // WINDOW_H