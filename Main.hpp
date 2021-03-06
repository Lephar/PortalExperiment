#pragma once

//#define VULKAN_HPP_NO_EXCEPTIONS
#define GLFW_INCLUDE_VULKAN
#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define GLM_FORCE_SWIZZLE
#define GLM_FORCE_RADIANS
#define GLM_FORCE_RIGHT_HANDED
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES

#include <array>
#include <limits>
#include <vector>
#include <chrono>
#include <memory>
#include <fstream>
#include <iostream>

#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <tinygltf/tiny_gltf.h>

namespace svh {
	struct Controls {
		uint8_t observer;
		double_t mouseX;
		double_t mouseY;
		float_t deltaX;
		float_t deltaY;
		uint8_t keyW;
		uint8_t keyA;
		uint8_t keyS;
		uint8_t keyD;
		uint8_t keyQ;
		uint8_t keyE;
		uint8_t keyR;
		uint8_t keyF;
	};

	struct State {
		uint32_t currentImage;
		uint16_t frameCount;
		float_t timeDelta;
		float_t checkPoint;
		std::chrono::time_point<std::chrono::system_clock> previousTime;
		std::chrono::time_point<std::chrono::system_clock> currentTime;
	};

	struct Details {
		uint32_t imageCount;
		uint32_t renderTransformCount;
		uint32_t offscreenTransformCount;
		uint32_t bufferAlignment;
		vk::Extent2D swapchainExtent;
		vk::SurfaceTransformFlagBitsKHR swapchainTransform;
		vk::Format depthStencilFormat;
		vk::SurfaceFormatKHR surfaceFormat;
		vk::PresentModeKHR presentMode;
		vk::Format imageFormat;
		vk::SampleCountFlagBits sampleCount;
		uint32_t mipLevels;
		float_t maxAnisotropy;
	};

	struct Vertex {
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 texture;
	};

	struct Camera {
		glm::vec3 pos;
		glm::vec3 dir;
		glm::vec3 up;
	};

	struct Buffer {
		vk::Buffer buffer;
		vk::DeviceMemory memory;
	};

	struct Image {
		uint32_t width;
		uint32_t height;
		vk::Image image;
		vk::ImageView view;
		vk::DeviceMemory memory;
	};

	struct Mesh {
		uint32_t indexOffset;
		uint32_t indexLength;
		uint32_t vertexOffset;
		uint32_t vertexLength;
		uint32_t textureOffset;
		uint32_t matrixIndex;
	};

	struct Model {
		uint32_t meshOffset;
		uint32_t meshCount;
	};

	struct Asset {
		uint32_t modelIndex;
		uint32_t matrixIndex;
		uint32_t transformOffset;
	};

	struct Portal {
		uint32_t blueAssetIndex;
		uint32_t orangeAssetIndex;
	};
}
