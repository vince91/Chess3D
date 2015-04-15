#ifndef __vao_h_
#define __vao_h_

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#define __gl_h_
#else
#include <GL/glew.h>
#endif

#include <glm/glm.hpp>

class Vao
{
public:
    GLuint getId() const { return id; }
    GLsizei getVertexCount() const { return vertex_count; }
    static Vao getCube();
    
private:
    GLuint id;
    GLsizei vertex_count;
    glm::mat4 model_matrix;
    
};


#endif