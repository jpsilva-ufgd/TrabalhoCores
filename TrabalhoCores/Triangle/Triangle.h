#pragma once

#include <Shader.h>

class Triangle
{
private:
	/*
	* Shader para renderizar o objeto.
	*/
	Shader shader;

	/*
	* VAO - Vertex Array Object
	* Armazena estado dos vértices do objeto.
	* Contém um ou mais VBOs (Vertex Buffer Object), os quais contém os
	* dados dos vértices em si.
	*
	* Este array é referenciado toda vez que o objeto for renderizado,
	* para recuperar os dados dos vértices que estão na memória da GPU.
	*/
	unsigned int vertexArrayObject;

	/* VBO - Vertex Buffer Object
	* Array com os dados dos vértices na GPU.
	*/
	unsigned int vertexBufferObject;

public:
	/*
	* Se o objeto será desenhado como wireframe.
	*/
	bool wireframe = false;

	Triangle();

	~Triangle();

	/*
	* Desenha objeto.
	*/
	void draw() const;
};
