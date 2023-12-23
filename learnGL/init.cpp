#include <iostream>

// GLEW
// #define GLEW_STATIC
// #include <GL/glew.h>

// GLFW
#include <glfw3.h>


//Window Dimensions
const GLint WIDTH = 800, HEIGHT = 600;


int main()
{

    // Set all the required options for GLFW 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions 
    // glewExperimental = GL_TRUE;


    //start glfw
    glfwInit();

    //define the window size, title, and pointers to refer to the window and monitor variables
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);

    //these variables refer to the screen size after pixel ratio is factored in
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);


    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();

        return EXIT_FAILURE;
    }

    //make the window the current context
    glfwMakeContextCurrent(window);


    // Initialize GLEW to setup the OpenGL Function pointers 
    // if (GLEW_OK != glewInit())
    // {
    //     std::cout << "Failed to initialize GLEW" << std::endl;
    //     return EXIT_FAILURE;
    // }

    // Define the viewport dimensions using ratio'd screen size
    glViewport(0, 0, screenWidth, screenHeight);
    

    // Game loop 
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activiated (key pressed, 
        //mouse moved etc.) and call corresponding response functions 
        glfwPollEvents();

        // Render 
        // Clear the colorbuffer 
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw OpenGL 


        glfwSwapBuffers(window);
    }


    // Terminate GLFW, clearing any resources allocated by GLFW. 
    glfwTerminate();

    return EXIT_SUCCESS;
}


