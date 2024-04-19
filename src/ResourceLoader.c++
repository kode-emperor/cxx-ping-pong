#include "include/ResourceLoader.hpp"

std::map<ResourceIndex, fs::path> resourcesPaths(const fs::path& rootDir) {
  auto rootDirStr = rootDir.string();
    std::map<ResourceIndex, fs::path> appResources{
    {ResourceIndex::FONTS, fs::path( rootDirStr + "/src/res/fonts")},
    {ResourceIndex::TEXTURES, fs::path( rootDirStr + "/src/res/textures")}
  };
  return appResources;
}