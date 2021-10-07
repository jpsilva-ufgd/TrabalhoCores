#pragma once

#include <string>

/*
* Carrega e compila programas de shader.
*/
class Shader
{
private:
	/*
	* ID do programa que contém os shaders compilados.
	*/
	unsigned int shaderProgram;

public:
	/*
	* Carrega e compila os shaders a partir dos códigos fontes especificados.
	* 
	* 'shaderPath' deve referenciar dois arquivos que contém os vertex e fragment shaders,
	* com a extensão .vert e .frag, respectivamente.
	* Por exemplo, ao passar o valor "shaders/triangle", deverão existir os arquivos fonte
	* "shaders/triangle.vert" e "shaders/triangle.frag".
	*/
	Shader(const std::string& shaderPath);

	/*
	* Ativa este programa de shader para uso no frame atual.
	*/
	void use() const;
};