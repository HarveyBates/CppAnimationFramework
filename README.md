# CppAnimationFramework
A C++ animation framework to create visualisations of data and mathematical functions for use in videos and as a standalone interactive framework. 

## About

This framework is build upon [raylib](https://www.raylib.com/index.html) a cross platform videogaming library which supports a number of languages through various bindings. The current system uses Apples [Metal](https://developer.apple.com/metal/) to access the GPU; however, [OpenGL](https://www.opengl.org/) could also be implemented in its place on other operating systems.

## Installation

### Mac

#### Homebrew & XCode

The easiest way to get up and running on a Mac is to install [homebrew](https://brew.sh/) by navigating to this [webpage](https://brew.sh/) and following the instructions. Thereafter you can now run the following command in your terminal.

```bash
brew install raylib
```

Next if you haven't already, install [XCode](https://developer.apple.com/xcode/) on your machine by following this [link](https://developer.apple.com/xcode/).

Once installed, launch XCode and follow these steps:

1. Select MacOS
2. Select Command Line Tool and click Next
3. Name your project
4. Choose C++ as your desired language

This should open your new XCode project. Next we need to link raylib and Metal (or OpenGL) to our XCode project. 

1. Double click on the project name in the folder section on the left hand side of the window. This should open your `.xcodeproj` file. 
2. In the tabs across the top of your window choose "Build Settings"
3. Select both "All" and "Combined"
4. Under "Search Paths" choose "Header Search Paths" and add the folder "/usr/local/include"
5. Now select the "Build Phases" tab and navigate to "Link Binary With Libraries"
6. Click the "+" icon and search for "Metal" or "OpenGL" depending on which framework you wish to access you GPU with
7. Next we need to link to raylib by again clicking the "+" and selecting "'Add Other-> Add Files'"
8. Once a finder window has opened press "CMD + Shift + G" to open the search bar and enter "/usr/local/Cellar/raylib/"
9. Navigate to the "lib" directory and select this file `libraylib.VerNum.dylib` where "VerNum" is your version number
10. Once selected click add and it will link raylib to XCode

To test your installation open the file `main.cpp` and enter the [sample code](https://www.raylib.com/examples.html) from raylib and press CMD + r to build and run the program. 