#pragma once

// special keys
const int SPECIAL_KEY = 224;
const int KB_UP = 73;
const int KB_DOWN = 74;
const int KB_LEFT = 71;
const int KB_RIGHT = 72; 
const int KB_SPACE = 57;

// game objects
const char digger = '/';
const char monster = '!';
const char diamond = 'D';
const char wall = '#';
const char stone = '@';
const char gift = '+';
const char space = ' ';

// size of the game
const float Hight = 800;
const float Width = 1400;
const  float menu = 50;
// other const
const int LIVE = 3;
const int digSpeed = 5000;
const int monSpeed = 100;

// direction
enum direction {up, down, right, left};
