#include "playable_character.h"

PlayableCharacter::~PlayableCharacter() {}

PlayableCharacter::PlayableCharacter(const std::string& file_path,
                                     SDL_Surface* window_surface_ptr,double speed, std::set<std::string> properties) 
: MovingObject(file_path,window_surface_ptr,5,properties){

}





void PlayableCharacter::stop() { image_direction = Direction::NONE; }
