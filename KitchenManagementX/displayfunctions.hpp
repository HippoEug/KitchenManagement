#pragma once

#include <stdexcept>

#define GLFW_INCLUDE_GLU
#include <GLFW\glfw3.h>

#include "imgui\imgui.h"
#include "imgui\imgui_impl_glfw.h"

// Basic Data Types, where Struct behaves like a Class except members and base classes are public by default
struct float3_rs {
	float x, y, z;
};

struct float2_rs {
	float x, y;
};

struct rect_rs {
	float x, y;
	float w, h;

	// Create new rect within original boundaries with give aspect ration
	rect_rs adjust_ratio(float2_rs size) const {
		auto H = static_cast<float>(h), W = static_cast<float>(h) * size.x / size.y;
		if (W > w) {
			auto scale = w / W;
			W *= scale;
			H *= scale;
		}

		return{ x + (w - W) / 2, y + (h - H) / 2, W, H };
	}
};

class window_rs
{
public:
	void onCreate(int width, int height, const char* title) {
		_width = width;
		_height = height;

		// Initialize the library
		if (!glfwInit()) {
			throw std::runtime_error("GLFW INIT FAILED");
			return;
		}

		// Create a windowed mode window and the OpenGL context
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Prevent window from resizing by user
		win = glfwCreateWindow(width, height, title, nullptr, nullptr);
		// Create a full screen window, no border or decorations
		// win = glfwCreateWindow(width, height, title, glfwGetPrimaryMonitor(), NULL);

		if (!win) {
			glfwTerminate();
			throw std::runtime_error("Could not open OpenGL window, please check your graphic drivers or use the textual SDK tools");
		}

		glfwMakeContextCurrent(win); // Make the window's context current
		glfwSetWindowUserPointer(win, this); // Sets user-defined pointer of the specified window
	}

	float width() const {
		return float(_width);
	}

	float height() const {
		return float(_height);
	}

	operator bool() {
		glPopMatrix();
		// GLFW windows are double buffered by default, a front buffer and a back buffer
		// Front buffer is the one being displayed, while the back buffer is the one being rendered
		// When the entire frame has been rendered, it is time to swap the back and the front buffers,
		// in order to display what has been rendered and begin rendering a new frame
		glfwSwapBuffers(win); // Swap front and back buffers
		glfwSwapInterval(1); // VSync, FPS Limit: 60

		auto res = !glfwWindowShouldClose(win);

		// Event Processing: GLFW needs to communicate with the system to receive events and show the application has not locked up
		// glfwPollEvents processes only those events that have already been received and then returns immediately
		glfwPollEvents(); // Poll for and process events
		glfwGetFramebufferSize(win, &_width, &_height); // For directly retrieving the current size of the framebuffer of aindow

														// Clear the framebuffer
		glClear(GL_COLOR_BUFFER_BIT); // Render here
		glViewport(0, 0, _width, _height);

		// Draw the images
		glPushMatrix();
		glfwGetWindowSize(win, &_width, &_height);
		glOrtho(0, _width, _height, 0, -1, +1);

		return res;
	}

	~window_rs() {
		glfwDestroyWindow(win); // Window destroyed when no longer needed
		glfwTerminate(); // Terminates te GLFW library, destroying any remaining window, monitor or objects etc
	}

	operator GLFWwindow*() {
		return win;
	}

private:
	GLFWwindow * win;
	int _width, _height;
};
