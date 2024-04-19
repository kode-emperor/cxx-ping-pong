#ifndef RESOURCELOADER_HPP
#define RESOURCELOADER_HPP

#include <filesystem>
#include <string>
#include <map>

namespace fs = std::filesystem;

enum class ResourceIndex{FONTS, TEXTURES};
std::map<ResourceIndex, fs::path> resourcesPaths(const fs::path& rootDir);


#endif          // RESOURCELOADER_HPP