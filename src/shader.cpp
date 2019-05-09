#include "LearnOpenGL/shader.h"

#include <glad/glad.h> //includes all the required openGL libraries

#include <fstream>
#include <sstream>
#include <iostream>

unsigned int Shader::ID() const {
    return m_id;
}

Shader::Shader (const std::string & vertex_path, const std::string & fragment_path) {

    //Load the shaders
    std::string vertex_code, fragment_code;
    std::ifstream vertex_shader_file, fragment_shader_file;
    //enable exceptions
    vertex_shader_file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fragment_shader_file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        vertex_shader_file.open(vertex_path.c_str());
        fragment_shader_file.open(fragment_path.c_str());
        std::stringstream vertex_shader_stream, fragment_shader_stream;
        vertex_shader_stream << vertex_shader_file.rdbuf();
        fragment_shader_stream << fragment_shader_file.rdbuf();
        vertex_shader_file.close();
        fragment_shader_file.close();
        vertex_code = vertex_shader_stream.str();
        fragment_code = fragment_shader_stream.str();
    } catch (std::ifstream::failure e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ"<< std::endl;
    }

    //Compile the shaders
    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    const char * vertex_code_array (vertex_code.c_str());
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource (vertex, 1, &vertex_code_array, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, & success);
    if (!success) {
        glGetShaderInfoLog (vertex, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    const char * fragment_code_array (fragment_code.c_str());
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragment_code_array, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog (fragment, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    m_id = glCreateProgram();
    glAttachShader(m_id, vertex);
    glAttachShader(m_id, fragment);
    glLinkProgram(m_id);
    glGetProgramiv(m_id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(m_id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use() {
    glUseProgram(m_id);
}

void Shader::setBool(const std::string &name, bool value) const {         
    glUniform1i(glGetUniformLocation(m_id, name.c_str()), (int)value); 
}

void Shader::setInt(const std::string &name, int value) const { 
    glUniform1i(glGetUniformLocation(m_id, name.c_str()), value); 
}

void Shader::setFloat(const std::string &name, float value) const { 
    glUniform1f(glGetUniformLocation(m_id, name.c_str()), value); 
}