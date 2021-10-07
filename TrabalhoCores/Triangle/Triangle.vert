// Define a versão mínima do OpenGL como 3.3, com o core profile,
// em que funcionalidades descontinuadas não funcionam.
#version 330 core

/*
* Variáveis de entrada.
*/
// Coordernada do vértice, atributo 0.
layout (location = 0) in vec3 aPos;
// Cor do vértice, atributo 1.
layout (location = 1) in vec3 aColor;

/*
* Variáveis de saída, que serão passadas ao fragment shader.
*/
// Cor do vértice.
out vec3 vertexColor;

void main()
{
    // Posiciona vértice.
    gl_Position = vec4(aPos, 1.0);
    // Define cor do vértice para o próximo shader (fragment).
    vertexColor = aColor;
}