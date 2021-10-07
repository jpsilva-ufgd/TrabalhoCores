#include "Triangle.h"

#include <glad/glad.h>

#include <iostream>
#include <vector>

// Chama construtor do shader.
Triangle::Triangle() : shader("Shaders/Triangle")
{
	// Dados dos vértices.
	float vertices[] =
	{    /* Coordenadas */     /* Cores */
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // Inferior direito
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // inferior esquerdo
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f  // Topo
	};

	// Gera o array de informações dos vértices.
	glGenVertexArrays(1, &vertexArrayObject);
	// Define o Vertex Array Object como ativo, isto é, qualquer chamada posterior
	// às funções 'glVertexAttribPointer' e 'glEnableVertexAttribArray' irão
	// referenciar esse VAO.
	glBindVertexArray(vertexArrayObject);

	// Gera o buffer para armazenar array de vértices.
	glGenBuffers(1, &vertexBufferObject);
	// Define o VBO como o ARRAY_BUFFER, que é o buffer que armazena dados de vértices.
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	// Carrega dados dos vértices no buffer.
	// GL_STATIC_DRAW define que o objeto será estático, isto é, os vértices não serão constantemente movidos.
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Atributos dos vértices
	
	/*
	* Atributo 0: coordenada.
	* 
	* Acessado no shader como:
	* layout (location = 0) in vec3 aPos;
	*/

	// Define o formato do array de dados dos vértices.
	// Neste caso, informa que o primeiro atributo '0'
	// do array acima 'vertices' possui tamanho 3 do tipo float.
	// Cada vértice possui o tamanho de 6 floats,
	// e este atributo está na posição inicial 0.
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) 0);
	// Habilita o atributo '0' cujo formato foi definido acima.
	glEnableVertexAttribArray(0);

	/*
	* Atributo 1: cor.
	*
	* Acessado no shader como:
	* layout (location = 1) in vec3 aColor;
	*/

	// Define o formato do array de dados dos vértices.
	// Neste caso, informa que o segundo atributo '1'
	// do array acima 'vertices' possui tamanho 3 do tipo float.
	// Cada vértice possui o tamanho de 6 floats,
	// e este atributo está na posição 3.
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	// Habilita o atributo '1' cujo formato foi definido acima.
	glEnableVertexAttribArray(1);

	// Remove status de ativo dos arrays acima (valor 0),
	// de modo que futuras alterações não possam acidentalmente alterar seus estados.
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
	// Define o método de rasterização do polígono como
	// preenchido (padrão) ou wireframe.
	glPolygonMode(GL_FRONT_AND_BACK, wireframe ? GL_LINE : GL_FILL);

	// Define os shaders que serão utilizados, que foram compilados no construtor.
	shader.use();
	// Carrega o array de dados dos vértices que serão renderizados.
	glBindVertexArray(vertexArrayObject);
	// Desenha 3 vértices, a partir do primeiro (0), formando um triângulo a cada 3.
	glDrawArrays(GL_TRIANGLES, 0, 3);
}