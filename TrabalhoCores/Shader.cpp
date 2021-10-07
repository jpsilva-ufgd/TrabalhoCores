#include "Shader.h"

#include <glad/glad.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

/*
* Carrega conte�do do arquivo em uma string.
* 
* 'path' � relativo ao execut�vel da aplica��o.
*/
std::string readFile(const std::string& path)
{
	// Abre arquivo.
	std::ifstream fileStream(path);

	// Verifica se foi aberto corretamente.
	if (!fileStream.is_open())
	{
		std::cerr << "[ERROR] Shader file not found: " << path << std::endl;
		return "";
	}

	// Carrega conte�do do arquivo em um buffer.
	// Nota: esse m�todo n�o � eficiente para arquivos grandes.
	std::stringstream buffer;
	buffer << fileStream.rdbuf();

	// Converte em string e retorna.
	return buffer.str();
}

Shader::Shader(const std::string& shaderPath)
{
	// Carrega c�digo fonte dos shaders.
	std::string vertexShaderSourceFile = readFile(shaderPath + ".vert");
	std::string fragmentShaderSourceFile = readFile(shaderPath + ".frag");

	// Converte em const char* por necessidade da API.
	const char* vertexShaderSource = vertexShaderSourceFile.c_str();
	const char* fragmentShaderSource = fragmentShaderSourceFile.c_str();

	// Resultado da verifica��o de erros.
	int status, logLength;

	// Cria o vertex shader.
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// Define c�digo fonte do vertex shader.
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	// Compila o vertex shader.
	glCompileShader(vertexShader);

	// Verifica erros de compila��o.
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);

	if (!status)
	{
		// Recupera quantidade de caracteres na mensagem de erro.
		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &logLength);
		// Aloca vetor para armazenar mensagem de erro.
		std::vector<char> vertexShaderLog(logLength);
		// Recupera mensagem de erro.
		glGetShaderInfoLog(vertexShader, logLength, nullptr, &vertexShaderLog[0]);
		// Exibe erro.
		std::cerr << "[ERROR] VertexShader: " << shaderPath << std::endl;
		std::cerr << &vertexShaderLog[0] << std::endl;
	}

	// Cria o fragment shader.
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// Define o c�digo fonte do fragment shader.
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	// Compila o fragment shader.
	glCompileShader(fragmentShader);

	// Verifica erros de compila��o.
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);

	if (!status)
	{
		// Recupera quantidade de caracteres na mensagem de erro.
		glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &logLength);
		// Aloca vetor para armazenar mensagem de erro.
		std::vector<char> fragmentShaderLog(logLength);
		// Recupera mensagem de erro.
		glGetShaderInfoLog(fragmentShader, logLength, nullptr, &fragmentShaderLog[0]);
		// Exibe erro.
		std::cerr << "[ERROR] FragmentShader: " << shaderPath << std::endl;
		std::cerr << &fragmentShaderLog[0] << std::endl;
	}

	// Cria o programa de shaders.
	shaderProgram = glCreateProgram();
	// Anexa vertex shader ao programa.
	glAttachShader(shaderProgram, vertexShader);
	// Anexa fragment shader ao programa.
	glAttachShader(shaderProgram, fragmentShader);
	// Linka todos os shaders anexados em um programa.
	glLinkProgram(shaderProgram);

	// Verifica erros de linkagem.
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);

	if (!status)
	{
		// Recupera quantidade de caracteres na mensagem de erro.
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &logLength);
		// Aloca vetor para armazenar mensagem de erro.
		std::vector<char> shaderProgramLog(logLength);
		// Recupera mensagem de erro.
		glGetProgramInfoLog(shaderProgram, logLength, nullptr, &shaderProgramLog[0]);
		// Exibe erro.
		std::cerr << "[ERROR] ShaderProgram: " << shaderPath << std::endl;
		std::cerr << &shaderProgramLog[0] << std::endl;
	}

	// Descarta shaders j� linkados.
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::use() const
{
	glUseProgram(shaderProgram);
}
