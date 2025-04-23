#pragma once
#include "../main.hpp"

// paths::previousDirectory BUG

std::map<std::string, std::pair<int, int>> parceTexturesSizes() {
	// �����������, ��� ����� �� ����� ������� � ����� �����, ������������� ����� �� ������ �������� ��� �� �� ��������, ������������� �� ��������� ������ ������
	// �����������, ��� �� ��������� ������� ������ ��� ���������� �����

	std::ifstream read(paths::previousDirectory + paths::textures::sizes);

	std::string line = "";

	std::map<std::string, std::pair<int, int>> parcedTexturesSizes;

	while (std::getline(read, line)) {
		std::string pathToTexture = "";

		std::string allSizes = "";

		std::string width = "";
		std::string height = "";

		// I THINK SLOW ALGORITHM
		std::size_t firstDeep = line.find(' ');

		for (std::size_t i = 0; i < firstDeep; i++) {
			pathToTexture.push_back(line[i]);
		}

		for (std::size_t i = firstDeep + 1; i < line.length(); i++) {
			allSizes.push_back(line[i]);
		}

		std::size_t secondDeep = allSizes.find(' ');

		for (std::size_t i = 0; i < secondDeep; i++) {
			width.push_back(allSizes[i]);
		}

		for (std::size_t i = secondDeep + 1; i < allSizes.length(); i++) {
			height.push_back(allSizes[i]);
		}

		parcedTexturesSizes.insert(
			std::make_pair(
				pathToTexture, 
				std::make_pair(std::stoi(width), std::stoi(height))
			)
		);
	}
	
	read.close();

	return parcedTexturesSizes;
}