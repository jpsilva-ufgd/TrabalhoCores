#include "Triangle.h"

#include <glad/glad.h>

#include <iostream>
#include <vector>

// Chama construtor do shader.
Triangle::Triangle() : shader("Shaders/Triangle")
{
	// Dados dos v�rtices.
	float vertices[] =
	{    /* Coordenadas */     /* Cores */
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // Inferior direito
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // inferior esquerdo
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f  // Topo
	};

	// Gera o array de informa��es dos v�rtices.
	glGenVertexArrays(1, &vertexArrayObject);
	// Define o Vertex Array Object como ativo, isto �, qualquer chamada posterior
	// �s fun��es 'glVertexAttribPointer' e 'glEnableVertexAttribArray' ir�o
	// referenciar esse VAO.
	glBindVertexArray(vertexArrayObject);

	// Gera o buffer para armazenar array de v�rtices.
	glGenBuffers(1, &vertexBufferObject);
	// Define o VBO como o ARRAY_BUFFER, que � o buffer que armazena dados de v�rtices.
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	// Carrega dados dos v�rtices no buffer.
	// GL_STATIC_DRAW define que o objeto ser� est�tico, isto �, os v�rtices n�o ser�o constantemente movidos.
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Atributos dos v�rtices
	
	/*
	* Atributo 0: coordenada.
	* 
	* Acessado no shader como:
	* layout (location = 0) in vec3 aPos;
	*/

	// Define o formato do array de dados dos v�rtices.
	// Neste caso, informa que o primeiro atributo '0'
	// do array acima 'vertices' possui tamanho 3 do tipo float.
	// Cada v�rtice possui o tamanho de 6 floats,
	// e este atributo est� na posi��o inicial 0.
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) 0);
	// Habilita o atributo '0' cujo formato foi definido acima.
	glEnableVertexAttribArray(0);

	/*
	* Atributo 1: cor.
	*
	* Acessado no shader como:
	* layout (location = 1) in vec3 aColor;
	*/

	// Define o formato do array de dados dos v�rtices.
	// Neste caso, informa que o segundo atributo '1'
	// do array acima 'vertices' possui tamanho 3 do tipo float.
	// Cada v�rtice possui o tamanho de 6 floats,
	// e este atributo est� na posi��o 3.
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	// Habilita o atributo '1' cujo formato foi definido acima.
	glEnableVertexAttribArray(1);

	// Remove status de ativo dos arrays acima (valor 0),
	// de modo que futuras altera��es n�o possam acidentalmente alterar seus estados.
	glBindBuffer(GL_ARRAY_BUFFER, 0); // VBO
	glBindVertexArray(0); // VAO
}

Triangle::~Triangle()
{
	// Descarta recursos ao destruir objeto.
	glDeleteVertexArrays(1, &vertexArrayObject);
	glDeleteBuffers(1, &vertexBufferObject);
}

void Triangle::draw() const
{
	// Define o m�todo de rasteriza��o do pol�gono como
	// preenchido (padr�o) ou wireframe.
	glPolygonMode(GL_FRONT_AND_BACK, wireframe ? GL_LINE : GL_FILL);

	// Define os shaders que ser�o utilizados, que foram compilados no construtor.
	shader.use();
	// Carrega o array de dados dos v�rtices que ser�o renderizados.
	glBindVertexArray(vertexArrayObject);
	// Desenha 3 v�rtices, a partir do primeiro (0), formando um tri�ngulo a cada 3.
	glDrawArrays(GL_TRIANGLES, 0, 3);
}