#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include <iostream>

void ProcessInput(GLFWwindow *window);

int main()
{
	// Set window configuration
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a 800 * 600 window
	GLFWwindow *window = glfwCreateWindow(800, 600, "LearnGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << " Create window failed \n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Initailize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD \n";
		return -1;
	}

	// Set viewport
	glViewport(0, 0, 800, 600);

	// Set callback to resize viewport everytime the size of window changes
	glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); });

	while (!glfwWindowShouldClose(window))
	{
		ProcessInput(window);

		glClearColor(0.3f, 0.3f, 0.2f, 0.3f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	// Give the resources back
	glfwTerminate();
	return 0;
}


void ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}