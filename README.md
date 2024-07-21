# Wolf And Sheep

![Screen Shot 2022-02-14 at 19.34.18.png](Wolf%20And%20Sheep%208d2b97a26f1741c8b42bab4fe4b87af6/Screen_Shot_2022-02-14_at_19.34.18.png)

Game where you control a shepherd and you need to protect your herd of sheeps against the hungry wolves. Your friendly dog is there to help you by scaring away the up-close wolves, however wolves are reknown hunters that will  hunt for sheeps activily.

You can move with : Q + Z + S +D ( Azerty users )

You can send your dog with : left click

You can send him back : right click

The purpose of this project was to code with a scalable layout following the **Open/Close Principle** so that people will feel free to easily add new features to the game.

# Compatibility

- Nous n'avons pas testé sur Windows, uniquement sur ubuntu/macos.
- Pour macos nous avons créé un CMakeList spécifique.
- Le CMakeList de base fonctionne très bien sur Ubuntu en ajoutant la ligne suivante :

```c++
add_executable(SDL_part1 main.cpp application.cpp ground.cpp animal.cpp sheep.cpp wolf.cpp helper.cpp)
```

# Compile

Pour Compiler ce projet

```
cd Project_SDL_Part1_base
cmake .
make
```

# Run
```
./SDL_part1 5 5 1000
```

# Sommaire :

- Finished Features
- Principles to Respect
- The Layout we have chosen
- Demonstration of the scalibity of our code

# Finished Features :

These are the features we finished for this game and you can feel free to add more.

- Sheep :
    - Get scared of wolf
    - Have a temporal boost in the opposite direction
    - Two Sheep can create an offspring a long as :
        - opposite sex
        - female didn’t create in some time
    - The new sheep is lamb and grows over time.

- Wolves
    - They actively hunt the closest sheep.
    - It dies of starvation if he doesn’t eat in some time.
    - Fear shepherd dogs
    - Don’t create offspring

- Shepherd dogs
    - Circle arround the shepherd
    - Clickable can receive orders and go to a certain point and come back to circle around the sheperd.
    - Scares the wolf.

- Playable character
    - Can be move with keyboard  Q + Z + S +D
    
- Gameplay
    - The game ends after a predifined number of seconds
    

# Principles to Respect :

- No Raw Pointers, only Smart Pointers
- Every characters derives from a commun class “interracting_object”
- Only one vector of characters in the ground class

# The Layout we have chosen :

![Screen Shot 2022-02-14 at 20.04.23.png](Wolf%20And%20Sheep%208d2b97a26f1741c8b42bab4fe4b87af6/Screen_Shot_2022-02-14_at_20.04.23.png)

We have chosen the proposed Layout because it is excellent and there is no better way to do it.

It’s a scalable layout and easy to understand. Every classes in green overrides virtual functions to create polymorphism.

# Demonstration of the scalibity of our code :

To demonstrate that our code respects the **Open/Close Principl**e  we will show you how we implement BearMan another playable character that can be played by another player and who can walk but who can also kill sheep, and revive dead wolves.

### Path to the image for the character :

Inside the `constants.h` file put an entry with the path leading to the image 

```cpp
const std::string IMG_BEARMAN = "../media/bearman.png";
```

### Create the `bearman .h and .cpp` files inside the Characters folder :

`bearman.h`

as you can see you need to override two functions :

```cpp
#pragma once
#include "playable_character.h"
#include "../constants.h"

class Bearman : public PlayableCharacter {
public:
  Bearman(SDL_Surface* window_surface_ptr);
  ~Bearman();
    void interract(InterractingObject& interractingObject,
                    const SDL_Rect&  interractingObjectPosition, 
                    const float& interractingObjectDirectionX, 
                    const float& interractingObjectDirectionY) override;
    void handle_events(SDL_Event const& event) override;
};
```

`bearman.cpp`

**the constructor**

You need to give the image, the window_surface_ptr, the speed, and you need to say that you are a Bearman, and you need to say Playable, and Predator spellt this way and only this way.

```cpp
Bearman::Bearman(SDL_Surface* window_surface_ptr_)
    : PlayableCharacter(IMG_BEARMAN, 
window_surface_ptr_,
AVERAGE_SPEED_PLAYABLE,
std::set<std::string> { "Bearman", "Alive", "Playable", "Predator") {}
```

**the handle events**

here you just need to define which event will move your character to which direction. The move function inside the parent class will do the actual movement.

Because our shepherd already take the letter keys we will take the key arrows.

```cpp
void Bearman::handle_events(SDL_Event const& event) {

  switch (event.type) {
  case SDL_KEYDOWN:
    Uint8 const* keys = SDL_GetKeyboardState(nullptr);

    if (keys[SDL_SCANCODE_UP] == 1) {
      this->timeWalking = 0;
      image_direction = Direction::UP;
    } else if (keys[SDL_SCANCODE_DOWN] == 1) {
      this->timeWalking = 0;
      image_direction = Direction::DOWN;
    } else if (keys[SDL_SCANCODE_DOWN] == 1) {
      this->timeWalking = 0;
      image_direction = Direction::LEFT;
    } else if (keys[SDL_SCANCODE_LEFT] == 1) {
      this->timeWalking = 0;
      image_direction = Direction::RIGHT;
    } else {
      image_direction = Direction::NONE;
    }
    break;
  }
}
```

### Add your character to the playground

To add him you just have to go to the application.cpp go to the loop function and add this :

```cpp
std::unique_ptr<Bearman> bearman =
      std::make_unique<Bearman>(this->window_surface_ptr_);
  this->playing_ground->add_character(std::move(bearman));
```

As you can see you can already kill sheeps. That’s because sheeps always die when they are in contact of a predator and we’ve already implemented it.



### Now you can put the revive dead wolf inside the interact function

the change takes place inside Wolf.cpp because we decided that if you need to change attributes it should take place inside the function

```cpp
void Wolf::interract(InterractingObject& interractingObject,const SDL_Rect&  interractingObjectPosition, const float& interractingObjectDirectionX, const float& interractingObjectDirectionY){
 if(collision::isColliding(this->get_position(),interractingObjectPosition)){
    if(interractingObject.has_attribute("Bearman") && this->has_attribute("Dead") && interractingObject.has_attribute("Alive")){ 
      this->withoutEatingTime = 0; //Wolf feeds so his without eating time go back to 0
      this->modify_picture(IMG_WOLF);
      this->replace_attribute("Dead", "Alive");
    }  
 }
```
