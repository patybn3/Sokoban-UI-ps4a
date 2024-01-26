# PS2a: Sokoban

## Contact
Name: Patricia Antlitz
Section:
Time to Complete: 4 hours (this was fast, I wish I started earlier because Im literally a week late)


## Description
This project diplays a Sokoman game board based on the entries on the level files under the /sokoban directory. The game presents a classic Sokoban pussle where the player's objective is to push boxes onto storage locations while navigating around obstacles. The game logic has not been implemented yet.

### Features
- Level-Based gameplay: the sokoban game can read level data from text files and generate a playable game board.
- Player movement: The player does not move up, down, left and right currently, the only thing implemented was the change of the player images when clicking on the arrows.

### Memory
The project uses a teo-dimentional grid (matrix) to represent the game board. Level data is stores as characters with this grid, with each character representing a specific game element (e.g., walls, empty spaces, boxes, etc.). Smart pointers are not used in this implementation, but this is just a very basic, initial version. Instead, the project relies on stardard data structures to manage and manipulate level data.

### Lambdas
Although this project makes use of some library functions from <algorithm> (its was not necessary to include <algorithm> to make them work), it does not explicity use lambda expressions, but again, this is just displaying the levels. This might be implemented on ps4b

### Issues
- Data Structure and Logic: Implementing the data structure for the game board and the game logic itself seemed to be one of the initial challenges. Ensuring that the player's position, box positions, and storage locations are accurately represented and updated was a key issue.
- Loading images and textures: Loading and displaying images and textures in the game was another recurring challenge. Handling image loading, texture management, and displaying sprites with the apporpriate textures required multiple iterations to get right.
- Refactoring and redundancy: refactoring the code to eliminate redundancy and ensure that it adheres to best practices was an ongoing process. This included addressing issues realted to texture loading and using the appropriate data structures.

### Extra Credit
Anything special you did.  This is required to earn bonus points.


## Acknowledgements
class' materials and videos
