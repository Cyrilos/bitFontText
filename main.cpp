#include "SDL.h"
#include "Window.h"
#include "Text.h"

/* main program */ 
int main(int argc, char* argv[]) {

  /* subsystem initialisation */ 
  SDL_Init(SDL_INIT_VIDEO); 

  /* objects for this program */ 
  Window* mainWindow = new Window("Text class", 400, 400); 
  Text myText{mainWindow->getRenderer(), "Hello World !"};
  size textSize = myText.getSize(20);

  /* rectangle for centering the text texture */ 
  SDL_Rect destination = {
    200 - (textSize.w / 2), 
    200 - (textSize.h / 2), 
    textSize.w, 
    textSize.h
  }; 

  /* rendering on the screen */ 
  mainWindow->setDrawColor({0, 0, 0, 255}); 
  mainWindow->clear(); 
  SDL_RenderCopy(mainWindow->getRenderer(), myText.getTexture(), NULL, &destination); 
  mainWindow->update(); 

  /* program main loop */ 
  SDL_Event programEvent; 
  bool runProgram = true; 
  while(runProgram) {
    SDL_WaitEvent(&programEvent); 
    if(programEvent.type == SDL_QUIT)
      runProgram = false; 
  }

  /* free memory allocation */ 
  if(mainWindow)
    delete mainWindow; 
  SDL_Quit(); 
  return 0; 
}