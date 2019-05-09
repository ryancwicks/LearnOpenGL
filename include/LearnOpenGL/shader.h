#ifndef SHADER_H
#define SHADER_H

/**
 * @file shader.h
 * 
 * @author Ryan Wicks
 * @brief Tool for loading shaders from the hard drive and compiling them. from https://learnopengl.com/Getting-started/Shaders
 * @version 0.1
 * @date 2019-05-09
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#include <string>

class Shader {
public:
    ///< the program ID
    unsigned int ID() const;

    /**
     * @brief Construct a new Shader object
     * 
     * @param vertex_path string path to vertex file
     * @param fragment_path string path to fragment file 
     */
    Shader (const std::string & vertex_path, const std::string & fragment_path );

    /**
     * @brief use or activate the shader
     */
    void use();

    /**
     * @brief Set the Bool object set a uniform object in the shader
     * 
     * @param name name of variable
     * @param value value of variable
     */
    void setBool( const std::string & name, bool value) const;

    /**
     * @brief Set an Int object in the shader
     * 
     * @param name variable name
     * @param value variable value
     */
    void setInt (const std::string & name, int value) const;

    /**
     * @brief Set the Float object in the shader
     * 
     * @param name variable name
     * @param value variable value
     */
    void setFloat (const std::string & name, float value) const;

private:

    unsigned int m_id;
};

#endif