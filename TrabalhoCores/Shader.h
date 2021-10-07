#pragma once

#include <string>

/*
* Carrega e compila programas de shader.
*/
class Shader
{
private:
	/*
	* ID do programa que cont�m os shaders compilados.
	*/
	unsigned int shaderProgram;

public:
	/*
	* Carrega e compila os shaders a partir dos c�digos fontes especificados.
	* 
	* 'shaderPath' deve referenciar dois arquivos que cont�m os vertex e fragment shaders,
	* com a extens�o .vert e .frag, respectivamente.
	* Por exemplo, ao passar o valor "shaders/triangle", dever�o existir os arquivos fonte
	* "shaders/triangle.vert" e "shaders/triangle.frag".
	*/
	Shader(const std::string& shaderPath);

	/*
	* Ativa este programa de shader para uso no frame atual.
	*/
	void use() const;
};