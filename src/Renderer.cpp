
#include "SimplexGraphics/Renderer.h"

#include <iostream>

using namespace Simplex::Graphics;

float t[] = 
{
    -0.5f, -0.5f,
    0.0f, 0.0f,
    0.0f, -0.5f,

    -0.5f, -0.5f,
    -0.5f, 0.0f,
    0.0f, 0.0f
};

static const char* vertex_shader_text =
"#version 110\n"
"attribute vec2 vPos;\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(vPos, 0.0, 1.0);\n"
"}\n";

static const char* fragment_shader_text =
"#version 110\n"
"void main()\n"
"{\n"
"    gl_FragColor = vec4(1.0, 0.5, 0.5, 1.0);\n"
"}\n";

Renderer::Renderer(int width, int height) : m_width(width), m_height(height)
{
    if (!glfwInit())
    {
        std::cout << "Failed to initialize glfw" << std::endl;
    }

    m_window = glfwCreateWindow(m_width, m_height, "Simplex", NULL, NULL);
    if (!m_window)
    {
        std::cout << "Window or OpenGL context creation failed" << std::endl;
    }

    glfwMakeContextCurrent(m_window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    // Slow down the buffer swaps
    glfwSwapInterval(1);
}

Renderer::~Renderer()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

void Renderer::Render(std::vector<Simplex::Common::Object> *objects)
{
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint vpos_location;

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(t), t, GL_STATIC_DRAW);

    program = glCreateProgram();

    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);
    glAttachShader(program, vertex_shader);

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);
    glAttachShader(program, fragment_shader);

    glLinkProgram(program);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    vpos_location = glGetAttribLocation(program, "vPos");
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);





    while(!glfwWindowShouldClose(m_window))
    {
        glfwGetFramebufferSize(m_window, &m_width, &m_height);

        glViewport(0, 0, m_width, m_height);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}