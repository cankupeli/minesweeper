# minesweeper

##Functionality
  ##Flags##
    Using the right mouse click the user can flag a board tile as a potential bomb,
    this will be indicated with a flagged symbol and render the tile unflippable until it is unflipped.
  ##Flipping tiles##
    Left clicking an unflagged and unflipped tile will flip it. 
    If the tile is valueless, that is a tile with no surrounding bombs, the flipping will cascading and flip surrouding tiles until a numbered tile is flipped.
##The game has 3 modes
  ##Easy##
    9x9 board
    10 mines
    10 flags
  ##Medium##
    16x16 board
    40 mines
  ##Hard##
    24x24 board
    99 mines
##Sound##
  Each round is accompanied with a background soundtrack, a victory sound-affect upon victory and defeat sound-affect upon defeat. 
##Flags##
  The amount of available flags is shown above the board, the amount of total flags is equal to that of the amount of mines for the current mode.
##Timer##
  Each round has a timer to indicate how long the round has been active, the timer stops updating at victory or defeat.
##Defeat##
  Detonating the bomb will lead to a defeat and unflips all tiles.
##Victory##
  Flipping all non-bomb tiles will lead to a victory
