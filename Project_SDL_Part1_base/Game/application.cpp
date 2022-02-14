#include "application.h"

application::application(unsigned n_sheep, unsigned n_wolf) {

  // creation of the window
  this->window_ptr_ =
      SDL_CreateWindow("Sheep and Wolf", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, frame_width, frame_height, 0);
  if (!this->window_ptr_) {
    std::cout << "Failed to create window\n";
    std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
    return;
  }

  // Get the Ptr of the window surface
  this->window_surface_ptr_ = SDL_GetWindowSurface(this->window_ptr_);
  if (!window_surface_ptr_) {
    std::cout << "Failed to get window's surface\n";
    std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
    return;
  }

  // Put the window in the right color
  SDL_FillRect(this->window_surface_ptr_, NULL,
               SDL_MapRGB(this->window_surface_ptr_->format, 153, 255, 51));

  // Instanciation of ground

   std::unique_ptr<ground> playing_ground =
      std::make_unique<ground>(this->window_surface_ptr_);
  this->playing_ground = std::move(playing_ground);

  // Loop to instance all the sheeps
  for (int i = 0; i < n_sheep; i++) {
    // std::unique_ptr<Animal> sheep(new Sheep(this->window_surface_ptr_));
    std::unique_ptr<Animal> sheep =
        std::make_unique<Sheep>(this->window_surface_ptr_);
    this->playing_ground->add_character(std::move(sheep));
  }

  for (int i = 0; i < n_wolf; i++) {
    // std::unique_ptr<Animal> wolf(new Wolf(this->window_surface_ptr_));
    std::unique_ptr<Animal> wolf =
        std::make_unique<Wolf>(this->window_surface_ptr_);
    this->playing_ground->add_character(std::move(wolf));
  }

  // Loop to instance all the wolves
}

// DESTRUCTOR
application::~application() {
  // Destroy the window
  SDL_DestroyWindow(this->window_ptr_);
  // Free the surface of the window
  SDL_FreeSurface(this->window_surface_ptr_);
}

// LOOP
int application::loop(unsigned period) {
  auto start = SDL_GetTicks();
  bool running = true;

  int count = 0;

  // make a playable character
  std::unique_ptr<Shepherd> shepherd =
      std::make_unique<Shepherd>(this->window_surface_ptr_);
  this->playing_ground->add_character(std::move(shepherd));

  //  std::unique_ptr<Bearman> bearman =
  //     std::make_unique<Bearman>(this->window_surface_ptr_);
  // this->playing_ground->add_character(std::move(bearman));

  std::unique_ptr<ShepherdDog> shepherdDog =
      std::make_unique<ShepherdDog>(this->window_surface_ptr_);
  this->playing_ground->add_character(std::move(shepherdDog));
  // shepherd->addPet(std::move(shepherdDog));
    
  while (running && (SDL_GetTicks() - start < period * 1000)) {

    while (SDL_PollEvent(&window_event_)) {

      this->playing_ground->event_handler(window_event_);

      switch (window_event_.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_WINDOWEVENT:
        break;
      }
    }

    // update the playing ground with the animals
    this->playing_ground->update();

    // update the window
    SDL_UpdateWindowSurface(this->window_ptr_);

    count++;
    SDL_Delay(1000 / frame_rate); // Run the game at 60Hz
  }


  return 0;
}
