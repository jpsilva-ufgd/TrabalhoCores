/*
* Universidade Federal da Grande Dourados
* Faculdade de Ciências Exatas e Tecnológicas
*
* Cor e suas aplicações na computação gráfica: uma visão top-down
*
* Cristopher Felipe Pinheiro
* João Paulo da Silva
* José Yan Gonçalves
* Otávio Augusto Paganotti Messias da Silva
* Pedro Henrique Araujo
* Wellington Lucas
*/

#include <glad/glad.h> // GLAD: provê os headers OpenGL e deve ser incluído antes do GLFW.
#include <GLFW/glfw3.h> // GLFW: APIs extras para gerenciamento de janelas, conextos, inputs e eventos.

#include <iostream>

#include <Triangle/Triangle.h>

namespace App
{
	// Configurações padrão.
	const char* WINDOW_TITLE = "Trabalho Cores";
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	/*
	* Callback chamado quando janela é redimensionada.
	*/
	void framebufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		// Ajusta viewport de acordo dimensões da janela.
		glViewport(0, 0, width, height);
	}

	/*
	* Processa entradas em uma janela.
	*/
	void processInput(GLFWwindow* window)
	{
		// Fecha aplicação ao apertar ESC.
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}
	}
}

int main()
{
	glfwInit();

	// Configurações da janela: https://www.glfw.org/docs/latest/window.html#window_hints
	// GLFW_DOUBLEBUFFER é true por padrão, e não precisa ser especificado.

	// Especifica versão mínima do OpenGL requerida.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core profile: funcionalidades descontinuadas não funcionam.
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Cria janela.
	GLFWwindow* window = glfwCreateWindow(App::SCREEN_WIDTH, App::SCREEN_HEIGHT, App::WINDOW_TITLE, NULL, NULL);

	if (window == nullptr)
	{
		std::cerr << "Erro ao inicializar janela OpenGL." << std::endl;
		glfwTerminate();
		return -1;
	}

	// Define janela como o contexto atual do OpenGL.
	glfwMakeContextCurrent(window);
	// Callback quando janela é redimensionada.
	glfwSetFramebufferSizeCallback(window, App::framebufferSizeCallback);

	// GLAD: Carrega implementação da biblioteca OpenGL disponível.
	// Deve ser chamado após definir o contexto.
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Erro ao inicializar OpenGL/GLAD." << std::endl;
		return -1;
	}

	// Cria objeto para desenhar.
	Triangle triangle;

	// Main loop, executa enquanto janela estiver aberta.
	while (!glfwWindowShouldClose(window))
	{
		// Processa entrada.
		App::processInput(window);

		// Limpa janela com a cor especificada.
		glClearColor(0.0f, 0.05f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Desenha.
		triangle.draw();

		// Troca buffer de renderização.
		glfwSwapBuffers(window);
		// Processa todos os eventos pendentes.
		glfwPollEvents();
	}

	// Finaliza.
	glfwTerminate();
	return 0;
}