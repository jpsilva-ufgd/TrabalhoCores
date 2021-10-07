// Define a versão mínima do OpenGL como 3.3, com o core profile,
// em que funcionalidades descontinuadas não funcionam.
#version 330 core

/*
* Variáveis de entrada, recebidas do vertex shader.
*/
// Cor do vértice.
in vec3 vertexColor;

/*
* Variáveis de saída.
*/
// Cor do pixel.
out vec4 FragColor;

void main()
{
//    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
	FragColor = vec4(vertexColor, 1.0);
}