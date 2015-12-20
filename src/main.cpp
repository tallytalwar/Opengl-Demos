#include <iostream>

#define GL_GLEXT_PROTOTYPES
#include <GLFW/glfw3.h>

int main(int argc, char* argv[]) {

    int width = 800;
    int height = 600;

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* main_window = nullptr;

    // Initialize the windowing library
    if (!glfwInit()) {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    glfwWindowHint(GLFW_SAMPLES, 2);
    main_window = glfwCreateWindow(width, height, "Opengl Demos", nullptr, nullptr);
    if (!main_window) {
        glfwTerminate();
        return 1;
    }

    // Make the main_window's context current
    glfwMakeContextCurrent(main_window);

    // Set input callbacks
    //glfwSetWindowSizeCallback(main_window, window_size_callback);
    //glfwSetMouseButtonCallback(main_window, mouse_button_callback);
    //glfwSetCursorPosCallback(main_window, cursor_pos_callback);
    //glfwSetScrollCallback(main_window, scroll_callback);
    //glfwSetKeyCallback(main_window, key_callback);
    //glfwSetDropCallback(main_window, drop_callback);

    // Setup graphics
    // Any Opengl Inits


    double lastTime = glfwGetTime();

    glfwSwapInterval(0);

    if (!main_window) { std::cout<<"WHat??"; }

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(main_window)) {

        double currentTime = glfwGetTime();
        double delta = currentTime - lastTime;
        lastTime = currentTime;

        // Render
        // My Update and Render calls

        // Swap front and back buffers
        glfwSwapBuffers(main_window);
    }

    glfwTerminate();
    return 0;
}
