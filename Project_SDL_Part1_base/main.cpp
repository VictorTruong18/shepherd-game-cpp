#include "./Game/application.h"
#include <stdio.h>
#include <string>

void init() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
    throw std::runtime_error("init():" + std::string(SDL_GetError()));

  // Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
    throw std::runtime_error("init(): SDL_image could not initialize! "
                             "SDL_image Error: " +
                             std::string(IMG_GetError()));

   // Initialize TTF
   if (TTF_Init() < 0)
     throw std::runtime_error("init(): TTF could not initialize! "
                              "TTF Error: " +
                              std::string(TTF_GetError()));
}

int main(int argc, char* argv[]) {

  std::cout << "Starting up the application" << std::endl;

  if (argc != 4)
    throw std::runtime_error("Need three arguments - "
                             "number of sheep, number of wolves, "
                             "simulation time\n");

  std::cout << "Step 0" << std::endl;

  init();

  std::cout << "Done with initilization" << std::endl;
  {
  application my_app(std::stoul(argv[1]), std::stoul(argv[2]));

  std::cout << "Created window" << std::endl;

  int retval = my_app.loop(std::stoul(argv[3]));

  std::cout << "Exiting application with code " << retval << std::endl;
  }

  TTF_Quit();
  SDL_Quit();

  return 0;
}