#include "scene.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

#include <iostream>

constexpr float Scene::zFar;
constexpr float Scene::zNear;
constexpr float Scene::fov;

Scene::Scene()
{

}

void Scene::initScene()
{
    projection_matrix = glm::mat4(0.5f);
    vao_list.push_back(Vao::getCube());
}

void Scene::setPerspective(int width, int height)
{
    projection_matrix = glm::mat4(1.0f);
    projection_matrix = glm::perspective(fov, (float)width/height, zNear, zFar);
}