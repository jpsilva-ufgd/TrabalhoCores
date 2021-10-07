// Define a vers�o m�nima do OpenGL como 3.3, com o core profile,
// em que funcionalidades descontinuadas n�o funcionam.
#version 330 core

/*
* Vari�veis de entrada.
*/
// Coordernada do v�rtice, atributo 0.
layout (location = 0) in vec3 aPos;
// Cor do v�rtice, atributo 1.
layout (location = 1) in vec3 aColor;

/*
* Vari�veis de sa�da, que ser�o passadas ao fragment shader.
*/
// Cor do v�rtice.
out vec3 vertexColor;

void main()
{
    // Posiciona v�rtice.
    gl_Position = vec4(aPos, 1.0);
    // Define cor do v�rtice para o pr�ximo shader (fragment).
    vertexColor = aColor;
}