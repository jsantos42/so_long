# so_long

![screenshot](screenshot.png)

The program has two possible compiling modes.
 - MANDATORY PART: it's just the player with the collectibles. The moves counter appears on the shell.
 - BONUS PART: there's two enemies patrolling the map; the player char rotates when it changes side (very basic sprite) and the moves counter appears on the game window.

To run the program:
 - use the Makefile to compile the program along with the .dylib of MiniLibX. You can either run make or make bonus.\*
 - run "./so_long <valid map.ber file>"

\*note that to run the bonus after compiling only the mandatory part you have to do make rebonus
 
If using CLion or other editor that uses CMake:
- you still have to first compile with the Makefile in order to get the libmlx.dylib file
- on the Run/Debug configurations, add your working directory 
- on the Run/Debug configurations, add "DYLD_LIBRARY_PATH=/Users/jas/Desktop/42/so_long/" as an environment variable
