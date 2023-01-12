// #include "Text.h"

/* Text class constructor */ 
Text::Text(SDL_Renderer* renderer, std::string str, SDL_Color color) : m_texture{nullptr}, m_text{str}, m_renderer{renderer} {
  setColor(color); 
  renderText(m_text); 
}

/* method for rendering text on the m_surface */ 
void Text::renderText(std::string str) {
  SDL_Surface* tempSurface = NULL; 

  /* text rendering */ 
  __int32 *pixels = (__int32*) malloc(sizeof(__int32) * 64 * str.size()); 
  for(int i = 0, k = 0; i < 8; i++) {
    for(const auto& c : str) {
      int pixelIndex = (c - 32)*8 + i; 
      for(int mask = 128; mask != 0; mask >>= 1) {
        pixels[k] = ((mask & bitFont[pixelIndex]) == 0)? 0x00000000 : m_color; 
        k++; 
      }
    }
  }

  /* creating new surface */ 
  tempSurface = SDL_CreateRGBSurfaceFrom(pixels, 8*str.size(), 8, 32, 32*str.size(), 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);

  /* texture update */ 
  if(m_texture) {
    /* texture update */ 
    if(m_text.size() == str.size()) {
      /* update the current texture */ 
      SDL_UpdateTexture(m_texture, NULL, pixels, 32*str.size()); 
    }
    else {
      /* new texture */
      SDL_DestroyTexture(m_texture); 
      m_texture = SDL_CreateTextureFromSurface(m_renderer, tempSurface);
    }
  }
  else {
    /* new texture creation */ 
    m_texture = SDL_CreateTextureFromSurface(m_renderer, tempSurface);
  }

  if(tempSurface)
    SDL_FreeSurface(tempSurface); 
  free(pixels); 
}

/* get surface */ 
SDL_Texture* Text::getTexture() {
  return m_texture; 
}

/* get surface size */ 
size Text::getSize() {
  int width, height; 
  SDL_QueryTexture(m_texture, NULL, NULL, &width, &height);
  return size{width, height}; 
}

/* texture size for a text scaling height equal to height argument */ 
size Text::getSize(int height) {
  int textureWidth = getSize().w; 
  int textureHeight = getSize().h; 
  return size{textureWidth * (height/textureHeight), height}; 
}

/* set the text */ 
void Text::setText(std::string str) {
  m_text = str; 
  renderText(str); 
} 

/* set the color */ 
void Text::setColor(SDL_Color color) {
  m_color = (color.r << 24) + (color.g << 16) + (color.b << 8) + color.a;
}