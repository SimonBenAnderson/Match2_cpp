# MATCH 2
*A simple C++ implementation of the match up card game*

***

### How to play?
1. Follow the on screen prompts.
2. Type in the size you want the board to be.
3. Type in the amount of players.
4. Type in players names.

5. The game board will appear, you type in the row, and then the column. *eg. Input: 3,5*

### Rules!
1. Player reveal two cards, one at a time.
2. If the cards are a match, said player gets to go again.
3. If cards are not a match, then move onto next player.
4. Game completes when all cards are facing up.

***

## Folder structure
* **bin**: The output executables go here, both for the app and for any tests and spikes.
* **build**: This folder contains all object files, and is removed on a clean.
* **doc**: Any notes, like my assembly notes and configuration files, are here. I decided to create the development and production config files in here instead of in a separate config folder as they “document” the configuration.
* **include**: All project header files. All necessary third-party header files that do not exist under /usr/local/include are also placed here.
* **lib**: Any libs that get compiled by the project, third party or any needed in development. Prior to deployment, third party libraries get moved to /usr/local/lib where they belong, leaving the project clean enough to compile on our Linux deployment servers. I really use this to test different library versions than the standard.
* **spike**: I often write smaller classes or files to test technologies or ideas, and keep them around for future reference. They go here, where they do not dilute the real application’s files, but can still be found later.
* **src**: The application and only the application’s source files.
* **test**: All test code files. You do write tests, no?

***

## TODO
 [ ] Setup CMAKE builder.
 [ ] Setup Tests for specific components
 [ ] Implement a save / load feature (high score/ in game exit)

***

## Notes
#### CMAKE
 - Every direcory included in CMake, needs to have its own CMakeList.txt file
