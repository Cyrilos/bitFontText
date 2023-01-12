/* constructor */ 
Window::Window (const char* title, int width, int height) {
  m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0); 
  m_renderer = SDL_CreateRenderer(m_window, -1, 0); 
} 

/* set render draw color */ 
void Window::setDrawColor(SDL_Color color) {
  SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a); 
}

/* clear the window renderer */ 
void Window::clear() {
  SDL_RenderClear(m_renderer); 
}

/* update the window renderer */ 
void Window::update() {
  SDL_RenderPresent(m_renderer); 
}

/* render texture */ 
void Window::renderTexture(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination) {
  SDL_Rect tempSource = source; 
  SDL_Rect tempDestination = destination; 
  SDL_RenderCopy(m_renderer, texture, &source, &destination); 
} 

