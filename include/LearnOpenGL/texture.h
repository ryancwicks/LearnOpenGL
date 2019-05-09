#ifndef TEXTURE_H
#define TEXTURE_H

/**
 * @file Texture.h
 * 
 * @author Ryan Wicks
 * @brief Tool for loading Textures from the hard drive.
 * @version 0.1
 * @date 2019-05-09
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#include <string>

class Texture {
public:
    ///< the texture ID
    unsigned int ID() const;

    /**
     * @brief Construct a new Texture object
     * 
     * @param texture_path string path to vertex file
     */
    Texture (const std::string & texture_path );

private:

    unsigned int m_id;
};

#endif