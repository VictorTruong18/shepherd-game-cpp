#include "playable_character.h"

PlayableCharacter::~PlayableCharacter() {}

PlayableCharacter::PlayableCharacter(const std::string& file_path,
                                     SDL_Surface* window_surface_ptr,double speed, std::set<std::string> properties) 
: MovingObject(file_path,window_surface_ptr,5,properties){
    this->timeWalking = 0;
}

void PlayableCharacter::stop() { image_direction = Direction::NONE; }

void PlayableCharacter::update_status() {
    
    if( this->timeWalking > TIME_MOVEMENT_SHEPHERD){
        this->stop();
    } else {
        this->timeWalking++;
    }
}