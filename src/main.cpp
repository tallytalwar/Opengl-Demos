#include <cstdio>

#define GL_GLEXT_PROTOTYPES
#include <GLFW/glfw3.h>

#include <glbinding/gl/gl.h>
#include <glbinding/Binding.h>

using namespace gl;

int main(int argc, char* argv[]) {

    const int width = 800;
    const int height = 600;

    // Load GLFW and Create a Window
    GLFWwindow* main_window = nullptr;
    glfwInit();
    glfwWindowHint(GLFW_SAMPLES, 2);
    main_window = glfwCreateWindow(width, height, "Opengl Demos", nullptr, nullptr);

    // Check for Valid Context
    if (!main_window) {
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(main_window);

    // Create Context and Load OpenGL Functions
    glbinding::Binding::initialize();
    fprintf(stderr, "OpenGL %s\n", glGetString(GL_VERSION));
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    //Rendering Loop
    while (!glfwWindowShouldClose(main_window)) {
        if (glfwGetKey(main_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(main_window, true);
        }

        // Background Fill Color
        glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Flip Buffers and Draw
        glfwSwapBuffers(main_window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
