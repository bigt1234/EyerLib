//
// Created by redknot on 2020/1/5.
//
#include "EyerGL.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "EyerGLWindowPrivate.hpp"

namespace Eyer
{

    EyerGLWindow::EyerGLWindow(EyerString _title, int _width, int _height)
    {
        title = _title;
        width = _width;
        height = _height;

        window = new EyerGLWindowPrivate();

        glfwInit();
    }

    EyerGLWindow::~EyerGLWindow()
    {
        Close();

        glfwTerminate();

        if(window != nullptr) {
            delete window;
            window = nullptr;
        }
    }

    int EyerGLWindow::Open()
    {
        if(window->window != NULL){
            Close();
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        window->window = glfwCreateWindow(width, height, title.str, NULL, NULL);
        if (window->window == NULL) {
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window->window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            return -1;
        }

        return 0;
    }

    int EyerGLWindow::Close()
    {
        if(window->window == NULL){
            return -1;
        }

        glfwDestroyWindow(window->window);
        window->window = NULL;

        return 0;
    }


    int EyerGLWindow::ShouldClose()
    {
        if(window->window == NULL){
            return -1;
        }

        int ret = glfwWindowShouldClose(window->window);

        return ret;
    }

    int EyerGLWindow::Loop()
    {
        if(window->window == NULL){
            return -1;
        }

        glfwSwapBuffers(window->window);
        glfwPollEvents();

        return 0;
    }
}

