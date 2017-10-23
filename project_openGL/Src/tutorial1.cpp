#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

#include "glCommonClass.h"

/* General comman function */

GLuint CreateVBO(const std::vector<float> &init_data)
{
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, init_data.size() * sizeof(float), init_data.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return VBO;
}

GLuint CreateEBO(const std::vector<unsigned int> &init_data)
{
	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, init_data.size() * sizeof(unsigned int), init_data.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	return EBO;
}



/*	Programe specific function */
void ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

GLuint CreateVAO(GLuint VBO, GLuint EBO)
{
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Unbind buffers
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	return VAO;
};



int main()
{
	// Set window configuration
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a 800 * 600 window
	GLFWwindow *window = glfwCreateWindow(800, 600, "LearnGL", NULL, NULL);
	if (window == NULL)
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



	// Setup triangle vertice
	std::vector<float> vertices = {
		0.5f,  0.5f, 0.0f,  // top right
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left   
	};

	// Setup indices
	std::vector<unsigned int> indices =
	{
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};


	GLuint triangle_VBO = CreateVBO(vertices);
	GLuint EBO = CreateEBO(indices);
	GLuint VAO = CreateVAO(triangle_VBO, EBO);

	ShaderProgram program("D:\\OpenGL_learn\\project_openGL\\Src\\Shader\\vertex_shader.vs", "D:\\OpenGL_learn\\project_openGL\\Src\\Shader\\fragment_shader.fs");
	

	while (!glfwWindowShouldClose(window))
	{
		ProcessInput(window);

		glClearColor(0.0f, 0.3f, 0.2f, 0.3f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw call
		program.use();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	// Give the resources back
	glfwTerminate();
	return 0;
}


