#ifndef TEXT_H
#define TEXT_H

#include "BitFont.h"
#include "SDL.h"
#include <string>
#include <cstdlib>

struct size {
  int w; // width 
  int h; // height 
}; 

/* text class */ 
class Text {

private:
  SDL_Texture  *m_texture;  // text texture 
  SDL_Renderer *m_renderer; // the renderer destination of the texture
  std::string   m_text;     // the text renderer on the texture
  __int32       m_color;    // text color 

public:
  /* constructor */ 
  Text(SDL_Renderer* renderer, std::string str, SDL_Color color = {255, 255, 255, 255});
  ~Text() {
    if(m_texture)
      SDL_DestroyTexture(m_texture);
  }

  /* get texture */ 
  SDL_Texture* getTexture();

  /* get texture size */ 
  size getSize();

  /* 
    return a size of the text texture proportional with the height argument 
    text scaling purpose only
  */
  /* texture size for a text scaling height equal to height argument */ 
  size getSize(int height);

  /* set the text */ 
  void setText(std::string str); 

  /* set the color */ 
  void setColor(SDL_Color color); 


private:
  /* method for rendering text on the m_surface */ 
  void renderText(std::string str); 
};

#include "Text.cpp"
#endif // TEXT_H