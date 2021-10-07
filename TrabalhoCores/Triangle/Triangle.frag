// Define a vers�o m�nima do OpenGL como 3.3, com o core profile,
// em que funcionalidades descontinuadas n�o funcionam.
#version 330 core

/*
* Vari�veis de entrada, recebidas do vertex shader.
*/
// Cor do v�rtice.
in vec3 vertexColor;

/*
* Vari�veis de sa�da.
*/
// Cor do pixel.
out vec4 FragColor;

void main()
{
//    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
	FragColor = vec4(vertexColor, 1.0);
}