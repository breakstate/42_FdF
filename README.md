# 42_FdF
### Parent school: Ecole 42
### School: WeThinkCode_ Johannesburg
### Year: 1
### Semester: 1
### Branch: Graphics

#### Summary:
The aim of this project is to create a a simplified graphical representation of a relief landscape / a very basic 3d graphics engine.

#### Learning opportunities:
- Basics of graphics programming
- Using graphics library
- Input/Event handling
- Computer line-drawing algorithms

#### Instructions
- Executable to be named fdf
- You must submit a Makefile
- Use of libft project allowed and encouraged
- No global variables
- You must use miniLibX (42 graphics library)
- Project must be Norminette compliant (42 C programming standard)
- Handle errors - project must not quit in an unexpected manner (Seg fault, bus error, double free, etc)
- No memory leaks
- Include author file 

##### Allowed functions: 
- open, read, write, close
- malloc, free
- perror, strerror
- exit
- All functions in math library (-lm and man 3 math)
- All the functions defined in the miniLibX library

#### Overview:
This project is about creating a simplified graphics wireframe. With the use of x, y, z values displayed as vertices - landscapes or basic 3D planes with points of varying heights are displayed in a window. The values of the vertices are read from a file. The x and y values are determines from the position and line of the value in the file, and the numerical value itself determines the height or z axis. 

#### Usage:
Run binary from command line, giving a valid file as a command-line paramater.
