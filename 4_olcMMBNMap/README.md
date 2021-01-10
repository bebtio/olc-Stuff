Author: Alberto Heras

Date: 05 January 2021

The goal here is to load a map from megaman battle network and eventually place characters in it and have them walk around like in the actual game.

9 January 2021: Added Animation class that can store a sequence of frames from a sprite sheet to played back  later.  Not sure if I want to add state for cycling through frames at a certain rate within the Animation class or if I want the owner of Animations to do this.  Yeah, I might make another class called CharacterAnimations or something that has a map of Animations for different actions. Took inspiratino from [matt-hayward](https://github.com/matt-hayward/olcPGEX_AnimatedSprite), thanks for the addState idea. I turned it into addFrame for my animation class.