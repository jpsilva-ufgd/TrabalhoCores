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
	* Armazena estado dos v�rtices do objeto.
	* Cont�m um ou mais VBOs (Vertex Buffer Object), os quais cont�m os
	* dados dos v�rtices em si.
	*
	* Este array � referenciado toda vez que o objeto for renderizado,
	* para recuperar os dados dos v�rtices que est�o na mem�ria da GPU.
	*/
	unsigned int vertexArrayObject;

	/* VBO - Vertex Buffer Object
	* Array com os dados dos v�rtices na GPU.
	*/
	unsigned int vertexBufferObject;

public:
	/*
	* Se o objeto ser� desenhado como wireframe.
	*/
	bool wireframe = false;

	Triangle();

	~Triangle();

	/*
	* Desenha objeto.
	*/
	void draw() const;
};
