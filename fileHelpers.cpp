#include <filesystem>


std::filesystem::path getSrcDir(std::filesystem::path currentDirectory)
{
    // Iterate over the current path from the root to find the project name folder "mnist-classifier".
    std::filesystem::path sourceDir = "";
    auto it = currentDirectory.begin();
    while (*it != "mnist-classifier" && it != currentDirectory.end())
    {
        sourceDir /= *it;
        it++;
    }
    sourceDir /= *it;

    return sourceDir;
}
