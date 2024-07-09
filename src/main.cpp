#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    GLFWwindow* window;

    /* Инициализация GLFW */
    if (!glfwInit())
    {
        std::cerr << "Ошибка при инициализации GLFW" << std::endl;
        return -1;
    }

    /* Создание окна */
    window = glfwCreateWindow(800, 600, "Пример GLFW", NULL, NULL);
    if (!window)
    {
        std::cerr << "Ошибка при создании окна GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Делаем текущим контекст окна */
    glfwMakeContextCurrent(window);

    /* Инициализация GLAD */
    if (!gladLoadGL())
    {
        std::cerr << "Не удалось загрузить GLAD!" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Вывод версии OpenGL */
    std::cout << "OpenGL " << GLVersion.major << "." << GLVersion.minor << std::endl;

    glClearColor(0, 1, 0, 1); // Жёлтый фон

    /* Основной цикл программы */
    while (!glfwWindowShouldClose(window))
    {
        /* Отрисовка здесь */

        glClear(GL_COLOR_BUFFER_BIT);

        /* Обмен буферов */
        glfwSwapBuffers(window);

        /* Обработка событий */
        glfwPollEvents();
    }

    /* Завершение работы GLFW */
    glfwTerminate();
    return 0;
}
