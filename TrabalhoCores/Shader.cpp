#include "Shader.h"

#include <glad/glad.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

/*
* Carrega conteúdo do arquivo em uma string.
* 
* 'path' é relativo ao executável da aplicação.
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

	// Carrega conteúdo do arquivo em um buffer.
	// Nota: esse método não é eficiente para arquivos grandes.
	std::stringstream buffer;
	buffer << fileStream.rdbuf();

	// Converte em string e retorna.
	return buffer.str();
}

Shader::Shader(const std::string& shaderPath)
{
	// Carrega código fonte dos shaders.
	std::string vertexShaderSourceFile = readFile(shaderPath + ".vert");
	std::string fragmentShaderSourceFile = readFile(shaderPath + ".frag");

	// Converte em const char* por necessidade da API.
	const char* vertexShaderSource = vertexShaderSourceFile.c_str();
	const char* fragmentShaderSource = fragmentShaderSourceFile.c_str();

	// Resultado da verificação de erros.
	int status, logLength;

	// Cria o vertex shader.
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// Define código fonte do vertex shader.
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	// Compila o vertex shader.
	glCompileShader(vertexShader);

	// Verifica erros de compilação.
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
	// Define o código fonte do fragment shader.
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	// Compila o fragment shader.
	glCompileShader(fragmentShader);

	// Verifica erros de compilação.
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

	// Descarta shaders já linkados.
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::use() const
{
	glUseProgram(shaderProgram);
}
