/*
 * OpenGLContext.cpp
 *
 *  Created on: 24.07.2019
 *      Author: florian
 */

#include "OpenGLContext.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../zoe/Console.h"
#include "OpenGLIndexBufferImpl.h"
#include "OpenGLRenderImpl.h"
#include "OpenGLShaderImpl.h"
#include "OpenGLVertexArrayImpl.h"
#include "OpenGLVertexBufferImpl.h"
#include "OpenGLVertexBufferLayoutImpl.h"
#include "OpenGLTextureImpl.h"

namespace Zoe {

OpenGLContext::OpenGLContext(GLFWwindow* window): GraphicsContext(),
		windowHandle(window) {

}

void OpenGLContext::init() {
	glfwMakeContextCurrent(windowHandle);
	info("OpenGLContext:");
	info("  Vendor: \t", glGetString(GL_VENDOR));
	info("  Renderer:\t", glGetString(GL_RENDERER));
	info("  Version:\t", glGetString(GL_VERSION));
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1.0f);
}

void OpenGLContext::swapBuffers() {
	glfwSwapBuffers(windowHandle);
}

std::shared_ptr<IndexBuffer> OpenGLContext::getIndexBuffer(){
	return std::make_shared<IndexBuffer>(new OpenGLIndexBufferImpl(this));
}

std::shared_ptr<Render> OpenGLContext::getRender(){
	return std::make_shared<Render>(new OpenGLRenderImpl(this));
}

std::shared_ptr<Shader> OpenGLContext::getShader(const File& file){
	return std::make_shared<Shader>(new OpenGLShaderImpl(file,this));
}

std::shared_ptr<VertexArray> OpenGLContext::getVertexArray(){
	return std::make_shared<VertexArray>(new OpenGLVertexArrayImpl(this));
}

std::shared_ptr<VertexBuffer> OpenGLContext::getVertexBuffer(){
	return std::make_shared<VertexBuffer>(new OpenGLVertexBufferImpl(this));
}

std::shared_ptr<VertexBufferLayout> OpenGLContext::getVertexBufferLayout(){
	return std::make_shared<VertexBufferLayout>(new OpenGLVertexBufferLayoutImpl());
}

std::shared_ptr<Texture> OpenGLContext::getTexture(unsigned int width, unsigned int height){
	return std::make_shared<Texture>(new OpenGLTextureImpl(this,width,height));
}

std::shared_ptr<Texture> OpenGLContext::getTexture(const File& file){
	return std::make_shared<Texture>(new OpenGLTextureImpl(this,file));
}

}

