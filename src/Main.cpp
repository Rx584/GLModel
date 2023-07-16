#define GLEW_STATIC
#define WIDTH 1920
#define HEIGHT 1080
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

void KeyCallback(GLFWwindow *window,int key,int scancode,int action,int mode)
{
    if(key==GLFW_KEY_ESCAPE)
    {
        glfwSetWindowShouldClose(window,GL_TRUE);
    }
}

void RenderWindowBackground()
{
    glClearColor(0,1,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(WIDTH,HEIGHT,"OpenGL Window",nullptr,nullptr);
    if(window==nullptr)
    {
        std::cout<<"Fail to create GL Window";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glewExperimental=GL_TRUE;
    if(glewInit()!=GLEW_OK)
    {
        std::cout<<"Fail to init GLEW";
        return -1;
    }
    int width,height;
    glfwGetFramebufferSize(window,&width,&height);
    glViewport(0,0,width,height);
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glfwSetKeyCallback(window,KeyCallback);
        RenderWindowBackground();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}