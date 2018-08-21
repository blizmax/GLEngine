#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// TODO: Research reentrancy

void GLFWErrorCallback(int error, const char* description)
{
	std::cout << description << std::endl;
}

int main()
{
	GLFWwindow* window;
	/* Setup GLFW */
	if (!glfwInit())
	{
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL

	glfwSetErrorCallback(GLFWErrorCallback);

	/* Setup GLFW Window */
	window = glfwCreateWindow(1280, 720, "GLEngine Test Application", NULL, NULL);
	if(!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	/* Setup GLFW Input */

	/* Main Loop */
	while(!glfwWindowShouldClose(window)) {
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	/* Clean Up */
	glfwTerminate();
	return 0;
}
