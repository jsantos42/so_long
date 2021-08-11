# so_long

To run the program:
 - use the Makefile to compile the program along with the .dylib of MiniLibX.
 - run "./so_long <valid map.ber file>"
 
If using CLion or other editor that uses CMake:
- you still have to first compile with the Makefile in order to get the libmlx.dylib file.
- on the Run/Debug configurations, add your working directory 
- on the Run/Debug configurations, add "DYLD_LIBRARY_PATH=/Users/jas/Desktop/42/so_long/" as an environment variable