#ifndef _GL_COMMON_CLASS_H
#define _GL_COMMON_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

class ShaderProgram
{
public:
	// ctor & dtor
	ShaderProgram(const std::string &vShaderFile, const std::string &fShaderFile);
	~ShaderProgram();

	void use();

	// Set uniform type
	bool setBool(const std::string &name, bool value) const;
	bool setInt(const std::string &name, int value) const;
	bool setFloat(const std::string &name, float value) const;

private:
	GLuint mProgramID = -1;
};




#endif